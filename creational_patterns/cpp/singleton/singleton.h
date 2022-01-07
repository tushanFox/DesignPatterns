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
#include <mutex>

// 单例模式模板类
template <typename T>
class Singleton {
 public:
  static T &GetInstance() {
    static T instance_;  // c++11以上能保证静态局部变量线程安全
    return instance_;
  }
  Singleton(const Singleton&) = delete;
  Singleton(const Singleton&&) = delete;
  Singleton &operator=(const Singleton&) = delete;
  virtual ~Singleton() {};
 protected:
  Singleton() {}  // 模板类的构造函数protected, 保证在子类可以实例化, 而在其他地方无法实例化
};

// 单例模式非模板类
class Singleton1 {
 public:
  static Singleton1 *GetInstance() {
    if (instance_ == nullptr) {
      if (mutex_.try_lock()) {
        instance_ = new Singleton1();
        mutex_.unlock();
      }
    }
    return instance_;
  }
  void SetValue(int v) {
    value = v;
  }
  int GetValue(void) {
    return value;
  }
  Singleton1(const Singleton1&) = delete;
  Singleton1(const Singleton1&&) = delete;
  Singleton1 &operator=(const Singleton1&) = delete;
  virtual ~Singleton1() {};
 private:
  Singleton1() {}
  static Singleton1 *instance_;
  static std::mutex mutex_;
  int value = 0;
};