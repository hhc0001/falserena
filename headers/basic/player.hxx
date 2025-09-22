/**
 * This program is part of falserena.
 * 
 * falserena is free software: you can redistribute it ans/or modify it under the terms of the
 * GNU General Public License as published by the Free Software Foundation, either
 * version 3 of the License, or (at your option) any later version.
 * 
 * falserena is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 * without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with falserena. If
 * not, see <https://www.gnu.org/licenses/>.
 **/
#include "iostream"
#include "definition.hxx"
#ifndef _MACROS
#define _MACROS
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned int;
using i64 = long long;
using u64 = unsigned long long;
using ui32 = std::uniform_int_distribution<i32>;
using uu32 = std::uniform_int_distribution<u32>;
using ui64 = std::uniform_int_distribution<i64>;
using uu64 = std::uniform_int_distribution<u64>;
using m32 = std::mt19937;
using m64 = std::mt19937_64;
#endif
#ifndef _PLAYER_DETAIL
#define _PLAYER_DETAIL
void player::die(player b) {
  std::cout << "Fighter " << (*this).name << " in team " << (*this).team << " was killed by ";
  std::cout << "fighter " << b.name << " in team " << b.team << "!\n";
}
#endif
