# nodeJS call DLL

### This is a example using addon to call DLL in nodeJS.

1. 运行环境（Win7系统）<br>
    （1）nodeJS 0.10.26（64位）<br>
    （2）python-2.7.6（64位）<br>
    （3）Visual studio 2013（必须）<br>
    这里使用的dll是64位的，所以对应的软件必须也匹配为64位的。如果你要加载的dll是32位，那么请使用对应的32位软件。<br><br>

2. 使用方法<br>
    （1）DOS下执行npm install node-gyp -g 安装<br>
    （2）下载例子到本地，cd进入到本地demo的文件夹<br>
    （3）执行node-gyp configure<br>
    （4）执行node-gyp build<br>
    完成上述操作后代码会编译生成文件demo\build\Release\max_addon.node，直接在js文件中引入就可以使用了。<br><br>

3. 测试 <br>
    在DOS下执行node max.js，看到输出数字2就说明成功了。
