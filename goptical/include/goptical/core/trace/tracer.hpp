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

#ifndef GOPTICAL_TRACER_HH_
#define GOPTICAL_TRACER_HH_

#include "goptical/core/common.hpp"

#include "goptical/core/sys/system.hpp"
#include "goptical/core/trace/params.hpp"
#include "goptical/core/trace/result.hpp"

namespace goptical
{

	namespace trace
	{

		/**
		   @short light propagation algorithms
		   @header <goptical/core/trace/Tracer
		   @module {Core}
		   @main

		   This class handle light propagation in an optical system.

		   Propagation result is stored in a @ref Result object.
		   Propagation parameters are stored in a @ref Params object.

		   @xsee {tuto_seqtrace}
		 */
		class Tracer
		{
			public:
				/** Create a new light porpagator object */
				Tracer (const sys::System *system);

				~Tracer ();
				Tracer ()
				{
					;
				}
				/** Set the Result object which must be used to store ray
				    tracing data. a new Result object will be allocated on
				    first ray trace operation if none were defined. */
				inline void set_trace_result (Result &res);

				/** replace all tracer parameters */
				inline void set_params (const Params &params);
				/** get tracer parameters */
				inline const Params &get_params () const;
				/** get tracer parameters */
				inline Params &get_params ();

				/* Get current trace result object */
				inline Result &get_trace_result () const;

				/** Undefine user defined Result object. Next ray trace
				    operation will allocate a new internal trace result object */
				inline Result &set_default_trace_result ();

				/** Get attached system */
				inline const sys::System *get_system () const;

				/** Launch ray tracing operation */
				void trace ();

			private:
				template <IntensityMode m> void trace_template ();
				template <IntensityMode m> void trace_seq_template ();

				const sys::System *_system; // Warning must be valid!
				Params _params;
				Result _result;
				Result *_result_ptr;
		};
		void
		Tracer::set_trace_result (Result &res)
		{
			_result_ptr = &res;
		}

		trace::Result &
		Tracer::get_trace_result () const
		{
			return *_result_ptr;
		}

		trace::Result &
		Tracer::set_default_trace_result ()
		{
			return *(_result_ptr = &_result);
		}

		const sys::System *
		Tracer::get_system () const
		{
			return _system;
		}

		const Params &
		Tracer::get_params () const
		{
			return _params;
		}

		Params &
		Tracer::get_params ()
		{
			return _params;
		}

	}
}

#endif
