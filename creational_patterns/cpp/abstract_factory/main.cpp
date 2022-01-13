#include <iostream>
#include <cmath>
#include "computer.h"
using namespace std;
int main() {
  ComputerFactory *ifa = new Brand1ComputerFactory();
  Cpu *cpu = ifa->CreateCpu();
  Memory *mem = ifa->CreateMemory();
  cout << cpu->GetCpuBrand() << "|" << mem->GetMemoryBrand() << endl;

  ifa = new Brand2ComputerFactory();
  cpu = ifa->CreateCpu();
  mem = ifa->CreateMemory();
  cout << cpu->GetCpuBrand() << "|" << mem->GetMemoryBrand() << endl;

  delete mem;
  delete cpu;
  delete ifa;
  return 0;
}