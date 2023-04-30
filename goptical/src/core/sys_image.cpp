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

#include <goptical/core/curve/flat.hpp>
#include <goptical/core/shape/rectangle.hpp>
#include <goptical/core/sys/image.hpp>
#include <goptical/core/trace/ray.hpp>

namespace goptical
{

	namespace sys
	{

		Image::Image (const math::VectorPair3 &p,
		              const std::shared_ptr<curve::Base> &curve,
		              const std::shared_ptr<shape::Base> &shape)
			: Surface (p, curve, shape)
		{
		}

		Image::Image (const math::VectorPair3 &p, double radius)
			: Surface (p, curve::flat,
			           std::make_shared<shape::Rectangle> (radius * 2.))
		{
		}

		void
		Image::trace_ray_simple (trace::Result &result, trace::Ray &incident,
		                         const math::VectorPair3 &local,
		                         const math::VectorPair3 &intersect) const
		{
		}

		void
		Image::trace_ray_intensity (trace::Result &result, trace::Ray &incident,
		                            const math::VectorPair3 &local,
		                            const math::VectorPair3 &intersect) const
		{
		}

		void
		Image::trace_ray_polarized (trace::Result &result, trace::Ray &incident,
		                            const math::VectorPair3 &local,
		                            const math::VectorPair3 &intersect) const
		{
		}

	}

}
