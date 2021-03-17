#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100 
void Shift(int* mass, int startShift, int s)
{
	for (int i = startShift; i < s - 1; i++) {
		mass[i] = mass[i + 1];
	}
}

void ChangeArray(int* mass, int* s) {
	for (int i = 0; i < *s; i++) {
		for (int j = i + 1; j < *s; j++) {
			if (mass[i] == mass[j])
			{
				Shift(mass, j, *s);
				*s=*s-1;
				j--;
			}
		}
	}
}

int main() {
	int c[N];
	int s;
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%d", &c[i]);
	}

	ChangeArray(c, &s);

	printf("\n");
	for (int i = 0; i < s; i++) {
		printf("%d ", c[i]);
	}
}