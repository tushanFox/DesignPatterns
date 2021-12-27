/**
*/
package main
import (
	"fmt"
)
func main() {
	var op Operation
	var factory OperationFactory
	factory = new(AddFactory)
	op = factory.CreateProduct()
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("add result:", op.GetResult())

	factory = new(SubFactory)
	op = factory.CreateProduct()
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("sub result:", op.GetResult())

	factory = new(MulFactory)
	op = factory.CreateProduct()
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("mul result:", op.GetResult())

	factory = new(DivFactory)
	op = factory.CreateProduct()
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("div result:", op.GetResult())
}