//#include "stdafx.h"
#include "Auxil.h"                            // ��������������� ������� 
#include <iostream>
#include <ctime>
#include <locale>

#define  CYCLE  100000                       // ��������� ���������� ������  

void resurch(int cycle);

int wmain(int argc, const wchar_t * argv[])
{
	setlocale(LC_ALL, "rus");

	for (int j = 0,i=CYCLE; j < 10; j++,i+=5000)
	{
		resurch(i);
	}
		system("pause");
	return 0;
}

void resurch(int cycle)
{
	double  av1 = 0, av2 = 0;
	clock_t  t1 = 0, t2 = 0;

	auxil::start();                          // ����� ��������� 
	t1 = clock();                            // �������� ������� 
	for (int i = 0; i < cycle; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // ����� ��������� ����� 
		av2 += auxil::dget(-100, 100);         // ����� ��������� ����� 
	}
	t2 = clock();                            // �������� ������� 


	std::cout << std::endl << "���������� ������:         " << cycle;
	std::cout << std::endl << "������� �������� (int):    " << av1 / cycle;
	std::cout << std::endl << "������� �������� (double): " << av2 / cycle;
	std::cout << std::endl << "����������������� (�.�):   " << (t2 - t1);
	std::cout << std::endl << "                  (���):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;

}