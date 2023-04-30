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

#include <goptical/core/io/renderer.hpp>
#include <goptical/core/math/vector_pair.hpp>
#include <goptical/core/sys/group.hpp>

namespace goptical
{

	namespace sys
	{

		Group::~Group () {}

		void
		Group::system_register (System *s)
		{
			Element::system_register (s);
			// register all children elements
for (auto &i : get_element_list ())
			{
				i->system_register (s);
			}
		}

		void
		Group::system_unregister ()
		{
			assert (_system);
			// unregister all children elements
for (auto &i : get_element_list ())
			{
				i->system_unregister ();
			}
			Element::system_unregister ();
		}

		void
		Group::system_moved ()
		{
for (auto &i : get_element_list ())
			{
				i->system_moved ();
			}
			Element::system_moved ();
		}

		math::VectorPair3
		Group::get_bounding_box () const
		{
			return Container::get_bounding_box ();
		}

		void
		Group::draw_2d_e (io::Renderer &r, const Element *ref) const
		{
for (auto &i : get_element_list ())
			{
				r.draw_element_2d (*i, ref);
			}
		}

		void
		Group::draw_3d_e (io::Renderer &r, const Element *ref) const
		{
for (auto &i : get_element_list ())
			{
				r.draw_element_3d (*i, ref);
			}
		}

	}
}
