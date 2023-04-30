/*

      This file is part of the Goptical Core library.

      The Goptical library is free software; you can redistribute it
      and/or modify it under the terms of the GNU General Public
      License as published by the Free Software Foundation; either
      version 3 of the License, or (at your option) any later version.

      The Goptical library is distributed in the hope that it will be
      useful, but WITHOUT ANY WARRANTY; without even the implied
      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
      See the GNU General Public License for more details.

      You should have received a copy of the GNU General Public
      License along with the Goptical library; if not, write to the
      Free Software Foundation, Inc., 59 Temple Place, Suite 330,
      Boston, MA 02111-1307 USA

      Copyright (C) 2010-2011 Free Software Foundation, Inc
      Author: Alexandre Becoulet

*/

#ifndef GOPTICAL_MATH_VECTORPAIR_HH_
#define GOPTICAL_MATH_VECTORPAIR_HH_

#include <ostream>

#include "goptical/core/common.hpp"

#include "goptical/core/error.hpp"
#include "goptical/core/math/vector.hpp"

namespace goptical
{

	namespace math
	{

		/**
		   @short Vector pair base class
		   @header goptical/core/math/VectorPair
		   @module {Core}
		   @internal

		   This class is the base class for N dimensions vector pair.
		 */
		template <int N> struct VectorPairBase
		{
				inline VectorPairBase ();

				inline VectorPairBase (const Vector<N> &a, const Vector<N> &b);

				/** Get a reference to a vector stored in the pair */
				inline const Vector<N> &operator[] (int n) const;
				/** Get a reference to a vector stored in the pair */
				inline Vector<N> &operator[] (int n);

				inline const VectorPairBase &operator+= (const VectorPairBase &p);
				inline VectorPairBase operator* (double factor);

				/** Get reference to first vector */
				inline Vector<N> &origin ();
				/** Get reference to first vector */
				inline const Vector<N> &origin () const;

				/** Get reference to second vector */
				inline Vector<N> &direction ();
				/** Get reference to second vector */
				inline const Vector<N> &direction () const;

				/** Get reference to second vector */
				inline Vector<N> &normal ();
				/** Get reference to second vector */
				inline const Vector<N> &normal () const;

				/** Consider the @ref VectorPair as a segment with two point
				    vectors and find the closest point on this segment to a
				    point in space.

				    @return position of the closest point on segment.
				    @see seg_pt_clst_pt_scale
				*/
				inline Vector<N> seg_pt_clst_pt (const Vector<N> &point) const;

				/** Consider the @ref VectorPair as a segment with two point
				    vectors and find the closest point on this segment to a
				    point in space.

				    @return position on segment, value is in [0, 1] range if on segment.
				    @see seg_pt_clst_pt
				*/
				inline double seg_pt_clst_pt_scale (const Vector<N> &point) const;

				/** Consider the @ref VectorPair as a line with origin and
				    direction vectors and find the closest point on this line to
				    a point.

				    @return position of the closest point on the line.
				    @see ln_pt_clst_pt_scale
				*/
				inline Vector<N> ln_pt_clst_pt (const Vector<N> &point) const;

				/** Consider the @ref VectorPair as a line with origin and
				    direction vectors and find the closest point on this line to
				    an other line.

				    @return scale factor of the direction vector from origin.
				    @see ln_pt_clst_pt
				*/
				inline double ln_pt_clst_pt_scale (const Vector<N> &point) const;

			protected:
				Vector<N> _v[2];
		};

		/**
		   @short Vector pair class
		   @header goptical/core/math/VectorPair
		   @module {Core}

		   This class hold two N dimensions vectors.
		 */
		template <int N> struct VectorPair : public VectorPairBase<N>
		{
			inline VectorPair ();

			inline VectorPair (const VectorPairBase<N> &vp);

			inline VectorPair (const Vector<N> &a, const Vector<N> &b);
		};

