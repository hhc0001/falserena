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
struct buff : effect {
  double damageBoost;
  i64 immune;
};

struct nerf : effect {
  i64 damage, damagePerAction, stuck;
};

struct onFire : nerf {
};
#endif
