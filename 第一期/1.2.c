#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define my 'a'    //加密密匙
#define MAX 10    //加密文件最长数值长度
#define LENTH 20  //单个文件名最大长度
int main(int argc,char *argv[])
{
	FILE *in,*out;
	char ch,num[MAX],letters[argc-3][LENTH],encrpted[argc-3][LENTH]; 
	for(int i=0;i < argc-3;i++){         //使用二位数组为多个文件命名
		sprintf(letters[i],"letter%d.txt",i+1);
		sprintf(encrpted[i],"encrpted%d.txt",i+1);
	}				
	while(atoi(argv[2]) != 1234){  //判断密码是否正确
        	printf("password error");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i< argc-3;i++){     //根据文件个数判断进行加密的次数
	    if (!strcmp(argv[1],"-e")){   //判断操作为加密或解密
		in = fopen(argv[i+3],"r"); //循环读取待加密文件
		out = fopen(encrpted[i],"w");//生成加密后文件并以写打开
	       while((ch = getc(in)) != EOF){ 
		 	ch ^= my;             //对文件内容进行异或加密
			putc(ch,out);}
	    }else if(!strcmp(argv[1],"-d")){  //解密操作
		in = fopen(argv[i+3],"r");    //打开加密后文件
 		out = fopen(letters[i],"w");  //生成解密后文件
	       while((ch = getc(in)) != EOF){    
            	ch ^= my;       //再次使用异或加密使内容复原
            	putc(ch,out);}   
	    }else{             //输入错误退出程序
	    	printf("parameter error");
        	exit(EXIT_FAILURE);}
	}
	return 0;
}
