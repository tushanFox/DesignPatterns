/**
 * @file adapter.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 适配器模式：A需要调用B，但是A/B之间协议不通，于是增加C。由C直接调用B，并且C提供A需要的接口。
 *        比如，读卡器把作为电脑和SD卡之间的适配器。
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
// -----------------------------------------------------------------
// 对外的接口
class Target {
 public:
  Target() = default;
  virtual ~Target() = default;
  virtual void Request();
};

// -----------------------------------------------------------------
// 内部接口
class Adaptee {
 public:
  Adaptee() = default;
  ~Adaptee() = default;
  void SpecificRequest();
};

// -----------------------------------------------------------------
// 适配器：包装内部接口，对外提供Request()函数
class Adapter : public Target {
 public:
  Adapter(Adaptee* ade);
  ~Adapter() = default;
  void Request() override;

 private:
  Adaptee* ade_ = nullptr;
};