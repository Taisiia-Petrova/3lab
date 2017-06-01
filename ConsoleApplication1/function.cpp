#include "function.h"

void printMatrix(int** graph, int vert_num)
{
	for (int i = 0; i < vert_num; i++)
	{
		for (int j = 0; j < vert_num; j++)
		{
			/*åñëè íåò ðåáðà*/
			if (UNDEF_INT_MAX == graph[i][j])
			{
				cout << "0" << "	";
			}
			else
			{
				cout << graph[i][j] << "	";
			}
		}
		cout << endl;
	}

	cout << endl;
	cout << endl;
}

int min_str(int** graph, int* result_str, int* result_raw, int vert_num)
{
	int minSum = 0;
	int currMin = 0;
	for (int i = 0; i < vert_num; i++)
	{
		if (result_str[i] == UNDEF_INT_MAX)
		{
			currMin = UNDEF_INT_MAX;
			for (int j = 0; j < vert_num; j++)
			{
				if (result_raw[j] == UNDEF_INT_MAX)
				{
					if (graph[i][j] < currMin)
					{
						currMin = graph[i][j];
					}
				}

			}
		}
		minSum += currMin;
		currMin = 0;
	}
	return minSum;
}

int min_raw(int** graph, int* result_str, int* result_raw, int vert_num)
{
	int minSum = 0;
	int currMin = 0;
	for (int i = 0; i < vert_num; i++)
	{
		if (result_raw[i] == UNDEF_INT_MAX)
		{
			currMin = UNDEF_INT_MAX;
			for (int j = 0; j < vert_num; j++)
			{
				if (result_str[j] == UNDEF_INT_MAX)
				{
					if (graph[j][i] < currMin)
					{
						currMin = graph[j][i];
					}
				}

			}
		}
		minSum += currMin;
		currMin = 0;
	}
	return minSum;
}

void printRes(int* resMass, int** graph, int vert_num)
{
	int minWork = 0;
	for (int i = 0; i < vert_num; i++)
	{
		cout << "Работник " << i + 1 << " выполняет работу " << resMass[i] + 1 << endl;
		minWork += graph[i][resMass[i]];
	}

	cout << endl;
	cout << "Минимальные затраты труда " << minWork << endl;
	cout << endl;
}
