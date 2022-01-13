/**
 */
package main

import (
	"fmt"
)

func main() {
	var cpu Cpu
	var mem Memory
	var factory ComputerFactory
	factory = new(Computer1Factory) // computer 1
	cpu = factory.CreateCpu()
	mem = factory.CreateMemory()
	cpu.SetCpuBrand("Cpu Brand1")
	mem.SetMemoryBrand("Memory Brand1")
	fmt.Println(cpu.GetCpuBrand(), "|", mem.GetMemoryBrand())

	factory = new(Computer2Factory) // computer 2
	cpu = factory.CreateCpu()
	mem = factory.CreateMemory()
	cpu.SetCpuBrand("Cpu Brand2")
	mem.SetMemoryBrand("Memory Brand2")
	fmt.Println(cpu.GetCpuBrand(), "|", mem.GetMemoryBrand())

}
