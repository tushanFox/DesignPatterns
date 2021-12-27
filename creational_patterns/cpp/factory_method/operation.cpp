/**
 * @file Operation.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 工厂方法模式又称为工厂模式。这里以“计算器”举例：
 *        由抽象工厂类创建出抽象产品类，由具体工厂类创建加/减/乘/除的产品类。
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "operation.h"
// 加法工厂类
Operation *AddFactory::CreateOperation() {
  return new OperAdd();
}

// 减法工厂类
Operation *SubFactory::CreateOperation() {
  return new OperSub();
}

// 乘法工厂类
Operation *MulFactory::CreateOperation() {
  return new OperMul();
}

// 加法工厂类
Operation *DivFactory::CreateOperation() {
  return new OperDiv();
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