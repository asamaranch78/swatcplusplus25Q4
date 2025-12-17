#include <iostream>
using namespace std;
 
void func(int &x, int &y, int &z) {
   x = y + z;
   y = 10;
   x = 20;
}
 
int main() {
   int a = 10, b = 20, c = 30;
   func(a, b, c);
   cout << a << " " << b << " " <<  c << endl;
   return 0;
}