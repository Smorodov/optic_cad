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

#ifndef GOPTICAL_CURVE_BASE_HH_
#define GOPTICAL_CURVE_BASE_HH_

#include "goptical/core/common.hpp"

namespace goptical
{

	namespace curve
	{

		/**
		   @short Base class for surface curvature models
		   @header <goptical/core/curve/base.hpp>
		   @module {Core}
		   @main

		   This class defines an interface for surface curvature
		   implementations. Curvature is defined as a surface curve in
		   three dimensional space. It is mainly used by the @ref sys::Surface
		   class to describe optical surface curvature.

		   It provides access to sagitta (z) and gradient data on any
		   curved surface point (x, y). Ability to find point of
		   intersection between a given 3d ray and the curve is also
		   provided.

		   @xsee {tuto_usercurve}
		*/
		class Base
		{
			public:
				virtual inline ~Base ();

				/** Get curve sagitta (z) at specified point */
				virtual double sagitta (const math::Vector2 &xy) const = 0;

				/** Get curve dz/dx and dx/dy partial derivatives (gradient) at specified
				 * point */
				virtual void derivative (const math::Vector2 &xy, math::Vector2 &dxdy) const;

				/** Get intersection point between curve and 3d ray. Return
				    false if no intersection occurred. ray must have a position vector and
				    direction vector (cosines). */
				virtual bool intersect (math::Vector3 &point,
				                        const math::VectorPair3 &ray) const;

				/** Get normal to curve surface at specified point. */
				virtual void normal (math::Vector3 &normal,
				                     const math::Vector3 &point) const;
		};

		Base::~Base () {}

	}
}

#endif
