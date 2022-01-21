/**
 * @file composite.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-20
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "composite.h"
#include <iterator>
#include <iostream>

// -----------------------------------------------------------------
// 树枝构件
void Composite::Operation() {
  std::cout << "Composite: " << name_ << std::endl;
  if (!child_components_.empty()) {
    for (auto &child : child_components_) {
      // 递归调用子构件的函数
      child->Operation();
    }
  }
}

int Composite::AddChild(Component *child) {
  child_components_.push_back(child);
  return 0;
}

int Composite::RemoveChild(Component *child) {
  child_components_.remove(child);
  return 0;
}

Component *Composite::GetChildren(int index) {
  if (index >= 0 && index < child_components_.size()) {
    auto it = child_components_.begin();
    std::advance(it, index);  // Advances the iterator it by n element positions.
    return *it;
  }
  return nullptr;
}

// -----------------------------------------------------------------
// 叶子构件
void Leaf::Operation() {
  std::cout << "Leaf: " << name_ << std::endl;
}