/**
 * @file facade.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 外观模式
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 */

package main

// 假设完成一个功能有多个步骤或者要访问多个子系统，
// 为了客户端使用方便，可以通过外观模式把这些操作统一封装到一个接口里面。

// -----------------------------------------------------------------
// 子系统
type SubSystem1 struct{}

func (s *SubSystem1) Process1() string {
	return "Process1"
}

type SubSystem2 struct{}

func (s *SubSystem2) Process2() string {
	return "Process2"
}

type SubSystem3 struct{}

func (s *SubSystem3) Process3() string {
	return "Process3"
}

// -----------------------------------------------------------------
// 外观
type Facade struct {
	sys1 *SubSystem1
	sys2 *SubSystem2
	sys3 *SubSystem3
}

func (f *Facade) Process() string {
	str := f.sys1.Process1()
	str = str + " | " + f.sys2.Process2()
	str = str + " | " + f.sys3.Process3()
	return str
}
