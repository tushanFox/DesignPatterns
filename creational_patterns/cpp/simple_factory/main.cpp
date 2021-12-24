#include <iostream>
#include "operation.h"
using namespace std;
int main() {
  Operation *oper = OperationFactory::CreateProduct(OPER_ADD);
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "add result:" << oper->GetResult() << endl;
  delete oper;

  oper = OperationFactory::CreateProduct(OPER_SUB);
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "sub result:" << oper->GetResult() << endl;
  delete oper;

  oper = OperationFactory::CreateProduct(OPER_MUL);
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "mul result:" << oper->GetResult() << endl;
  delete oper;

  oper = OperationFactory::CreateProduct(OPER_DIV);
  oper->SetValue1(100);
  oper->SetValue2(200);
  cout << "div result:" << oper->GetResult() << endl;
  delete oper;
  return 0;
}