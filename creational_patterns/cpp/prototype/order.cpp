/**
 * @file order.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 原型模式，以订单举例。
 * @version 0.1
 * @date 2022-01-14
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "order.h"
#include <iostream>
// -----------------------------------------------------------------
// 具体原型类
// 个人订单
OrderIntf *PersonalOrder::Clone() {
  PersonalOrder *order = new PersonalOrder();
  std::cout << "cloning PersonalOrder" << std::endl;
  order->SetOrderId(order_id_);
  order->SetProductNum(product_num_);
  order->SetCustomerName(customer_name_);
  return order;
}
void PersonalOrder::SetOrderId(const std::string &id) {
  order_id_ = id;
}
std::string &PersonalOrder::GetOrderId() {
  return order_id_;
}
void PersonalOrder::SetProductNum(int num) {
  product_num_ = num;
}
int PersonalOrder::GetProductNum() {
  return product_num_;
}
void PersonalOrder::SetCustomerName(const std::string &name) {
  customer_name_ = name;
}
std::string &PersonalOrder::GetCustomerName() {
  return customer_name_;
}
void PersonalOrder::ShowOrder() {
  std::cout << order_id_ << "|" << product_num_ << "|" << customer_name_ << std::endl;
}

// -----------------------------------------------------------------
// 具体原型类
// 公司订单
OrderIntf *EnterpriseOrder::Clone() {
  EnterpriseOrder *order = new EnterpriseOrder();
  std::cout << "cloning EnterpriseOrder" << std::endl;
  order->SetOrderId(order_id_);
  order->SetProductNum(product_num_);
  order->SetEnterpriseName(enterprise_name_);
  return order;
}
void EnterpriseOrder::SetOrderId(const std::string &id) {
  order_id_ = id;
}
std::string &EnterpriseOrder::GetOrderId() {
  return order_id_;
}
void EnterpriseOrder::SetProductNum(int num) {
  product_num_ = num;
}
int EnterpriseOrder::GetProductNum() {
  return product_num_;
}
void EnterpriseOrder::SetEnterpriseName(const std::string &name) {
  enterprise_name_ = name;
}
std::string &EnterpriseOrder::GetEnterpriseName() {
  return enterprise_name_;
}
void EnterpriseOrder::ShowOrder() {
  std::cout << order_id_ << "|" << product_num_ << "|" << enterprise_name_ << std::endl;
}