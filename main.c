// #include "main.h"  
#include <stdio.h>
#include <stdlib.h>

int file_size(FILE* fp);
char *shell(char *command);

//执行shell命令，返回字符串(注意记得释放空间)
char *shell(char *command)
{
    FILE *fp;
    fp = popen("echo $(date)","r");
    char *buf = (char*)malloc(file_size(fp));
    fseek(fp,0,SEEK_SET);
    fgets(buf,sizeof(buf),fp);
    pclose(fp);
    return buf;
}


//获取文件大小，副作用文件指针会跑到最后
int file_size(FILE* fp)
{
    fseek(fp,0,SEEK_END);
    return ftell(fp);
}

int main()  
{  
    char* shell_ret = shell("echo $(date)");
    printf("time:%s\n",shell_ret);
    free(shell_ret);
    return 0;  
}


