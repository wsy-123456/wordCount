#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc, char* argv[])
{
    int Number_char=0,Number_word=0;//定义两个int变量分别来统计字符的数量以及单词的数量 
    int k=0; 
	FILE* fp;
	char* file;
	char ch;

	file = argv[2];
	
	//输入“-c”时判断字符个数 
	if(strcmp(argv[1],"-c")==0)
	{
	    if((fp=fopen(file,"r"))==NULL)
		{
		    printf("打开文件失败！!\n");
			exit(-1);
		}
		while((ch=fgetc(fp))!=EOF)
		{
		    Number_char++;
		}
		printf("字符个数为：%d",Number_char);
	}
	
	//输入“-w”时判断单词个数 
	else if(strcmp(argv[1],"-w")==0)
	{
	    if((fp=fopen(file,"r"))==NULL)
		{
		    printf("打开文件失败！");
			exit(-1);
		}
		while((ch=fgetc(fp))!=EOF)
		{
			if(ch==' '||ch==',')//只已空格和逗号来作为判断单词的依据 
			{
			    k=0;
			}
			else if(k==0)
			{
			    k=1;
				Number_word++;
			}
		}
		printf("单词个数为：%d",Number_word);
	}
	fclose(fp);
	return 0;
}