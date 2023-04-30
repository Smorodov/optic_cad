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

#ifndef GOPTICAL_MATERIAL_VACUUM_HH_
#define GOPTICAL_MATERIAL_VACUUM_HH_

#include "goptical/core/common.hpp"

#include "base.hpp"

namespace goptical
{

	namespace material
	{

		/**
		   @short Vacuum optical material model
		   @header <goptical/core/material/Vacuum
		   @module {Core}
		   @main

		   This class models optical properties of vacuum.
		   A global variable @ref vacuum is available.
		*/

		class Vacuum : public Base
		{
			public:
				Vacuum ();

				/** @override */
				bool is_opaque () const;
				/** @override */
				bool is_reflecting () const;

				/** @override */
				double get_internal_transmittance (double wavelen, double thickness) const;
				/** @override */
				double get_refractive_index (double wavelen) const;
				/** @override */
				double get_extinction_coef (double wavelen) const;
		};

		/** A global instance of material::Vacuum material. */
		extern Vacuum vacuum;

	}
}

#endif
