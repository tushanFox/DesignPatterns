/**
 */
package main

func main() {
	var imp MessageImplementor
	var msg AbstractMessage
	// -----------------------------------------------------------------
	// 创建具体的实现结构体
	imp = &MessageSMS{}
	// 创建一个普通消息结构体
	msg = &CommonMessage{
		impl: imp,
	}
	msg.SendMessage("aaaaaa", "zhangsan")

	// 创建一个紧急消息结构体
	msg = &UrgencyMessage{
		impl: imp,
	}
	msg.SendMessage("bbbbbb", "lisi")

	// -----------------------------------------------------------------
	// 创建具体的实现结构体
	imp = &MessageEmail{}
	// 创建一个紧急消息结构体
	msg = &UrgencyMessage{
		impl: imp,
	}
	msg.SendMessage("cccccc", "wangwu")

	// -----------------------------------------------------------------
	// 创建具体的实现结构体
	imp = &MessageMobile{}
	// 创建一个特急消息结构体
	msg = &SpecialUrgencyMessage{
		impl: imp,
	}
	msg.SendMessage("dddddd", "zhaoliu")
}
