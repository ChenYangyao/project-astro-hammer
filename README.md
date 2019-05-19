# Astro Hammer - 天文方法、技术与软件分享

## About

### 这个库是用来干嘛的？

THCA星系与宇宙学研究组的同学们发现：“十年磨一剑，磨个稀巴烂”。对于一个刚刚入门天文学研究的新手来讲，掌握更多的小技能能够帮助自己更好地在这个残酷的领域生存下去；而闭门造轮则往往会事倍功半。因此，我们决定定期地组织一些小讲座，来分享自己在天文学研究上的方法、技术与软件工具，希望借此来拉动整个团队的作战能力。而这个git仓库则用来存储讲座的计划、讲义和相关的资源，也用来搜集同学们的意见和建议。

### 讲座如何组织？

我们的讲座具有**高度的自由性**和**彻底的公益性**。讲座的组织是不定期的（因为大家已经被沉重的科研和课业包袱压得喘不过气来）：任何同学，只要准备好了讲座的内容，都可以进行讲座。参与也是完全自愿的：如果对讲座内容感兴趣，就可以来参加。

讲座人和参加者需要提前向王凯（wk17@mails.tsinghua.edu.cn）或者陈洋遥同学（yangyao-17@mails.tsinghua.edu.cn）报名。这两个家伙会负责来根据报名人数和设备要求预约场地、确定时间和讲座形式。一般来讲，我们的讲座会在蒙民伟科技楼南楼得某个房间进行，时间周期为一年（也就是说，每年会将所有内容重新轮一次。我们希望，每个新加入我们团体的同学，都能够从我们的活动中受益，也能有机会将自己的经验分享给大家）。

## 资源

### Lectures
**Lecture 1： Git仓库的使用和Github代码管理**

时间 | 地点 | 讲座人 | 讲座资源
---|---|---|---
2018年9月9日 | 蒙民伟科技楼南楼-S327 | 王凯（wk17@mails.tsinghua.edu.cn）| 讲义: [[PPT]](./lectures/lecture1-git-and-github/src/slides.pdf)

Git仓库是对自己代码版本管理的好工具，而Github则可以在线分享与发布自己的代码。在这一讲中，我们介绍了
* Git仓库的建立、版本的更新与回退。
* Git仓库的分支管理。
* 远程仓库的使用和代码同步。
* 多人合作的工作模式。

**Lecture 2: Statistical Learning in a Nutshell**
时间 | 地点 | 讲座人 | 讲座资源
--- | --- | --- | ---
2019年5月16日 | 蒙民伟科技楼南楼-S727 | 陈洋遥（yangyao-17@mails.tsinghua.edu.cn）| 讲义：[[PPT]](./lectures/lecture2-statistical-learning-in-a-nutshell/src/slides.pdf)

统计学习是科研工作中分析数据、建立模型、理解数据中蕴含的科学的必要工具。在这一讲中，我们为大家介绍
* 统计学习在天文学中的一些应用举例（光谱红移测定、星系分类、密度场重构）
* 统计学习的定义（什么是AI，什么是ML，什么是NN，它们之间的关系是什么？）
* 统计学习建模的基本流程
* 统计学习建模中最重要的几个关键点和它们的处理方法：the bias variance trade-off， the prediction-interpretability trade-off， non-linearity， goodness of fitting and model selection。

本次讲座的目的是希望大家对于统计学习的基本框架有所了解（而不是拘泥于具体的算法细节），这将为今后进一步介绍统计学习的理论、算法、应用打下基础。

### Lecture Series Under Preparing

**Series 1：Python编程技术简介和Python科学计算库的使用** （负责人：王凯）

Topic 1: Python编程基础

* Python基本语法和类型

    在这一小节中，我会简单讲述一下Python的基本语法和内置类型；Python作为面向对象语言的相关语法知识；Python对函数式编程的支持、闭包和装饰器；Python内部的资源管理机制和垃圾回收机制。

* Python编程风格

    在这一小节中，我会主要讲解一些Python语言特有的编程风格，比如文档化，package和module的相关知识。

Topic 2: Python实用工具
 
