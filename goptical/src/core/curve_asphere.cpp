#include <goptical/core/curve/curve_asphere.hpp>
#include <goptical/core/math/vector.hpp>
#include <goptical/core/math/vector_pair.hpp>

#include <cmath>
#include <cstdio>

namespace goptical
{
	namespace curve
	{

		/**
		 * Compute A_4*s^4 + A_6*s^6 + A_8*s^8 + A_10*s^10 + A_12*s^12 + A_14*s^14
		 * s2 = x^2 + y^2
		 */
		static inline double
		deform_sagitta (const goptical::curve::Asphere *S, double s2)
		{
			double s4 = s2 * s2;
			double s6 = s4 * s2;
			double s8 = s6 * s2;
			double s10 = s8 * s2;
			double s12 = s10 * s2;
			double s14 = s12 * s2;
			return S->_A4 * s4 + S->_A6 * s6 + S->_A8 * s8 + S->_A10 * s10
			       + S->_A12 * s12 + S->_A14 * s14;
		}

		/**
		 * Compute 4*A_4*s^2 + 6*A_6*s^4 + 8*A_8*s^6 + 10*A_10*s^8 + 12*A_12*s^10 +
		 * 14*A_14*s^12 s2 = x^2 + y^2 Used in dz/dy and dz/dx calculations
		 */
		static inline double
		deform_dz_dxy (const goptical::curve::Asphere *S, double s2)
		{
			double s4 = s2 * s2;
			double s6 = s4 * s2;
			double s8 = s6 * s2;
			double s10 = s8 * s2;
			double s12 = s10 * s2;
			return 4 * S->_A4 * s2 + 6 * S->_A6 * s4 + 8 * S->_A8 * s6
			       + 10 * S->_A10 * s8 + 12 * S->_A12 * s10 + 14 * S->_A14 * s12;
		}

		/**
		 * Compute 4*A_4*s^3 + 6*A_6*s^5 + 8*A_8*s^7 + 10*A_10*s^9 + 12*A_12*s^11 +
		 * 14*A_14*s^13 s2 = x^2 + y^2 Used in dz/ds calculation
		 */
		static inline double
		deform_dz_ds (const goptical::curve::Asphere *S, double s)
		{
			double s2 = s * s;
			double s3 = s2 * s;
			double s5 = s3 * s2;
			double s7 = s5 * s2;
			double s9 = s7 * s2;
			double s11 = s9 * s2;
			double s13 = s11 * s2;
			return 4 * S->_A4 * s3 + 6 * S->_A6 * s5 + 8 * S->_A8 * s7
			       + 10 * S->_A10 * s9 + 12 * S->_A12 * s11 + 14 * S->_A14 * s13;
		}

