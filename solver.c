#include "functions.h"

int check_double(int tab[4][4], int pos, int num)
{
	int row = pos / 4;
	int col = pos % 4;
	int i = 0;

	while (i < row)
	{
		if (tab[i][col] == num)
			return 1;
		i++;
	}

	i = 0;
	while (i < col)
	{
		if (tab[row][i] == num)
			return 1;
		i++;
	}

	return 0;
}

int check_col_up(int tab[4][4], int col, int expected_count)
{
	int i = 0;
	int max = 0;
	int visible_count = 0;

	while (i < 4)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			visible_count++;
		}
		i++;
	}

	return visible_count == expected_count;
}

int check_col_down(int tab[4][4], int col, int expected_count)
{
	int i = 3;
	int max = 0;
	int visible_count = 0;

	while (i >= 0)
	{
		if (tab[i][col] > max)
		{
			max = tab[i][col];
			visible_count++;
		}
		i--;
	}

	return visible_count == expected_count;
}

int check_row_left(int tab[4][4], int row, int expected_count)
{
	int i = 0;
	int max = 0;
	int visible_count = 0;

	while (i < 4)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			visible_count++;
		}
		i++;
	}

	return visible_count == expected_count;
}


int check_row_right(int tab[4][4], int row, int expected_count)
{
	int i = 3;
	int max = 0;
	int visible_count = 0;

	while (i >= 0)
	{
		if (tab[row][i] > max)
		{
			max = tab[row][i];
			visible_count++;
		}
		i--;
	}

	return visible_count == expected_count;
}

int check_case(int tab[4][4], int pos, int entry[16])
{
	int row = pos / 4;
	int col = pos % 4;

	if (col == 3 && !check_row_right(tab, row, entry[12 + row]))
		return 1;
	if (col == 3 && !check_row_left(tab, row, entry[8 + row]))
		return 1;
	if (row == 3 && !check_col_down(tab, col, entry[4 + col]))
		return 1;
	if (row == 3 && !check_col_up(tab, col, entry[col]))
		return 1;

	return 0;
}

int check_case(int tab[4][4], int pos, int entry[16])
{
	if (check_row_left(tab, pos, entry) == 1)
		return (1);
	if (check_row_right(tab, pos, entry) == 1)
		return (1);
	if (check_col_down(tab, pos, entry) == 1)
		return (1);
	if (check_col_up(tab, pos, entry) == 1)
		return (1);
	return (0);
}

