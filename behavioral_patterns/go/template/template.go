/**
 * @file template.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief
 * @version 0.1
 * @date 2022-01-25
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// 案例：出国留学手续一般经过以下流程：索取学校资料，提出入学申请，办理因私出国护照、出境卡和公证，
//      申请签证，体检、订机票、准备行装，抵达目标学校等，其中有些业务对各个学校是一样的，
//      但有些业务因学校不同而不同，所以比较适合用模板方法模式来实现。

// -----------------------------------------------------------------
// 抽象接口：出国留学
type IStudyAbroad interface {
	ApplyForPassort()
	ApplyForVisa()
	ReadyGoAbroad()
	LookingForSchool()
	ApplyForEnroll()
	Arriving()
}

// 类似于基类
type StudyAbroad struct {
}

func (s *StudyAbroad) ApplyForPassort() {
	fmt.Println("3. apply for passport and notarized certificate")
}

func (s *StudyAbroad) ApplyForVisa() {
	fmt.Println("4. apply for visa")
}

func (s *StudyAbroad) ReadyGoAbroad() {
	fmt.Println("5. ready go abroad")
}

func (s *StudyAbroad) LookingForSchool() {
}

func (s *StudyAbroad) ApplyForEnroll() {
}

func (s *StudyAbroad) Arriving() {
}

// -----------------------------------------------------------------
// 具体子类：美国留学
type StudyInAmerica struct {
	*StudyAbroad
}

func (s *StudyInAmerica) LookingForSchool() {
	fmt.Println("1. looking for America school")
}

func (s *StudyInAmerica) ApplyForEnroll() {
	fmt.Println("2. apply for America enroll")
}

func (s *StudyInAmerica) Arriving() {
	fmt.Println("6. arriving America")
}

// -----------------------------------------------------------------
// 封装具体步骤
func TemplateMethod(isa IStudyAbroad) {
	isa.LookingForSchool() // 获取学校资料
	isa.ApplyForEnroll()   // 入学申请
	isa.ApplyForPassort()  // 办理因私出国护照/出境卡和公证
	isa.ApplyForVisa()     // 申请签证
	isa.ReadyGoAbroad()    // 体检/订机票/准备行装
	isa.Arriving()         // 抵达
}
