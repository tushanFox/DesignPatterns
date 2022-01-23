/**
 * @file flyweight.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 享元模式
 * @version 0.1
 * @date 2022-01-21
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <iostream>
#include <map>
#include <string>
// -----------------------------------------------------------------
// 抽象享元角色
class Flyweight {
 public:
  Flyweight() = default;
  virtual ~Flyweight() = default;
  /**
   * @brief 传入外部状态
   *
   * @param extrinsic_state：外部状态
   */
  virtual void Operation(const std::string &extrinsic_state) = 0;
};

// -----------------------------------------------------------------
// 具体享元
class ConcreteFlyweight : public Flyweight {
 public:
  /**
   * @brief 构造函数，传入享元对象的内部状态的数据
   *
   * @param state：享元对象的内部状态的数据
   */
  ConcreteFlyweight(const std::string &state) : intrinsic_state_(state) {}
  virtual ~ConcreteFlyweight() = default;
  void Operation(const std::string &extrinsic_state) override {
    std::cout << "ConcreteFlyweight::Operation, state:" << extrinsic_state << std::endl;
  }

 private:
  std::string intrinsic_state_;
};

// -----------------------------------------------------------------
// 非享元
class UnsharedConcreteFlyweight : public Flyweight {
 public:
  UnsharedConcreteFlyweight() = default;
  virtual ~UnsharedConcreteFlyweight() = default;
  void Operation(const std::string &extrinsic_state) override {
    std::cout << "UnsharedConcreteFlyweight::Operation, state:" << extrinsic_state << std::endl;
  }

 private:
  std::string all_state;
};

// -----------------------------------------------------------------
// 享元工厂
class FlyweightFactory {
 public:
  Flyweight *GetFlyweight(const std::string &key);

 private:
  std::map<std::string, Flyweight *> fly_map_;  // 保存多个享元对象
};