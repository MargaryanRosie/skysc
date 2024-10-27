#include <stdio.h>
#include "functions.h"

int solve(int tab[4][4], int entry[16], int pos)
{
    int number;

    if (pos == 16)
        return (1);
    number = 1;
    while (number <= 4)
    {
        if (check_double(tab, pos, number) == 0)
        {
            tab[pos / 4][pos % 4] = number;
            if (check_case(tab, pos, entry) == 0)
            {
                if (solve(tab, entry, pos + 1) == 1)
                    return (1);
            }
            else
                tab[pos / 4][pos % 4] = 0;
        }
        number++;
    }
    return (0);
}

void display_solution(int tab[4][4])
{
    int row;
    int col;

    row = 0;
    while (row < 4)
    {
        col = 0;
        while (col < 4)
        {
            printf("%d ", tab[row][col]);
            col++;
        }
        printf("\n");
        row++;
    }
}

int main(int ac, char **av)
{
    int tab[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
    int *entry;

    if (check(ac, av) == 1)
        return (0);
    entry = get_numbers(av[1]);

    if (solve(tab, entry, 0) == 1)
        display_solution(tab);
    else
        printf("Did not find any solutions\n");
    return (0);
}

