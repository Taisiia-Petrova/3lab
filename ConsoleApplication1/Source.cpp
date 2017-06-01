#include "function.h"
// ñòîëáöû - ðàáîòû, ñòðîêè - ðàáî÷èå
int main()
{
	setlocale(LC_ALL, "rus");
	const int vert_num = 4;
	int** graph = new int*[vert_num];
	int* result_str = new int[vert_num];
	int* result_raw = new int[vert_num];
	int* min_fi = new int[vert_num];
	int resMass[vert_num], resMassInd = 0;

	for (int i = 0; i < vert_num; i++)
	{
		graph[i] = new int[vert_num];
		result_str[i] = UNDEF_INT_MAX;
		result_raw[i] = UNDEF_INT_MAX;
	}

	//1
	graph[0][0] = 4;
	graph[0][1] = 4;
	graph[0][2] = 4;
	graph[0][3] = 4;
	//2
	graph[1][0] = 3;
	graph[1][1] = 3;
	graph[1][2] = 3;
	graph[1][3] = 3;
	//3
	graph[2][0] = 2;
	graph[2][1] = 2;
	graph[2][2] = 2;
	graph[2][3] = 2;
	//4
	graph[3][0] = 1;
	graph[3][1] = 1;
	graph[3][2] = 1;
	graph[3][3] = 1;

	printMatrix(graph, vert_num);

	int min[vert_num];	//ìàññèâ, õðàíÿùèé âñå ôè äëÿ îäíîãî ðàáîòíèêà

	for (int j = 0; j < vert_num; j++)	//ðàáîòíèêè
	{
		result_str[j] = 0;	//çàíóëÿåì ñòðîêó
		for (int i = 0; i < vert_num; i++)	//ðàáîòû
		{
			if (result_raw[i] == UNDEF_INT_MAX)
			{
				result_raw[i] = graph[j][i];
				//íàçíà÷àåì íà ðàáîòó result_raw[i], âû÷åðêèâàåì j ñòðîêó i ñòîëáåö
				int minS = min_str(graph, result_str, result_raw, vert_num);	// ñóììà min ýëåìåíòîâ ïî îñòàâøèìñÿ ñòðîêàì
				int minR = min_raw(graph, result_str, result_raw, vert_num);	// ñóììà min ýëåìåíòîâ ïî îñòàâøèìñÿ ñòîëáöàì
																				//âûáèðàåì min èç ñóìì ñòðîê è ñóìì ñòîëáöîâ
				if (minS < minR)
				{
					min[i] = minS;
				}
				else
				{
					min[i] = minR;
				}
				min[i] += graph[j][i];	//ïðèáàâëÿåì ê min äàííîå çíà÷åíèå ðàáîòû äëÿ äàííîãî ðàáîòíèêà (íàøëè ôè)
				result_raw[i] = UNDEF_INT_MAX;
			}
			else
			{
				min[i] = UNDEF_INT_MAX;
			}
		}
		int curr_min = UNDEF_INT_MAX;
		//èùåì min ôè 
		for (int i = 0; i < vert_num; i++)
		{
			if (min[i] < curr_min)
			{
				curr_min = min[i];
				min_fi[j] = i;		//ñîõðàíÿåò äëÿ j ðàáîòíèêà ëó÷øóþ ðàáîòó i
			}
		}
		result_raw[min_fi[j]] = 0;	//âû÷åðêèâàåì j ñòîëáåö, òê ýòî ðàáîòà óæå çàíÿòà
		resMass[resMassInd] = min_fi[j];	//èòîãîâûé ìàññèâ ðàáîòíèê - ðàáîòà
		resMassInd++;
	}
	printRes(resMass, graph, vert_num);
	return 0;
}