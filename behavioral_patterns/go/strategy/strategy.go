/**
 * @file strategy.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 策略模式
 * @version 0.1
 * @date 2022-01-24
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// 考虑销售报价的场景，对于不同类型的客户有不同的报价策略：
// 对普通客户或者新客户全价无折扣
// 对老客户有5%的折扣
// 对大客户有10%的折扣

// -----------------------------------------------------------------
// 抽象策略角色
// 定义报价算法接口
type Strategy interface {
	CalcPrice(goodsPrice float64) float64
}

// -----------------------------------------------------------------
// 具体策略角色
// 为新客户或者普通客户计算应报价格
type OrdinaryCustomerStrategy struct{}

func (o *OrdinaryCustomerStrategy) CalcPrice(goodsPrice float64) float64 {
	fmt.Println("OrdinaryCustomerStrategy.CalcPrice, original price:", goodsPrice, ", quote price:", goodsPrice)
	return goodsPrice
}

// 为老客户计算应报价格
type RegularCustomerStrategy struct{}

func (o *RegularCustomerStrategy) CalcPrice(goodsPrice float64) float64 {
	price := goodsPrice * (1 - 0.05)
	fmt.Println("RegularCustomerStrategy.CalcPrice, original price:", goodsPrice, ", quote price:", price)
	return price
}

// 为大客户计算应报价格
type BigCustomerStrategy struct{}

func (o *BigCustomerStrategy) CalcPrice(goodsPrice float64) float64 {
	price := goodsPrice * (1 - 0.1)
	fmt.Println("OrdinaryCustomerStrategy::CalcPrice, original price:", goodsPrice, ", quote price:", price)
	return price
}

// -----------------------------------------------------------------
// 上下文角色
// 价格管理，主要完成计算给客户的报价的功能
type PriceContext struct {
	strategy Strategy
}

func (p *PriceContext) Quote(goodsPrice float64) float64 {
	return p.strategy.CalcPrice(goodsPrice)
}
