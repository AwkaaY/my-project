#include <iostream>
#include <time.h>
#include <windows.h>


using namespace std;


template <typename T> void ful(T mass[], int size)
{
	for (int j = 0; j < size; j++)
	{
		mass[j] = 1 + rand() % (100 - 1);
	}

}
template <typename T> void print(T mass[], int size)
{
	for (int j = 0; j < size; j++)
	{
		cout << mass[j] << " ";
	}
	cout << endl;
}

void zadanie1(int arr[], int size, int* summ, int* multi)
{
	for (int i = 0; i < size; i++)
	{
		*summ = *summ + arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		*multi = *multi * arr[i];
	}
}

void zadanie2(int arr[], int size, int* otr, int* pol, int* nul)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == 0)
		{
			*nul = *nul + 1;
		}
		else if (arr[i] < 0)
		{
			*otr = *otr + 1;
		}
		else if (arr[i] > 0)
		{
			*pol = *pol + 1;
		}
	}
}

bool check(int* nach, int B[], int size)
{
	bool prav;
	for (int i = 0; i < size; i++)
	{
		if (*nach == B[i])
		{
			prav = true;
		}
		else
		{
			return false;
		}
		nach++;
	}
	return prav;
}

void Search(int A[], int size1, int B[], int size2, int* start, int* IndxStart)
{
	bool prav;
	for (int i = 0; i < size1; i++)
	{
		if (A[i] == B[0])
		{
			if (check(&A[i], B, size2) == true)
			{
				*start = A[i];
				*IndxStart = i;
				break;
			}
			else
			{
				*start = 0;
			}
		}
	}
}



int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int const size = 10;
	int const size2 = 5;
	int mass[size];
	int sum = 0, multi = 1;
	int otr = 0, pol = 0, nul = 0;
	int start = 0, IndxStart = 0;
	ful(mass, size);
	print(mass, size);
	zadanie1(mass, size, &sum, &multi);
	cout << sum << " " << multi << endl;
	zadanie2(mass, size, &otr, &pol, &nul);
	cout << otr << " " << pol << " " << nul << endl;
	int arrayA[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int arrayB[size2] = { 4, 5, 6, 7, 8 };
	Search(arrayA, size, arrayB, size2, &start, &IndxStart);
	cout << start << " " << IndxStart;
	return 0;
}