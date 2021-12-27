/**
 * @file operation.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 工厂方法模式又称为工厂模式。以“计算器”举例：
 *        由抽象工厂类创建出抽象产品类，由具体工厂类创建加/减/乘/除的产品类。
 * @version 0.1
 * @date 2021-12-26
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#pragma once

class Operation;
// 抽象工厂类
class IFactory {
public:
  IFactory() = default;
  virtual ~IFactory() = default;
  virtual Operation *CreateOperation() = 0;
};

// 具体工厂类：加/减/乘/除分别有不同的具体工厂类
// 加法工厂类
class AddFactory : public IFactory {
 public:
  Operation *CreateOperation() override;
};

// 减法工厂类
class SubFactory : public IFactory {
 public:
  Operation *CreateOperation() override;
};

// 乘法工厂类
class MulFactory : public IFactory {
 public:
  Operation *CreateOperation() override;
};

// 加法工厂类
class DivFactory : public IFactory {
 public:
  Operation *CreateOperation() override;
};

// 运算基类
class Operation {
 public:
  Operation() = default;
  virtual ~Operation() = default;
  void SetValue1(double v1);
  void SetValue2(double v2);
  virtual double GetResult(void) = 0;

 protected:
  double GetValue1(void);
  double GetValue2(void);

 private:
  double v1;
  double v2;
};

// 加法
class OperAdd : public Operation {
 public:
  OperAdd() = default;
  ~OperAdd() override = default;
  double GetResult(void) override;
};

// 减法
class OperSub : public Operation {
 public:
  OperSub() = default;
  ~OperSub() override = default;
  double GetResult(void) override;
};

// 乘法
class OperMul : public Operation {
 public:
  OperMul() = default;
  ~OperMul() override = default;
  double GetResult(void) override;
};

// 除法
class OperDiv : public Operation {
 public:
  OperDiv() = default;
  ~OperDiv() override = default;
  double GetResult(void) override;
};