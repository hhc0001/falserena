#include "string"
#include "set"
#include "math/probability.hxx"
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
struct effect {
  std::string type;
  i64 level, duration;
  double damageTakenMultiplier;
  
  virtual void operator()() = 0;
};

struct effectCmp {
  bool operator ()(effect *a, effect *b) {
    return a -> duration < b -> duration;
  }
};

struct player {
  i64 health, healthCap, mana, manaCap, team;
  std::string name;
  std::set<effect *, effectCmp> effects;
  
  void die(player b);
};
#endif
