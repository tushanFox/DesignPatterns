/**
 * @file operation.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 抽象工厂模式，以“电脑”举例。
 * @version 0.1
 * @date 2022-02-13
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

// --------------------------------------------------------
// 抽象工厂接口
type ComputerFactory interface {
	CreateCpu() Cpu
	CreateMemory() Memory
}

// --------------------------------------------------------
// 具体工厂(computer1)的实现
type Computer1Factory struct{}

func (c *Computer1Factory) CreateCpu() Cpu {
	return &Cpu1{
		CpuBase: &CpuBase{},
	}
}
func (c *Computer1Factory) CreateMemory() Memory {
	return &Memory1{
		MemoryBase: &MemoryBase{},
	}
}

// 具体工厂(computer2)的实现
type Computer2Factory struct{}

func (c *Computer2Factory) CreateCpu() Cpu {
	return &Cpu2{
		CpuBase: &CpuBase{},
	}
}
func (c *Computer2Factory) CreateMemory() Memory {
	return &Memory2{
		MemoryBase: &MemoryBase{},
	}
}

// --------------------------------------------------------
// 抽象的产品接口
type Cpu interface {
	SetCpuBrand(b string)
	GetCpuBrand() string
}
type Memory interface {
	SetMemoryBrand(b string)
	GetMemoryBrand() string
}

// --------------------------------------------------------
// 具体产品的基结构体，封装公共方法
type CpuBase struct {
	cpuBrand string
}
type MemoryBase struct {
	memBrand string
}

func (c *CpuBase) SetCpuBrand(b string) {
	c.cpuBrand = b
}

func (c *CpuBase) GetCpuBrand() string {
	return c.cpuBrand
}

func (m *MemoryBase) SetMemoryBrand(b string) {
	m.memBrand = b
}

func (m *MemoryBase) GetMemoryBrand() string {
	return m.memBrand
}

// --------------------------------------------------------
// 具体产品结构体的实现
type Cpu1 struct {
	*CpuBase // 匿名成员
}
type Memory1 struct {
	*MemoryBase // 匿名成员
}

type Cpu2 struct {
	*CpuBase // 匿名成员
}
type Memory2 struct {
	*MemoryBase // 匿名成员
}
