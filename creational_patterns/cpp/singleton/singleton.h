/**
 * @file singleton.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 单例模式
 * @version 0.1
 * @date 2022-01-06
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
template <typename T>
class Singleton {
 public:
  static T &GetInstance() {
    static T instance_;  // c++11以上能保证静态局部变量线程安全
    return instance_;
  }
  Singleton(const Singleton&) = delete;
  Singleton &operator=(const Singleton&) = delete;
  virtual ~Singleton() {};
 protected:
  Singleton() {}  // 模板类的构造函数protected, 保证在子类可以实例化, 而在其他地方无法实例化
};