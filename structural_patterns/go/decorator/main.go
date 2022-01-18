/**
 */
package main

import "fmt"

func main() {
	var c Component
	c = new(ConcreteComponent)
	d1 := &ConcreteDecorator1{
		component: c,
	}
	fmt.Println(d1.Operation())

	d2 := &ConcreteDecorator2{
		component: c,
	}
	fmt.Println(d2.Operation())
}
