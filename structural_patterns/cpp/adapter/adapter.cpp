/**
 * @file adapter.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 适配器模式：A需要调用B，但是A/B之间协议不通，于是增加C。由C直接调用B，并且C提供A需要的接口。
 *        比如，读卡器把作为电脑和SD卡之间的适配器。
 * @version 0.1
 * @date 2022-01-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "adapter.h"
#include <iostream>

// -----------------------------------------------------------------
void Target::Request() {
  std::cout << "call Target::Request()" << std::endl;
  return;
}

// -----------------------------------------------------------------
void Adaptee::SpecificRequest() {
  std::cout << "call Adaptee::SpecificRequest()" << std::endl;
  return;
}

// -----------------------------------------------------------------
Adapter::Adapter(Adaptee* ade) { ade_ = ade; }

void Adapter::Request() {
  std::cout << "call Adapter::Request()" << std::endl;
  if (ade_) {
    ade_->SpecificRequest();
  }
  return;
}