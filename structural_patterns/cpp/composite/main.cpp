#include <iostream>
#include "composite.h"
using namespace std;
int main() {
  // 定义多个Composite
  Component *root = new Composite("root");
  Component *c1 = new Composite("c1");
  Component *c2 = new Composite("c2");

  // 定义多个Leaf
  Component *leaf1 = new Leaf("leaf1");
  Component *leaf2 = new Leaf("leaf2");
  Component *leaf3 = new Leaf("leaf3");

  // 组合成树形结构
  root->AddChild(c1);
  root->AddChild(c2);
  root->AddChild(leaf1);
  c1->AddChild(leaf2);
  c1->AddChild(leaf3);

  // 操作Component
  Component *c = root->GetChildren(0);
  c->Operation();
  cout << "------------------------" << endl;

  c = root->GetChildren(1);
  c->Operation();
  cout << "------------------------" << endl;

  c = c1->GetChildren(0);
  c->Operation();
  return 0;
}
