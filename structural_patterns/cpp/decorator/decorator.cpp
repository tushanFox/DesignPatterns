/**
 * @file decorator.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 装饰器模式
 * @version 0.1
 * @date 2022-01-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include "decorator.h"
#include <iostream>

// -----------------------------------------------------------------
// 抽象装饰
std::string Decorator::Operation() {
  return component_->Operation();
}

// -----------------------------------------------------------------
// 具体装饰
std::string ConcreteDecorator1::Operation() {
  return "ConcreteDecorator1 | " + component_->Operation();
};

std::string ConcreteDecorator2::Operation() {
  return "ConcreteDecorator2 | " + component_->Operation();
};