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

#ifndef GOPTICAL_MATERIAL_CATALOG_HH_
#define GOPTICAL_MATERIAL_CATALOG_HH_

#include <map>
#include <string>

#include "goptical/core/common.hpp"

#include "base.hpp"
#include "goptical/core/error.hpp"

namespace goptical
{

	namespace material
	{

		/**
		   @short Hold a glass material catalog
		   @header <goptical/core/material/Catalog
		   @module {Core}
		   @main
		 */
		class Catalog
		{
			public:
				/** Create a catalog with given name */
				Catalog (const std::string &name = "");

				/** Get catalog name */
				inline const std::string &get_name () const;
				/** Set catalog name */
				inline void set_name (const std::string &name);

				/** Get material with given name */
				inline const Base &get_material (const std::string &material_name);

				/** Add a material to catalog. material object will be deleted
				    on catalog destruction if owner is set. */
				void add_material (const std::string &material_name,
				                   const std::shared_ptr<Base> &material);

				/** Remove a material from catalog */
				void del_material (const std::string &material_name);

			private:
				typedef std::map<std::string, std::shared_ptr<Base> > catalog_map_t;

				std::string _name;
				catalog_map_t _list;
		};
		inline const std::string &
		Catalog::get_name () const
		{
			return _name;
		}

		inline void
		Catalog::set_name (const std::string &name)
		{
			_name = name;
		}

		inline const Base &
		Catalog::get_material (const std::string &material_name)
		{
			catalog_map_t::iterator i = _list.find (material_name);
			if (i == _list.end ())
			{
				throw Error ("No such material in catalog");
			}
			return *i->second;
		}

	}

}

#endif
