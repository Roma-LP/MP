// Main 
//#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include "Knapsack.h"
#include <time.h>
#include <iomanip> 
#define NN (sizeof(c)/sizeof(int))
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	int V = 600,              // ����������� �������              
		v[] = { 25, 56, 67, 40, 20, 27, 37, 33, 33, 44, 53, 12,
			   60, 75, 12, 55, 54, 42, 43, 14, 30, 37, 31, 12 },
		c[] = { 15, 26, 27, 43, 16, 26, 42, 22, 34, 12, 33, 30,
			   12, 45, 60, 41, 33, 11, 14, 12, 25, 41, 30, 40 };
	short m[NN];
	int maxcc = 0;
	clock_t t1, t2;
	std::cout << std::endl << "-------- ������ � ������� --------- ";
	std::cout << std::endl << "- ����������� �������  : " << V;
	std::cout << std::endl << "-- ���������� ------ ����������������� -- ";
	std::cout << std::endl << "    ���������          ����������  ";
	for (int i = 14; i <= NN; i++)
	{
		t1 = clock();
		maxcc = knapsack_s(V, i, v, c, m);
		t2 = clock();
		std::cout << std::endl << "       " << std::setw(2) << i
			<< "               " << std::setw(5) << (t2 - t1);
	}
	std::cout << std::endl << std::endl;
	system("pause");
	return 0;
}