		/* computes intersection using Feder's equations - code is taken from
		 * https://github.com/dibyendumajumdar/ray.
		 * Note that Feder's paper uses x-axis rather than z-axis as the
		 * optical axis, so below we switch from x to z.
		 */
		bool
		compute_intersection (const Vector3 &origin, const Vector3 &direction,
		                      const goptical::curve::Asphere *S, Vector3 &result,
		                      Vector3 &N)
		{
			/* NOTE: variable 't' was
			 used by Feder as the vertex separation between previous
			 surface and this surface. In the new scheme, in which rays
			 are transformed to the coordinate system of the surface
			 before tracing, 't' is _zero_. It is still present in this
			 code to enable comparison with the Feder paper; the
			 optimizing compiler will eliminate it from the
			 expressions. */
			/* direction (X,Y,Z) is the vector along the ray to the surface */
			/* origin (x,y,z) is the vector form of the vertex of the surface */
			/* Feder paper equation (1) */
			double t = 0;
			double e = (t * origin.z ()) - origin * direction;
			/* Feder paper equation (2) */
			double M_1x = origin.z () + e * direction.z () - t;
			/* Feder paper equation (3) */
			double M_1_2 = origin * origin - (e * e) + (t * t) - (2.0 * t * origin.z ());
			double r_1_2 = 1. / (S->_c * S->_c);
			if (M_1_2 > r_1_2)
			{
				M_1_2 = r_1_2; /* SPECIAL RULE! 96-01-22 */
			}
			/* Feder paper equation (4) */
			double xi_1 = sqrt ((direction.z () * direction.z ())
			                    - S->_c * (S->_c * M_1_2 - 2.0 * M_1x));
			if (isnan (xi_1))
			{
				/* NaN! reject this ray! */
				printf ("Nan value\n");
				return false;
			}
			/* Feder paper equation (5) */
			double L = e + (S->_c * M_1_2 - 2.0 * M_1x) / (direction.z () + xi_1);
			/* Get intercept with new (spherical) surface: */
			double delta_length[3];
			for (int j = 0; j < 3; j++)
			{
				delta_length[j] = -origin[j];
			}
			result = origin + direction * L;
			result.z () = result.z () - t;
			/* Now (result) has x1, y1, z1 */
			/* The ray has been traced to the osculating sphere with
			   curvature c1. Now we will iterate to get the intercept with
			   the nearby aspheric surface. Suppose the (rotationally
			   symmetric) aspheric is given by $$x = f(y,z)$$, and is a
			   function of $y^2 + z^2$ only. For a spherical surface, one
			   has $$x = r - (r^2 - s^2)^{1\over2}$$, where $s^2 = y^2 +
			   z^2$. For a general surface one may add deformation terms
			   to this expression and obtain $$x = c s^2 / (1 + (1 - c^2
			   s^2)^{1\over2})) + (A_2 s^2 + A_4 s^4 + ...) = f$$.  The
			   equation is expressed in this form in order to avoid
			   indeterminacy as c approaches zero, and in order to
			   represent surfaces that are nearly spherical. Near-spheres
			   cannot be handled well by a power series alone, especially
			   in the neighborhood of $s = 1 / c$.

			   In this implementation we include a term for the numerical
			   eccentricity so that we can trace any pure conic section
			   without using the $A_i$ terms. */
			enum
			{
			    TOLMAX = 10
			};
			double tolerance = 1e-15;
			int j = 0;
			double delta = 0.0;
			do
			{
				/* Get square of radius of intercept: */
				/* Feder equation s^2 = x^2 + y^2, section E */
				double s_2 = result.y () * result.y () + result.x () * result.x ();
				/* Get the point on aspheric which is at the same radius as
				   the intercept of the ray. Then compute a tangent plane to
				   the aspheric at this point and find where it intersects
				   the ray.  This point will lie very close to the aspheric
				   surface.  The first step is to compute the z-coordinate
				   on the aspheric surface using $\overline{z}_0 = f(x_0,
				   y_0)$. */
				/* (1 - k*c^2*s^2)^(1/2) - part of equation (12) */
				double temp = sqrt (1.0 - S->_c * S->_c * s_2 * S->_k);
				if (isnan (temp) || (1.0 + temp) == 0.0)
				{
					printf ("Nan or zero divide value\n");
					return false;
				}
				/* Feder equation (12) */
				/* But using c*s^2/[1 + (1 - k*c^2*s^2)^(1/2)] + aspheric A_2*s^2 +
				 * A_4*s^4 + ... */
				double x_bar_0 = (S->_c * s_2) / (1.0 + temp) + deform_sagitta (S, s_2);
				delta = fabs (result.z () - x_bar_0);
				/* Get the direction numbers for the normal to the
				   aspheric: */
				/* Feder equation (13), l */
				N.z () = temp;
				temp = S->_c + N.z () * deform_dz_dxy (S, s_2);
				/* Feder equation (14), m */
				N.y () = -result.y () * temp;
				/* Feder equation (15), n */
				N.x () = -result.x () * temp;
				/* Get the distance from aspheric point to ray intercept */
				double G_0 = N.z () * (x_bar_0 - result.z ()) / (direction * N);
				/* and compute new estimate of intercept point: */
				result = result + direction * G_0;
			}
			while ((delta > tolerance) && (++j < TOLMAX));
			if (j >= TOLMAX)
			{
				printf ("rayTrace: delta=%g, reached %d iterations!?!\n", delta, j);
				return false;
			}
			return true;
		}

		bool
		compute_normal (const goptical::curve::Asphere *S, const Vector3 &point,
		                Vector3 &N)
		{
			/* General ray tracing procedure - Spencer and Murty */
			/* See eq 18, 19 */
			/* Also same as p632 Feder - but z axis swapped with x */
			double s_2 = point.y () * point.y () + point.x () * point.x ();
			double temp = sqrt (1.0 - S->_c * S->_c * s_2 * S->_k);
			if (temp == 0.0)
			{
				N.x () = 0;
				N.y () = 0;
				N.z () = 1.0;
				return true; // See curve_rotational.cpp - we mimic
			}
			if (isnan (temp))
			{
				return false;
			}
			double E = S->_c / temp + deform_dz_dxy (S, s_2); // eq 19
			N.y () = -point.y () * E;                         // eq 18
			N.x () = -point.x () * E;                         // eq 18
			N.z () = 1.0;                                     // eq 18
			// Following is from Goptical - tbc
			N.normalize ();
			return true;
		}

		/** Compute z at s^2, where s^2 = x^2 + y^2 */
		static double
		compute_Z (const Asphere *surface, double s2)
		{
			/* Our formula is:
			 * z = f(s) = c*s^2/(1 + (1 - c^2*k*s^2)^(1/2)) + A_4*s^4 + A_6*s^6 + A_8*s^8
			 * + A_10*s^10 + + A_12*s^12 + A_14*s^14
			 *
			 * where s = (x^2 + y^2)^(1/2)
			 */
			double c = surface->_c; /* curvature = 1/radius */
			double c2 = c * c;
			double K = surface->_k;
			double l = sqrt (1 - s2 * K * c2);
			double temp = 1 + l;
			if (temp == 0.0)
			{
				// division by zero, really an error
				return 0;
			}
			return c * s2 / temp + deform_sagitta (surface, s2);
		}

