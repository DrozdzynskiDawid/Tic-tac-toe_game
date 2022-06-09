#include "choice.h"

int field_id(int x, int y)
{
    if (y < 200 && x < 263)
    {
        return 0;
    }
    if (y < 200 && x > 263 && x < 526)
    {
        return 1;
    }
    if (y < 200 && x > 526)
    {
        return 2;
    }
    if (y > 200 && y < 400 && x < 263)
    {
        return 3;
    }
    if (y > 200 && y < 400 && x > 263 && x < 526)
    {
        return 4;
    }
    if (y > 200 && y < 400 && x > 526)
    {
        return 5;
    }
    if (y > 400 && x < 263)
    {
        return 6;
    }
    if (y > 400 && x > 263 && x < 526)
    {
        return 7;
    }
    if (y > 400 && x > 526)
    {
        return 8;
    }
}

int choiceX(int matrix[3][3], int clickx, int clicky)
{
    int number = field_id(clickx, clicky);
    if (number == 0 && matrix[0][0] == 0)
    {
        matrix[0][0] = 1;
        return 1;
    }
    if (number == 1 && matrix[0][1] == 0)
    {
        matrix[0][1] = 1;
        return 1;
    }
    if (number == 2 && matrix[0][2] == 0)
    {
        matrix[0][2] = 1;
        return 1;
    }
    if (number == 3 && matrix[1][0] == 0)
    {
        matrix[1][0] = 1;
        return 1;
    }
    if (number == 4 && matrix[1][1] == 0)
    {
        matrix[1][1] = 1;
        return 1;
    }
    if (number == 5 && matrix[1][2] == 0)
    {
        matrix[1][2] = 1;
        return 1;
    }
    if (number == 6 && matrix[2][0] == 0)
    {
        matrix[2][0] = 1;
        return 1;
    }
    if (number == 7 && matrix[2][1] == 0)
    {
        matrix[2][1] = 1;
        return 1;
    }
    if (number == 8 && matrix[2][2] == 0)
    {
        matrix[2][2] = 1;
        return 1;
    }
}

int choiceY(int matrix[3][3], int clickx, int clicky)
{
    int number = field_id(clickx, clicky);
    if (number == 0 && matrix[0][0] == 0)
    {
        matrix[0][0] = 2;
        return 1;
    }
    if (number == 1 && matrix[0][1] == 0)
    {
        matrix[0][1] = 2;
        return 1;
    }
    if (number == 2 && matrix[0][2] == 0)
    {
        matrix[0][2] = 2;
        return 1;
    }
    if (number == 3 && matrix[1][0] == 0)
    {
        matrix[1][0] = 2;
        return 1;
    }
    if (number == 4 && matrix[1][1] == 0)
    {
        matrix[1][1] = 2;
        return 1;
    }
    if (number == 5 && matrix[1][2] == 0)
    {
        matrix[1][2] = 2;
        return 1;
    }
    if (number == 6 && matrix[2][0] == 0)
    {
        matrix[2][0] = 2;
        return 1;
    }
    if (number == 7 && matrix[2][1] == 0)
    {
        matrix[2][1] = 2;
        return 1;
    }
    if (number == 8 && matrix[2][2] == 0)
    {
        matrix[2][2] = 2;
        return 1;
    }
}