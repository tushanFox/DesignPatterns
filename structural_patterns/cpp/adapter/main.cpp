#include "adapter.h"

int main() {
  Adaptee ade;
  Target *target = new Adapter(&ade);
  target->Request();
  return 0;
}