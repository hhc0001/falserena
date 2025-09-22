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
#ifndef _EFFECTS
#define _EFFECTS
struct buff : public effect {
public:
  double damageBoost;
  i64 immune;
};

struct nerf : public effect {
public:
  i64 damage;
  bool stuck;
};

struct onFire : public nerf {
public:
  void operator ()(player &b) override final {
    b.health -= damage, duration--;
  }
  onFire operator +(onFire b) {
    onFire temp;
    temp.type = "onFire";
    temp.level = std::max(level, b.level) + 1;
    temp.duration = duration + b.duration;
    temp.damageTakenMultiplier = 1;
    temp.damage = damage + b.damage;
    temp.stuck = 0;
    return temp;
  }
};

struct frozen : public nerf {
public:
  void operator ()(player &b) override final {
    duration--;
  }
  frozen operator +(frozen b) {
    frozen temp;
    temp.type = "frozen";
    temp.level = std::max(level, b.level) + 1;
    temp.duration = duration + b.duration;
    temp.damageTakenMultiplier = 1;
    temp.damage = 0;
    temp.stuck = 1;
    return temp;
  }
};

effect* iceCrash(onFire &a, frozen &b) {
  effect* res = nullptr;
  if(a.level > b.level) {
    return &a;
  }
  if(a.level < b.level) {
    return &b;
  }
  if(a.duration >= b.duration) {
    res = new onFire;
    onFire* tres = dynamic_cast<onFire*>(res);
    tres -> type = "onFire";
    tres -> level = a.level;
    tres -> duration = a.duration - b.duration;
    tres -> damageTakenMultiplier = 1;
    tres -> damage = a.damage;
    tres -> stuck = 0;
  }else {
    res = new frozen;
    frozen* tres = dynamic_cast<frozen*>(res);
    tres -> type = "frozen";
    tres -> level = b.level;
    tres -> duration = b.duration - a.duration;
    tres -> damageTakenMultiplier = 1;
    tres -> damage = 0;
    tres -> stuck = 1;
  }
  return res;
}

effect* iceCrash(frozen &a, onFire &b) {
  return iceCrash(b, a);
}

struct freezeFire : public nerf {
public:
  void operator ()(player &b) override final {
    b.health -= damage, duration--;
  }
  freezeFire operator +(freezeFire b) {
    freezeFire temp;
    temp.type = "freezeFire";
    temp.level = std::max(level, b.level) + 1;
    temp.duration = duration + b.duration;
    temp.damageTakenMultiplier = 1 + temp.level / 1.6;
    temp.damage = damage + b.damage;
    temp.stuck = 1;
    return temp;
  }
  freezeFire operator +(onFire b) {
    freezeFire temp;
    temp.type = "freezeFire";
    temp.level = std::max(level, b.level) + 1;
    temp.duration = duration + ((b.duration + 1) / 2);
    temp.damageTakenMultiplier = 1 + temp.level / 1.6;
    temp.damage = damage + ((b.damage + 2) / 3);
    temp.stuck = 1;
    return temp;
  }
  freezeFire operator +(frozen b) {
    freezeFire temp;
    temp.type = "freezeFire";
    temp.level = std::max(level, b.level) + 1;
    temp.duration = duration + ((b.duration + 1) / 2);
    temp.damageTakenMultiplier = 1 + temp.level / 1.6;
    temp.damage = damage;
    temp.stuck = 1;
    return temp;
  }
};

freezeFire operator +(onFire a, freezeFire b) {
  return b + a;
}
freezeFire operator +(frozen a, freezeFire b) {
  return b + a;
}

struct stun : public nerf {
};

struct shock : public nerf {
public:
  void operator ()(player &b) override final {
    duration--;
  }
  shock operator +(shock b) {
    shock temp;
    temp.type = "shock";
    temp.level = std::max(level, b.level) + 1;
    temp.duration = ((duration + level - 1) / level + (b.duration + b.level - 1) / b.level) * temp.level;
    temp.damageTakenMultiplier = 1 + temp.level / 4.0;
    temp.damage = 0;
    temp.stuck = 1;
    return temp;
  }
  shock operator +(frozen b) {
    shock temp;
    temp.type = "shock";
    temp.level = level + b.level + 1;
    temp.duration = ((duration + level - 1) / level + (b.duration + b.level - 1) / b.level) * temp.level;
    temp.damageTakenMultiplier = 1 + temp.level / 4.0;
    temp.damage = 0;
    temp.stuck = 1;
    return temp;
  }
  shock operator +(freezeFire b) {
    shock temp;
    temp.type = "shock";
    temp.level = level + b.level + 1;
    temp.duration = duration + b.duration * b.level;
    temp.damageTakenMultiplier = 1 + temp.level / 4.0;
    temp.damage = 0;
    temp.stuck = 1;
    return temp;
  }
};

struct poison : public nerf {
};
#endif
