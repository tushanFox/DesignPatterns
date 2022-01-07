#include <unistd.h>
#include <iostream>
#include <thread>
#include "singleton_imp.h"
using namespace std;
std::mutex Singleton1::mutex_;
Singleton1 *Singleton1::instance_ = nullptr;
int func1(int v) {
  Singleton1::GetInstance()->SetValue(v);
  return 0;
}
int func2() {
  return Singleton1::GetInstance()->GetValue();
}
int main() {
  S1::GetInstance().SetValue(1);
  cout << "value=" << S1::GetInstance().GetValue() << endl;  // value=1
  // S1 s;  // 编译失败


  S2::GetInstance().SetValue(2);
  cout << "value=" << S2::GetInstance().GetValue() << endl;  // value=2

  S2 s;  // s本身是一个S2类型的对象，然后同时持有一个S2单例对象
  cout << "value=" << s.GetInstance().GetValue() << endl;  // value=2，与前面通过类名访问的结果一样
  cout << "value=" << s.GetValue() << endl;  // value=0

  std::thread t1(func1, 100);
  usleep(1000);
  cout << func2() << endl;
  t1.join();
  return 0;
}