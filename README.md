[![996.icu](https://img.shields.io/badge/link-996.icu-red.svg)](https://996.icu) [![LICENSE](https://img.shields.io/badge/license-Anti%20996-blue.svg)](https://github.com/996icu/996.ICU/blob/master/LICENSE)

# CCF CSP 考试和 PAT 甲级乙级考试题解

<img src="https://z3.ax1x.com/2021/06/17/2zNIII.md.jpg">

本仓库是书籍《算法详解（C++11 语言描述）》的配套仓库，主要负责更新 CCF CSP 和 PAT 甲级乙级题解代码。书籍《算法详解（C++11 语言描述）》已在各大电商平台上架，搜索书名即可找到对应商品。关于书籍的勘误信息可参考[书籍勘误](书籍勘误.md)。

有关 CCF CSP 考试的简介可参考[CCF CSP 认证考试在线评测系统](https://www.cnblogs.com/richenyunqi/p/14892974.html)，有关 PAT 考试的简介可参考[浙江大学计算机程序设计能力考试（PAT）简介](https://www.cnblogs.com/richenyunqi/p/14892982.html)。本仓库的代码会一直维护，每次考试后都会尽快更新新的题解，希望这一工作能够给予算法初学者们一定的帮助。由于 CCF CSP 和 PAT 考试都已支持 C++14 标准，**本仓库的所有题解代码均将基于 C++14 语法编写**。在编译本仓库的代码之前，最好选择支持 C++14 的编译环境。

如果发现本仓库的代码有问题，欢迎通过提 issue 的方式给予说明，最好附上错误的输入数据或正确的题解代码。

## 题解目录

为方便查阅，在[题解目录](题解目录)文件夹下附上了本仓库中题解的汇总链接：

1. [CCF CSP 题解目录](题解目录/CCF%20CSP题解目录.md)
2. [PAT 甲级题解目录](题解目录/PAT甲级题解目录.md)
3. [PAT 乙级题解目录](题解目录/PAT乙级题解目录.md)

## 相关推荐

1. 为了更好地浏览本仓库，建议使用 `chrome` 或新版 `Edge` 浏览器并安装以下插件（这里提供的插件链接需要科学上网才能打开）。科学上网的方法有很多，例如通过安装[蓝灯](https://github.com/ainiyiwan/forum)可以正常访问谷歌相关网站。

   1. [Gitako - GitHub file tree](https://chrome.google.com/webstore/detail/gitako-github-file-tree/giljefjcheohhamkjphiebfjnlphnokk)：对打开的 Github 代码仓库，可以像 IDE 一样提供项目目录并自动生成一个仓库目录树侧边栏，通过这个插件你可以很方便地打开这个仓库内的任何一个文件。
   2. [MathJax Plugin for Github](https://chrome.google.com/webstore/detail/mathjax-plugin-for-github/ioemnmodlmafdkllaclgeombjnmnbima)：对`github`上`markdown`文本的`latex`语法进行渲染。

2. 建议安装 VSCode 并进行相应配置，来编写运行 C++代码。VSCode 是一款现代化的的编辑器，相比于 vc++、CodeBlocks、Dev c++等等老旧的 IDE，VSCode 提供的功能更加强大；相比于 Visual Studio，VSCode 更加小巧。有关 VSCode 的安装以及 C/C++环境的配置可以参考[挑把趁手的兵器——VSCode 配置 C/C++学习环境（小白向）](https://zhuanlan.zhihu.com/p/147366852)。
3. 可以利用 windows 批处理文件比较程序输出和样例输出或者进行程序对拍，可以参考[用 VSCode 终端实现重定向比较程序输出和正确输出](https://www.cnblogs.com/richenyunqi/p/14894172.html)。
4. 一些常见的数据结构和算法的代码模板可以参考[ACM、OI、OJ 代码模板](https://github.com/richenyunqi/code-templates)。
5. 为方便交流，建立了一个 QQ 群，群号是[673612216](https://qm.qq.com/cgi-bin/qm/qr?k=7vZCZuLbDvjYI33zxScZMV0irFFaO-xH&jump_from=webapi)，可按需求加入。

## 鸣谢

### 书籍勘误

感谢指出本书籍勘误的目光敏锐的读者朋友：苏义煊、汪兆祥、[Frazier Lei](https://github.com/FrazierLei)。

### 代码改进

- 感谢[夜行少女](https://me.csdn.net/qq_37967797)对`CCF 认证 201812-3CIDR 合并`代码的改进
- 感谢[Highlight_Jin](https://me.csdn.net/Highlight_Jin)对`CCF 认证 201512-4 送货`代码的改进

### bug 提示

- 感谢**张建勋**指出`CCF 认证 201612-1 中间数`中存在的 bug 并提供相应的出现错误的测试数据
- 感谢[星辰浩宇](https://me.csdn.net/amf12345)指出`CCF 认证 201803-3URL 映射`中存在的 bug 并提供相应的出现错误的测试数据
- 感谢[chocolate-emperor](https://github.com/chocolate-emperor)对`CCF 认证 201512-2 消除类游戏`代码错误的提醒
- 感谢[田奕轩](https://me.csdn.net/qq_45057634)对`CCF 认证 20161202-工资计算`代码错误的提醒
- 感谢[徐嘉诚](https://github.com/xiaobanni)指出`CCF 认证 201403-4 无线网络`中存在的 bug 并提供相应的出现错误的测试数据
- 感谢[promise6512](https://github.com/promise6512)指出`pat 甲级 1104. Sum of Number Segments、乙级 1049. 数列的片段和`中存在的 bug

### 代码补充

- 感谢[zhanyeye](https://github.com/zhanyeye)对`CCF认证201312-4有趣的数`题解代码的补充

## 打赏

仓库维护不易，您的每次打赏和支持都是我不断更新和维护仓库的动力。万水千山总是情，给个打赏行不行？Ծ‸Ծ

<center>
<table><tr>
<td><img src="https://z3.ax1x.com/2021/06/17/2zNe8f.jpg" alt="alipay" hspace="20"></td>
<td><img src="https://z3.ax1x.com/2021/06/17/2zNZPP.jpg" alt="wechat" hspace="20"></td>
</tr></table>
</center>
