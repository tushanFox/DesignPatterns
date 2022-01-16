#include <iostream>
#include "car.h"
using namespace std;
int main() {
  BuilderInterface *builder = new Brand1Builder();
  Director dir;
  Car *car = dir.Create(builder);
  car->Show();
  delete builder;

  builder = new Brand2Builder();
  car = dir.Create(builder);
  car->Show();
  delete builder;
  return 0;
}