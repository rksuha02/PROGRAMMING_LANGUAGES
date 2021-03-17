#include <stdio.h>
#include <locale.h>

struct city
{
	char name[30];
};

int Getfirst(struct city* cities, int* m, int n) {
	for (int i = 0; i < n; i++) {
		char letter = tolower(cities[i].name[0]);
		int j = 0;
		for (j = 0; j < n; j++) {
			int length = strlen(cities[j].name);
			if ((i != j) && (letter == cities[j].name[length - 1])) {
				break;
			}
		}
		if (j == n) {
			m[i] = 0;
			return i;
		}
	}
	m[0] = 0;
	return 0;
}

void GetSequenceOrder(int indexElem, int* m, struct city* cities, int n)
{
	int index = 1;
	int lengthFirstElem = strlen(cities[indexElem].name);
	char lastChar = tolower(cities[indexElem].name[lengthFirstElem - 1]);
	for (int i = 0; i < n; i++)
	{
		char c = tolower(cities[i].name[0]);
		if ((i != indexElem) && (lastChar == c) && (m[i]<0)) {

			m[i] = index;
			index++;
			int length = strlen(cities[i].name);
			lastChar = tolower(cities[i].name[length - 1]);
			indexElem = i;
			i = -1;
		}
	}
}

void GetResult(int* m, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (m[i] == n - 1)
		{
			printf("YES");
			return;
		}
	}
	printf("NO");
}

void main() {
	setlocale(LC_ALL, "RU");

	struct city cities[100];
	int i = 0;
	FILE* f;
	f = fopen("input.txt", "r");
	int m[100];
	while (!feof(f)) {
		fscanf(f, "%s", &cities[i]);
		i++;
	}
	int firstElem = Getfirst(&cities, m, i);
	GetSequenceOrder(firstElem, m, &cities, i);
	GetResult(m, i);
}
