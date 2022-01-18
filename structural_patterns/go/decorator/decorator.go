/**
 * @file decorator.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 装饰器模式
 * @version 0.1
 * @date 2022-01-18
 *
 * @copyright Copyright (c) 2022
 *
 */

package main

// -----------------------------------------------------------------
// 抽象构件
type Component interface {
	Operation() string
}

// -----------------------------------------------------------------
// 具体构件
type ConcreteComponent struct{}

func (a *ConcreteComponent) Operation() string {
	return "ConcreteComponent"
}

// -----------------------------------------------------------------
// 具体装饰
type ConcreteDecorator1 struct {
	component Component
}

func (c *ConcreteDecorator1) NewComponent(component Component) {
	c.component = component
}

func (c *ConcreteDecorator1) Operation() string {
	return "ConcreteDecorator1 | " + c.component.Operation()
}

// -----------------------------------------------------------------
// 具体装饰
type ConcreteDecorator2 struct {
	component Component
}

func (c *ConcreteDecorator2) NewComponent(component Component) {
	c.component = component
}

func (c *ConcreteDecorator2) Operation() string {
	return "ConcreteDecorator2 | " + c.component.Operation()
}
