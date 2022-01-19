/**
 * @file adapter.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 适配器模式：A需要调用B，但是A/B之间协议不通，于是增加C。由C直接调用B，并且C提供A需要的接口。
 *        比如，读卡器把作为电脑和SD卡之间的适配器。
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// -----------------------------------------------------------------
// 对外的接口
type Target interface {
	Request()
}

// -----------------------------------------------------------------
// 内部接口
type Adaptee struct{}

func (a *Adaptee) SpecificRequest() {
	fmt.Println("call Adaptee.SpecificRequest")
}

// -----------------------------------------------------------------
// 适配器：包装内部接口，对外提供Request()函数
type Adapter struct {
	ade *Adaptee
}

func (a *Adapter) Request() {
	fmt.Println("call Adapter.Request")
	a.ade.SpecificRequest()
}
