#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int Number_char=0,Number_word=0;//��������int�����ֱ���ͳ���ַ��������Լ����ʵ����� 
    int k=0; 
	FILE* fp;
	char* file;
	char ch;

	file = argv[2];
	
	//���롰-c��ʱ�ж��ַ����� 
	if(strcmp(argv[1],"-c")==0)
	{
	    if((fp=fopen(file,"r"))==NULL)
		{
		    printf("���ļ�ʧ�ܣ�!\n");
			exit(-1);
		}
		while((ch=fgetc(fp))!=EOF)
		{
		    Number_char++;
		}
		printf("�ַ�����Ϊ��%d",Number_char);
	}
	
	//���롰-w��ʱ�жϵ��ʸ��� 
	else if(strcmp(argv[1],"-w")==0)
	{
	    if((fp=fopen(file,"r"))==NULL)
		{
		    printf("���ļ�ʧ�ܣ�");
			exit(-1);
		}
		while((ch=fgetc(fp))!=EOF)
		{
			if(ch==' '||ch==',')//ֻ�ѿո�Ͷ�������Ϊ�жϵ��ʵ����� 
			{
			    k=0;
			}
			else if(k==0)
			{
			    k=1;
				Number_word++;
			}
		}
		printf("���ʸ���Ϊ��%d",Number_word);
	}
	fclose(fp);
	return 0;
}