//#include "stdafx.h"
#include "Auxil.h"                            // вспомогательные функции 
#include <iostream>
#include <ctime>
#include <locale>

#define  CYCLE  100000                       // начальное количество циклов  

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

	auxil::start();                          // старт генерации 
	t1 = clock();                            // фиксация времени 
	for (int i = 0; i < cycle; i++)
	{
		av1 += (double)auxil::iget(-100, 100); // сумма случайных чисел 
		av2 += auxil::dget(-100, 100);         // сумма случайных чисел 
	}
	t2 = clock();                            // фиксация времени 


	std::cout << std::endl << "количество циклов:         " << cycle;
	std::cout << std::endl << "среднее значение (int):    " << av1 / cycle;
	std::cout << std::endl << "среднее значение (double): " << av2 / cycle;
	std::cout << std::endl << "продолжительность (у.е):   " << (t2 - t1);
	std::cout << std::endl << "                  (сек):   "
		<< ((double)(t2 - t1)) / ((double)CLOCKS_PER_SEC);
	std::cout << std::endl;

}