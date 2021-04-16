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

int* ChangeArray(int* mass, int* s) {
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
	int* newArray = (int*)malloc(*s * sizeof(int));
	for (int i = 0; i < s; i++) {
		newArray[i] = mass[i];
	}
	int a = sizeof(newArray);
	free(mass);
	return newArray;
}

int main() {
	int *c = (int*)malloc(N * sizeof(int));
	int s;
	scanf("%d", &s);
	for (int i = 0; i < s; i++) {
		scanf("%d", &c[i]);
	}
	int a = sizeof(c);
	c=ChangeArray(c, &s);
	a = sizeof(c);
	printf("\n");
	for (int i = 0; i < s; i++) {
		printf("%d ", c[i]);
	}
}