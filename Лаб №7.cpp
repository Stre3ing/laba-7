// Лаб №7.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>

using namespace std;

const int n = 7;
int i, j, M[n][n];
bool* v = new bool[n];

void dfs(int st)
{
	int k;
	cout << st + 1 << " ";
	v[st] = true;
	for (k = 0; k <= n; k++)
		if ((M[st][k] != 0) && (!v[k]))
			dfs(k);
}

void main()
{
	setlocale(LC_ALL, "Rus");
	int s;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == j)
				M[i][j] = 0;
			if (i < j)
				M[i][j] = rand() % 2;
			M[j][i] = M[i][j];
		}
	}
	cout << "Матрица смежности графа: " << endl;
	for (i = 0; i < n; i++)
	{
		v[i] = false;
		for (j = 0; j < n; j++)
			cout << " " << M[i][j];
		cout << endl;
	}
	cout << "Введите стартовую вершину для обхода: "; cin >> s;
	cout << "Порядок обхода: ";
	dfs(s - 1);
	delete[]v;
	system("pause>>void");
}
