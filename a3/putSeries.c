#include <stdio.h>
    
int main(void)
{    
    FILE *fp;
    fp = fopen("output.txt", "a");
    if (fp == NULL)
    {
        printf("파일 열기 실패\n");
        return 1;
    }
    putc('A', fp);
    putc('A', stdout);
    fputc('B', fp);
    fputc('B', stdout);
    // put deprecicate 지원 종료
    fputs("puts로 문지가 간다.\n", fp);
    fputs("puts로 문자가 간다.\n", stdout);

    fprintf(fp, "printf로 문지가 간다.\n");
    // fflush(fp);
    fprintf(stdout, "printf로 문자가 간다.\n");
    // fflush(stdout);
    EOF == -1;
    fclose(fp);
    return 0;
}