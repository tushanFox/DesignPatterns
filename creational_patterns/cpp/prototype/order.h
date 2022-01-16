/**
 * @file order.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 原型模式，以订单举例。
 * @version 0.1
 * @date 2022-01-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <string>

// -----------------------------------------------------------------
// 抽象原型
class OrderIntf {
 public:
  OrderIntf() = default;
  virtual ~OrderIntf() = default;

  virtual OrderIntf *Clone() = 0;  // 有时候会有深拷贝和浅拷贝的区别，比如类成员有指针。

  virtual void SetOrderId(const std::string &id) = 0;
  virtual std::string &GetOrderId() = 0;
  virtual void SetProductNum(int num) = 0;
  virtual int GetProductNum() = 0;
  virtual void ShowOrder() = 0;
};

// -----------------------------------------------------------------
// 具体原型类
// 个人订单
class PersonalOrder : public OrderIntf {
 public:
  PersonalOrder() = default;
  virtual ~PersonalOrder() = default;

  OrderIntf *Clone() override;
  void SetOrderId(const std::string &id) override;
  std::string &GetOrderId() override;
  void SetProductNum(int num) override;
  int GetProductNum() override;
  void ShowOrder() override;

  void SetCustomerName(const std::string &name);
  std::string &GetCustomerName();

 private:
  std::string customer_name_;
  std::string order_id_;
  int product_num_;
};

// -----------------------------------------------------------------
// 具体原型类
// 公司订单
class EnterpriseOrder : public OrderIntf {
 public:
  EnterpriseOrder() = default;
  virtual ~EnterpriseOrder() = default;

  OrderIntf *Clone() override;
  void SetOrderId(const std::string &id) override;
  std::string &GetOrderId() override;
  void SetProductNum(int num) override;
  int GetProductNum() override;
  void ShowOrder() override;

  void SetEnterpriseName(const std::string &name);
  std::string &GetEnterpriseName();

 private:
  std::string enterprise_name_;
  std::string order_id_;
  int product_num_;
};