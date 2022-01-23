/**
 * @file flyweight.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 享元模式
 * @version 0.1
 * @date 2022-01-23
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// -----------------------------------------------------------------
// 抽象享元角色
type Flyweight interface {
	Operation(extrinsicState string)
}

// -----------------------------------------------------------------
// 具体享元
type ConcreteFlyweight struct {
	intrinsicState string
}

func (c *ConcreteFlyweight) Operation(extrinsicState string) {
	fmt.Println("ConcreteFlyweight.Operation, state:", extrinsicState)
}

// -----------------------------------------------------------------
// 非享元
type UnsharedConcreteFlyweight struct {
	allState string
}

func (u *UnsharedConcreteFlyweight) Operation(extrinsicState string) {
	fmt.Println("UnsharedConcreteFlyweight.Operation, state:", extrinsicState)
}

// -----------------------------------------------------------------
// 享元工厂
type FlyweightFactory struct {
	flyMap map[string]Flyweight
}

func (f *FlyweightFactory) GetFlyweight(key string) Flyweight {
	// 1. 先从本地缓存查找，是否存在key对应的享元角色
	var fly Flyweight
	fly, ok := f.flyMap[key]
	if ok {
		// 2. 如果存在，就返回本地缓存的对象
		return fly
	}

	// 3. 如果不存在就创建一个新的Flyweight对象并返回
	fly = new(ConcreteFlyweight)
	if f.flyMap == nil {
		f.flyMap = make(map[string]Flyweight)
	}
	f.flyMap[key] = fly
	return fly
}
