#include "random"
#include "ctime"
#pragma ONCE

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

m32 _Base(std::time(0));
ui32 _BSft(0, 63);
ui32 _BTyp(0, 1);
ui32 _BCnt(1, 6);

u64 _F1(u64 x) {
  for(int _ = _BCnt(_Base); _--; ) {
    int _Tp = _BTyp(_Base);
    if(_Tp) {
      x ^= x << (_BSft(_Base));
    }else {
      x ^= x >> (_BSft(_Base));
    }
  }
  return x;
}
u64 _F2(u64 x) {
  for(int _ = _BCnt(_Base); _--; ) {
    u64 y = 1;
    for(int __ = _BCnt(_Base); __--; ) {
      y = y * x;
    }
    x ^= y;
  }
  return x;
}
//Fibonacci function. Interesting.
u64 _F(u64 x, u16 y) {
  if(y == 0) {
    return x;
  }
  if(y == 1) {
    return _F1(x);
  }
  if(y == 2) {
    return _F2(x);
  }
  for(int _ = _BCnt(_Base); _--; ) {
    int _Tp = _BTyp(_Base);
    if(_Tp) {
      x ^= _F(x, y - 1);
    }else {
      x ^= _F(x, y - 2);
    }
  }
  return x;
}
