/**
 */
package main

func main() {
	var strategy Strategy
	var ctx PriceContext
	strategy = new(OrdinaryCustomerStrategy)
	ctx = PriceContext{
		strategy: strategy,
	}
	ctx.Quote(1000)

	strategy = new(RegularCustomerStrategy)
	ctx = PriceContext{
		strategy: strategy,
	}
	ctx.Quote(1000)

	strategy = new(BigCustomerStrategy)
	ctx = PriceContext{
		strategy: strategy,
	}
	ctx.Quote(1000)
}
