/**
 */
package main

import (
	"fmt"
	"time"
)

func setSingletonValue(v int) {
	s := GetInstance()
	s.SetValue(v)
}

func getSingletonValue() {
	s := GetInstance()
	v := s.GetValue()
	fmt.Println("value=", v)
}

func setSingletonValue1(v int) {
	s := GetInstance1()
	s.SetValue(v)
}

func getSingletonValue1() {
	s := GetInstance1()
	v := s.GetValue()
	fmt.Println("value=", v)
}

func main() {
	go setSingletonValue(100)
	go setSingletonValue1(200)
	time.Sleep(2 * time.Microsecond)
	for i := 0; i < 10; i++ {
		getSingletonValue()  // 返回100
		getSingletonValue1() // 返回200
	}
}
