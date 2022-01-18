#include "decorator.h"
#include <iostream>
int main() {
  Component *component = new ConcreteComponent();

  Decorator *decorator = new ConcreteDecorator1(component);
  std::cout << decorator->Operation() << std::endl;

  decorator = new ConcreteDecorator2(component);
  std::cout << decorator->Operation() << std::endl;

  delete decorator;
  delete component;
  return 0;
}