* Python实用工具（非数据处理）

    这一小节主要讲解Python的一些实用的工具，如profile工具，logging包等。
    
* Python实用工具（数据处理）
   
   这一小节主要讲解Python中一些常用的数据包，如numpy, pandas, matplotlib等
  
**Series 2：程序设计和软件开发基础** （负责人：陈洋遥）

Topic 1: 如何编写高效、安全和对用户友好的程序 - 面向对象的程序设计基础、算法与接口设计
* 面向对象的程序（OOP）设计基础 - 高效性、安全性和用户友好性的基石
    
    在这一小节中，我会通过几个天文研究中常见的例子来展示OOP的必要性，来说明：（1）通过对象方法与成员的交互，才能实现计算的高效。（2）通过数据的独立性以及合理的开放与封闭策略，才能保证程序设计的安全性。（3）通过利用对象的接口，才能使得用户更方便地使用程序。

* 算法（Algorithm） - 如何实现程序的高效性
  
    在任何程序设计语言中，算法都是实现程序高效性的直接来源。我们会介绍主要的单线程、内存计算环境下的数据结构和算法。主要包括：线性结构与算法（排序，索引/slab），tree结构与算法（查找算法，堆算法，等价类和并查集），图结构和算法（最小生成树，最短路径），散列结构和冲突避免技术（hash表，典型的近邻查找算法）。

    我们会通过天文学里面的几个常见的例子来展示算法对提高程序效率的重要作用：（1）FOF算法的实现（2）两点关联函数的计算（3）多维空间的模板参数匹配，

* 故障检测与恢复（Debug） - 如何保证程序的鲁棒性 
    
    一个经常出bug的程序是没人愿意用的，而一个出了bug却无法定位bug所在的程序是自己都不愿意用的。在这一节讲座中，我们会介绍：参数类型检测与值检测，异常类的层次、抛出与捕获，算法进度跟踪以及log系统的设计和使用。

* 良好的接口设计（Interface Designing） - 如何设计对用户友好的程序
    
    良好的接口设计有利于更高效的编写调用这些接口的程序。这一节讲座中，我们会介绍：接口与实现分离的策略，继承、包含和接口组合机制。

Topic 2：如何编写更高效的程序 - 并行编程计算导论
    
* 并行技术基础

    任何并行计算都依赖于硬件和操作系统提供的环境。因而，对硬件和操作系统的基本了解是并行程序设计的基础。我们将介绍：（1）多核系统的基本构架，（2）操作系统中进程/线程的内存映像，（3）进程的调度机制，（4）进程/线程间数据共享的机制（signal、pipe and FIFO、message queue、semaphore、shared memory object和memory mapping），（5）进程/线程间的互斥与同步机制（signal、pipe、semaphore、mutex、file lock、transaction）。
    
    我们将通过具体的例子来介绍并行算法设计的特点和方法（进程/线程的启动与join/detach/wait，同步与互斥机制，任务分配与均衡，数据共享和进程通信）。

* 并行控制协议和软件简介

    并行程序设计依赖于操作系统提供的并行控制协议和软件。我们将介绍（1）linux系统下的线程间共享内存的并发控制协议（POSIX thread接口），（2）进程间并发控制技术（消息传递、共享内存和同步机制以及System V和POSIX接口）。这些基本的技术允许我们对并行程序以及它们之间的相互作用提供细粒度的控制。
    
    一些高级的协议和接口，允许我们更方便的利用并行环境。我们将介绍两个高级的接口：（1）OpenMP-共享内存的并发技术，（2）MPI-消息传递接口。这些高级接口使用更加方便，允许我们对并发程序进行粗粒度的控制。

Topic 3：如何展示和发布自己的软件 - web开发的原理和应用

展示自己的工作有时甚至比完成一项工作更加重要。互联网技术的发展为我们展示自己的工作（不仅仅是软件）提供了便利。我们将要在这里介绍web应用开发的原理和应用，包括：前端设计与开发（HTML5，CSS和JavaScript），后端环境的搭建与开发（PHP和MYSQL）。

**Series 3: 统计（机器）学习理论与应用**（我们缺少一个志愿者）





