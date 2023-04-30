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

#ifndef GOPTICAL_OPTICALSURFACE_HH_
#define GOPTICAL_OPTICALSURFACE_HH_

#include "goptical/core/common.hpp"

#include "goptical/core/curve/flat.hpp"
#include "goptical/core/material/air.hpp"
#include "goptical/core/shape/infinite.hpp"
#include "goptical/core/sys/surface.hpp"

namespace goptical
{

	namespace sys
	{

		/**
		   @short Optical surface element
		   @header <goptical/core/sys/OpticalSurface
		   @module {Core}
		   @main

		   This class implements optical surfaces.

		   Optical surfaces are defined by material on both side of the
		   surface, curve and contour shape. This class handle light rays
		   refraction and reflection.

		   If @ref material::none is passed as material, it will be
		   replaced by system environement @ref material::Proxy
		   {proxy} material when the optical surface becomes part of a
		   @ref system.
		*/

		class OpticalSurface : public Surface
		{
			public:
				/** Create an optical surface at specified location. */
				OpticalSurface (const math::VectorPair3 &p,
				                const std::shared_ptr<curve::Base> &curve,
				                const std::shared_ptr<shape::Base> &shape,
				                const std::shared_ptr<material::Base> &left,
				                const std::shared_ptr<material::Base> &right);

				/** Create a circular aperture optical surface at specified
				    location.
				    @param ap_radius circular aperture radius.
				*/
				OpticalSurface (const math::VectorPair3 &p,
				                const std::shared_ptr<curve::Base> &curve, double ap_radius,
				                const std::shared_ptr<material::Base> &left,
				                const std::shared_ptr<material::Base> &right);

				/** Create a spherical optical surface with circular aperture at
				    specified location.
				    @param roc spherical radius of curvature. 0 means flat curve.
				    @param ap_radius circular aperture radius.
				*/
				OpticalSurface (const math::VectorPair3 &p, double roc, double ap_radius,
				                const std::shared_ptr<material::Base> &left,
				                const std::shared_ptr<material::Base> &right);

				virtual ~OpticalSurface ();

				/** Set surface left or right material */
				void set_material (unsigned index, const std::shared_ptr<material::Base> &m);

				/** Get surface left or right material */
				inline const material::Base &get_material (unsigned id) const;

				/** Get surface natural color from material properties. */
				io::Rgb get_color (const io::Renderer &r) const;

			private:
				void trace_ray_simple (trace::Result &result, trace::Ray &incident,
				                       const math::VectorPair3 &local,
				                       const math::VectorPair3 &intersect) const;

				void trace_ray_intensity (trace::Result &result, trace::Ray &incident,
				                          const math::VectorPair3 &local,
				                          const math::VectorPair3 &intersect) const;

				/** @override */
				virtual void system_register (System *s) override;

				/** @override */
				virtual void system_unregister () override;

				/** @override */
				void print (std::ostream &o) const;

				/** compute refracted ray direction according to fresnel law */
				bool refract (const math::VectorPair3 &ray, math::Vector3 &direction,
				              const math::Vector3 &normal, double refract_index) const;

				/** compute reflected ray direction according to fresnel law */
				void reflect (const math::VectorPair3 &ray, math::Vector3 &direction,
				              const math::Vector3 &normal) const;

				std::shared_ptr<material::Base> _mat[2];
		};
		const material::Base &
		OpticalSurface::get_material (unsigned index) const
		{
			assert (index < 2);
			return *_mat[index];
		}

	}
}

#endif
