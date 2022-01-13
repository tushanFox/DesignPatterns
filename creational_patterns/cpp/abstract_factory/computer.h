/**
 * @file computer.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 抽象工厂模式：一个抽象工厂可以生产一系列相关或相互依赖的抽象产品，这些抽象产品属于同一事物的不同子模块，而工厂方法模式只能生产一个抽象产品。
 *        比如一台电脑，有cpu/内存/显卡/硬盘等子模块，这些子模块具体对应不同的品牌、型号等等。
 * @version 0.1
 * @date 2022-01-12
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <string>
class Cpu;
class Memory;
// -----------------------------------------------------------------
// 抽象工厂类
class ComputerFactory {
 public:
  ComputerFactory() = default;
  virtual ~ComputerFactory() = default;
  virtual Cpu *CreateCpu() = 0;  // 电脑包含cpu/memeory等等组件
  virtual Memory *CreateMemory() = 0;
};
// -----------------------------------------------------------------
// 具体工厂类
// 品牌1电脑的工厂类
class Brand1ComputerFactory : public ComputerFactory {
 public:
  Cpu *CreateCpu() override;
  Memory *CreateMemory() override;
};

// 品牌2电脑的工厂类
class Brand2ComputerFactory : public ComputerFactory {
 public:
  Cpu *CreateCpu() override;
  Memory *CreateMemory() override;
};
// -----------------------------------------------------------------
// 抽象产品类
// Cpu基类
class Cpu {
 public:
  Cpu() = default;
  virtual ~Cpu() = default;
  virtual std::string GetCpuBrand(void) = 0;
};

// 内存基类
class Memory {
 public:
  Memory() = default;
  virtual ~Memory() = default;
  virtual std::string GetMemoryBrand(void) = 0;
};
// -----------------------------------------------------------------
// 具体产品类
// 品牌1 Cpu
class Cpu1 : public Cpu {
 public:
  Cpu1() = default;
  ~Cpu1() override = default;
  std::string GetCpuBrand(void) override;
};

// 品牌1 Memory
class Memory1 : public Memory {
 public:
  Memory1() = default;
  ~Memory1() override = default;
  std::string GetMemoryBrand(void) override;
};

// 品牌2 Cpu
class Cpu2 : public Cpu {
 public:
  Cpu2() = default;
  ~Cpu2() override = default;
  std::string GetCpuBrand(void) override;
};

// 品牌2 Memory
class Memory2 : public Memory {
 public:
  Memory2() = default;
  ~Memory2() override = default;
  std::string GetMemoryBrand(void) override;
};


