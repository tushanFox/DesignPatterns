/**
 */
package main

import "fmt"

func main() {
	proxy := &Proxy{
		realSubject: &RealSubject{},
	}
	fmt.Println(proxy.Request())
}
