#include <iostream>
#include <iomanip>
#include <limits>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void SearchMinEvenAndMax(int** a, const int n, int& minRow, int& minCol, int& maxRow, int& maxCol, int& minVal, int& maxVal);
void SwapElem(int** a, int& minRow, int& minCol, int& maxRow, int& maxCol);
void sumVal(int& sum, int& minVal, int& maxVal);
int main()
{
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n,sum;
	int minVal = numeric_limits<int>::max();
	int maxVal = numeric_limits<int>::min();
	int minRow, minCol, maxRow, maxCol;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	Print(a, n);
	SearchMinEvenAndMax(a, n, minRow, minCol, maxRow, maxCol, minVal, maxVal);
	SwapElem(a, minRow, minCol, maxRow, maxCol);
	Print(a, n);
	sumVal(sum, minVal, maxVal);
	int minEven;
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void sumVal(int& sum, int& minVal, int& maxVal) {
	sum = minVal + maxVal;
	cout << setw(4) << "sum: " << sum;
}
void SwapElem(int** a, int& minRow, int& minCol, int& maxRow, int& maxCol)
{
	int temp = a[minRow][minCol];
	a[minRow][minCol] = a[maxRow][maxCol];
	a[maxRow][maxCol] = temp;
}
void SearchMinEvenAndMax(int** a, const int n, int& minRow, int& minCol, int& maxRow, int& maxCol, int& minVal, int& maxVal)
{
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i < j) { 
				if (a[i][j] < minVal) {
					minVal = a[i][j];
					minRow = i;
					minCol = j;
				}
			}
			else if (i > j) {
				if (a[i][j] > maxVal) {
					maxVal = a[i][j];
					maxRow = i;
					maxCol = j;
				}
			}
		}
	}
}