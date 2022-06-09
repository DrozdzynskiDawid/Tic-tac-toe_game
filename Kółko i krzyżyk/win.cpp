#include "win.h"

int winOfX(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == 1 && matrix[i][1] == 1 && matrix[i][2] == 1)
        {
            return 1;
        }
        if (matrix[0][i] == 1 && matrix[1][i] == 1 && matrix[2][i] == 1)
        {
            return 1;
        }
    }
    if (matrix[0][0] == 1 && matrix[1][1] == 1 && matrix[2][2] == 1)
    {
        return 1;
    }
    if (matrix[0][2] == 1 && matrix[1][1] == 1 && matrix[2][0] == 1)
    {
        return 1;
    }
    return 0;
}

int winOfO(int matrix[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        if (matrix[i][0] == 2 && matrix[i][1] == 2 && matrix[i][2] == 2)
        {
            return 1;
        }
        if (matrix[0][i] == 2 && matrix[1][i] == 2 && matrix[2][i] == 2)
        {
            return 1;
        }
    }
    if (matrix[0][0] == 2 && matrix[1][1] == 2 && matrix[2][2] == 2)
    {
        return 1;
    }
    if (matrix[0][2] == 2 && matrix[1][1] == 2 && matrix[2][0] == 2)
    {
        return 1;
    }
    return 0;
}

int winType(int matrix[3][3])
{
    if (matrix[0][0] == matrix[0][1] && matrix[0][1] == matrix[0][2] && (matrix[0][0] == 1 || matrix[0][0] == 2))
    {
        return 1;
    }
    if (matrix[1][0] == matrix[1][1] && matrix[1][1] == matrix[1][2] && (matrix[1][0] == 1 || matrix[1][0] == 2))
    {
        return 2;
    }
    if (matrix[2][0] == matrix[2][1] && matrix[2][1] == matrix[2][2] && (matrix[2][0] == 1 || matrix[2][0] == 2))
    {
        return 3;
    }
    if (matrix[0][0] == matrix[1][0] && matrix[1][0] == matrix[2][0] && (matrix[0][0] == 1 || matrix[0][0] == 2))
    {
        return 4;
    }
    if (matrix[0][1] == matrix[1][1] && matrix[1][1] == matrix[2][1] && (matrix[0][1] == 1 || matrix[0][1] == 2))
    {
        return 5;
    }
    if (matrix[0][2] == matrix[1][2] && matrix[1][2] == matrix[2][2] && (matrix[0][2] == 1 || matrix[0][2] == 2))
    {
        return 6;
    }
    if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2] && (matrix[0][0] == 1 || matrix[0][0] == 2))
    {
        return 7;
    }
    if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0] && (matrix[0][2] == 1 || matrix[0][2] == 2))
    {
        return 8;
    }
}