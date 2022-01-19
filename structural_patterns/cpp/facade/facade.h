/**
 * @file facade.h
 * @author tushanFox (tushanFox@outlook.com)
 * @brief 外观模式
 * @version 0.1
 * @date 2022-01-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <string>
// 假设完成一个功能有多个步骤或者要访问多个子系统，
// 为了客户端使用方便，可以通过外观模式把这些操作统一封装到一个接口里面。

// -----------------------------------------------------------------
// 子系统
class SubSystem1 {
 public:
  std::string Process1() { return "Process1"; }
};

class SubSystem2 {
 public:
  std::string Process2() { return "Process2"; }
};

class SubSystem3 {
 public:
  std::string Process3() { return "Process3"; }
};

// -----------------------------------------------------------------
// 外观
class Facade {
 public:
  std::string Processs() {
    std::string str = sys1.Process1();
    str = str + " | " + sys2.Process2();
    str = str + " | " + sys3.Process3();
    return str;
  }

 private:
  SubSystem1 sys1;
  SubSystem2 sys2;
  SubSystem3 sys3;
};