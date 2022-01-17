/**
 */
package main

func main() {
	var target Target
	adee := &Adaptee{}
	target = &Adapter{
		ade: adee,
	}
	target.Request()
}
