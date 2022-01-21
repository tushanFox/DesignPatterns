/**
 * @file composite.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 组合模式
 * @version 0.1
 * @date 2022-01-21
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// -----------------------------------------------------------------
// 抽象构件
type Component interface {
	Operation()
	AddChild(child Component) int
	RemoveChild(child Component) int
	GetChildren(index int) Component
}

// -----------------------------------------------------------------
// 树枝构件
type Composite struct {
	childComponents []Component
	name            string
}

func (c *Composite) Operation() {
	fmt.Println("Composite: ", c.name)
	if c.childComponents != nil {
		for _, child := range c.childComponents {
			child.Operation()
		}
	}
}

func (c *Composite) AddChild(child Component) int {
	c.childComponents = append(c.childComponents, child)
	return 0
}

func (c *Composite) RemoveChild(child Component) int {
	if c.childComponents != nil {
		for index, ch := range c.childComponents {
			if child == ch {
				c.childComponents = append(c.childComponents[:index], c.childComponents[index+1:]...)
				return 0
			}
		}
	}
	return -1
}

func (c *Composite) GetChildren(index int) Component {
	if c.childComponents != nil {
		for i, ch := range c.childComponents {
			if index == i {
				return ch
			}
		}
	}
	return nil
}

// -----------------------------------------------------------------
// 叶子构件
type Leaf struct {
	name string
}

func (l *Leaf) Operation() {
	fmt.Println("leaf: ", l.name)
}
func (l *Leaf) AddChild(child Component) int {
	return -1
}
func (l *Leaf) RemoveChild(child Component) int {
	return -1
}
func (l *Leaf) GetChildren(index int) Component {
	return nil
}
