GSv
===

LINUX_____________View

简要：
		这是个在linux平台上的基层显示开源项目

==

构建GSv的硬性支持项：
	
	1 ：Linux 平台（目前暂不支持windows 平台）
	2 ：Kernel 至少在2.4版本以上（2.4以前的内核因为部分设备不支持）

构建GSv的软性需求：
	
	1 ：在png图像的支持方面采用 libpng12 解码，您要保证已安装 libpng12， 并拥有 png 头文件. （你可以在此页面中下载安装libpng12）
	2 :字体方面使用了新的font点阵字集,放弃原先的freetype方法
	
构建GSv的法律申明：

	1 ：GSv采用GPLv2版法律，您若要使用并开发完善GSv，您必须 保证其符合GPLv2法律，而不是GPL.
	2 ：法律内容附在GSv的项目根目录下，如若未找到，可以在 GNU 相关网址查询.
	3 : GPLv2法律内容请详细阅读.

==

构建说明：

	GSv的构建很简单，一般只需要下载得到GSv源，解压，安装就可以将GSv构建在当前计算机上.
	
构建步骤:

	1 ：下载GSv源.
	2 ：解压得到项目文件夹，例如的到 ‘GS_Project’ 这个文件夹.
	3 ：cd ./GS_Project/  将工作目录切换至此.
	5 ：# make #编译
        # make install #安装
        # cd ./test/ #测试程序目录
            ex:
                # gcc GS_Screeninfo.c -lgsv -o GS_Screeninfo
                # GS_Screeninfo #输出屏幕信息
                # gcc GS_image.c -lgsv -lgsv_image -o GS_image
                # GS_image bg.png #输出bg.png图像
                # gcc GS_Window.c -lgsv -o GS_Windoe
                # GS_Window #输出窗口
        # make uninstall #卸载
        # make clean #清除
    6 : 上述显示图像的程序均在字符界面下运行,若在gnome,gtk等界面环境下运行均会因为图像输出的抢占问题而无法显示图像


构建方法2：
	git clone https://github.com/gloxec/GSv.git
==

开发近期目标：
	
		-> 关于窗口等UI事件的信号处理机制
        -> 关于屏幕图像输出的独占模式
		
==

联系方式：
	
	E-Mail : gloxec@gmail.com

==

—————————————————————————————————————————————————————————————
                 GSv项目开发组期待你的加入！                
—————————————————————————————————————————————————————————————




========================================================================================================================
