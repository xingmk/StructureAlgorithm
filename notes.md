# 数据
- 能输入计算机且被计算机处理的各种符号的集合

- 数值型的数据：整数 实数
- 非数值型的数据：文字 图像 图形 声音...

# 数据元素
- 是数据的基本单位 在计算机程序中通常作为一个整体进行考虑和处理

- 也称：元素 记录 结点 顶点

# 数据项
- 构成数据元素的不可分割的最小单位


> 数据 --》数据元素 --》数据项

# 数据对象
- 性质相同的数据元素的集合 是数据的一个子集


# 逻辑结构的种类
 
 1）线性结构
    有且仅有一个开始和一个终端节点，且所有结点都最多只有一个直接前趋和一个直接后继

 2）非线性结构
    一个结点可能有多个前趋和直接后继

# 存储结构
- 顺序存储结构：
    用一组连续的存储单元依次存储数据元素，数据元素之间的逻辑关系由元素的存储位置来表示  

- 链接存储结构
    - 用一组任意的存储单元存储数据元素，数据元素之间的逻辑关系用指针来表示   
    - C中用指针来实现  


# 数据类型
- 作用：
    - 约束变量或常量的 取值范围  
    - 约束变量或常量的 操作  

- 定义：
    数据类型是一组性质相同的值的集合以及定义与这个值集合上的一组操作的总称

数据类型 = 值的集合 + 值集合上的一组操作 

# 抽象数据类型(Abstract Data Type, ADT)：
    一个数学模型以及定义在数学模型上的一组操作

## 抽象数据类型的形式定义

>  抽象数据类型可用(D, S, P) **三元组** 表示
>  D --> 数据对象
>  S --> D上的关系集合
>  P --> 对D的基本操作集

## 抽象数据类型的定义格式：

```
ADT  抽象数据类型名{
    数据对象：<数据对象的定义>
    数据关系：<数据关系的定义>
    基本操作：<基本操作的定义>
}
```

- 基本操作的定义格式
    - 基本操作名 （参数表）
    - 初始条件 （初始条件描述）
    - 操作结果 （操作结果描述）

Example：
```
ADT Circle{
    数据对象： D={r,x,y| r,x,y 均为实数}
    数据关系： R={< r,x,y > | r是半径，<x,y>是圆心坐标}
    基本操作：
    Circle(&C,r,x,y)
        操作结果： 构造一个圆.
    double Area(C)
        初始条件：圆已经存在
        操作结果：计算面积
    double Circumference(C)
        初始条件：圆已经存在
        操作结果：计算周长
      ...
}ADT Circle

```

# 抽象数据类型的实现

```C
#include <stdio.h>

typedef struct{
    float realpaet;  # 实部
    float imagpaet;  # 虚部
}Complex
    
void assign(Complex *A, float real, float imag );
void add(Complex *A, float real, float imag);
void minus(Complex *A, float real, float imag);
void multiply(Complex *A, float real, float imag);
void divide(Complex *A, float real, float imag);
    

void assign(Complex *A, float real, float imag ){
    A-> realpart = real;
    A-> imagpaet = imag
}

void add(Complex *c, Complex A, Complex B){
   c-> realpart = A.realpart + B.realpart;
   c-> imagpart = A.imagpaet + B.imagpaet;
}

void mian(){
    Complex z1,z2,z3,z4,z;
    float RealPart,ImagPart;

    assign(z1,8.0,6.0);   // 构造复数z1
    assign(z2,8.0,6.0);   // 构造复数z2
    add(z1,z2,z3)            // 相加
    multiply(z1,z2,z4)       // 相乘

    if(divide (z4,z3,z)){
        GetReal (z, RealPart);
        GetImag (z, ImagPart);
    }
}

```

# 算法

## 算法的特性
    - 有穷性
    - 确定性
    - 可行性
    - 输入
    - 输出

## 算法设计的要求
    - 正确性(Correctness)
    - 可读性(Readability)
    - 健壮性(Robustness)
    - 高效性(Efficiency)
