#include<stdio.h>
float aver(float *a,int n);
int main()
{
	int i;
	float sco[5],av;
	for(i = 0;i<5;i++)
		scanf("%f",&sco[i]);
	av = aver(sco,5);
	printf("average = %5.2f",av);
	return 0;
}
float aver(float *a,int n)
{
	int i;
	float av,s = a[0];
	for(i = 1;i<n;i++)
	s+=*a++;
	av = s/n;
	return av;
}
