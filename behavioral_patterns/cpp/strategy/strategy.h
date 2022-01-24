/**
 * @file strategy.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 策略模式
 * @version 0.1
 * @date 2022-01-24
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
// 考虑销售报价的场景，对于不同类型的客户有不同的报价策略：
// 对普通客户或者新客户全价无折扣
// 对老客户有5%的折扣
// 对大客户有10%的折扣

// -----------------------------------------------------------------
// 抽象策略角色
// 定义报价算法接口
class Strategy {
 public:
  Strategy() = default;
  virtual ~Strategy() = default;
  /**
   * @brief 计算报价
   *
   * @param goods_price：商品的原价
   * @return double 计算出来，应该报给客户的价格
   */
  virtual double CalcPrice(double goods_price) = 0;
};

// -----------------------------------------------------------------
// 具体策略角色
// 为新客户或者普通客户计算应报价格
class OrdinaryCustomerStrategy : public Strategy {
 public:
  OrdinaryCustomerStrategy() = default;
  virtual ~OrdinaryCustomerStrategy() = default;
  double CalcPrice(double goods_price) override;
};

// 为老客户计算应报价格
class RegularCustomerStrategy : public Strategy {
 public:
  RegularCustomerStrategy() = default;
  virtual ~RegularCustomerStrategy() = default;
  double CalcPrice(double goods_price) override;
};

// 为大客户计算应报价格
class BigCustomerStrategy : public Strategy {
 public:
  BigCustomerStrategy() = default;
  virtual ~BigCustomerStrategy() = default;
  double CalcPrice(double goods_price) override;
};

// -----------------------------------------------------------------
// 上下文角色
// 价格管理，主要完成计算给客户的报价的功能
class PriceContext {
 public:
  PriceContext(Strategy *strategy) : strategy_(strategy) {}
  virtual ~PriceContext() = default;
  double Quote(double goods_price);

 private:
  Strategy *strategy_;
};
