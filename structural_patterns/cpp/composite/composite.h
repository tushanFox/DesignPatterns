/**
 * @file composite.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 组合模式
 * @version 0.1
 * @date 2022-01-20
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

#include <list>
#include <string>
// -----------------------------------------------------------------
// 抽象构件
class Component {
 public:
  Component() = default;
  virtual ~Component() = default;
  // 子构件可能有一些方法，这个只是示例
  virtual void Operation() = 0;
  virtual int AddChild(Component *child) {
    // 叶子构件没有子构件，所以默认返回-1
    return -1;
  }
  virtual int RemoveChild(Component *child) {
    // 叶子构件没有子构件，所以默认返回-1
    return -1;
  }
  virtual Component *GetChildren(int index) {
    // 叶子构件没有子构件，所以默认返回-1
    return nullptr;
  }
};

// -----------------------------------------------------------------
// 树枝构件
class Composite : public Component {
 public:
  Composite(const std::string &name) : name_(name) {}
  virtual ~Composite() = default;
  void Operation() override;
  int AddChild(Component *child) override;
  int RemoveChild(Component *child) override;
  Component *GetChildren(int index) override;

 private:
  std::list<Component *> child_components_;
  std::string name_;
};

// -----------------------------------------------------------------
// 叶子构件
class Leaf : public Component {
 public:
  Leaf(const std::string &name) : name_(name) {}
  virtual ~Leaf() = default;
  void Operation() override;

 private:
  std::string name_;
};