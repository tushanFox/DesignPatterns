/**
 * @file Operation.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 简单工厂模式，又称为静态工厂方法模式。这里以“计算器”举例：由工厂类创建出加/减/乘/除的产品类。
 * @version 0.1
 * @date 2021-12-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "operation.h"
Operation *OperationFactory::CreateProduct(Operator op) {
  Operation *oper = nullptr;
  switch (op) {
    case OPER_ADD:
    oper = new OperAdd();
    break;
    case OPER_SUB:
    oper = new OperSub();
    break;
    case OPER_MUL:
    oper = new OperMul();
    break;
    case OPER_DIV:
    oper = new OperDiv();
    break;
  }
  return oper;
}


void Operation::SetValue1(double v1) {
  this->v1 = v1;
}
void Operation::SetValue2(double v2) {
  this->v2 = v2;
}
double Operation::GetValue1(void) {
  return v1;
}
double Operation::GetValue2(void) {
  return v2;
}


double OperAdd::GetResult(void) {
  return GetValue1() + GetValue2();
}

double OperSub::GetResult(void) {
  return GetValue1() - GetValue2();
}

double OperMul::GetResult(void) {
  return GetValue1() * GetValue2();
}

double OperDiv::GetResult(void) {
  return GetValue1() / GetValue2();
}