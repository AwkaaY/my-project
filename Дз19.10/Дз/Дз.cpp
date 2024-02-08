#include <iostream>
#include <time.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	cout << "Задание 1:\n";
	int const size = 5;
	int array[size], min, max;
	for (int i = 0; i < size ; i++) 
	{
		array[i] = rand();
		cout << array[i] << " ";
	}
	min = array[0];
	max = array[0];
	for (int i = 0; i < size; i++) 
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	cout << "\nMin:" << min; 
	cout << "\nMax:" << max; 
	cout << "\n Задание 2:\n";
	int mass[size];
	int dia1, dia2, summ = 0, gr; 
	cout << "Введите диапазон рандомных чисел от и до через пробел:" << endl;
	cin >> dia1 >> dia2;
	for (int i = 0; i < size; i++)
	{
		mass[i] = dia1 + rand() % (dia2 - dia1);
		cout << mass[i] << " ";
	}
	cout << "\nВведите меньше какого числа должны быть элементы:" << endl;
	cin >> gr;
	for (int i = 0; i < size; i++)
	{
		if (mass[i] < gr)
		{
			summ = summ + mass[i];
		}
	}
	cout << summ;
	cout << "\n Задание 3: \n";
	int god[12], mMin, mMax, diap1, diap2;
	for (int i = 0; i < 12; i++) 
	{
		cout << "Введите прибыль " << i + 1 << " месяца\n";
		cin >> god[i];
	}
	cout << "Введите диапазон от и до включительно через пробел\n";
	cin >> diap1 >> diap2;
	mMax = diap1 - 1;
	mMin = diap1 - 1;
	for (int i = diap1; i <= diap2 - 1; i++)
	{
		if (god[i] < god[mMin]) 
		{
			mMin = i;
		}
		if (god[i] > god[mMax])
		{
			mMax = i; 
		}
	}
	cout << "Большая прибыль в " << mMax + 1 << " месяце\n"; 
	cout << "Меньшая прибыль в " << mMin + 1 << " месяце\n";
	int sumO, min4, max4, multi, chet, first, last, pass; 
	int const SIZE = 10;
	int array4[SIZE] = { 15,26,49,-78,-2,38,342,23,6,-13 };
	cout << "Числа выбраны для примера их можно менять, как и размер массива\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << array4[i] << " ";
	}
	sumO = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (array4[i] < 0)
		{
			sumO = sumO + array4[i];
		}
	}
	cout << "\nСумма отрицательных чисел:" << sumO;
	min4 = 0;
	max4 = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (array4[i] <= array4[min4])
		{
			min4 = i; 
		}
		if (array4[i] >= array4[max4])
		{
			max4 = i; 
		}
	}
	cout << "\nМинимальноe число номер(нумерация идет начиная с нуля): " << min4  << "\nМаксимальное число номер(нумерация идет начиная с нуля): " << max4;
	multi = 1;
	if (min4 == max4 + 1 || max4 == min4 + 1)
	{
		cout << "\n Произведение чисел между минимальным и максимальным: " << 0;
	}
	if (min4 < max4 && max4 != min4 + 1) 
	{
		for (int i = min4 + 1; i < max4; i++)
		{
			multi = array4[i] * multi; 
		}
		cout << "\n Произведение чисел между минимальным и максимальным: " << multi;
	}
	if (min4 > max4 && min4 != max4 + 1) 
	{
		for (int i = max4 + 1; i < min4 ; i++)
		{
			multi = array4[i] * multi;  
		}
		cout << "\n Произведение чисел между минимальным и максимальным: " << multi;
	}
	chet = 1;
	for (int i = 0; i < SIZE; i++) 
	{
		if (i % 2 == 0)
		{
			chet = chet * array4[i];	
		}
	}
	cout << "\nПроизведение чисел под четными номерами начиная с 0: " << chet;
	first = -1;
	last = 0;
	for (int i = 0; i < SIZE; i++) 
	{
		if(array4[i] < 0)
		{
			last = i;
		}
		if (array4[i] < 0 && first == -1)
		{
			first = i;
		}
	}
	cout << "\nПервое отрицательное число номер: " << first << "\n Последнее отрицательное число номер: " << last;
	pass = 0;
	for (int i = first + 1; i < last; i++)
	{
		pass = pass + array4[i];
	}
	cout << "\n Сумма чисел между первым и последним отрицательным чисом: " << pass;

	return 0;
}