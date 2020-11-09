#include<stdio.h>

bool checkSB(int, int*, int*, int*);

struct Taste
{
	int S;
	int B;
};

int main()
{
	int N;
	Taste taste[10];
	int result[2];
	if (scanf_s("%d", &N) != 1)
	{
		printf("ERROR");
		return 1;
	}
	else if (N < 1 || N > 10)
	{
		printf("ERROR");
		return 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (scanf_s("%d", &taste[i].S) != 1)
		{
			printf("ERROR");
			return 1;
		}
		if (scanf_s("%d", &taste[i].B) != 1)
		{
			printf("ERROR");
			return 1;
		}
	}
	if (!checkSB(N, &taste[0].S, &taste[0].B, &result[0]))
	{
		printf("ERROR");
		return 1;
	}
	int diff = result[0] - result[1];
	if (diff < 0)
	{
		diff = diff * (-1);
	}
	printf("%d", diff);
	return 0;
}

bool checkSB(int n, int* s, int* b, int* r)
{
	long long allS = 1, allB = 0;
	for (int i = 0; i < n; i++, s = s + 2)
	{
		allS = allS * (long long)*s;
	}
	for (int j = 0; j < n; j++, b = b + 2)
	{
		allB = allB + (long long)*b;
	}
	if (allS > 1000000000 || allB > 1000000000)
		return false;
	else
	{
		*r = (int)allS;
		*(r + 1) = (int)allB;
		return true;
	}
}
