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

#ifndef GOPTICAL_RGB_HH_
#define GOPTICAL_RGB_HH_

#include "goptical/core/common.hpp"

namespace goptical
{

	namespace io
	{

		/**
		   @short RGB color descriptor
		   @header <goptical/core/io/Rgb
		   @module {Core}
		 */

		struct Rgb
		{
			inline Rgb ();
			inline Rgb (float red, float green, float blue, float alpha = 1.0);
			inline bool operator< (const Rgb &rgb) const;
			inline Rgb operator~ () const;

			float r;
			float g;
			float b;
			float a;
		};

		extern const Rgb rgb_black;
		extern const Rgb rgb_red;
		extern const Rgb rgb_green;
		extern const Rgb rgb_blue;
		extern const Rgb rgb_yellow;
		extern const Rgb rgb_cyan;
		extern const Rgb rgb_magenta;
		extern const Rgb rgb_gray;
		extern const Rgb rgb_white;

		/** This constant specifies the number of entries in @ref rgb_table. @showvalue
		 */
		static const size_t rgb_table_size = 9;
		/** This table contains some common colors. @see rgb_table_size */
		extern const Rgb rgb_table[];

		Rgb::Rgb () {}

		Rgb::Rgb (float red, float green, float blue, float alpha)
			: r (red), g (green), b (blue), a (alpha)
		{
		}

		bool
		Rgb::operator< (const Rgb &rgb) const
		{
			return (a * 1000.0 + r * 100.0 + g * 10.0 + b
			        < rgb.a * 1000.0 + rgb.r * 100.0 + rgb.g * 10.0 + rgb.b);
		}

		Rgb
		Rgb::operator~ () const
		{
			return Rgb (1. - r, 1. - g, 1. - b, a);
		}
	}

}
#endif
