# 抽象工厂模式

抽象工厂模式与工厂方法模式的区别：前者的抽象工厂有多个方法，可以生产一系列相关或相互依赖的抽象产品；后者的抽象工厂只有一个方法，只能生产一个抽象产品。<br/>
go中不存在继承，所以使用匿名组合来实现<br/>
