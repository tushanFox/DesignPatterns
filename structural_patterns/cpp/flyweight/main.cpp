#include <iostream>
#include "flyweight.h"
using namespace std;
int main() {
  FlyweightFactory *ff = new FlyweightFactory();
  Flyweight *f1 = ff->GetFlyweight("aaa");
  f1->Operation("20");

  Flyweight *f2 = ff->GetFlyweight("bbb");
  f2->Operation("19");

  UnsharedConcreteFlyweight *f3 = new UnsharedConcreteFlyweight();
  f3->Operation("18");
  delete f3;
  delete ff;
  return 0;
}
