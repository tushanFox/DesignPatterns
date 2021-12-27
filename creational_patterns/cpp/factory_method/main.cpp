#include <iostream>
#include "operation.h"
using namespace std;
int main() {
  IFactory *ifa = new AddFactory();
  Operation *oper = ifa->CreateOperation();
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "add result:" << oper->GetResult() << endl;
  delete oper;
  delete ifa;

  ifa = new SubFactory();
  oper = ifa->CreateOperation();
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "sub result:" << oper->GetResult() << endl;
  delete oper;
  delete ifa;

  ifa = new MulFactory();
  oper = ifa->CreateOperation();
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "mul result:" << oper->GetResult() << endl;
  delete oper;
  delete ifa;

  ifa = new DivFactory();
  oper = ifa->CreateOperation();
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "div result:" << oper->GetResult() << endl;
  delete oper;
  delete ifa;
  return 0;
}