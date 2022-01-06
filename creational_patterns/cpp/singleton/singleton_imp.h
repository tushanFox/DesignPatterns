/**
 * @file singleton_imp.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 单例模式
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include "singleton.h"
#include <iostream>

using namespace std;
class S1 : public Singleton<S1> {
  friend Singleton<S1>;
 public:
  void SetValue(int v) {
    value = v;
  }
  int GetValue(void) {
    return value;
  }
 private:
  int value = 0;
 protected:
  S1() {}
};

class S2 : public Singleton<S2> {
  // friend Singleton<S2>;
 public:
  void SetValue(int v) {
    value = v;
  }
  int GetValue(void) {
    return value;
  }
 private:
  int value = 0;
 public:
  S2() {}  // 如果不设置友元, 那么S2的构造函数必须是默认或者设置public，否则Singleton<S2>没法实例化
};