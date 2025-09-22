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
#include "string"
#include "set"
#include "random"
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
#ifndef _BASIC_DEFINITION
#define _BASIC_DEFINITION
struct player;

struct effect {
public:
  std::string type;
  i64 level, duration;
  double damageTakenMultiplier;
  
  virtual void operator()(player &b) = 0;
};

struct effectCmp {
public:
  bool operator ()(effect *a, effect *b) {
    return a -> duration < b -> duration;
  }
};

struct player {
public:
  i64 health, healthCap, mana, manaCap;
  std::string name, team;
  std::set<effect *, effectCmp> effects;
  
  void die(player b);
};
#endif
