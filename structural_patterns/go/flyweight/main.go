/**
 */
package main

func main() {
	ff := new(FlyweightFactory)
	f1 := ff.GetFlyweight("aaa")
	f1.Operation("20")

	f2 := ff.GetFlyweight("bbb")
	f2.Operation("19")

	f3 := new(UnsharedConcreteFlyweight)
	f3.Operation("18")
}
