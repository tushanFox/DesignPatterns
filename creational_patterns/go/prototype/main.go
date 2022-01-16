/**
 */
package main

func main() {
	var order OrderIntf
	perOrder := new(PersonalOrder)
	perOrder.SetOrderId("order id1")
	perOrder.SetProductNum(200)
	perOrder.SetCustomerName("Tom")
	order = perOrder.Clone()
	order.ShowOrder()

	entOrder := new(EnterpriseOrder)
	entOrder.SetOrderId("order id2")
	entOrder.SetProductNum(300)
	entOrder.SetEnterpriseName("Google")
	order = entOrder.Clone()
	order.ShowOrder()
}
