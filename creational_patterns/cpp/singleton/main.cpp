#include <iostream>
#include "singleton_imp.h"
using namespace std;
int main() {
  S1::GetInstance().SetValue(1);
  cout << "value=" << S1::GetInstance().GetValue() << endl;  // value=1
  // S1 s;  // 编译失败


  S2::GetInstance().SetValue(2);
  cout << "value=" << S2::GetInstance().GetValue() << endl;  // value=2

  S2 s;  // s本身是一个S2类型的对象，然后同时持有一个S2单例对象
  cout << "value=" << s.GetInstance().GetValue() << endl;  // value=2，与前面通过类名访问的结果一样
  cout << "value=" << s.GetValue() << endl;  // value=0
  return 0;
}