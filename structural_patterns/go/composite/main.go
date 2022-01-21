/**
 */
package main

import "fmt"

func main() {
	// 定义多个Composite
	var root Component
	var c1 Component
	var c2 Component
	root = &Composite{
		childComponents: make([]Component, 0, 4),
		name:            "root",
	}
	c1 = &Composite{
		childComponents: make([]Component, 0, 2),
		name:            "c1",
	}
	c2 = &Composite{
		childComponents: make([]Component, 0, 2),
		name:            "c2",
	}

	// 定义多个Leaf
	var leaf1 Component
	var leaf2 Component
	var leaf3 Component

	leaf1 = &Leaf{
		name: "leaf1",
	}
	leaf2 = &Leaf{
		name: "leaf2",
	}
	leaf3 = &Leaf{
		name: "leaf3",
	}

	// 组合成树形结构
	root.AddChild(c1)
	root.AddChild(c2)
	root.AddChild(leaf1)
	c1.AddChild(leaf2)
	c1.AddChild(leaf3)

	// 操作Component
	c := root.GetChildren(0)
	c.Operation()
	fmt.Println("---------------------------")

	c = root.GetChildren(1)
	c.Operation()

	fmt.Println("---------------------------")
	c = c1.GetChildren(0)
	c.Operation()
}
