/**
 * @file bridge.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 桥接模式
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#pragma once

// 一个发送消息的模块，发送的消息类型有：普通消息、加急消息、特急消息，发送消息的方式有：站内信息、Email、手机短信。
// 通过桥接模式实现该功能，抽象部分为消息类型，实现部分为发送方式。

#include <string>
// -----------------------------------------------------------------
// 实现化角色：消息发送方式
class MessageImplementor {
 public:
  MessageImplementor() = default;
  virtual ~MessageImplementor() = default;

  /**
   * @brief 发送消息
   *
   * @param message 待发送的消息内容
   * @param to_user 消息接收者
   */
  virtual void Send(std::string &message, std::string &to_user) = 0;
};

// -----------------------------------------------------------------
// 抽象化角色：消息类型
class AbstractMessage {
 public:
  AbstractMessage(MessageImplementor *impl) : impl_(impl) {}
  virtual ~AbstractMessage() = default;

  /**
   * @brief 发送消息，调用实现部分的方法
   *
   * @param message 待发送的消息内容
   * @param to_user 消息接收者
   */
  virtual void SendMessage(std::string &message, std::string &to_user) { impl_->Send(message, to_user); }

 protected:
  MessageImplementor *impl_;
};

// -----------------------------------------------------------------
// 具体实现化角色
// 站内消息发送
class MessageSMS : public MessageImplementor {
  void Send(std::string &message, std::string &to_user) override;
};

// Email发送
class MessageEmail : public MessageImplementor {
  void Send(std::string &message, std::string &to_user) override;
};

// 手机短信发送
class MessageMobile : public MessageImplementor {
  void Send(std::string &message, std::string &to_user) override;
};

// -----------------------------------------------------------------
// 扩展抽象化角色
// 普通消息
class CommonMessage : public AbstractMessage {
 public:
  CommonMessage(MessageImplementor *impl) : AbstractMessage(impl) {}
  // 对于普通消息，没有别的额外动作，直接调用基类的函数发送消息即可
  void SendMessage(std::string &message, std::string &to_user) override {
    AbstractMessage::SendMessage(message, to_user);
  }
};

// 加急消息
class UrgencyMessage : public AbstractMessage {
 public:
  UrgencyMessage(MessageImplementor *impl) : AbstractMessage(impl) {}

  void SendMessage(std::string &message, std::string &to_user) override;
};

// 特急消息
class SpecialUrgencyMessage : public AbstractMessage {
 public:
  SpecialUrgencyMessage(MessageImplementor *impl) : AbstractMessage(impl) {}

  void Hurry(std::string message_id);
  void SendMessage(std::string &message, std::string &to_user) override;
};