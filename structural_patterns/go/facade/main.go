/**
 */
package main

import "fmt"

func main() {
	var f Facade
	f = Facade{
		sys1: &SubSystem1{},
		sys2: &SubSystem2{},
		sys3: &SubSystem3{},
	}
	fmt.Println(f.Process())
}
