/**
 * @file proxy.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 代理模式
 * @version 0.1
 * @date 2022-01-18
 *
 * @copyright Copyright (c) 2022
 *
 */

package main

// -----------------------------------------------------------------
// 抽象主题
type Subject interface {
	Request() string
}

// -----------------------------------------------------------------
// 真实主题
type RealSubject struct{}

func (r *RealSubject) Request() string {
	return "RealSubject"
}

// -----------------------------------------------------------------
// 代理
type Proxy struct {
	realSubject *RealSubject
}

func (p *Proxy) Request() string {
	return "Proxy | " + p.realSubject.Request()
}
