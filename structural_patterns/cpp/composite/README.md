# 组合模式
组合（Composite Pattern）模式的定义：有时又叫作整体-部分（Part-Whole）模式，它是一种将对象组合成树状的层次结构的模式，
用来表示“整体-部分”的关系，使用户对单个对象和组合对象具有一致的访问性，属于结构型设计模式。<br/>
组合模式一般用来描述整体与部分的关系，它将对象组织到树形结构中，顶层的节点被称为根节点，根节点下面可以包含树枝节点和叶子节点，
树枝节点下面又可以包含树枝节点和叶子节点。<br/>

# 优点
组合模式使得客户端代码可以一致地处理单个对象和组合对象，无须关心自己处理的是单个对象，还是组合对象，这简化了客户端代码；<br/>
更容易在组合体内加入新的对象，客户端不会因为加入了新的对象而更改源代码，满足“开闭原则”；<br/>

# 缺点
设计较复杂，客户端需要花更多时间理清类之间的层次关系；<br/>
不容易限制容器中的构件；<br/>
不容易用继承的方法来增加构件的新功能；<br/>

# 角色
组合模式通过引入抽象构件角色，作为树枝构件和叶子构件的父角色，把树枝构件和叶子构件统一起来了。<br/>
&emsp;抽象构件（Component）角色：它的主要作用是为树叶构件和树枝构件声明公共接口，并实现它们的默认行为。<br/>
&emsp;&emsp;在透明式的组合模式中抽象构件还声明访问和管理子类的接口；在安全式的组合模式中不声明访问和管理子类的接口，管理工作由树枝构件完成。（总的抽象类或接口，定义一些通用的方法，比如新增、删除）<br/>
&emsp;树枝构件（Composite）角色 / 中间构件：是组合中的分支节点对象，它有子节点，用于继承和实现抽象构件。它的主要作用是存储和管理子部件，通常包含 Add()、Remove()、GetChild() 等方法。<br/>
&emsp;叶子构件（Leaf）角色：是组合中的叶节点对象，它没有子节点，用于继承或实现抽象构件。<br/>