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

#ifndef GOPTICAL_MATH_VECTORBASE_HH_
#define GOPTICAL_MATH_VECTORBASE_HH_

#include <ostream>

#include "goptical/core/common.hpp"

namespace goptical
{

	namespace math
	{

		/**
		   @short Vector base class
		   @header goptical/core/math/Vector
		   @module {Core}
		   @internal

		   This class is the base class for N dimensions vector.
		 */
		template <int N, typename T> struct VectorBase
		{
				template <int, typename> friend struct VectorBase;

				/** Set the whole vector to the specified value */
				inline void set (T value);
				/** Get value at specified index */
				inline T operator[] (int n) const;
				/** Get reference to value at specified index */
				inline T &operator[] (int n);
				/** Add two vectors */
				inline VectorBase operator+ (const VectorBase &v) const;
				/** Subtract two vectors */
				inline VectorBase operator- (const VectorBase &v) const;
				/** Get negated vector */
				inline VectorBase operator- () const;
				/** Negate vector */
				inline VectorBase &neg ();
				/** Add a vector */
				inline const VectorBase &operator+= (const VectorBase &v);
				/** Sutract a vector */
				inline const VectorBase &operator-= (const VectorBase &v);
				/** Vector dot product */
				inline T operator* (const VectorBase &v) const;
				/** Vector values multiply */
				inline VectorBase mul (const VectorBase &v) const;
				/** Scale vector */
				inline VectorBase operator* (T scale) const;
				/** Scale vector */
				inline VectorBase operator/ (T scale) const;
				/** Vector division */
				inline VectorBase operator/ (const VectorBase &v) const;
				/** Multiply by a vector */
				inline const VectorBase &operator*= (T scale);
				/** Divide by a vector */
				inline const VectorBase &operator/= (T scale);
				/** Compute vector length */
				inline T len () const;
				/** Normalize vector length @see normalized */
				inline const VectorBase &normalize ();
				/** Get normalized vector @see normalize */
				inline VectorBase normalized () const;
				/** Adjust vector length */
				inline VectorBase magnitude (T newlen) const;
				/** Select components from two vectors. Components which have
				    their corresponding bit set in the mask are extracted from
				    this vector and other components are taken from passed
				    vector. */
				template <int M>
				inline VectorBase<M, T> select (unsigned int bitmask,
				                                const VectorBase<M, T> &v) const;
				/** Multiply vector with matrix. See Vector class for
				    matrix/vector multiplication. */
				inline VectorBase operator* (const Matrix<N> &m);
				/** compare two vectors for equality */
				inline bool operator== (const VectorBase &m) const;
				/** compare two almost equal vectors */
				inline bool close_to (const VectorBase &m, T error = 1e-8);

			protected:
				T _val[N];
		};

		/**
		   @short N dimension vector class
		   @header goptical/core/math/Vector
		   @module {Core}

		   This class is the general purpose N dimensions vector class.
		 */
		template <int N, typename T> struct Vector : public VectorBase<N, T>
		{
			inline Vector ();
			inline Vector (const VectorBase<N, T> &v);
			/** Create a 2d vector with same value for all components */
			inline Vector (T v);
		};

		/**
		   @short 2d vector class
		   @header goptical/core/math/Vector
		   @module {Core}
		   @alias Vector2

		   This class implements 2d vectors.

		   The @ref math namespace contains some commonly used constant vector objects.
		 */

		template <typename T> struct Vector<2, T> : public VectorBase<2, T>
		{
			typedef VectorBase<2, T> base;
			typedef std::function<void (const math::Vector2 &)> put_delegate_t;

			inline Vector ();

			inline Vector (const VectorBase<2, T> &v);

			template <int M> inline Vector (const VectorBase<M, T> &v, T p);

			/** Create a 2d vector with same value for all components */
			inline Vector (T v);

			/** Create a 2d vector from x and y z values */
			inline Vector (T x, T y);

			/** Create a 2d vector and initialize from specified components of an other
			 * vector */
			template <int N>
			inline Vector (const VectorBase<N, T> &v, unsigned int c0, unsigned int c1);

			inline T cross_product (const Vector<2, T> &v) const;

			/** Get reference to vector x value */
			inline T &x ();
			/** Get reference to vector y value */
			inline T &y ();
			/** Get vector x value */
			inline T x () const;
			/** Get vector y value */
			inline T y () const;
		};