		/** Compute z at x,y */
		static double
		compute_Z (const Asphere *surface, const math::Vector2 &xy)
		{
			/* Our formula is:
			 * z = f(s) = c*s^2/(1 + (1 - c^2*k*s^2)^(1/2)) + A_4*s^4 + A_6*s^6 + A_8*s^8
			 * + A_10*s^10 + + A_12*s^12 + A_14*s^14
			 *
			 * where s = (x^2 + y^2)^(1/2)
			 */
			double s2 = xy.x () * xy.x () + xy.y () * xy.y ();
			return compute_Z (surface, s2);
		}

		/** Compute dz/ds. For the equation see next function below. */
		static double
		compute_derivative (const Asphere *surface, double s)
		{
			double s2 = s * s;
			double c = surface->_c; /* curvature = 1/radius */
			double c2 = c * c;
			double K = surface->_k;
			double l = sqrt (1 - s2 * K * c2);
			if (l == 0.0)
			{
				// division by zero, really an error
				return 0;
			}
			return (c * s) / l + deform_dz_ds (surface, s);
		}

		/** Compute dz/dx and dz/dy at x,y */
		static void
		compute_derivative (const Asphere *surface, const math::Vector2 &xy,
		                    math::Vector2 &dxdy)
		{
			/*
			 * Let s^2 = x^2 + y^2
			 * and,
			 * z = f(s) = c*s^2/(1 + (1 - c^2*k*s^2)^(1/2)) + A_4*s^4 + A_6*s^6 + A_8*s^8
			 * + A_10*s^10 + A_12*s^12 + A_14*s^14
			 *
			 * Then,
			 * dz/dx = dz/ds * ds/dx
			 *
			 * Now,
			 * dz/ds = c*s/(1 - c^2*k*s^2)^(1/2) + 4*A_4*s^3 + 6*A_6*s^5 + 8*A_8*s^7 +
			 * 10*A_10*s^9 + 12*A_12*s^11 + 14*A_14*s^13 and, ds/dx = x/s
			 *
			 * using
			 * E = dz/ds * 1/s = c/(1 - c^2*k*s^2)^(1/2) + 4*A_4*s^2 + 6*A_6*s^4 +
			 * 8*A_8*s^6 + 10*A_10*s^8 + 12*A_12*s^10 + 14*A_14*s^12 dz/dx = x*E and
			 * dz/dy = y*E
			 */
			double s = sqrt (xy.x () * xy.x () + xy.y () * xy.y ());
			double E = compute_derivative (surface, s) / s;
			dxdy.x () = xy.x () * E;
			dxdy.y () = xy.y () * E;
		}

		double
		Asphere::sagitta (double s) const
		{
			return compute_Z (this, s * s);
		}

		double
		Asphere::derivative (double r) const
		{
			if (_feder_algo)
			{
				return compute_derivative (this, r);
			}
			else
			{
				return Rotational::derivative (r);
			}
		}

		double
		Asphere::sagitta (const math::Vector2 &xy) const
		{
			return compute_Z (this, xy);
		}

		void
		Asphere::derivative (const math::Vector2 &xy, math::Vector2 &dxdy) const
		{
			if (_feder_algo)
			{
				compute_derivative (this, xy, dxdy);
			}
			else
			{
				Rotational::derivative (xy, dxdy);
			}
		}

		bool
		Asphere::intersect (math::Vector3 &point, const math::VectorPair3 &ray) const
		{
			static int count = 0;
			count++;
			if (_feder_algo)
			{
				math::Vector3 normal (0, 0, 0);
				bool ok = compute_intersection (ray.origin (), ray.direction (), this,
				                                point, normal);
				// normal.normalize();
				//	  if (ok && count % 25 == 0)
				//	    {
				//	      printf ("{ %.16f, %.16f", this->_r, this->_k);
				//	      printf (", %.16f, %.16f, %.16f, %.16f, %.16f, %.16f",
				//this->_A4, 		      this->_A6, this->_A8, this->_A10, this->_A12, this->_A14);
				//	      printf (", %.16f, %.16f, %.16f", ray.origin ().x (),
				//		      ray.origin ().y (), ray.origin ().z ());
				//	      printf (", %.16f, %.16f, %.16f", ray.direction ().x (),
				//		      ray.direction ().y (), ray.direction ().z ());
				//	      printf (", %.16f, %.16f, %.16f },\n", point.x (), point.y
				//(), 		      point.z ());
				//	    }
				return ok;
			}
			else
			{
				return Base::intersect (point, ray);
			}
		}

		void
		Asphere::normal (math::Vector3 &normal, const math::Vector3 &point) const
		{
			if (_feder_algo)
			{
				compute_normal (this, point, normal);
				normal *= -1.0;
			}
			else
			{
				Rotational::normal (normal, point);
			}
		}

	} // namespace curve
} // namespace goptical