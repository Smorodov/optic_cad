/*

      This file is part of the <goptical/core Design library.

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

#ifndef GOPTICAL_DESIGN_TELESCOPE_NEWTON_HH_
#define GOPTICAL_DESIGN_TELESCOPE_NEWTON_HH_

#include <algorithm>

#include <goptical/core/common.hpp>

#include <goptical/core/curve/conic.hpp>
#include <goptical/core/curve/flat.hpp>
#include <goptical/core/shape/disk.hpp>
#include <goptical/core/shape/ellipse.hpp>
#include <goptical/core/sys/mirror.hpp>

#include "telescope.hpp"

namespace goptical
{

	namespace Design
	{

		namespace telescope
		{

			/**
			   @short Newton telescope optical design
			   @header <goptical/core/Design/telescope/Newton
			   @module {Design}

			   This class is a group of optical elements forming a Newton
			   telescope. Optical elements are adjusted as needed from
			   prescribed telescope parameters.

			   @xsee {tuto_newton}
			*/
			class Newton : public telescope
			{
				public:
					Newton (const math::VectorPair3 &p, double focal, double diameter,
					        double bwd = 100, double field_angle = 1.);

					/** Get telescope primary mirror component */
					inline std::shared_ptr<sys::Mirror> get_primary ();

					/** Get telescope secondary mirror component */
					inline std::shared_ptr<sys::Mirror> get_secondary ();

					/** Get secondary mirror offset */
					inline double get_secondary_offset () const;

					/** Get secondary mirror minor axis length */
					inline double get_secondary_minor_axis () const;
					/** Set telescope secondary mirror diameter */
					void set_secondary_minor_axis (double diameter);

					/** Get secondary mirror major axis length */
					inline double get_secondary_major_axis () const;

					/** @override */
					void set_focal (double focal);
					/** @override */
					inline double get_focal () const;

					/** @override */
					void set_diameter (double diameter);
					/** @override */
					inline double get_diameter () const;

					/** @override */
					void set_bwd (double bwd);
					/** @override */
					inline double get_bwd () const;

					/** @override */
					void set_field_angle (double fa);
					/** @override */
					inline double get_field_angle () const;

					/** @override */
					inline double get_unvignetted_image_diameter () const;

					/** @override */
					math::VectorPair3 get_focal_plane () const;

				private:
					void update ();

					double calc_field_angle ();
					double calc_secondary ();
					double calc_unvignetted_image_size ();

					double _focal;
					double _diameter;
					double _bwd;
					double _field_angle;
					double _unvignetted_image_size;
					double _offset;
					double _minor_axis;
					double _major_axis;

					std::shared_ptr<shape::Disk> _primary_shape;
					std::shared_ptr<curve::Conic> _primary_curve;
					std::shared_ptr<sys::Mirror> _primary;
					std::shared_ptr<shape::Ellipse> _secondary_shape;
					std::shared_ptr<sys::Mirror> _secondary;
					math::VectorPair3 _focal_plane;
			};

			double
			Newton::get_focal () const
			{
				return _focal;
			}

			double
			Newton::get_diameter () const
			{
				return _diameter;
			}

			double
			Newton::get_bwd () const
			{
				return _bwd;
			}

			double
			Newton::get_field_angle () const
			{
				return _field_angle;
			}

			std::shared_ptr<sys::Mirror>
			Newton::get_primary ()
			{
				return _primary;
			}

			std::shared_ptr<sys::Mirror>
			Newton::get_secondary ()
			{
				return _secondary;
			}

			double
			Newton::get_secondary_offset () const
			{
				return _offset;
			}

			double
			Newton::get_secondary_minor_axis () const
			{
				return _minor_axis;
			}

			double
			Newton::get_secondary_major_axis () const
			{
				return _major_axis;
			}

			double
			Newton::get_unvignetted_image_diameter () const
			{
				return _unvignetted_image_size;
			}
		}
	}
}

#endif
