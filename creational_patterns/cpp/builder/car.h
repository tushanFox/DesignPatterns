/**
 * @file car.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 创建者模式，以汽车为例。
 * @version 0.1
 * @date 2022-01-13
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <string>

// -----------------------------------------------------------------
// 产品
// 汽车产品包含轮胎/引擎/车体等等
class Car {
 public:
  Car() = default;
  virtual ~Car() = default;
  void SetWheel(const std::string &wheel);
  void SetEngine(const std::string &engine);
  void SetCarBody(const std::string &carbody);
  void Show();

 private:
  std::string wheel;
  std::string engine;
  std::string carbody;
};

// -----------------------------------------------------------------
// 抽象创建者
// 创建抽象的汽车组件：轮胎/引擎/车体
class BuilderInterface {
 public:
  BuilderInterface() = default;
  virtual ~BuilderInterface() = default;
  virtual void BuildWheel() = 0;
  virtual void BuildEngine() = 0;
  virtual void BuildCarBody() = 0;
  Car *GetResult() { return &car; }

 protected:
  Car car;
};
// -----------------------------------------------------------------
// 具体创建者
// 创建品牌1的汽车
class Brand1Builder : public BuilderInterface {
 public:
  void BuildWheel() override;
  void BuildEngine() override;
  void BuildCarBody() override;
};

// 创建品牌2的汽车
class Brand2Builder : public BuilderInterface {
 public:
  void BuildWheel() override;
  void BuildEngine() override;
  void BuildCarBody() override;
};
// -----------------------------------------------------------------
// 指挥者
class Director {
 public:
  Car *Create(BuilderInterface *builder);
};