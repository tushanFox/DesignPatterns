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
#pragma once
enum Operator {
  OPER_ADD = 1,
  OPER_SUB = 2,
  OPER_MUL = 3,
  OPER_DIV = 4
};
class Operation;
// 工厂类
class OperationFactory {
public:
  static Operation *CreateProduct(Operator op);
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