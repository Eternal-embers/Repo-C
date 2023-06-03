#include<stdio.h>
int main()
{
	int n, i;
	int cont = 0;
	char a[100];
	scanf("%d", &n);
	while (n)
	{
		if (n % 26 == 0)
		{
			a[cont++] = 'Z';
			n /= 26;
			n--;
		}
		else {
			a[cont++] = n % 26 + 'A'-1;
			n /= 26;
		}

	}
	for (i = cont - 1; i >= 0; i--)
	{
		printf("%c", a[i]);
	}

	return 0;
}
