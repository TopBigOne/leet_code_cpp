```shell
clang++ -std=c++17  -g main.cpp -o main
```

```shell
sudo ./main
```


* lldb * 启动方式 1
```shell
lldb main
```

* lldb * 启动方式 2
```shell
lldb 
file main
```


----
## list 查看源码
* list [10] ，显示10行代码
```shell
list  10 
```
* list [函数名称] 
```shell
list pivotIndex
```


## 设置断点
### 函数名设置断点
* breakpoint set --name [函数名] 可设置断点
* 设置断点后，再执行run,可见程序已经停在了函数的入口处
```shell
breakpoint  set --name pivotIndex
```
### 行号设置断点
* breakpoint set --line [行号] s设置断点. 下面演示了在当前文件的第8行设置断点。且断点序号为3
```shell
(lldb) breakpoint set --line 8

```
### 根据文件名设置断
* breakpoint set --file [文件名] --line [行号]
```shell
(lldb) breakpoint set --file car.hpp --line 17

```
### 删除所有断点
* breakpoint delete可删除所有断点，并提示确认 。
```shell
(lldb) breakpoint delete
About to delete all breakpoints, do you want to do that?: [Y/n] 

```
### 删除某个断点
* 断点列表
```shell
(lldb) breakpoint list
```
* breakpoint delete [断点序号] 可删除指定断点。 下面删除序号为2的断点和删除后的断点列表
```shell
breakpoint delete 2
```
* breakpoint delete [n-m] 可删除从 序号n到序号m之间的断点。一个例子
```shell
(lldb) breakpoint delete 3-4
```
* breakpoint delete [序号1] [序号2] [序号3]..... 可删除多个断点。 删除多个不连续断点
```shell
breakpoint delete 5 7 8
```
## run 命令可以让程序运行起来。
## next 下一步
* 使用 next or n 可以单步执行
## step 步入
* 使用 step or s 步入 函数。
## finish 跳出

* 使用 finish 跳出，返回步入的地方
### p和po输出变量
* 使用p [变量名] 可以查看变量的值。
* 使用 po [指针变量名] 可以查看其值
### frame查看变量值
* 使用frame variable 可以查看当前frame中的所有value
### expression 修改变量值
* 使用expression [变量名]=[value]可以修改变量的值
* expression ret=10.
