# SemiGlobalMatching
SGM，立体匹配最经典应用最广泛算法，4000+引用，兼顾效率和效果。完整实现，代码规范，注释清晰，博客教学，欢迎star！

<table>
    <tr>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/cone/im2.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/cone/im6.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/res/cone-d.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/res/cone-c.png"></center></td>
    </tr>
    <tr>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/Reindeer/view1.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/Reindeer/view5.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/res/reindeer-d.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/res/reindeer-c.png"></center></td>
    </tr>
    <tr>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/Cloth3/view1.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/Cloth3/view5.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/res/cloth-d.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/res/cloth-c.png"></center></td>
    </tr>
</table>
 
# CSDN博客
[【恒叨立码】【码上实战】【立体匹配系列】经典SGM：（1）框架与类设计](https://ethanli.blog.csdn.net/article/details/105065660)<br>
[【恒叨立码】【码上实战】【立体匹配系列】经典SGM：（2）代价计算](https://ethanli.blog.csdn.net/article/details/105142484)<br>
[【恒叨立码】【码上实战】【立体匹配系列】经典SGM：（3）代价聚合](https://ethanli.blog.csdn.net/article/details/105316274)<br>
[【恒叨立码】【码上实战】【立体匹配系列】经典SGM：（4）代价聚合2](https://ethanli.blog.csdn.net/article/details/105396761)<br>
[【恒叨立码】【码上实战】【立体匹配系列】经典SGM：（5）视差优化](https://blog.csdn.net/rs_lys/article/details/105715526)<br>
[【恒叨立码】【码上实战】【立体匹配系列】经典SGM：（6）视差填充](https://ethanli.blog.csdn.net/article/details/105897391)<br>
[【恒叨立码】【码上实战】【立体匹配系列】经典SGM：（7）弱纹理优化](https://ethanli.blog.csdn.net/article/details/106168040)<br>

# 环境
windows10 / visual studio 2015&2019
<br>代码基本没有使用系统api，你可以非常方便的移植到linux，可能需要做极少量的修改

# 第三方库
opencv310
<br>
百度网盘连接：https://pan.baidu.com/s/1_WD-KdPyDBazEIim7NU3jA 
<br>
提取码：aab4
<br><br>
解压后放将名称为OpenCV的文件夹复制到到3rdparty文件夹下
<br><br>若运行时提示缺少opencv_world310(d).dll，则在OpenCV文件夹里找到对应的dll文件复制到程序exe所在的目录即可（Opencv\dll\opencv_world310(d).dll），带d为debug库，不带d为release库。
<br><br>
为便于移植，算法是不依赖任何图像库的，只在算法实验部分调用opencv库读取和显示图像，也可替换成其他图像库

# 算法引导
SGM步骤图
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/SGM%E6%AD%A5%E9%AA%A4%E5%9B%BE.png" width=70%>
</div>
<br>SGM类设计图<br/>
<div align=center>
<img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/SGM%E5%8C%B9%E9%85%8D%E7%B1%BB%E7%BB%93%E6%9E%84.png" width=50%>
</div>

## 备注
<b>算法优点</b>：效果好，效率高，且可高度并行
<br><b>算法缺点</b>：效果非SOTA、内存占用高（可优化）、对弱纹理、重复纹理支持不太好

## 论文
1. Heiko Hirschmüller. Hirschmüller, H: <b>Stereo processing by semiglobal matching and mutual information</b>. IEEE PAMI 30(2), 328-341[J]. IEEE Transactions on Pattern Analysis and Machine Intelligence, 2008, 30(2):328-341.
2. Humenberger M , Engelke T , Kubinger W . <b>A census-based stereo vision algorithm using modified Semi-Global Matching and plane fitting to improve matching quality</b>[C]// IEEE Computer Society Conference on Computer Vision & Pattern Recognition-workshops. IEEE, 2010.

## 实验图
<table>
    <tr>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/cone/im2.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/Data/cone/im6.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/Init.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/CA.png"></center></td>
    </tr>
    <tr>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/LRCheck.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/LRCheck%2BRemovePeaks.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/MedianFilter.png"></center></td>
        <td ><center><img src="https://github.com/ethan-li-coding/SemiGlobalMatching/blob/master/doc/exp/Fill.png"></center></td>
    </tr>
</table>
<b>上行</b>：左视图、右视图、初始代价结果、聚合代价结果<br>
<b>下行</b>：一致性检查、唯一性约束+去小连通区、中值滤波、视差填充<br>

## Github图片不显示的解决办法
修改hosts

C:\Windows\System32\drivers\etc\hosts

在文件末尾添加：


```cpp
# GitHub Start
192.30.253.119      gist.github.com
151.101.184.133     assets-cdn.github.com
151.101.184.133     raw.githubusercontent.com
151.101.184.133     gist.githubusercontent.com
151.101.184.133     cloud.githubusercontent.com
151.101.184.133     camo.githubusercontent.com
151.101.184.133     avatars0.githubusercontent.com
151.101.184.133     avatars1.githubusercontent.com
151.101.184.133     avatars2.githubusercontent.com
151.101.184.133     avatars3.githubusercontent.com
151.101.184.133     avatars4.githubusercontent.com
151.101.184.133     avatars5.githubusercontent.com
151.101.184.133     avatars6.githubusercontent.com
151.101.184.133     avatars7.githubusercontent.com
151.101.184.133     avatars8.githubusercontent.com
# GitHub End


```
