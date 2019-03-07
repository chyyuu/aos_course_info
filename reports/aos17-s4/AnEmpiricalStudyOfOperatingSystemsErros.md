# 阅读报告

## 1，主要贡献和创新点

本文研究了Linux操作系统的bugs。不同于之前的研究，本文使用自动化的工具分析多个版本内核源文件中的bug。通过这些数据，本文发现驱动的error比内核其他部分的error要多3到7倍。此外，本文还发现了新的文件比旧的文件error多两倍。且一般一个bug的生命周期为1.8年。本文还研究了bug聚集现象，提出了一个指标来度量这种聚集程度，发现对于block checkor，能发现明显的bug聚集现象。

## 2，文章提出的问题

是否大多数bugs在driver中？

bugs是如何分布的？

bugs通常生命周期多长？

bugs是否聚集？

不同操作系统之间代码质量的比较。

## 3，相关工作

[A census of TANDEM system availability between 1985 and 1990](https://www.researchgate.net/publication/3151587_Gray_J_A_census_of_TANDEM_system_availability_between_1985_and_1990_IEEE_Trans_Reliab_394_409-418)研究了Tandem系统（1985-1990），他们使用人工收集的bug报告来分析造成中断的原因。之后，[Faults, symptoms, and software fault tolerance in the Tandem GUARDIAN90 operating system](http://ieeexplore.ieee.org/document/627304/)研究了Tandem GUARDIAN90一年的内存泄漏数据。

[Quantitative Analysis of Faults and Failures in a Complex Software System](http://www.literateprogramming.com/faults99.pdf)研究了两个连续版本的通信交换机系统。发现大多数faults存在于少部分的文件中。

[Comparing Operating Systems Using Robustness Benchmarks](http://www.cs.cmu.edu/afs/cs.cmu.edu/project/edrc-ballista/www/srds97/preprint.pdf)研究了使用自动化技术的bugs发现，他们使用随机测试来检验error处理的效率。



## 4，结果检验

关于bug在不同模块的数目，通过使用三个伪正例比较低的checker得到简单的统计图表，即能得出bug在不同模块的数目。此外，函数体的增长也会增加bug的数目。

关于bug的分布，文章中先用直方图将所有bug数据和文件数目绘制到一起，之后使用一个对数族分布去拟合这些点，使用卡方检验，发现对于多数分布，只有对数族拟合效果最好，卡方检验p值伪0.79,而对于block checker的数据，拟合得稍微差一些，相反，Yule分布拟合效果好一些。

对于bug生命周期，存在几个问题，由于，可能减短bug的生命周期，此外由于有的在最后考察的版本中的bug还没有得到修复，这部分数据就有可能不能用。文章通过Kaplan-Meier生存分析对bug的生命周期建模，计算出不同checker的得出bug的生命周期。

关于bug是否有聚集性，本文提出一个基于Possion实验的模型，将一个函数是否返回NULL看作是一次抛硬币实验，这样就可以求出各个文件中期望bug数，如果对于一个文件或者模块，它的Chernoff Bound接近于1,则没有聚集性，显然，由文中的图表可以知道这是不可能的。此外，本文还提出一种衡量全局聚集性的度量，并对之进行了计算，发现对于Block checker中的bug表现出很强的聚集性。

## 5，进一步改进

1，由于本文使用的Linux版本比较老，分析新的bug分布以及生存周期还是有一定意义。

2，对于分析的单元，应该有一种度量来选择不同的分析单元，比如chunk和file,对于不同的场景不同的问题，何种分析单元是合适的。

