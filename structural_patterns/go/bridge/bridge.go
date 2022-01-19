/**
 * @file bridge.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 桥接模式
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import "fmt"

// 一个发送消息的模块，发送的消息类型有：普通消息、加急消息、特急消息，发送消息的方式有：站内信息、Email、手机短信。
// 通过桥接模式实现该功能，抽象部分为消息类型，实现部分为发送方式。

// -----------------------------------------------------------------
// 实现化角色：消息发送方式
type MessageImplementor interface {
	Send(message string, toUser string)
}

// -----------------------------------------------------------------
// 抽象化角色：消息类型
type AbstractMessage interface {
	SendMessage(message string, toUser string)
}

// -----------------------------------------------------------------
// 具体实现化角色
// 站内消息发送
type MessageSMS struct{}

func (m *MessageSMS) Send(message string, toUser string) {
	fmt.Println("MessageSMS, send ", message, " to ", toUser)
}

// Email发送
type MessageEmail struct{}

func (m *MessageEmail) Send(message string, toUser string) {
	fmt.Println("MessageEmail, send ", message, " to ", toUser)
}

// 手机短信发送
type MessageMobile struct{}

func (m *MessageMobile) Send(message string, toUser string) {
	fmt.Println("MessageMobile, send ", message, " to ", toUser)
}

// -----------------------------------------------------------------
// 扩展抽象化角色
// 普通消息
type CommonMessage struct {
	impl MessageImplementor
}

func (c *CommonMessage) SendMessage(message string, toUser string) {
	c.impl.Send(message, toUser)
}

// 加急消息
type UrgencyMessage struct {
	impl MessageImplementor
}

func (c *UrgencyMessage) SendMessage(message string, toUser string) {
	message = " UrgencyMessage, " + message
	c.impl.Send(message, toUser)
}

// 特急消息
type SpecialUrgencyMessage struct {
	impl MessageImplementor
}

func (c *SpecialUrgencyMessage) Hurry() {
	// 发送催促信息
}

func (c *SpecialUrgencyMessage) SendMessage(message string, toUser string) {
	message = " SpecialUrgencyMessage, " + message
	c.impl.Send(message, toUser)
}
