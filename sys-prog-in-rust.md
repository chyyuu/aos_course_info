# 用RUST进行系统编程的自学资源

#### 7~21天内高效学习 Rust 建议：
前提条件： 要求有基本数据结构，算法基础，相对了解或熟悉C/C++/Java等编程.

1. 通过阅读和练习 [《 Rust by Example 》](https://doc.rust-lang.org/rust-by-example/)) 等，全面梳理一遍 Rust 语法。期间可参考书目：（《Programming Rust》、《Rust权威指南》（即官方 Rust Book 中译本）、《Rust编程之道》第二章 、《深入浅出 Rust》等）。（2~6天）
2. 重点阅读《Rust 编程之道》 （第三、四、五章，理解类型系统和所有权；第九章，理解错误处理； 第十三章，理解Unsafe Rust） （1~3天）
3. 完成《Rust 编程之道》第十章的完整示例代码，掌握Cargo和模块系统。（1~3天）
4. 尝试完成编程小练习和中等规模练习，在实践中反复学习。（3~9天）

#### 自学材料和练习要求: 
1. 自学：阅读书籍

1.1 编程学习类书籍/文档
 - [Learn X in Y minutes Where X=Rust](https://learnxinyminutes.com/docs/rust/)
 - [Rust 程序设计语言 简体中文版](https://kaisery.github.io/trpl-zh-cn/) 
 - [通过例子学 Rust](https://rust-by-example.budshome.com/)
 - [RUST编程之道](https://item.jd.com/12479415.html)
   - [《Rust编程之道》随书源码](https://ruststudy.github.io/tao_of_rust_docs/tao_of_rust/)
 - [深入浅出Rust](https://item.jd.com/12429296.html)
 - [easy rust: simple textbook](https://github.com/Dhghomon/easy_rust)
 - [Rust 的绅士(温柔)介绍](http://llever.com/gentle-intro/1-basics.zh.html)
 - [Rust Cookbook 中文版](https://rust-cookbook.budshome.com/intro.html#rust-cookbook-%E4%B8%AD%E6%96%87%E7%89%88)
   - [Rust Cookbook-eng](https://rust-lang-nursery.github.io/rust-cookbook/intro.html)
 - [Programming Rust](https://www.oreilly.com/library/view/programming-rust/9781491927274/) 在讲解中与python, C/C++等进行了对比，对理解Rust的ownership,生命周期等有帮助
   - [中文版：Rust程序设计](https://www.ituring.com.cn/book/2101)
 - [A Guide to Porting C/C++ to Rust](https://locka99.gitbooks.io/a-guide-to-porting-c-to-rust/content/)
 - [Rust Design Patterns](https://rust-unofficial.github.io/patterns/)
 - [HARD: The Rustonomicon ](https://doc.rust-lang.org/nomicon/)
   - [难: The Rustonomicon 中文版：Rust 高级编程](https://learnku.com/docs/nomicon/2018) 
 - [Rust相关书籍信息大全](https://github.com/sger/RustBooks)
 - [难: Learn Rust With Entirely Too Many Linked Lists](https://rust-unofficial.github.io/too-many-lists/)
   - [《Learn Rust With Entirely Too Many Linked Lists》的学习源码](https://github.com/anonymousGiga/Rust-link-list)
   - [视频地址](https://www.bilibili.com/video/BV1eb4y1Q7FA)
 - [Things you can’t do in Rust (and what to do instead)](https://blog.logrocket.com/what-you-cant-do-in-rust-and-what-to-do-instead/)
 - [24 days from node.js to Rust](https://vino.dev/blog/node-to-rust-day-1-rustup/)
 - [Rust语言圣经(Rust教程 Rust Course)](https://course.rs/)
1.2 参考和汇总类
- [Rust Design Patterns](https://rust-unofficial.github.io/patterns/) ：各种常用编程模式的代码片段
- [cargo book 中文](http://llever.com/cargo-book-zh/) ：各种小应用（与系统类访问相关）的参考实现
- [Rust Reference中文版](https://minstrel1977.gitee.io/rust-reference/)：Rust的语言描述
   - [Rust Reference-eng](https://doc.rust-lang.org/stable/reference/)
 - [Rust Language Cheat Sheet](https://cheats.rs/)：Rust语言特性的快速查找
 - [Rust Compiler Error Index](https://doc.rust-lang.org/error-index.html)：rustc编译错误的详细描述和修改提示
 - [Rust Learning 各种信息汇总](https://github.com/ctjhoa/rust-learning)：相关学习资料汇总（英文）
 - [Rust学习资源](https://zhuanlan.zhihu.com/p/273653469)：相关学习资料汇总（中文）
 - [Rust 语言术语中英文对照表](https://github.com/rust-lang-cn/english-chinese-glossary-of-rust/blob/master/rust-glossary.md)
 - [awesome-rust：About A curated list of Rust code and resources. in rustcc](https://github.com/rustcc/awesome-rust)
 - [Awesome Rust in rust-unoffical](https://github.com/rust-unofficial/awesome-rust)

2. 自学：在线课程/教程

2.1 初级：学习Rust语言

 - [中文：Rust编程视频教程（基础）--令狐壹冲](https://www.bilibili.com/video/BV1xJ411B79h?from=search&seid=11418904650629340673)
 - [中文：Rust编程视频教程（进阶）--令狐壹冲](https://www.bilibili.com/video/BV1FJ411Y71o?from=search&seid=11418904650629340673)
 - [Tour of Rust](https://tourofrust.com/)
 - [英文：CIS 198: Rust Programming: University of Pennsylvania:2016](http://cis198-2016s.github.io/schedule/)
 - [英文：CS 110L: Safety in Systems Programming : spring 2020](https://reberhardt.com/cs110l/spring-2020/)
   - [bilibili镜像+中文字幕: CS 110L: Safety in Systems Programming : spring 2020](https://www.bilibili.com/video/BV1Ra411A7kN?from=search&seid=6146651326062502685)

2.2 中级：如何用Rust写系统程序
 - [中文课程和作业笔记](https://pxiaoer.blog/category/rust/cs110l/)
 - [相关信息收集in github](https://github.com/xxg1413/CS110L)

3. 自学：编程练习

3.1 初级编程：小练习题

 - [Small exercises to get you used to reading and writing Rust code!](https://github.com/rust-lang/rustlings)
   
   - 要求：小练习全部通过。代码和README提交在自己在github的公开repo上。
 - [32 Rust Quizes](https://dtolnay.github.io/rust-quiz/1)
   
   - 要求：小练习全部通过。
   
 - [ Rust语言学习笔记和小练习](https://github.com/lesterli/rust-practice)

 - [exercisms.io 快速练习(88+道题目的中文详细描述)](http://llever.com/exercism-rust-zh/index.html)
   - 要求：大部分练习会做或能读懂。
   - [exercism.io官方站点](https://exercism.io/)

3.2 中级编程：100行左右的中小练习题

基于笨办法学C/python/ruby的书籍和例子，要求用rust语言重新实现15道以上的编程练习题
 - 参考[Learn C The Hard Way 中文版](https://docs.kilvn.com/lcthw-zh/)
   - [C语言练习题实现](https://github.com/zedshaw/learn-c-the-hard-way-lectures)
 - 参考[Learn Python 3 The Hard Way 视屏](https://www.bilibili.com/video/av25675370?from=search&seid=15962373731896636968)
   - [LP3THW英文版和code](https://github.com/cnR1ce/Learn-Python-3-the-Hard-Way)
   - [python3语言练习题实现](https://github.com/zedshaw/learn-python3-thw-code)
 - 参考[Learn Ruby The Hard Way 中文版](http://lrthw.github.io/)
   - [ruby语言练习题实现](https://github.com/lancelakey/lrthw)
 - (进阶，可选）[Algorithm in Rust](https://github.com/TianyiShi2001/Algorithms): 基于Rust语言的经典算法，看看自己能否做出来
 - 要求：用rust语言编写完成某本“笨办法学（选择一种你熟悉的编程语言）”书中描述的题目中的15道以上的题目。代码和README提交在自己在github的公开repo上。
 - 如果不选择“笨办法系列”，可以选择类似Leecode的题目，用Rust实现，但需要在README中给出题目的出处和相关描述信息，并给出采用Rust语言和非Rust语言的实现代码。

3.3 中高级编程：能阅读和编写上百行的程序
 - 基本掌握RUST编程，能理解下面的rCore tutorial中的文档和代码。
 - (进阶，可选）[BOOK:Rust in Action](https://www.manning.com/books/rust-in-action): 基于Rust语言的中小软件项目，看看自己能否做出来
   - [Rust in Action source code](https://github.com/rust-in-action/code)
