/**
 * @file flyweight.cpp
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 享元模式
 * @version 0.1
 * @date 2022-01-21
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include "flyweight.h"
#include <iterator>
#include <iostream>

// -----------------------------------------------------------------
/**
 * @brief 获取key对应的享元角色
 * 
 * @param key
 */
Flyweight *FlyweightFactory::GetFlyweight(const std::string &key) {
  // 1. 先从本地缓存查找，是否存在key对应的享元角色
  auto it = fly_map_.find(key);
  if (it != fly_map_.end()) {
    // 2. 如果存在，就返回本地缓存的对象
    return it->second;
  }

  // 3. 如果不存在就创建一个新的Flyweight对象并返回
  Flyweight *fly = new ConcreteFlyweight(key);
  fly_map_[key] = fly;
  return fly;
}