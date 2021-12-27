/**
 * @file Operation.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 简单工厂模式，又称为静态工厂方法模式，以“计算器”举例。
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

// 产品结构体(加法)的实现
type OperAdd struct {
	v1 float64
	v2 float64
}

func (o *OperAdd) SetValue1(v1 float64) {
	o.v1 = v1
}

func (o *OperAdd) SetValue2(v2 float64) {
	o.v2 = v2
}

func (o *OperAdd) GetResult() float64 {
	return o.v1 + o.v2
}

// 产品结构体(减法)的实现
type OperSub struct {
	v1 float64
	v2 float64
}

func (o *OperSub) SetValue1(v1 float64) {
	o.v1 = v1
}

func (o *OperSub) SetValue2(v2 float64) {
	o.v2 = v2
}

func (o *OperSub) GetResult() float64 {
	return o.v1 - o.v2
}

// 产品结构体(乘法)的实现
type OperMul struct {
	v1 float64
	v2 float64
}

func (o *OperMul) SetValue1(v1 float64) {
	o.v1 = v1
}

func (o *OperMul) SetValue2(v2 float64) {
	o.v2 = v2
}

func (o *OperMul) GetResult() float64 {
	return o.v1 * o.v2
}

// 产品结构体(除法)的实现
type OperDiv struct {
	v1 float64
	v2 float64
}

func (o *OperDiv) SetValue1(v1 float64) {
	o.v1 = v1
}

func (o *OperDiv) SetValue2(v2 float64) {
	o.v2 = v2
}

func (o *OperDiv) GetResult() float64 {
	return o.v1 / o.v2
}

// 工厂结构体的实现
type OperationFactory struct {}

func (o *OperationFactory) CreateProduct(op string) Operation {
	switch op {
	case "ADD":
		return &OperAdd{}
	case "SUB":
		return &OperSub{}
	case "MUL":
		return &OperMul{}
	case "DIV":
		return &OperDiv{}
	default:
		return nil
	}
}