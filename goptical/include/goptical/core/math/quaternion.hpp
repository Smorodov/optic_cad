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

      Quaternion class Based on work from Jeff Molofee 2000, at
   nehe.gamedev.net
*/

#ifndef GOPTICAL_MATH_QUATERNION_HH_
#define GOPTICAL_MATH_QUATERNION_HH_

#include "goptical/core/common.hpp"

#include "goptical/core/math/vector.hpp"

namespace goptical
{

	namespace math
	{

		/**
		   @short Quaternion class.
		   @header goptical/core/math/Quaternion
		   @module {Core}

		   This class describe a quaternion object. Useful for 3d
		   rotations.
		 */

		class Quaternion
		{
			public:
				inline Quaternion ();

				/** Create a Quaternion from its real values */
				inline Quaternion (double x, double y, double z, double w);

				/** Create a Quaternion as rotation between two unit vectors */
				inline Quaternion (const Vector3 &a, const Vector3 &b);

				/** Create a Quaternion with given rotation angle along a 3d vector */
				static inline Quaternion angle (const Vector3 &v, double angle);

				/** Create a Quaternion with given rotation angle in radian along a 3d vector
				 */
				static inline Quaternion angle_rad (const Vector3 &v, double angle);

				/** Get quaterion x value */
				inline double x () const;
				/** Get reference to quaterion x value */
				inline double &x ();
				/** Get quaterion y value */
				inline double y () const;
				/** Get reference to quaterion y value */
				inline double &y ();
				/** Get quaterion z value */
				inline double z () const;
				/** Get reference to quaterion z value */
				inline double &z ();
				/** Get quaterion w value */
				inline double w () const;
				/** Get reference to quaterion w value */
				inline double &w ();

				/** Multiply with an other quaternion */
				inline Quaternion operator* (const Quaternion &q) const;

				/** Normalize vector length */
				inline const Quaternion &normalize ();
				/** Adjust vector length */
				inline double norm () const;

			private:
				double _w, _x, _y, _z;
		};

		inline std::ostream &operator<< (std::ostream &o, const Quaternion &q);
		Quaternion::Quaternion () {}

		Quaternion::Quaternion (double x, double y, double z, double w)
			: _w (w), _x (x), _y (y), _z (z)
		{
		}

		Quaternion::Quaternion (const Vector3 &a, const Vector3 &b)
		{
			const Vector3 cp (a.cross_product (b));
			_x = cp.x ();
			_y = cp.y ();
			_z = cp.z ();
			_w = a * b + 1.0;
			normalize ();
		}

		Quaternion
		Quaternion::angle_rad (const Vector3 &v, double angle)
		{
			double w = cos (angle / 2.0);
			double sin2 = sin (angle / 2.0);
			return Quaternion (v.x () * sin2, v.y () * sin2, v.z () * sin2, w);
		}

		Quaternion
		Quaternion::angle (const Vector3 &v, double angle)
		{
			return angle_rad (v, (angle / 180.0) * M_PI);
		}

		const Quaternion &
		Quaternion::normalize ()
		{
			double n = norm ();
			_x /= n;
			_y /= n;
			_z /= n;
			_w /= n;
			return *this;
		}

		double
		Quaternion::norm () const
		{
			return sqrt (_x * _x + _y * _y + _z * _z + _w * _w);
		}

		double
		Quaternion::x () const
		{
			return _x;
		}

		double &
		Quaternion::x ()
		{
			return _x;
		}

		double
		Quaternion::y () const
		{
			return _y;
		}

		double &
		Quaternion::y ()
		{
			return _y;
		}

		double
		Quaternion::z () const
		{
			return _z;
		}

		double &
		Quaternion::z ()
		{
			return _z;
		}

		double
		Quaternion::w () const
		{
			return _w;
		}

		double &
		Quaternion::w ()
		{
			return _w;
		}

		Quaternion
		Quaternion::operator* (const Quaternion &q) const
		{
			return Quaternion (_w * q._x + _x * q._w + _y * q._z - _z * q._y,
			                   _w * q._y + _y * q._w + _z * q._x - _x * q._z,
			                   _w * q._z + _z * q._w + _x * q._y - _y * q._x,
			                   _w * q._w - _x * q._x - _y * q._y - _z * q._z);
		}

		std::ostream &
		operator<< (std::ostream &o, const Quaternion &q)
		{
			o << "[" << q.x () << ", " << q.y () << ", " << q.z () << ", " << q.w ()
			  << "]";
			return o;
		}
	}

}

#endif
