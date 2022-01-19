/**
 * @file bridge.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 桥接模式
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include "bridge.h"
#include <iostream>

// -----------------------------------------------------------------
// 站内消息发送
void MessageSMS::Send(std::string &message, std::string &to_user) {
  std::cout << "MessageSMS, send " << message << " to " << to_user << std::endl;
}

// Email发送
void MessageEmail::Send(std::string &message, std::string &to_user) {
  std::cout << "MessageEmail, send " << message << " to " << to_user << std::endl;
}

// 手机短信发送
void MessageMobile::Send(std::string &message, std::string &to_user) {
  std::cout << "MessageMobile, send " << message << " to " << to_user << std::endl;
}

// -----------------------------------------------------------------
// 加急消息
void UrgencyMessage::SendMessage(std::string &message, std::string &to_user) {
  message = "Urgency: " + message;
  AbstractMessage::SendMessage(message, to_user);
}

// 特急消息
void SpecialUrgencyMessage::Hurry(std::string message_id) {
  // 发送催促信息
}
void SpecialUrgencyMessage::SendMessage(std::string &message, std::string &to_user) {
  message = "SpecialUrgency: " + message;
  AbstractMessage::SendMessage(message, to_user);
}