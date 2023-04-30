/*

      This file is part of the <goptical/core Core library.

      The <goptical/core library is free software; you can redistribute it
      and/or modify it under the terms of the GNU General Public
      License as published by the Free Software Foundation; either
      version 3 of the License, or (at your option) any later version.

      The <goptical/core library is distributed in the hope that it will be
      useful, but WITHOUT ANY WARRANTY; without even the implied
      warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
      See the GNU General Public License for more details.

      You should have received a copy of the GNU General Public
      License along with the <goptical/core library; if not, write to the
      Free Software Foundation, Inc., 59 Temple Place, Suite 330,
      Boston, MA 02111-1307 USA

      Copyright (C) 2010-2011 Free Software Foundation, Inc
      Author: Alexandre Becoulet

*/

#ifndef GOPTICAL_CURVE_SPHERE_HH_
#define GOPTICAL_CURVE_SPHERE_HH_

#include "goptical/core/common.hpp"

#include "goptical/core/curve/conic_base.hpp"

namespace goptical
{

	namespace curve
	{

		/**
		   @short Spherical curve model
		   @header <goptical/core/curve/Sphere
		   @module {Core}
		   @main

		   This class provides an efficient spherical curve implementation.
		 */
		class Sphere : public ConicBase
		{
			public:
				/** Creates a spherical curve with given radius of curvature */
				Sphere (double roc);

				bool intersect (math::Vector3 &point, const math::VectorPair3 &ray) const;
				void normal (math::Vector3 &normal, const math::Vector3 &point) const;

				double sagitta (double r) const;
				double derivative (double r) const;
		};

	}
}

#endif
