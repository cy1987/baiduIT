#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define my 'a'    //�����ܳ�
#define MAX 10    //�����ļ����ֵ����
#define LENTH 20  //�����ļ�����󳤶�
int main(int argc,char *argv[])
{
	FILE *in,*out;
	char ch,num[MAX],letters[argc-3][LENTH],encrpted[argc-3][LENTH]; 
	for(int i=0;i < argc-3;i++){         //ʹ�ö�λ����Ϊ����ļ�����
		sprintf(letters[i],"letter%d.txt",i+1);
		sprintf(encrpted[i],"encrpted%d.txt",i+1);
	}				
	while(atoi(argv[2]) != 1234){  //�ж������Ƿ���ȷ
        	printf("password error");
		exit(EXIT_FAILURE);
	}
	for(int i=0;i< argc-3;i++){     //�����ļ������жϽ��м��ܵĴ���
	    if (!strcmp(argv[1],"-e")){   //�жϲ���Ϊ���ܻ����
		in = fopen(argv[i+3],"r"); //ѭ����ȡ�������ļ�
		out = fopen(encrpted[i],"w");//���ɼ��ܺ��ļ�����д��
	       while((ch = getc(in)) != EOF){ 
		 	ch ^= my;             //���ļ����ݽ���������
			putc(ch,out);}
	    }else if(!strcmp(argv[1],"-d")){  //���ܲ���
		in = fopen(argv[i+3],"r");    //�򿪼��ܺ��ļ�
 		out = fopen(letters[i],"w");  //���ɽ��ܺ��ļ�
	       while((ch = getc(in)) != EOF){    
            	ch ^= my;       //�ٴ�ʹ��������ʹ���ݸ�ԭ
            	putc(ch,out);}   
	    }else{             //��������˳�����
	    	printf("parameter error");
        	exit(EXIT_FAILURE);}
	}
	return 0;
}
