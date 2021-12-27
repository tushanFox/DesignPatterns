/**
 * @file operation.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 工厂方法模式，以“计算器”举例。
 * @version 0.1
 * @date 2021-12-27
 * 
 * @copyright Copyright (c) 2021
 * 
 */
package main

// 抽象的产品接口
type Operation interface {
	SetValue1(float64)
	SetValue2(float64)
	GetResult() float64
}
 
// 具体产品的基结构体，封装公共方法
type OperBase struct {
	v1 float64
	v2 float64
}

func (o *OperBase) SetValue1(v1 float64) {
	o.v1 = v1
}

func (o *OperBase) SetValue2(v2 float64) {
	o.v2 = v2
}

// 产品结构体(加法)的实现
type OperAdd struct {
	*OperBase  // 匿名成员
}

func (o *OperAdd) GetResult() float64 {
	return o.v1 + o.v2
}

// 产品结构体(减法)的实现
type OperSub struct {
	*OperBase  // 匿名成员
}

func (o *OperSub) GetResult() float64 {
	return o.v1 - o.v2
}

// 产品结构体(乘法)的实现
type OperMul struct {
	*OperBase  // 匿名成员
}

func (o *OperMul) GetResult() float64 {
	return o.v1 * o.v2
}

// 产品结构体(除法)的实现
type OperDiv struct {
	*OperBase  // 匿名成员
}

func (o *OperDiv) GetResult() float64 {
	return o.v1 / o.v2
}

//////// 工厂接口和结构体
// 工厂接口
type OperationFactory interface {
	CreateProduct() Operation
}

// 工厂产品(加法)的实现
type AddFactory struct {}

func (a *AddFactory) CreateProduct() Operation {
	return &OperAdd{
		OperBase: &OperBase{},
	}
}

// 工厂产品(加法)的实现
type SubFactory struct {}

func (s *SubFactory) CreateProduct() Operation {
	return &OperSub{
		OperBase: &OperBase{},
	}
}

// 工厂产品(乘法)的实现
type MulFactory struct {}

func (m *MulFactory) CreateProduct() Operation {
	return &OperMul{
		OperBase: &OperBase{},
	}
}

// 工厂产品(除法)的实现
type DivFactory struct {}

func (d *DivFactory) CreateProduct() Operation {
	return &OperDiv{
		OperBase: &OperBase{},
	}
}