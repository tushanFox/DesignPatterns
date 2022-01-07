/**
 * @file singleton.go
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 单例模式
 * @version 0.1
 * @date 2022-01-07
 *
 * @copyright Copyright (c) 2022
 *
 */
package main

import (
	"sync"
)

type Singleton struct {
	value int
}

//  一种实现
var instance *Singleton
var once sync.Once

func GetInstance() *Singleton {
	once.Do(func() {
		instance = &Singleton{}
	})
	return instance
}

// 另一种实现
var instance1 *Singleton
var mutex sync.Mutex

func GetInstance1() *Singleton {
	if instance1 == nil {
		mutex.Lock()
		defer mutex.Unlock()
		if instance1 == nil {
			instance1 = &Singleton{}
		}
	}
	return instance1
}

// 公共函数
func (s *Singleton) SetValue(v int) {
	s.value = v
}

func (s *Singleton) GetValue() int {
	return s.value
}
