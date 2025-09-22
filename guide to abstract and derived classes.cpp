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
#include <bits/stdc++.h>
using namespace std;

struct abstract {
  string a;
  int b;
  
  virtual ~abstract() = default;
  virtual void placeHolder() = 0;
};

struct derived : abstract {
  int c;
  
  void placeHolder() override {
  }
};

derived a;

int main() {
  a.a = "11111", a.c = 114514;
  abstract* b = &a;
  cout << dynamic_cast<derived*>(b) -> c << '\n';
  return 0;
}
