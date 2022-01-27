/**
 * @file template.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-01-25
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once
// 案例：出国留学手续一般经过以下流程：索取学校资料，提出入学申请，办理因私出国护照、出境卡和公证，
//      申请签证，体检、订机票、准备行装，抵达目标学校等，其中有些业务对各个学校是一样的，
//      但有些业务因学校不同而不同，所以比较适合用模板方法模式来实现。

// -----------------------------------------------------------------
// 抽象类：出国留学
class StudyAbroad {
 public:
  StudyAbroad() = default;
  virtual ~StudyAbroad() = default;
  void TemplateMethod();  // 模板方法
  void ApplyForPassort();
  void ApplyForVisa();
  void ReadyGoAbroad();
  virtual void LookingForSchool() = 0;
  virtual void ApplyForEnroll() = 0;
  virtual void Arriving() = 0;
};

// -----------------------------------------------------------------
// 具体子类：美国留学
class StudyInAmerica : public StudyAbroad {
 public:
  StudyInAmerica() = default;
  virtual ~StudyInAmerica() = default;
  void LookingForSchool() override;
  void ApplyForEnroll() override;
  void Arriving() override;
};