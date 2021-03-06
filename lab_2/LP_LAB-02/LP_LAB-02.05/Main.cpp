// Main 
//#include "stdafx.h"
#include <iostream>
#include "Combi.h"
#include "Knapsack.h"
#include "Auxil.h"
#include <ctime>
#include <iomanip>

#define NN 18
//int _tmain(int argc, _TCHAR* argv[])
int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	int V = 300,                // ����������� �������              
		//v[] = { 25, 30, 60, 20 },     // ������ �������� ������� ����  
		//c[] = { 25, 10, 20, 30 };     // ��������� �������� ������� ���� 
		v[NN],     // ������ �������� ������� ����  
		c[NN];     // ��������� �������� ������� ���� 
	short m[NN];                // ���������� ��������� ������� ����  {0,1}  

	auxil::start();                // ����� ���������
	for (int i = 0; i < NN; i++)
	{
		v[i] = auxil::iget(10, 300); // ��������� ����� �� � ��
		c[i] = auxil::iget(5, 55); // ��������� ����� �� � ��
		//std::cout << "c["<<i<<"]= "<<c[i] <<" ";
		//std::cout << "v["<<i<<"]= "<<v[i] <<" ";
	}

	int maxcc = knapsack_s(

		V,   // [in]  ����������� ������� 
		NN,  // [in]  ���������� ����� ��������� 
		v,   // [in]  ������ �������� ������� ����  
		c,   // [in]  ��������� �������� ������� ����     
		m    // [out] ���������� ��������� ������� ����  
	);

	std::cout << std::endl << "-------- ������ � ������� --------- ";
	std::cout << std::endl << "- ���������� ��������� : " << NN;
	std::cout << std::endl << "- ����������� �������  : " << V;
	std::cout << std::endl << "- ������� ���������    : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3)<<v[i] << " ";
	std::cout << std::endl << "- ��������� ���������  : ";
	for (int i = 0; i < NN; i++) std::cout << std::setw(3)<<c[i] << " ";
	std::cout << std::endl << "- ����������� ��������� �������: " << maxcc;
	std::cout << std::endl << "- ��� �������: ";
	int s = 0; for (int i = 0; i < NN; i++) s += m[i] * v[i];
	std::cout << s;
	std::cout << std::endl << "- ������� ��������: ";
	for (int i = 0; i < NN; i++) std::cout << " " << m[i];
	std::cout << std::endl << std::endl;

	system("pause");
	return 0;
}
