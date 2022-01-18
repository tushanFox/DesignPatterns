#include "proxy.h"
#include <iostream>
using namespace std;
int main() {
  Proxy *proxy = new Proxy();
  cout << proxy->Request() << endl;;
  return 0;
}