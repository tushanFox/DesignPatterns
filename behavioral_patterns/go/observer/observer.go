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
package main

import "fmt"

// 案例：读者向报社订阅报纸，符合观察者模式使用场景
// 读者(订阅者)是观察者；报纸是被观察者

// -----------------------------------------------------------------
// 抽象目标，抽象被观察者
type Subject interface {
	/**
	 * @brief 报纸的读者需要向报社订阅，先得注册
	 *
	 * @param reader 报纸的读者
	 */
	Attach(reader Observer)

	/**
	 * @brief 报纸的读者可以取消订阅
	 *
	 * @param reader 报纸的读者
	 */
	Detach(reader Observer)

	/**
	 * @brief 报纸被印刷出来后，要迅速送到读者手中，相当于通知读者(观察者)
	 *
	 */
	NotifyObservers()

	GetContent() string        // 读取报纸内容
	SetContent(content string) // 设置报纸内容
}

// -----------------------------------------------------------------
// 具体目标，报纸
type NewsPaper struct {
	readers []Observer // 报纸的订阅者(观察者)
	content string     // 报纸的内容
}

func (n *NewsPaper) Attach(reader Observer) {
	n.readers = append(n.readers, reader)
}

func (n *NewsPaper) Detach(reader Observer) {
	for i, v := range n.readers {
		if v == reader {
			n.readers = append(n.readers[0:i], n.readers[i+1:]...)
			return
		}
	}
	return
}

func (n *NewsPaper) NotifyObservers() {
	for _, v := range n.readers {
		v.Update(n)
	}
}

func (n *NewsPaper) GetContent() string {
	return n.content
}

func (n *NewsPaper) SetContent(content string) {
	n.content = content
	n.NotifyObservers()
}

// -----------------------------------------------------------------
// 抽象观察者
type Observer interface {
	Update(subject Subject)
}

// -----------------------------------------------------------------
// 具体观察者，报纸的读者
type Reader struct {
	name string
}

func (r *Reader) Update(subject Subject) {
	fmt.Println(r.name, "received a newspaper. The content is ", subject.GetContent())
}

func (r *Reader) GetName() string {
	return r.name
}

func (r *Reader) SetName(name string) {
	r.name = name
}
