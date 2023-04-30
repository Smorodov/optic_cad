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

#include <goptical/core/curve/conic.hpp>
#include <goptical/core/curve/flat.hpp>
#include <goptical/core/shape/disk.hpp>

#include <goptical/core/sys/mirror.hpp>
#include <goptical/core/sys/optical_surface.hpp>

namespace goptical
{

	namespace sys
	{

		Mirror::Mirror (const math::VectorPair3 &p,
		                const std::shared_ptr<curve::Base> &curve,
		                const std::shared_ptr<shape::Base> &shape,
		                bool light_from_left,
		                const std::shared_ptr<material::Base> &metal,
		                const std::shared_ptr<material::Base> &air)
			: OpticalSurface (p, curve, shape, light_from_left ? air : metal,
			                  light_from_left ? metal : air)
		{
		}

		Mirror::Mirror (const math::VectorPair3 &p,
		                const std::shared_ptr<curve::Base> &curve, double ap_radius,
		                bool light_from_left,
		                const std::shared_ptr<material::Base> &metal,
		                const std::shared_ptr<material::Base> &air)
			: OpticalSurface (p, curve, ap_radius, light_from_left ? air : metal,
			                  light_from_left ? metal : air)
		{
		}

		Mirror::Mirror (const math::VectorPair3 &p, double roc, double sc,
		                double ap_radius, bool light_from_left,
		                const std::shared_ptr<material::Base> &metal,
		                const std::shared_ptr<material::Base> &air)
			: OpticalSurface (p,
			                  roc == 0. ? std::shared_ptr<curve::Base> (curve::flat)
			                  : std::shared_ptr<curve::Base> (
			                      std::make_shared<curve::Conic> (roc, sc)),
			                  std::make_shared<shape::Disk> (ap_radius),
			                  light_from_left ? air : metal,
			                  light_from_left ? metal : air)
		{
		}

	}

}
