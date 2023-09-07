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

        if (judge(stone_count, "���Ȃ�"))
            break;

        computerTurn(&stone_count);

        if (judge(stone_count, "�R���s���[�^"))
            break;
    }
}

void inputStoneCount(int *stone_count)
{
    printf("�ŏ��̐΂̐��𐮐��œ��͂��ĉ������B\n");
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
        printf("���Ȃ��̃^�[���ł��B%d����%d�܂ł̊ԂŎ��΂̐�����͂��ĉ������B\n", MIN, max);
        scanf("%d", &take_count);
    }

    *stone_count -= take_count;
    printf("���Ȃ��͐΂�%d���܂����B���݁A�΂͑S����%d�ł��B\n", take_count, *stone_count);
}

void computerTurn(int *stone_count)
{
    int max = getMax(stone_count);
    int take_count = rand() % max + 1;
    *stone_count -= take_count;
    printf("�R���s���[�^�͐΂�%d���܂����B���݁A�΂͑S����%d�ł��B\n", take_count, *stone_count);
}

bool judge(int stone_count, char user_name[])
{
    if (stone_count <= 0)
    {
        printf("%s�̏����ł��B", user_name);
        return true;
    }

    return false;
}