/**
 * @file proxy.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 代理模式
 * @version 0.1
 * @date 2022-01-18
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
// -----------------------------------------------------------------
// 抽象主题
class Subject {
 public:
  Subject() = default;
  virtual ~Subject() = default;
  virtual std::string Request() = 0;
};

// -----------------------------------------------------------------
// 真实主题
class RealSubject : public Subject {
 public:
  RealSubject() = default;
  virtual ~RealSubject() = default;
  std::string Request() override { return "RealSubject"; }
};

// -----------------------------------------------------------------
// 代理
class Proxy : public Subject {
 public:
  Proxy() = default;
  virtual ~Proxy() = default;
  std::string Request() override { 
    return "Proxy | " + real_subject_.Request();
  }

 private:
  RealSubject real_subject_;
};