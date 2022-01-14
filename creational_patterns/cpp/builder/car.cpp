/**
 * @file car.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 创建者模式。
 * @version 0.1
 * @date 2022-01-13
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "car.h"
#include <iostream>
// -----------------------------------------------------------------
void Car::SetWheel(const std::string &wheel) {
  this->wheel = wheel;
  return;
}
void Car::SetEngine(const std::string &engine) {
  this->engine = engine;
  return;
}
void Car::SetCarBody(const std::string &carbody) {
  this->carbody = carbody;
  return;
}
void Car::Show() {
  std::cout << wheel << "|" << engine << "|" << carbody << std::endl;
}

// -----------------------------------------------------------------
void Brand1Builder::BuildWheel() {
  car.SetWheel("Brand1 wheel");
  return;
}

void Brand1Builder::BuildEngine() {
  car.SetEngine("Brand1 engine");
  return;
}

void Brand1Builder::BuildCarBody() {
  car.SetCarBody("Brand1 carbody");
  return;
}

// -----------------------------------------------------------------
void Brand2Builder::BuildWheel() {
  car.SetWheel("Brand2 wheel");
  return;
}

void Brand2Builder::BuildEngine() {
  car.SetEngine("Brand2 engine");
  return;
}

void Brand2Builder::BuildCarBody() {
  car.SetCarBody("Brand2 carbody");
  return;
}

// -----------------------------------------------------------------
Car *Director::Create(BuilderInterface *builder) {
  builder->BuildWheel();
  builder->BuildEngine();
  builder->BuildCarBody();
  return builder->GetResult();
}