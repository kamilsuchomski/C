#include <stdio.h>
#include <stdlib.h>

int main()
{

	float a, b;
	int opcja;

	printf("Wprowadz pierwsza liczbe:\n");
	scanf("%f", &a);
	printf("Wprowadz druga liczbe:\n");
	scanf("%f", &b);
	printf("Wybierz dzialanie:\n");
	printf("1 - dodawanie\n2 - odejmowanie\n3 - mnozenie\n4 - dzielenie\n");
	scanf("%d", &opcja);

	switch(opcja)
	{
		case 1:
			printf("%f + %f = %f\n", a, b, a + b);
			break;
		case 2:
			printf("%f - %f = %f\n", a, b, a - b);
			break;
		case 3:
			printf("%f * %f = %f\n", a, b, a * b);
			break;
		case 4:
			printf("%f / %f = %f\n", a, b, a / b);
			break;
		default:
			printf("Niepoprawny wybor!\n");
	}

	return 0;
}
