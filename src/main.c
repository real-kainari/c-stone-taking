#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MIN 1
#define MAX 3

void inputStoneCount(int *stone_count);
void playerTurn(int *stone_count);
void computerTurn(int *stone_count);
bool judge(int stone_count, char user_name[]);

void main()
{
    int stone_count = 0;
    inputStoneCount(&stone_count);
    srand((unsigned int)time(NULL));

    while (true)
    {
        playerTurn(&stone_count);

        if (judge(stone_count, "あなた"))
            break;

        computerTurn(&stone_count);

        if (judge(stone_count, "コンピュータ"))
            break;
    }
}

void inputStoneCount(int *stone_count)
{
    printf("最初の石の数を整数で入力して下さい。\n");
    scanf("%d", stone_count);
}

int getMax(int *stone_count)
{
    if (*stone_count < MAX)
        return *stone_count;
    else
        return MAX;
}

void playerTurn(int *stone_count)
{
    int max = getMax(stone_count);
    int take_count = -1;

    while (take_count < MIN || take_count > max)
    {
        printf("あなたのターンです。%dから%dまでの間で取る石の数を入力して下さい。\n", MIN, max);
        scanf("%d", &take_count);
    }

    *stone_count -= take_count;
    printf("あなたは石を%d個取りました。現在、石は全部で%d個です。\n", take_count, *stone_count);
}

void computerTurn(int *stone_count)
{
    int max = getMax(stone_count);
    int take_count = rand() % max + 1;
    *stone_count -= take_count;
    printf("コンピュータは石を%d個取りました。現在、石は全部で%d個です。\n", take_count, *stone_count);
}

bool judge(int stone_count, char user_name[])
{
    if (stone_count <= 0)
    {
        printf("%sの勝ちです。", user_name);
        return true;
    }

    return false;
}