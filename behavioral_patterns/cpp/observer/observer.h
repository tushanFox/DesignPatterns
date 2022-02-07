/**
 * @file observer.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 观察者模式
 * @version 0.1
 * @date 2022-01-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
#include <string>
#include <set>
// 案例：读者向报社订阅报纸，符合观察者模式使用场景
// 读者(订阅者)是观察者；报纸是被观察者

class Observer;
// -----------------------------------------------------------------
// 抽象目标，抽象被观察者
class Subject {
 public:
  Subject() = default;
  virtual ~Subject() = default;
  /**
   * @brief 报纸的读者需要向报社订阅，先得注册
   *
   * @param reader 报纸的读者
   */
  void Attach(Observer *reader);

  /**
   * @brief 报纸的读者可以取消订阅
   *
   * @param reader 报纸的读者
   */
  void Detach(Observer *reader);

 protected:
  /**
   * @brief 报纸被印刷出来后，要迅速送到读者手中，相当于通知读者(观察者)
   *
   */
  void NotifyObservers();

 private:
  std::set<Observer *> readers;  // 报纸的订阅者(观察者)
};

// -----------------------------------------------------------------
// 具体目标，报纸
class NewsPaper : public Subject {
 public:
  NewsPaper() = default;
  virtual ~NewsPaper() = default;
  /**
   * @brief 获取报纸的内容
   *
   * @return std::string&
   */
  std::string &GetContent();

  /**
   * @brief 设置报纸内容，相当于要出版报纸
   *
   * @param content
   */
  void SetContent(const std::string &content);

 private:
  std::string content;  // 报纸的内容
};

// -----------------------------------------------------------------
// 抽象观察者
class Observer {
 public:
  Observer() = default;
  virtual ~Observer() = default;
  /**
   * @brief 被通知的方法
   *
   * @param subject
   */
  virtual void Update(Subject *subject) = 0;
};

// -----------------------------------------------------------------
// 具体观察者，报纸的读者
class Reader : public Observer {
 public:
  Reader() = default;
  virtual ~Reader() = default;
  void Update(Subject *subject) override;
  std::string &GetName();
  void SetName(const std::string &name);

 private:
  std::string name;  // 读者姓名
};
