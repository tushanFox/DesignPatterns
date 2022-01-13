/**
 * @file computer.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 抽象工厂模式：一个抽象工厂可以生产一系列相关或相互依赖的抽象产品，这些抽象产品属于同一事物的不同子模块，而工厂方法模式只能生产一个抽象产品。
 *        比如一台电脑，有cpu/内存/显卡/硬盘等子模块，这些子模块具体对应不同的品牌、型号等等。
 * @version 0.1
 * @date 2022-01-12
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "computer.h"
// 品牌1电脑的工厂
Cpu *Brand1ComputerFactory::CreateCpu() {
  return new Cpu1();
}
Memory *Brand1ComputerFactory::CreateMemory() {
  return new Memory1();
}

// 品牌2电脑的工厂
Cpu *Brand2ComputerFactory::CreateCpu() {
  return new Cpu2();
}
Memory *Brand2ComputerFactory::CreateMemory() {
  return new Memory2();
}


std::string Cpu1::GetCpuBrand(void) {
  return "Cpu Brand1";
}

std::string Memory1::GetMemoryBrand(void) {
  return "Memory Brand1";
}

std::string Cpu2::GetCpuBrand(void) {
  return "Cpu Brand2";
}

std::string Memory2::GetMemoryBrand(void) {
  return "Memory Brand2";
}