#include <stdio.h>
#include <stdlib.h>


int main()
{
	float a, b, c;
	int opcja;

	printf("Wprowadz liczbe:\n");
	scanf("%f", &a);

	printf("Wprowadz kolejna liczbe:\n");
	scanf("%f", &b);

	printf("Wynik: %f\n", c = a + b);

	kolejna_liczba:
		printf("Czy chcesz dodac kolejna liczbe?\n1 - tak, 2 - nie\n");
		scanf("%d", &opcja);

		if(opcja == 2)
			exit(1);
		if(opcja == 1)
		{
			printf("Wprowadz kolejna liczbe:\n");
			scanf("%f", &a);
			printf("Wynik: %f\n", c = c + a);
			goto kolejna_liczba;
		}

	return 0;
}