		/**
		   @short Vector pair class
		   @header goptical/core/math/VectorPair
		   @module {Core}
		   @alias VectorPair2

		   This class hold two 2d vectors.
		 */
		template <> struct VectorPair<2> : public VectorPairBase<2>
		{
			inline VectorPair ();

			inline VectorPair (const VectorPairBase<2> &vp);

			inline VectorPair (const Vector<2> &a, const Vector<2> &b);

			inline VectorPair (double ax, double ay, double bx, double by);

			/** @multiple Get vector pair component */
			inline double x0 () const;
			inline double &x0 ();
			inline double y0 () const;
			inline double &y0 ();
			inline double x1 () const;
			inline double &x1 ();
			inline double y1 () const;
			inline double &y1 ();

			/** Create a 2d vector pair and initialize vectors from
			    specified components of vectors from an other pair. */
			template <int N>
			inline VectorPair (const VectorPairBase<N> &v, unsigned int c0,
			                   unsigned int c1);

			/** Consider the @ref VectorPair as a line with origin and
			    direction vectors and find the intersection point with an
			    other line.

			    @return position of the intersection point.
			    @this throws if lines are almost parallel.
			    @see ln_intersect_ln_scale
			*/
			inline Vector<2> ln_intersect_ln (const VectorPair<2> &line) const;

			/** Consider the @ref VectorPair as a line with origin and
			    direction vectors and find the intersection point with an
			    other line.

			    @return scale factor of the direction vector from line origin.
			    @this throws if lines are almost parallel.
			    @see ln_intersect_ln
			*/
			inline double ln_intersect_ln_scale (const VectorPair<2> &line) const;

			/** Consider the @ref VectorPair as a segment with two point
			    vectors and find the intersection point with an other segment.

			    @return position of the intersection point.

			    The @tt infinite_1st and @tt infinite_2nd template parameters
			    can be used to disable point-in-segment tests for each segments.
			    @this throws if lines are almost parallel or if intersection
			    point lies outside segment and associated test is enabled.
			*/
			template <bool infinite_1st, bool infinite_2nd>
			inline Vector<2> seg_intersect_seg (const VectorPair<2> &segment) const;
		};

		/**
		   @short Vector pair class
		   @header goptical/core/math/VectorPair
		   @module {Core}
		   @alias VectorPair3

		   This class hold two 3d vectors.
		 */
		template <> struct VectorPair<3> : public VectorPairBase<3>
		{
			inline VectorPair ();

			inline VectorPair (const VectorPairBase<3> &vp);

			inline VectorPair (const Vector<3> &a, const Vector<3> &b = vector3_001);

			inline VectorPair (double ax, double ay, double az, double bx = 0.0,
			                   double by = 0.0, double bz = 1.0);

			/** @multiple Get vector pair component */
			inline double x0 () const;
			inline double &x0 ();
			inline double y0 () const;
			inline double &y0 ();
			inline double z0 () const;
			inline double &z0 ();
			inline double x1 () const;
			inline double &x1 ();
			inline double y1 () const;
			inline double &y1 ();
			inline double z1 () const;
			inline double &z1 ();

			/** Consider the @ref VectorPair as a line with origin and
			    direction vectors and find the closest point on this line to
			    an other line.

			    @return position of the closest point on the line.
			    @this throws if lines are almost parallel.
			    @see ln_ln_clst_pt_scale
			*/
			inline Vector<3> ln_ln_clst_pt (const VectorPair<3> &line) const;

			/** Consider the @ref VectorPair as a line with origin and
			    direction vectors and find the closest point on this line to
			    an other line.

			    @return scale factor of the direction vector from origin.
			    @this throws if lines are almost parallel.
			    @see ln_ln_clst_pt
			*/
			inline double ln_ln_clst_pt_scale (const VectorPair<3> &line) const;

			/** Consider the @ref VectorPair as a plane and find
			    intersection point with a line. Plane is defined by origin
			    and normal vectors and line is defined by origin and
			    direction vectors.

			    @return position of the intersection point on the line.
			    @see pl_ln_intersect_scale
			*/
			inline Vector<3> pl_ln_intersect (const VectorPair<3> &line) const;

			/** Consider the @ref VectorPair as a plane and find
			    intersection point with a line. Plane is defined by origin
			    and normal vectors and line is defined by origin and
			    direction vectors.

			    @return scale factor of the line direction vector from line origin.
			    @see pl_ln_intersect
			*/
			inline double pl_ln_intersect_scale (const VectorPair<3> &line) const;
		};

		template <int N>
		inline std::ostream &operator<< (std::ostream &o, const VectorPairBase<N> &l);

		static const VectorPair<2> vector2_pair_00
		    = VectorPair<2> (vector2_0, vector2_0);
		static const VectorPair<2> vector2_pair_01
		    = VectorPair<2> (vector2_0, vector2_1);

		static const VectorPair<3> vector3_pair_00
		    = VectorPair<3> (vector3_0, vector3_0);
		static const VectorPair<3> vector3_pair_01
		    = VectorPair<3> (vector3_0, vector3_1);

		template <int N> VectorPairBase<N>::VectorPairBase () {}

		template <int N>
		VectorPairBase<N>::VectorPairBase (const Vector<N> &first,
		                                   const Vector<N> &second)
		{
			_v[0] = first;
			_v[1] = second;
		}

		template <int N>
		const Vector<N> &
		VectorPairBase<N>::operator[] (int n) const
		{
			return _v[n];
		}

		template <int N>
		Vector<N> &
		VectorPairBase<N>::operator[] (int n)
		{
			return _v[n];
		}

		template <int N>
		const VectorPairBase<N> &
		VectorPairBase<N>::operator+= (const VectorPairBase<N> &p)
		{
			for (unsigned int i = 0; i < N; i++)
			{
				_v[i] += p._v[i];
			}
			return *this;
		}

