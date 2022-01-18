#include "decorator.h"
#include <iostream>
using namespace std;
int main() {
  Component *component = new ConcreteComponent();

  Decorator *decorator = new ConcreteDecorator1(component);
  cout << decorator->Operation() << endl;

  decorator = new ConcreteDecorator2(component);
  cout << decorator->Operation() << endl;

  delete decorator;
  delete component;
  return 0;
}