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

#ifndef GOPTICAL_MIRROR_HH_
#define GOPTICAL_MIRROR_HH_

#include "goptical/core/common.hpp"

#include "goptical/core/material/mirror.hpp"
#include "goptical/core/sys/optical_surface.hpp"

namespace goptical
{

	namespace sys
	{

		/**
		   @short Reflecting optical surface element
		   @header <goptical/core/sys/Mirror
		   @module {Core}
		   @main

		   This class provide a convenient way to describe a reflecting
		   optical surface. light is reflected only on 1 side of the
		   surface.
		 */

		class Mirror : public OpticalSurface
		{
			public:
#if 0
				/**
				   Specifies direction of incoming light rays that will be reflected.
				 */
				enum Direction
				{
				    /** The mirror will reflect light with negative Z direction
				        in its local coordinates */
				    lightFromRight = 0,
				    /** The mirror will reflect light with positive Z direction
				        in its local coordinates */
				    lightFromLeft = 1,
				};
#endif

				/** Create a mirror at given position with given shape and
				    curve. Default is to reflect light coming from left using
				    @ref material::mirror material. */
				Mirror (const math::VectorPair3 &p,
				        const std::shared_ptr<curve::Base> &curve,
				        const std::shared_ptr<shape::Base> &shape,
				        bool light_from_left = true,
				        const std::shared_ptr<material::Base> &metal = material::mirror,
				        const std::shared_ptr<material::Base> &env = material::none);

				/** Create a circular aperture mirror at given position with
				    given curve. Default is to reflect light coming from left
				    using @ref material::mirror material. */
				Mirror (const math::VectorPair3 &p,
				        const std::shared_ptr<curve::Base> &curve, double ap_radius,
				        bool light_from_left = true,
				        const std::shared_ptr<material::Base> &metal = material::mirror,
				        const std::shared_ptr<material::Base> &env = material::none);

				/** Create a conic mirror with circular aperture at given
				    position. Default is to reflect light coming from left using @ref
				    material::mirror material. */
				Mirror (const math::VectorPair3 &p, double roc, double sc, double ap_radius,
				        bool light_from_left = true,
				        const std::shared_ptr<material::Base> &metal = material::mirror,
				        const std::shared_ptr<material::Base> &env = material::none);
		};

	}
}

#endif
