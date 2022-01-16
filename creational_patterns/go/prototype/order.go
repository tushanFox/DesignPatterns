/**
 * @file order.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 创建者模式，以订单为例。
 * @version 0.1
 * @date 2022-02-14
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// -----------------------------------------------------------------
// 抽象原型
type OrderIntf interface {
	SetOrderId(id string)
	GetOrderId() string
	SetProductNum(num int)
	GetProductNum() int
	ShowOrder()
	Clone() OrderIntf
}

// -----------------------------------------------------------------
// 具体原型
// 个人订单
type PersonalOrder struct {
	customerName string
	orderId      string
	productNum   int
}

func (p *PersonalOrder) SetOrderId(id string) {
	p.orderId = id
}
func (p *PersonalOrder) GetOrderId() string {
	return p.orderId
}
func (p *PersonalOrder) SetProductNum(num int) {
	p.productNum = num
}
func (p *PersonalOrder) GetProductNum() int {
	return p.productNum
}
func (p *PersonalOrder) SetCustomerName(name string) {
	p.customerName = name
}
func (p *PersonalOrder) GetCustomerName() string {
	return p.customerName
}
func (p *PersonalOrder) ShowOrder() {
	fmt.Println(p.orderId, "|", p.productNum, "|", p.customerName)
}
func (p *PersonalOrder) Clone() OrderIntf {
	fmt.Println("cloning PersonalOrder")
	order := &PersonalOrder{
		customerName: p.customerName,
		orderId:      p.orderId,
		productNum:   p.productNum,
	}
	return order
}

// -----------------------------------------------------------------
// 具体原型
// 公司订单
type EnterpriseOrder struct {
	enterpriseName string
	orderId        string
	productNum     int
}

func (p *EnterpriseOrder) SetOrderId(id string) {
	p.orderId = id
}
func (p *EnterpriseOrder) GetOrderId() string {
	return p.orderId
}
func (p *EnterpriseOrder) SetProductNum(num int) {
	p.productNum = num
}
func (p *EnterpriseOrder) GetProductNum() int {
	return p.productNum
}
func (p *EnterpriseOrder) SetEnterpriseName(name string) {
	p.enterpriseName = name
}
func (p *EnterpriseOrder) GetEnterpriseName() string {
	return p.enterpriseName
}
func (p *EnterpriseOrder) ShowOrder() {
	fmt.Println(p.orderId, "|", p.productNum, "|", p.enterpriseName)
}
func (p *EnterpriseOrder) Clone() OrderIntf {
	fmt.Println("cloning EnterpriseOrder")
	order := &EnterpriseOrder{
		enterpriseName: p.enterpriseName,
		orderId:        p.orderId,
		productNum:     p.productNum,
	}
	return order
}
