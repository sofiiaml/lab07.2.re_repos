#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std; 
void Create(int** a, const int n, const int k, const int Low,
	const int High, int nIndex) {
	if (nIndex == n)
		return;
	for (int i = 0; i < k; i++) {
		a[nIndex][i] = Low + rand() % (High - Low + 1);
	}
	Create(a,n, k, Low, High, nIndex + 1);
}
void Print(int** a, const int n, const int k, int nIndex) {
	if (nIndex == n)
		return;
	for (int j = 0; j < k; j++)
		cout << setw(4) << a[nIndex][j];
	cout << endl;
	Print(a, n, k, nIndex + 1);
}

void Sort(int** a, const int n, const int k, int i) {
	if (i < n - 1) {
		int imin = 0;
		int imax = 0;
		for (int j = 0; j < k; j++)
		{
			if (a[i][j] < a[i][imin])
				imin = j;
			if (a[i + 1][j] > a[i + 1][imax])
				imax = j;

		}
		int temp = a[i][imin];
		a[i][imin] = a[i + 1][imax];
		a[i + 1][imax] = temp;
		Sort(a, n, k, i + 2);
	}
}
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n, k;
	cout << "n = "; cin >> n;
	cout << "k = "; cin >> k;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[k];
	Create(a, n, k, Low, High,0);
	cout << "Array:"; cout << endl;
	Print(a, n, k,0);
	Sort(a, n, k,0);
	cout << "Changed Array:"; cout << endl;
	Print(a, n, k,0);
	delete[] a;
	return 0;
}