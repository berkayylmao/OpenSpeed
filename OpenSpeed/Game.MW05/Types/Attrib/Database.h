// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Attrib {
  struct Database {
    DatabasePrivate& mPrivates;

    virtual ~Database();

    Class* GetClass(StringKey key) {
      return reinterpret_cast<Class*(__thiscall*)(Database*, StringKey)>(0x454DB0)(this, key);
    }

    static inline Database* g_sThis = reinterpret_cast<Database*>(0x90DCBC);

    static Database* Get() { return g_sThis; }
  };
}  // namespace OpenSpeed::MW05::Attrib
