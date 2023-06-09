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

#ifndef GOPTICAL_CURVE_ROC_HH_
#define GOPTICAL_CURVE_ROC_HH_

#include "goptical/core/common.hpp"

namespace goptical
{

	namespace curve
	{

		/**
		   @short Base class for curves with a radius of curvature
		   @header <goptical/core/curve/curveRoc
		   @module {Core}
		 */
		class curveRoc
		{
			public:
				/** Set the radius of curvature */
				inline void set_roc (double roc);

				/** Get the radius of curvature */
				inline double get_roc () const;

			protected:
				inline curveRoc (double roc);

				double _roc;
		};

		curveRoc::curveRoc (double roc) : _roc (roc) {}

		void
		curveRoc::set_roc (double roc)
		{
			_roc = roc;
		}

		double
		curveRoc::get_roc () const
		{
			return _roc;
		}
	}
}

#endif
