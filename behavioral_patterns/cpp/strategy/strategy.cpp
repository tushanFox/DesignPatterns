/**
 * @file strategy.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 策略模式
 * @version 0.1
 * @date 2022-01-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "strategy.h"
#include <iostream>

// -----------------------------------------------------------------
double OrdinaryCustomerStrategy::CalcPrice(double goods_price) {
  std::cout << "OrdinaryCustomerStrategy::CalcPrice, original price:" << goods_price << ", quote price:" << goods_price
            << std::endl;
  return goods_price;
}

// -----------------------------------------------------------------
double RegularCustomerStrategy::CalcPrice(double goods_price) {
  double price = goods_price * (1 - 0.05);
  std::cout << "RegularCustomerStrategy::CalcPrice, original price:" << goods_price << ", quote price:" << price
            << std::endl;
  return price;
}

// -----------------------------------------------------------------
double BigCustomerStrategy::CalcPrice(double goods_price) {
  double price = goods_price * (1 - 0.1);
  std::cout << "BigCustomerStrategy::CalcPrice, original price:" << goods_price << ", quote price:" << price
            << std::endl;
  return price;
}

// -----------------------------------------------------------------
double PriceContext::Quote(double goods_price) {
  double price = strategy_->CalcPrice(goods_price);
  return price;
}