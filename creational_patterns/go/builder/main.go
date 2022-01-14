/**
 */
package main

func main() {
	var builder BuilderInterface
	var dir Director
	builder = new(Brand1Builder) // brand1
	car := dir.Create(builder)
	car.Show()

	builder = new(Brand2Builder) // brand2
	car = dir.Create(builder)
	car.Show()
}
