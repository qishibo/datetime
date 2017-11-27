# datetime
一款在 Linux\Mac\Windows 下展示当系统时间的gui小工具

他是因为这样一个场景产生的: linux or mac下,每次想知道当前日期时, 总是得打开日历, 好不麻烦!

有了这个工具之后, 系统增加一个快捷键(如alt + d)直接指向这个可执行文件, 唰的一下子, 日期就显示出来了! 然后按任意键, 该窗口又自动消失, 目的达到.

>> 该工具基于GTK实现, 所以系统要安装GTK && GCC环境.

![效果图](http://ww1.sinaimg.cn/large/71405cably1flwmp6u7odj20i50ac3yj.jpg)

# Usage

```
gcc  -Wall -g -o clock clock.c `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

./clock

# 任意键退出
```