		/**
		   @short 3d vector class
		   @header goptical/core/math/Vector
		   @module {Core}
		   @alias Vector3

		   This class implements 3d vectors.

		   The @ref math namespace contains some commonly used constant vector objects.
		 */
		template <typename T> struct Vector<3, T> : public VectorBase<3, T>
		{
			typedef VectorBase<3, T> base;
			typedef std::function<void (const Vector<3, T> &)> put_delegate_t;

			inline Vector ();

			/** Copy constructor */
			inline Vector (const VectorBase<3, T> &v);

			/** Create a 3d vector from 2d vector and given z value. */
			template <int M> inline Vector (const VectorBase<M, T> &v, T p);

			/** Create a 2d vector with same value for all components */
			inline Vector (T v);
			/** Create a 3d vector from x, y and z values */
			inline Vector (T x, T y, T z);
			/** Get a 2d vector formed x and y values. */
			inline Vector<2, T> project_xy () const;
			/** Get a 2d vector formed z and y values. */
			inline Vector<2, T> project_zy () const;
			/** Compute vectors cross product */
			inline Vector cross_product (const Vector<3, T> &v) const;

			/** Get reference to vector x value */
			inline T &x ();
			/** Get reference to vector y value */
			inline T &y ();
			/** Get reference to vector z value */
			inline T &z ();

			/** Get vector x value */
			inline T x () const;
			/** Get vector y value */
			inline T y () const;
			/** Get vector z value */
			inline T z () const;
		};

		template <int N, typename T>
		std::ostream &operator<< (std::ostream &o, const VectorBase<N, T> &v);

		/** @multiple @showvalue Commonly used vector constant */
		static const Vector2 vector2_0 = Vector2 (0.0, 0.0);
		static const Vector2 vector2_1 = Vector2 (1.0, 1.0);

		static const Vector2 vector2_01 = Vector2 (0.0, 1.0);
		static const Vector2 vector2_10 = Vector2 (1.0, 0.0);

		static const Vector3 vector3_0 = Vector3 (0.0, 0.0, 0.0);
		static const Vector3 vector3_1 = Vector3 (1.0, 1.0, 1.0);

		static const Vector3 vector3_001 = Vector3 (0.0, 0.0, 1.0);
		static const Vector3 vector3_010 = Vector3 (0.0, 1.0, 0.0);
		static const Vector3 vector3_100 = Vector3 (1.0, 0.0, 0.0);
		/** */

		template <int N, typename T>
		void
		VectorBase<N, T>::set (T value)
		{
			for (unsigned int i = 0; i < N; i++)
			{
				_val[i] = value;
			}
		}

		template <int N, typename T>
		T &
		VectorBase<N, T>::operator[] (int n)
		{
			return _val[n];
		}

