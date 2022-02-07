/**
 */
package main

func main() {
	// 创建一个报纸，作为被观察者
	subject := new(NewsPaper)

	// 创建阅读者，即观察者
	rd1 := new(Reader)
	rd1.SetName("zhangsan")

	rd2 := new(Reader)
	rd2.SetName("lisi")

	rd3 := new(Reader)
	rd3.SetName("wangwu")

	// 注册阅读者
	subject.Attach(rd1)
	subject.Attach(rd2)
	subject.Attach(rd3)

	// 出新一期报纸
	subject.SetContent("hahahah")
}
