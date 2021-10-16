#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 128

typedef struct
{
	char ime[MAX];
	char prezime[MAX];
	int bodovi;
	float prosjek;
} student;

int broji_retke(char* redak);
int citaj(char* redak, student* s, int n);
int prosjek(char* redak, student* s, int max, int n);
int ispis(char* redak, student* s, int n);

int main()
{
	int n;
	student* s;
	int max = 0;
	char redak[1024];

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
	{
		printf("Greska pri otvaranju datoteke!");
	}
	fgets(redak, 1024, fp);

	n = broji_retke(redak);

	s = (student*)malloc(n * sizeof(student));
	max = citaj(redak, s, n);
	prosjek(redak, s, n, max);
	ispis(redak, s, n);
	close(fp);
	return 0;
}

int broji_retke(char* redak)
{
	int znak = 0;
	int brojac = 0;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
	{
		printf("Greska pri otvaranju datoteke!");
	}
	while ((znak) !=feof)
	{
		if (znak == '\n')
			brojac++;
	}
	close(fp);
	return brojac;
}
int citaj(char* redak, student* s, int n)
{
	int i, max;
	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
		printf("Greska pri otvaranju datoteke!");
	for (i = 0; i < n; i++)
	{
		scanf_s(fp, "%d", &s[i].bodovi);
		scanf_s(fp, "%s", s[i].ime);
		scanf_s(fp, "%s", s[i].prezime);
	}
	max = s[0].bodovi;
	for (i = 1; i<n;i++)
	{
		if (s[i].bodovi > max)
			max = s[i].bodovi;
	}
	close(fp);
	return max;
}
int prosjek(char* redak, student* s, int max, int n)
{
	int i;
	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
		printf("Greska pri otvaranju datoteke!");
	for (i = 0; i < n; i++)
	{
		s[i].prosjek = (int)(s[i].bodovi / max) * 100;

	}
	close(fp);
	return 0;
}
int ispis(char* redak, student* s, int n)
{
	int i;
	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL)
	{
		printf("Greska pri otvaranju datoteke");
	}
	printf("\nIme\nPrezime\n\Bodovi\nProsjek\n\n");
	for (i = 0; i < n; i++)
	{
		printf("%s", s[i].ime);
		printf("%s", s[i].prezime);
		printf("%d", s[i].bodovi);
		printf("%lf", s[i].prosjek);
	}
	close(fp);
	return 0;
}