		template <int N>
		VectorPairBase<N>
		VectorPairBase<N>::operator* (double factor)
		{
			return VectorPairBase (_v[0] * factor, _v[1] * factor);
		}

		template <int N>
		Vector<N> &
		VectorPairBase<N>::origin ()
		{
			return _v[0];
		}

		template <int N>
		const Vector<N> &
		VectorPairBase<N>::origin () const
		{
			return _v[0];
		}

		template <int N>
		Vector<N> &
		VectorPairBase<N>::direction ()
		{
			return _v[1];
		}

		template <int N>
		const Vector<N> &
		VectorPairBase<N>::direction () const
		{
			return _v[1];
		}

		template <int N>
		Vector<N> &
		VectorPairBase<N>::normal ()
		{
			return _v[1];
		}

		template <int N>
		const Vector<N> &
		VectorPairBase<N>::normal () const
		{
			return _v[1];
		}

		template <int N>
		double
		VectorPairBase<N>::seg_pt_clst_pt_scale (const Vector<N> &point) const
		{
			Vector<N> d = _v[1] - _v[0];
			return ((point - _v[0]) * d) / (d * d);
		}

		template <int N>
		Vector<N>
		VectorPairBase<N>::seg_pt_clst_pt (const Vector<N> &point) const
		{
			Vector<N> d = _v[1] - _v[0];
			double s = std::min (std::max (((point - _v[0]) * d) / (d * d), 0.0), 1.0);
			return _v[0] + d * s;
		}

		template <int N>
		double
		VectorPairBase<N>::ln_pt_clst_pt_scale (const Vector<N> &point) const
		{
			return _v[1] * (point - _v[0]);
		}

		template <int N>
		Vector<N>
		VectorPairBase<N>::ln_pt_clst_pt (const Vector<N> &point) const
		{
			return _v[0] + _v[1] * ln_pt_clst_pt_scale (point);
		}

		template <int N>
		std::ostream &
		operator<< (std::ostream &o, const VectorPairBase<N> &l)
		{
			o << "[" << l[0] << ", " << l[1] << "]";
			return o;
		}

		// **********************************************************************

		template <int N> VectorPair<N>::VectorPair () {}

		template <int N>
		VectorPair<N>::VectorPair (const VectorPairBase<N> &vp)
			: VectorPairBase<N> (vp)
		{
		}

		template <int N>
		VectorPair<N>::VectorPair (const Vector<N> &first, const Vector<N> &second)
			: VectorPairBase<N> (first, second)
		{
		}

		// **********************************************************************

		VectorPair<2>::VectorPair () {}

		VectorPair<2>::VectorPair (const VectorPairBase<2> &vp)
			: VectorPairBase<2> (vp)
		{
		}

		VectorPair<2>::VectorPair (const Vector<2> &first, const Vector<2> &second)
			: VectorPairBase<2> (first, second)
		{
		}

		VectorPair<2>::VectorPair (double ax, double ay, double bx, double by)
			: VectorPairBase<2> (math::Vector<2> (ax, ay), math::Vector<2> (bx, by))
		{
		}

		double
		VectorPair<2>::x0 () const
		{
			return _v[0].x ();
		}

		double &
		VectorPair<2>::x0 ()
		{
			return _v[0].x ();
		}

		double
		VectorPair<2>::y0 () const
		{
			return _v[0].y ();
		}

		double &
		VectorPair<2>::y0 ()
		{
			return _v[0].y ();
		}

		double
		VectorPair<2>::x1 () const
		{
			return _v[1].x ();
		}

		double &
		VectorPair<2>::x1 ()
		{
			return _v[1].x ();
		}

		double
		VectorPair<2>::y1 () const
		{
			return _v[1].y ();
		}

		double &
		VectorPair<2>::y1 ()
		{
			return _v[1].y ();
		}

		template <int N>
		VectorPair<2>::VectorPair (const VectorPairBase<N> &v, unsigned int c0,
		                           unsigned int c1)
			: VectorPairBase<2> (Vector<2> (v[0], c0, c1), Vector<2> (v[1], c0, c1))
		{
		}

		double
		VectorPair<2>::ln_intersect_ln_scale (const VectorPair<2> &line) const
		{
			// based on
			// http://geometryalgorithms.com/Archive/algorithm_0104/algorithm_0104B.htm
			const Vector<2> w = _v[0] - line._v[0];
			double d = _v[1].x () * line._v[1].y () - _v[1].y () * line._v[1].x ();
			if (fabs (d) < 1e-10)
			{
				throw Error ("ln_intersect_ln_scale: lines are parallel");
			}
			double s = (line._v[1].x () * w.y () - line._v[1].y () * w.x ()) / d;
			return s;
		}

