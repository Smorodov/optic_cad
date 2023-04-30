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

#include <algorithm>

#include <goptical/core/trace/sequence.hpp>

#include <goptical/core/sys/element.hpp>
#include <goptical/core/sys/system.hpp>

namespace goptical
{

	namespace trace
	{

		Sequence::Sequence () : _list () {}

		Sequence::Sequence (const sys::System &system) : _list ()
		{
			add (system);
		}

		static bool
		seq_sort (const std::shared_ptr<sys::Element> &a,
		          const std::shared_ptr<sys::Element> &b)
		{
			return a->get_position ().z () < b->get_position ().z ();
		}

		void
		Sequence::add (const sys::System &system)
		{
			_list.clear ();
			add (static_cast<const sys::Container &> (system));
			std::sort (_list.begin (), _list.end (), seq_sort);
		}

		void
		Sequence::add (const sys::Container &c)
		{
for (auto &i : c.get_element_list ())
			{
				if (const sys::Container *cc
				        = dynamic_cast<const sys::Container *> (i.get ()))
				{
					add (*cc);
				}
				else
				{
					_list.push_back (i);
				}
			}
		}

		std::ostream &
		operator<< (std::ostream &o, const Sequence &s)
		{
for (auto &i : s._list)
			{
				o << "  " << *i << std::endl;
			}
			return o;
		}

	}
}
