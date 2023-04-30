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

#ifndef GOPTICAL_MATH_TRIANGLE_HH_
#define GOPTICAL_MATH_TRIANGLE_HH_

#include <ostream>

#include "goptical/core/common.hpp"

#include "goptical/core/math/vector.hpp"

namespace goptical
{

	namespace math
	{

		/**
		   @short Triangle base class
		   @header <goptical/core/math/Triangle
		   @module {Core}
		   @internal

		   This class is the base class for triangles in N dimensions.
		 */
		template <int N> struct TriangleBase
		{
				inline TriangleBase ();

				/** Create a triangle from 3 points */
				inline TriangleBase (const Vector<N> &a, const Vector<N> &b,
				                     const Vector<N> &c);
				/** Get point n of the triangle */
				inline const Vector<N> &operator[] (int n) const;
				/** Get reference to point n of the triangle */
				inline Vector<N> &operator[] (int n);
				/** Get triangle centroid */
				inline Vector<N> get_centroid () const;

			protected:
				Vector<N> _v[3];
		};

		/**
		   @short N dimension triangle class
		   @header goptical/core/math/Triangle
		   @module {Core}

		   This class is the general purpose N dimensions triangles class.
		 */

		template <int N> struct Triangle : public TriangleBase<N>
		{
			typedef std::function<void (const math::Triangle<N> &)> put_delegate_t;

			inline Triangle<N> ();

			/** Create a triangle from 3 points */
			inline Triangle<N> (const Vector<N> &a, const Vector<N> &b,
			                    const Vector<N> &c);
		};

		/**
		   @short 3d triangle class
		   @header goptical/core/math/Triangle
		   @module {Core}

		   This class is the 3d triangles class.
		 */
		template <> struct Triangle<3> : public TriangleBase<3>
		{
			typedef std::function<void (const math::Triangle<3> &)> put_delegate_t;

			inline Triangle<3> ();

			/** Create a triangle from 3 points */
			inline Triangle<3> (const Vector3 &a, const Vector3 &b, const Vector3 &c);

			/** Get triangle normal */
			inline Vector3 normal () const;
		};

		template <int N>
		inline std::ostream &operator<< (std::ostream &o, const Triangle<N> &l);

		template <int N> TriangleBase<N>::TriangleBase () {}

		template <int N>
		TriangleBase<N>::TriangleBase (const Vector<N> &a, const Vector<N> &b,
		                               const Vector<N> &c)
		{
			_v[0] = a;
			_v[1] = b;
			_v[2] = c;
		}

		template <int N>
		const Vector<N> &
		TriangleBase<N>::operator[] (int n) const
		{
			assert (n < 3);
			return _v[n];
		}

		template <int N>
		Vector<N> &
		TriangleBase<N>::operator[] (int n)
		{
			assert (n < 3);
			return _v[n];
		}

		template <int N>
		std::ostream &
		operator<< (std::ostream &o, const TriangleBase<N> &l)
		{
			o << "[" << l.vect (0) << ", " << l.vect (1) << ", " << l.vect (2) << "]";
			return o;
		}

		// **********************************************************************

		template <int N> Triangle<N>::Triangle () {}

		template <int N>
		Triangle<N>::Triangle (const Vector<N> &a, const Vector<N> &b,
		                       const Vector<N> &c)
			: TriangleBase<N> (a, b, c)
		{
		}

		template <int N>
		Vector<N>
		TriangleBase<N>::get_centroid () const
		{
			return (_v[0] + _v[1] + _v[2]) / 3.;
		}

		// **********************************************************************

		Triangle<3>::Triangle () {}

		Triangle<3>::Triangle (const Vector3 &a, const Vector3 &b, const Vector3 &c)
			: TriangleBase<3> (a, b, c)
		{
		}

		Vector3
		Triangle<3>::normal () const
		{
			return Vector3 (_v[0] - _v[1]).cross_product (_v[0] - _v[2]).normalized ();
		}

	}
}

#endif
