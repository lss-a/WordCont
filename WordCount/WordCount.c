#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)

#define MAX_LINE 1000

int main(int argc, char* argv[])
{
    char data[MAX_LINE];  /*存储结构*/
    FILE* fp;            /*文件指针*/
    int len;             /*行字符个数*/
   
    int length = 0;

    //printf("%s    %s",argv[1],argv[2]);
    fp = fopen(argv[2], "rt");
    if (fp == NULL) {
        printf("提示:文件未能成功打开\n");
        exit(1);
    }
    else {
        //printf("提示:文件已经打开\n");
        while (fgets(data, MAX_LINE, fp) != NULL)
        {
            len = strlen(data);
            data[len - 1] = '\0';  //去掉换行符
            //printf("%s %d \n", data, len - 1);  //检验文本读取

        }

        if ((strcmp(argv[1],"-c") == 0) ){
            //printf("进去了");
            length = len;
            printf("字符数为:%d\n", length);
        }
        else if ((strcmp(argv[1], "-w") == 0) ){
            int i = 0;
            length = 1;
            for (i;i<=len;i++) {
                if ((data[i] == ',') ||  (data[i] == ' ')) {
                    length++;
                }
            }
            printf("单词数为:%d\n", length);
        }

        fclose(fp);
    }
    
       
    
    return 0;
}

