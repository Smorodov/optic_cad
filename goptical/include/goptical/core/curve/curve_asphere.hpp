#ifndef GOPTICAL_CURVE_ASPHERE_HPP
#define GOPTICAL_CURVE_ASPHERE_HPP

#include <goptical/core/curve/rotational.hpp>

namespace goptical
{
	namespace curve
	{

		/**
		 * This class implements general rotationally symmetric aspheric surphace.
		 * The formula used is as follows:
		 *
		 * z = f(x,y) = c*s^2/(1+(1-k*c^2*s^2)^(1/2)) + A_4*s^4 + A_6*s^6 + A_8*s^8 +
		 * A_10*s^10 + A_12*s^12 + A_14*s^14
		 *
		 * where
		 *
		 * s^2 = x^2 + y^2
		 * c = 1/r, i.e. curvature
		 * r = radius
		 * k = surface constant that determines the eccentricity
		 * A_4 ... A_14 - coefficients of the deformation polynomial
		 *
		 * When
		 * k < 0, surface is hyperboloid
		 * k == 0, paraboloid
		 * 0 < k < 1 hemelipsoid of revolution about major axis
		 * k = 1, hemisphere
		 * k > 1 hemelipsoid of revolution about minor axis
		 */
		class Asphere : public goptical::curve::Rotational
		{
			public:
				Asphere (double r, double k, double A4, double A6, double A8, double A10,
				         double A12 = 0.0, double A14 = 0.0, bool feder_algo = true)
					: _r (r), _c (1.0 / r), _k (k), _A4 (A4), _A6 (A6), _A8 (A8), _A10 (A10),
					  _A12 (A12), _A14 (A14), _feder_algo (feder_algo)
				{
				}

				/** Get curve sagitta (z) at specified distance from origin.
				 *  @param s distance from curve origin (0, 0), s = sqrt(x^2 + y^2).
				 */
				virtual double sagitta (double s) const override;

				/** Get intersection point between curve and 3d ray. Return
				    false if no intersection occurred. ray must have a position vector and
				    direction vector (cosines). The new position will be stored
				    in point. */
				virtual bool intersect (math::Vector3 &point,
				                        const math::VectorPair3 &ray) const override;

				/** Get normal to curve surface at specified point. */
				virtual void normal (math::Vector3 &normal,
				                     const math::Vector3 &point) const override;

				/** Get curve derivative dz/ds at specified distance from origin.
				    @param s distance from curve origin (0, 0), s = sqrt(x^2 + y^2).
				*/
				virtual double derivative (double s) const override;

				/** Get curve sagitta (z) at specified point (x,y) */
				virtual double sagitta (const math::Vector2 &xy) const override;

				/** Get curve dz/dx and dx/dy partial derivatives (gradient) at specified
				 * point (x,y) */
				virtual void derivative (const math::Vector2 &xy,
				                         math::Vector2 &dxdy) const override;

			public:
				double _r;        /* radius */
				double _c;        /* curvature = 1/_r */
				double _k;        /* K - eccentricity constant */
				double _A4;       /* deformation polynomial coefficient */
				double _A6;       /* deformation polynomial coefficient */
				double _A8;       /* deformation polynomial coefficient */
				double _A10;      /* deformation polynomial coefficient */
				double _A12;      /* deformation polynomial coefficient */
				double _A14;      /* deformation polynomial coefficient */
				bool _feder_algo; /* Use the algorithms by Feder */
		};

		bool compute_intersection (const Vector3 &origin, const Vector3 &direction,
		                           const goptical::curve::Asphere *S, Vector3 &result,
		                           Vector3 &normal);

	} // namespace curve
} // namespace goptical

#endif // GOPTICAL_CURVE_ASPHERE_HPP
