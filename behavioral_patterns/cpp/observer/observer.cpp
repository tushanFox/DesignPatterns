/**
 * @file observer.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 观察者模式
 * @version 0.1
 * @date 2022-01-28
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "observer.h"
#include <iostream>

// -----------------------------------------------------------------
void Subject::Attach(Observer *reader) { readers.insert(reader); }

void Subject::Detach(Observer *reader) { readers.erase(reader); }

void Subject::NotifyObservers() {
  for (auto rd : readers) {
    rd->Update(this);
  }
}

// -----------------------------------------------------------------
std::string &NewsPaper::GetContent() { return content; }

void NewsPaper::SetContent(const std::string &content) {
  this->content = content;
  NotifyObservers();
}

// -----------------------------------------------------------------
void Reader::Update(Subject *subject) {
  NewsPaper *newspaper = dynamic_cast<NewsPaper *>(subject);
  std::cout << GetName() << " received a newspaper. The content is " << newspaper->GetContent() << std::endl;
}

std::string &Reader::GetName() {
  return name;
}

void Reader::SetName(const std::string &name) {
  this->name = name;
}