		Vector<2>
		VectorPair<2>::ln_intersect_ln (const VectorPair<2> &line) const
		{
			return _v[0] + _v[1] * ln_intersect_ln_scale (line);
		}

		template <bool infinite_1st, bool infinite_2nd>
		Vector<2>
		VectorPair<2>::seg_intersect_seg (const VectorPair<2> &s) const
		{
			double d = ((s.x1 () - s.x0 ()) * y1 () + (s.x0 () - s.x1 ()) * y0 ()
			            + (s.y0 () - s.y1 ()) * x1 () + (s.y1 () - s.y0 ()) * x0 ());
			double t1 = ((s.x1 () - s.x0 ()) * y1 () + (s.y0 () - s.y1 ()) * x1 ()
			             + s.x0 () * s.y1 () - s.x1 () * s.y0 ())
			            / d;
			double t2 = -((x0 () - s.x1 ()) * y1 () + (s.x1 () - x1 ()) * y0 ()
			              + s.y1 () * x1 () - s.y1 () * x0 ())
			            / d;
			if (!infinite_1st && (t1 > 1. || t1 < 0.))
			{
				throw Error ("seg_intersect_seg: no intersection");
			}
			if (!infinite_2nd && (t2 > 1. || t2 < 0.))
			{
				throw Error ("seg_intersect_seg: no intersection");
			}
			return Vector<2> (x0 () * t1 + x1 () * (1. - t1),
			                  y0 () * t1 + y1 () * (1. - t1));
		}

		// **********************************************************************

		VectorPair<3>::VectorPair () {}

		VectorPair<3>::VectorPair (const Vector<3> &first, const Vector<3> &second)
			: VectorPairBase<3> (first, second)
		{
		}

		VectorPair<3>::VectorPair (const VectorPairBase<3> &vp)
			: VectorPairBase<3> (vp)
		{
		}

		VectorPair<3>::VectorPair (double ax, double ay, double az, double bx,
		                           double by, double bz)
			: VectorPairBase<3> (math::Vector<3> (ax, ay, az),
			                     math::Vector<3> (bx, by, bz))
		{
		}

		double
		VectorPair<3>::x0 () const
		{
			return _v[0].x ();
		}

		double &
		VectorPair<3>::x0 ()
		{
			return _v[0].x ();
		}

		double
		VectorPair<3>::y0 () const
		{
			return _v[0].y ();
		}

		double &
		VectorPair<3>::y0 ()
		{
			return _v[0].y ();
		}

		double
		VectorPair<3>::z0 () const
		{
			return _v[0].z ();
		}

		double &
		VectorPair<3>::z0 ()
		{
			return _v[0].z ();
		}

		double
		VectorPair<3>::x1 () const
		{
			return _v[1].x ();
		}

		double &
		VectorPair<3>::x1 ()
		{
			return _v[1].x ();
		}

		double
		VectorPair<3>::y1 () const
		{
			return _v[1].y ();
		}

		double &
		VectorPair<3>::y1 ()
		{
			return _v[1].y ();
		}

		double
		VectorPair<3>::z1 () const
		{
			return _v[1].z ();
		}

		double &
		VectorPair<3>::z1 ()
		{
			return _v[1].z ();
		}

		double
		VectorPair<3>::ln_ln_clst_pt_scale (const VectorPair<3> &line) const
		{
			// based on
			// http://geometryalgorithms.com/Archive/algorithm_0106/algorithm_0106.htm
			const math::Vector<3> &u = _v[1];
			const math::Vector<3> &v = line._v[1];
			const math::Vector<3> w = _v[0] - line._v[0];
			double b = u * v;
			double c = v * v;
			double k = (u * u) * c - b * b;
			if (k <= 1e-10) // throw if lines are almost parallel
			{
				throw Error ();
			}
			return (b * (v * w) - c * (u * w)) / k;
		}

		Vector<3>
		VectorPair<3>::ln_ln_clst_pt (const VectorPair<3> &line) const
		{
			return _v[0] + _v[1] * ln_ln_clst_pt_scale (line);
		}

		double
		VectorPair<3>::pl_ln_intersect_scale (const VectorPair<3> &line) const
		{
			return (_v[0] * _v[1] - _v[1] * line._v[0]) / (line._v[1] * _v[1]);
		}

		Vector<3>
		VectorPair<3>::pl_ln_intersect (const VectorPair<3> &line) const
		{
			return line._v[0] + line._v[1] * pl_ln_intersect_scale (line);
		}
	}
}

using goptical::math::VectorPair;
using goptical::math::VectorPair2;
using goptical::math::VectorPair3;

using goptical::math::vector2_pair_00;
using goptical::math::vector2_pair_01;
using goptical::math::vector3_pair_00;
using goptical::math::vector3_pair_01;

#endif
