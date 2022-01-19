#include <string>
#include "bridge.h"
using namespace std;
int main() {
  // 创建具体的实现类
  MessageImplementor *impl = new MessageSMS();

  // 创建一个普通消息对象
  AbstractMessage *msg = new CommonMessage(impl);
  string message = "111111";
  string user = "zhangsan";
  msg->SendMessage(message, user);
  delete msg;

  // 创建一个紧急消息对象
  msg = new UrgencyMessage(impl);
  message = "222222";
  user = "lisi";
  msg->SendMessage(message, user);
  delete msg;

  // -----------------------------------------------------------------
  // 创建具体的实现类
  impl = new MessageEmail();
  // 创建一个紧急消息对象
  msg = new UrgencyMessage(impl);
  message = "333333";
  user = "wangwu";
  msg->SendMessage(message, user);
  delete msg;
  delete impl;

  // -----------------------------------------------------------------
  // 创建具体的实现类
  impl = new MessageMobile();
  // 创建一个特急消息对象
  msg = new SpecialUrgencyMessage(impl);
  message = "444444";
  user = "zhaoliu";
  msg->SendMessage(message, user);
  delete msg;
  delete impl;
  return 0;
}