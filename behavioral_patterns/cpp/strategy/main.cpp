#include "strategy.h"

int main() {
  Strategy *strategy = new OrdinaryCustomerStrategy();
  PriceContext *ctx = new PriceContext(strategy);
  ctx->Quote(1000);
  delete ctx;
  delete strategy;

  strategy = new RegularCustomerStrategy();
  ctx = new PriceContext(strategy);
  ctx->Quote(1000);
  delete ctx;
  delete strategy;

  strategy = new BigCustomerStrategy();
  ctx = new PriceContext(strategy);
  ctx->Quote(1000);
  delete ctx;
  delete strategy;
  return 0;
}