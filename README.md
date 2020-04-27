# SemiGlobalMatching
SemiGlobalMatching立体匹配算法，学习SGM C++实现的好资源

# CSDN博客
[手把手教你编写SGM双目立体匹配（基于C++，Github同步更新）（一）（框架与类设计）](https://blog.csdn.net/rs_lys/article/details/105065660)
<br>
[手把手教你编写SGM双目立体匹配（基于C++，Github同步更新）（二）（代价计算）](https://blog.csdn.net/rs_lys/article/details/105142484)
<br>
[手把手教你编写SGM双目立体匹配（基于C++，Github同步更新）（三）（代价聚合）](https://ethanli.blog.csdn.net/article/details/105316274)
<br>
[手把手教你编写SGM双目立体匹配（基于C++，Github同步更新）（四）（代价聚合2）](https://blog.csdn.net/rs_lys/article/details/105396761)
<br>
[手把手教你编写SGM双目立体匹配（基于C++，Github同步更新）（五）（视差优化）](https://blog.csdn.net/rs_lys/article/details/105715526)

# 环境
windows10 / visual studio 2015&2019

# 第三方库
opencv310
<br>
百度网盘连接：https://pan.baidu.com/s/1_WD-KdPyDBazEIim7NU3jA 
<br>
提取码：aab4
<br>
解压后放到3rdparty文件夹下
<br>
只在实验部分调用opencv库读取和显示图像，也可替换成其他图像库

# 算法引导
SGM步骤图
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/SGM%E6%AD%A5%E9%AA%A4%E5%9B%BE.png" width=70%>
</div>
<br/>SGM类设计图<br/>
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/SGM%E5%8C%B9%E9%85%8D%E7%B1%BB%E7%BB%93%E6%9E%84.png" width=50%>
</div>

# 实验
实验(1)：只做从左到右聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E5%B7%A6-%E5%8F%B3%EF%BC%89.png" width=70%>
</div>
<br/>实验(2)：只做从右到左聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E5%8F%B3-%E5%B7%A6%EF%BC%89.png" width=70%>
</div>
<br/>实验(3)：只做从上到下聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E4%B8%8A-%E4%B8%8B%EF%BC%89.png" width=70%>
</div>
<br/>实验(4)：只做从下到上聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E4%B8%8B-%E4%B8%8A%EF%BC%89.png" width=70%>
</div>
<br/>实验(5)：从左上到右下聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E5%B7%A6%E4%B8%8A-%E5%8F%B3%E4%B8%8B%EF%BC%89.png" width=70%>
</div>
<br/>实验(6)：从右下到左上聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E5%8F%B3%E4%B8%8B-%E5%B7%A6%E4%B8%8A%EF%BC%89.png" width=70%>
</div>
<br/>实验(7)：从右上到左下聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E5%8F%B3%E4%B8%8A-%E5%B7%A6%E4%B8%8B%EF%BC%89.png" width=70%>
</div>
<br/>实验(8)：从左下到右上聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%88%E5%B7%A6%E4%B8%8B-%E5%8F%B3%E4%B8%8A%EF%BC%89.png" width=70%>
</div>
<br/>实验(9)：4-路径全聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%884%E8%B7%AF%E5%BE%84%EF%BC%89.png" width=70%>
</div>
<br/>实验(10)：8-路径全聚合：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E8%81%9A%E5%90%88%EF%BC%888%E8%B7%AF%E5%BE%84%EF%BC%89.png" width=70%>
</div>
<br/>实验(12)：一致性检查+中值滤波：
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/%E4%B8%80%E8%87%B4%E6%80%A7%E6%A3%80%E6%9F%A5%2B%E4%B8%AD%E5%80%BC%E6%BB%A4%E6%B3%A2.png" width=50%>
</div>

## Github图片不显示的解决办法
修改hosts

C:\Windows\System32\drivers\etc\hosts

在文件末尾添加：

``` cpp
# GitHub Start 
192.30.253.112    github.com 
192.30.253.119    gist.github.com
151.101.184.133    assets-cdn.github.com
151.101.184.133    raw.githubusercontent.com
151.101.184.133    gist.githubusercontent.com
151.101.184.133    cloud.githubusercontent.com
151.101.184.133    camo.githubusercontent.com
151.101.184.133    avatars0.githubusercontent.com
151.101.184.133    avatars1.githubusercontent.com
151.101.184.133    avatars2.githubusercontent.com
151.101.184.133    avatars3.githubusercontent.com
151.101.184.133    avatars4.githubusercontent.com
151.101.184.133    avatars5.githubusercontent.com
151.101.184.133    avatars6.githubusercontent.com
151.101.184.133    avatars7.githubusercontent.com
151.101.184.133    avatars8.githubusercontent.com
 
 # GitHub End
```
