/**
 * @file templete.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2022-01-25
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "template.h"
#include <iostream>

// -----------------------------------------------------------------
// 抽象类：出国留学
void StudyAbroad::TemplateMethod() {
  LookingForSchool();  // 获取学校资料
  ApplyForEnroll();  // 入学申请
  ApplyForPassort();  // 办理因私出国护照/出境卡和公证
  ApplyForVisa();  // 申请签证
  ReadyGoAbroad();  // 体检/订机票/准备行装
  Arriving();  // 抵达
  return;
}

void StudyAbroad::ApplyForPassort() {
  std::cout << "3. apply for passport and notarized certificate" << std::endl;
  return;
}

void StudyAbroad::ApplyForVisa() {
  std::cout << "4. apply for visa" << std::endl;
  return;
}

void StudyAbroad::ReadyGoAbroad() {
  std::cout << "5. ready go abroad" << std::endl;
  return;
}

// -----------------------------------------------------------------
// 具体子类：美国留学
void StudyInAmerica::LookingForSchool() {
  std::cout << "1. looking for America school" << std::endl;
  return;
}

void StudyInAmerica::ApplyForEnroll() {
  std::cout << "2. apply for America enroll" << std::endl;
  return;
}

void StudyInAmerica::Arriving() {
  std::cout << "6. arriving America" << std::endl;
  return;
}