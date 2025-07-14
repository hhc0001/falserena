#include "random"
#include "ctime"

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

#ifndef _SELF_INPLEMENTED_RNG
#define _SELF_INPLEMENTED_RNG
struct randNumberGenerator {
  m32 _Base;
  ui32 _BaseShift;
  ui32 _BaseType;
  ui32 _BaseCounter;
  
  randNumberGenerator() :
  _Base(std::time(0)),
  _BaseShift(0, 63),
  _BaseType(0, 1),
  _BaseCounter(1, 6) {
  }
  
  private:
    u64 _F1(u64 x) {
      for(int _ = _BaseCounter(_Base); _--; ) {
        int _Tp = _BaseType(_Base);
        if(_Tp) {
          x ^= x << (_BaseShift(_Base));
        }else {
          x ^= x >> (_BaseShift(_Base));
        }
      }
      return x;
    }
    u64 _F2(u64 x) {
      for(int _ = _BaseCounter(_Base); _--; ) {
        u64 y = 1;
        for(int __ = _BaseCounter(_Base); __--; ) {
          y = y * x;
          y += _Base() * (!y);
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
      for(int _ = _BaseCounter(_Base); _--; ) {
        int _Tp = _BaseType(_Base);
        if(_Tp) {
          x ^= _F(x, y - 1);
        }else {
          x ^= _F(x, y - 2);
        }
      }
      return x;
    }
  
  public:
    using result_type = u64;
  
    u64 min() const {return 0;}
    u64 max() const {return ULLONG_MAX;}
}RNG;
#endif

#include "iostream"
int main() {
  uu64 tmp;
  //std::cout << tmp(RNG) << '\n';
  RNG.min();
  return 0;
}
