/**
 * @file decorator.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 装饰器模式
 * @version 0.1
 * @date 2022-01-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
// -----------------------------------------------------------------
// 抽象构件
class Component {
 public:
  Component() = default;
  virtual ~Component() = default;
  virtual std::string Operation() = 0;
};

// -----------------------------------------------------------------
// 具体构件
class ConcreteComponent : public Component {
 public:
  ConcreteComponent() = default;
  virtual ~ConcreteComponent() = default;
  std::string Operation() override { return "ConcreteComponent"; };
};

// -----------------------------------------------------------------
// 抽象装饰
class Decorator : public Component {
 public:
  Decorator(Component *component) : component_(component) {}
  virtual ~Decorator() = default;
  std::string Operation() override;
 protected:
  Component *component_;
};

// -----------------------------------------------------------------
// 具体装饰
class ConcreteDecorator1 : public Decorator {
 public:
  ConcreteDecorator1(Component *component) : Decorator(component) {}
  std::string Operation() override;
};

class ConcreteDecorator2 : public Decorator {
 public:
  ConcreteDecorator2(Component *component) : Decorator(component) {}
  std::string Operation() override;
};


