#include "order.h"
using namespace std;
int main() {
  PersonalOrder *per_order = new PersonalOrder();
  per_order->SetOrderId("order id1");
  per_order->SetProductNum(200);
  per_order->SetCustomerName("Tom");
  OrderIntf *order = per_order->Clone();
  order->ShowOrder();

  EnterpriseOrder *ent_order = new EnterpriseOrder();
  ent_order->SetOrderId("order id2");
  ent_order->SetProductNum(300);
  ent_order->SetEnterpriseName("Google");
  order = ent_order->Clone();
  order->ShowOrder();
  return 0;
}