/**
 * @file car.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 创建者模式，以汽车为例。
 * @version 0.1
 * @date 2022-02-14
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// -----------------------------------------------------------------
// 产品
// 汽车产品包含轮胎/引擎/车体等等
type Car struct {
	wheel   string
	engine  string
	carbody string
}

func (c *Car) SetWheel(wheel string) {
	c.wheel = wheel
}
func (c *Car) SetEngine(engine string) {
	c.engine = engine
}
func (c *Car) SetCarBody(carbody string) {
	c.carbody = carbody
}
func (c *Car) Show() {
	fmt.Println(c.wheel, "|", c.engine, "|", c.carbody)
}

// -----------------------------------------------------------------
// 抽象创建者
// 创建抽象的汽车组件：轮胎/引擎/车体
type BuilderInterface interface {
	NewCar()
	BuildWheel()
	BuildEngine()
	BuildCarBody()
	GetResult() *Car
}

// -----------------------------------------------------------------
// 具体创建者
// 创建品牌1的汽车
type Brand1Builder struct {
	car *Car
}

func (b *Brand1Builder) NewCar() {
	b.car = new(Car)
}
func (b *Brand1Builder) BuildWheel() {
	b.car.wheel = "Brand1 wheel"
}
func (b *Brand1Builder) BuildEngine() {
	b.car.engine = "Brand1 engine"
}
func (b *Brand1Builder) BuildCarBody() {
	b.car.carbody = "Brand1 carbody"
}
func (b *Brand1Builder) GetResult() *Car {
	return b.car
}

// --------------------------------------------------------
// 具体创建者
// 创建品牌2的汽车
type Brand2Builder struct {
	car *Car
}

func (b *Brand2Builder) NewCar() {
	b.car = new(Car)
}
func (b *Brand2Builder) BuildWheel() {
	b.car.wheel = "Brand2 wheel"
}
func (b *Brand2Builder) BuildEngine() {
	b.car.engine = "Brand2 engine"
}
func (b *Brand2Builder) BuildCarBody() {
	b.car.carbody = "Brand2 carbody"
}
func (b *Brand2Builder) GetResult() *Car {
	return b.car
}

// -----------------------------------------------------------------
// 指挥者
type Director struct{}

func (d *Director) Create(builder BuilderInterface) *Car {
	builder.NewCar()
	builder.BuildWheel()
	builder.BuildEngine()
	builder.BuildCarBody()
	return builder.GetResult()
}
