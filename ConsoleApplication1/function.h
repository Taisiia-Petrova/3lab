#include <iostream>

using namespace std;

#define UNDEF_INT_MAX			(2147483647)

void printMatrix(int** graph, int vert_num);
int min_str(int** graph, int* result_str, int* result_raw, int vert_num);
int min_raw(int** graph, int* result_str, int* result_raw, int vert_num);
void printRes(int* resMass, int** graph, int vert_num);