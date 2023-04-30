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

#ifndef GOPTICAL_CURVE_RSYM_HH_
#define GOPTICAL_CURVE_RSYM_HH_

#include <gsl/gsl_deriv.h>

#include "goptical/core/common.hpp"

#include "base.hpp"
#include "goptical/core/math/vector.hpp"

namespace goptical
{

	namespace curve
	{

		/**
		   @short Base class for rotationally symmetric curves.
		   @header <goptical/core/curve/rotational.hpp>
		   @module {Core}

		   This class defines rotationally symmetric curve interface and
		   provide default implementation as generic non symmetric curve.
		   A derived curve need only implement the sagitta(double r) method.
		   In this case the derivatives will be computed numerically.
		 */
		class Rotational : public Base
		{
			public:
				Rotational ();

				/** Get normal to curve surface at specified point. */
				virtual void normal (math::Vector3 &normal,
				                     const math::Vector3 &point) const;

				/** Get curve sagitta (z) at specified distance from origin.
				 *  A derived class need only implement this method, in which case
				 *  derivatives will be computed numerically. Derived classes may of course
				 *  provide analytic implementations of derivatives.
				 *
				 *  @param s distance from curve origin (0, 0), s = sqrt(x^2 + y^2).
				 */
				virtual double sagitta (double s) const = 0;

				/** Get curve derivative dz/ds at specified distance from origin.
				    @param s distance from curve origin (0, 0), s = sqrt(x^2 + y^2).
				*/
				virtual double derivative (double s) const;

				/** Get curve sagitta (z) at specified point */
				virtual double sagitta (const math::Vector2 &xy) const;

				/** Get curve dz/dx and dx/dy partial derivatives (gradient) at specified
				 * point */
				virtual void derivative (const math::Vector2 &xy, math::Vector2 &dxdy) const;

				// FIXME sample points
				/** Get number of available sample points. Samples points may be
				    used by curve fitting algorithms and are choosen to avoid
				    using interpolated points. return 0 when not applicable. */
				virtual unsigned int get_sample_count () const;
				/** Get a sample point on curve. (0,0) is not included. */
				virtual void get_sample (unsigned int index, double &r, double &z) const;

			private:
				static double gsl_func_sagitta (double x, void *params);
				gsl_function gsl_func;
		};

	}
}

#endif
