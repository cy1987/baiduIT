#使用说明
1. 首先编译1.2.c文件(win下生成xxx.txt,liunx下生成a.out)
2. 在命令行下输入./a.out -e 1234 xxx.txt xxx.txt xxx.txt（文件数量不限但须于a.out在同级目录）
3. 程序按待加密文件顺序生成encrptedx.txt已加密文件（x为文件序号）
4. 解密文件输入./a.out -d 1234 xxx.txt xxx.txt xxx.txt(文件为已加密文件）
5. 程序按加密文件顺序生成letterx.txt解密后文件（x为文件序号）


