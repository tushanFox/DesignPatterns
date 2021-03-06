## 概念
简单工厂模式是属于创建型模式，又叫做静态工厂方法（Static Factory Method）模式。<br/>
简单工厂模式是由一个工厂对象决定创建出哪一种产品类的实例。<br/>
简单工厂模式是工厂模式家族中最简单实用的模式，可以理解为是不同工厂模式的一个特殊实现。<br/>
值得注意的是，简单工厂模式并不属于23种GOF设计模式之一。但是他是抽象工厂模式，工厂方法模式的基础，并且也有广泛的应用。<br/>
## 实现
简单工厂模式包含的角色：<br/>
&emsp;工厂类角色：用来创建产品<br/>
&emsp;抽象产品类角色：具体产品的抽象<br/>
&emsp;具体产品类角色：工厂创建的对象就是此角色的实例<br/>
## 总结
通过简单工厂模式创建产品，使用者不需要知道具体产品类的名字，只需要知道该具体产品类的参数即可。<br/>
简单工厂模式是违背了开闭原则(对扩展开放，对修改封闭)的。因为当需要新增产品时，就需要修改工厂类。<br/>