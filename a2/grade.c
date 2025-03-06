// 점수를 출력하는 코드 A - F
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int score;
    if (argc < 2)
    {
        printf("인자를 하나 넣어서 실행하세요.\n");
        return 0;
    }

    if (score >= 90){
        printf("scre : %d === A\n", score);
    } 
    else if(score >= 80)
    {
        printf("scre : %d === B\n", score);
    }
    else if(score >= 70)
    {
        printf("scre : %d === C\n", score);
    }
    else if(score >= 60)
    {
        printf("scre : %d === D\n", score);
    }
    else
    {
        printf("scre : %d === F\n", score);
    }
    return 0;
}