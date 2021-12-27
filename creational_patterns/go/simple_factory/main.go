/**
*/
package main
import (
	"fmt"
)
func main() {
	var op Operation
	factory := new(OperationFactory)
	op = factory.CreateProduct("ADD")
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("add result:", op.GetResult())

	op = factory.CreateProduct("SUB")
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("sub result:", op.GetResult())

	op = factory.CreateProduct("MUL")
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("mul result:", op.GetResult())

	op = factory.CreateProduct("DIV")
	op.SetValue1(100)
	op.SetValue2(200)
	fmt.Println("div result:", op.GetResult())
}