		template <int N, typename T>
		T
		VectorBase<N, T>::operator[] (int n) const
		{
			return _val[n];
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::operator+ (const VectorBase<N, T> &v) const
		{
			math::VectorBase<N, T> r;
			for (unsigned int i = 0; i < N; i++)
			{
				r._val[i] = _val[i] + v._val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::operator- (const VectorBase<N, T> &v) const
		{
			math::VectorBase<N, T> r;
			for (unsigned int i = 0; i < N; i++)
			{
				r._val[i] = _val[i] - v._val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::operator- () const
		{
			math::VectorBase<N, T> r;
			for (unsigned int i = 0; i < N; i++)
			{
				r._val[i] = -_val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T> &
		VectorBase<N, T>::neg ()
		{
			for (unsigned int i = 0; i < N; i++)
			{
				_val[i] = -_val[i];
			}
			return *this;
		}

		template <int N, typename T>
		const VectorBase<N, T> &
		VectorBase<N, T>::operator+= (const VectorBase<N, T> &v)
		{
			for (unsigned int i = 0; i < N; i++)
			{
				_val[i] += v._val[i];
			}
			return *this;
		}

		template <int N, typename T>
		const VectorBase<N, T> &
		VectorBase<N, T>::operator-= (const VectorBase<N, T> &v)
		{
			for (unsigned int i = 0; i < N; i++)
			{
				_val[i] -= v._val[i];
			}
			return *this;
		}

		template <int N, typename T>
		T
		VectorBase<N, T>::operator* (const VectorBase<N, T> &v) const
		{
			T r = 0;
			for (unsigned int i = 0; i < N; i++)
			{
				r += _val[i] * v._val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::mul (const VectorBase &v) const
		{
			math::VectorBase<N, T> r;
			for (unsigned int i = 0; i < N; i++)
			{
				r._val[i] = _val[i] * v._val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::operator/ (const VectorBase &v) const
		{
			math::VectorBase<N, T> r;
			for (unsigned int i = 0; i < N; i++)
			{
				r._val[i] = _val[i] / v._val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::operator* (T scale) const
		{
			math::VectorBase<N, T> r;
			for (unsigned int i = 0; i < N; i++)
			{
				r._val[i] = scale * _val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::operator/ (T scale) const
		{
			math::VectorBase<N, T> r;
			for (unsigned int i = 0; i < N; i++)
			{
				r._val[i] = _val[i] / scale;
			}
			return r;
		}

		template <int N, typename T>
		const VectorBase<N, T> &
		VectorBase<N, T>::operator*= (T scale)
		{
			for (unsigned int i = 0; i < N; i++)
			{
				_val[i] *= scale;
			}
			return *this;
		}

		template <int N, typename T>
		const VectorBase<N, T> &
		VectorBase<N, T>::operator/= (T scale)
		{
			for (unsigned int i = 0; i < N; i++)
			{
				_val[i] /= scale;
			}
			return *this;
		}

		template <int N, typename T>
		T
		VectorBase<N, T>::len () const
		{
			T r = 0;
			for (unsigned int i = 0; i < N; i++)
			{
				r += square (_val[i]);
			}
			return sqrt (r);
		}

		template <int N, typename T>
		const VectorBase<N, T> &
		VectorBase<N, T>::normalize ()
		{
			return *this /= len ();
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::normalized () const
		{
			VectorBase<N, T> r = *this / len ();
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::magnitude (T newlen) const
		{
			return *this * (newlen / len ());
		}

		template <int N, typename T>
		template <int M>
		VectorBase<M, T>
		VectorBase<N, T>::select (unsigned int mask, const VectorBase<M, T> &v) const
		{
			math::VectorBase<M, T> r;
			for (unsigned int i = 0; i < M; i++)
			{
				r._val[i] = (mask & (1 << i)) ? _val[i] : v._val[i];
			}
			return r;
		}

		template <int N, typename T>
		VectorBase<N, T>
		VectorBase<N, T>::operator* (const Matrix<N> &m)
		{
			VectorBase<N, T> r;
			for (int j = 0; j < N; j++)
			{
				T s = 0;
				for (int k = 0; k < N; k++)
				{
					s += _val[k][j] * m._val[k];
				}
				r[j] = s;
			}
			return r;
		}

		template <int N, typename T>
		inline bool
		VectorBase<N, T>::operator== (const VectorBase &m) const
		{
			for (int j = 0; j < N; j++)
				if (_val[j] != m._val[j])
				{
					return false;
				}
			return true;
		}

		template <int N, typename T>
		bool
		VectorBase<N, T>::close_to (const VectorBase &m, T error)
		{
			for (int j = 0; j < N; j++)
				if (fabs (_val[j] - m._val[j]) > error)
				{
					return false;
				}
			return true;
		}

		template <int N, typename T>
		std::ostream &
		operator<< (std::ostream &o, const VectorBase<N, T> &v)
		{
			o << "[";
			for (unsigned int i = 0; i < N; i++)
			{
				o << v[i];
				if (i + 1 < N)
				{
					o << ", ";
				}
			}
			o << "]";
			return o;
		}

		// **********************************************************************

		template <int N, typename T> Vector<N, T>::Vector () {}

		template <int N, typename T> Vector<N, T>::Vector (T value)
		{
			for (unsigned int i = 0; i < N; i++)
			{
				VectorBase<N, T>::_val[i] = value;
			}
		}

		template <int N, typename T>
		Vector<N, T>::Vector (const VectorBase<N, T> &v) : VectorBase<N, T> (v)
		{
		}

		// **********************************************************************

		template <typename T> Vector<3, T>::Vector () {}

		template <typename T>
		Vector<3, T>::Vector (const VectorBase<3, T> &v) : VectorBase<3, T> (v)
		{
		}

		template <typename T>
		template <int M>
		Vector<3, T>::Vector (const VectorBase<M, T> &v, T p)
		{
			int i;
			for (i = 0; i < std::min (3, M); i++)
			{
				base::_val[i] = v[i];
			}
			for (; i < 3; i++)
			{
				base::_val[i] = p;
			}
		}

		template <typename T> Vector<3, T>::Vector (T value)
		{
			base::_val[0] = base::_val[1] = base::_val[2] = value;
		}

		template <typename T> Vector<3, T>::Vector (T x, T y, T z)
		{
			base::_val[0] = x;
			base::_val[1] = y;
			base::_val[2] = z;
		}

		template <typename T>
		Vector<2, T>
		Vector<3, T>::project_xy () const
		{
			Vector<2, T> v;
			v[0] = x ();
			v[1] = y ();
			return v;
		}

		template <typename T>
		Vector<2, T>
		Vector<3, T>::project_zy () const
		{
			Vector<2, T> v;
			v[0] = z ();
			v[1] = y ();
			return v;
		}

		template <typename T>
		Vector<3, T>
		Vector<3, T>::cross_product (const Vector<3, T> &v) const
		{
			return Vector<3, T> (y () * v.z () - z () * v.y (),
			                     z () * v.x () - x () * v.z (),
			                     x () * v.y () - y () * v.x ());
		}

		template <typename T>
		T &
		Vector<3, T>::x ()
		{
			return base::_val[0];
		}

		template <typename T>
		T &
		Vector<3, T>::y ()
		{
			return base::_val[1];
		}

		template <typename T>
		T &
		Vector<3, T>::z ()
		{
			return base::_val[2];
		}

		template <typename T>
		T
		Vector<3, T>::x () const
		{
			return base::_val[0];
		}

		template <typename T>
		T
		Vector<3, T>::y () const
		{
			return base::_val[1];
		}

		template <typename T>
		T
		Vector<3, T>::z () const
		{
			return base::_val[2];
		}

		// **********************************************************************

		template <typename T> Vector<2, T>::Vector () {}

		template <typename T>
		Vector<2, T>::Vector (const VectorBase<2, T> &v) : VectorBase<2, T> (v)
		{
		}

		template <typename T>
		template <int M>
		Vector<2, T>::Vector (const VectorBase<M, T> &v, T p)
		{
			int i;
			for (i = 0; i < std::min (2, M); i++)
			{
				base::_val[i] = v[i];
			}
			for (; i < 2; i++)
			{
				base::_val[i] = p;
			}
		}

		template <typename T> Vector<2, T>::Vector (T value)
		{
			base::_val[0] = base::_val[1] = value;
		}

		template <typename T> Vector<2, T>::Vector (T x, T y)
		{
			base::_val[0] = x;
			base::_val[1] = y;
		}

		template <typename T>
		template <int N>
		Vector<2, T>::Vector (const VectorBase<N, T> &v, unsigned int a,
		                      unsigned int b)
		{
			base::_val[0] = v[a];
			base::_val[1] = v[b];
		}

		template <typename T>
		T
		Vector<2, T>::cross_product (const Vector<2, T> &v) const
		{
			return base::_val[0] * v.base::_val[1] - base::_val[1] * v.base::_val[0];
		}

		template <typename T>
		T &
		Vector<2, T>::x ()
		{
			return base::_val[0];
		}

		template <typename T>
		T &
		Vector<2, T>::y ()
		{
			return base::_val[1];
		}

		template <typename T>
		T
		Vector<2, T>::x () const
		{
			return base::_val[0];
		}

		template <typename T>
		T
		Vector<2, T>::y () const
		{
			return base::_val[1];
		}

	}
}

using goptical::math::Vector;
using goptical::math::Vector2;
using goptical::math::Vector3;

using goptical::math::vector2_0;
using goptical::math::vector2_01;
using goptical::math::vector2_1;
using goptical::math::vector2_10;
using goptical::math::vector3_0;
using goptical::math::vector3_001;
using goptical::math::vector3_010;
using goptical::math::vector3_1;
using goptical::math::vector3_100;

#endif
