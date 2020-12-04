#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<malloc.h>
#include<string.h>
#define MAX 20

typedef struct _student{
	char ime[MAX];
	char prezime[MAX];
	int abs_bodovi;
	float rel_bodovi;
}student;

int retci();
student* citajIzdat(student*, int );
int ispis(student*, int);
int max_bodovi(student* s, int);
student* racunajRelativne(student*, int, int);

int main()
{
	int broj_redaka,max;
	broj_redaka = retci();
	student* s;
	s=(student*)malloc(sizeof(student)*broj_redaka);
	s=citajIzdat(s,broj_redaka);
	max=max_bodovi(s,broj_redaka);
	s=racunajRelativne(s,broj_redaka,max);
	ispis(s,broj_redaka);
	return 0;
}

int retci()
{
	FILE* fp = NULL;
	int broj_redaka=0;
	char* buffer;
	buffer=(char*)malloc(1024*sizeof(char));
	fp = fopen("studenti.txt", "r");
	if (NULL==fp)
	{
		printf("Greska u otvaranju datoteke!");
		return -1;
	}

	while (!feof(fp)))
	{
		fgets(buffer,1024,fp);
		broj_redaka++;
	}

	fclose(fp);
	return broj_redaka;
}

student* citajIzdat(student* s, int broj_redaka)
{
	FILE* fp = NULL;
	int i;
	fp = fopen("studenti.txt", "r");
	{
		if (fp == NULL)
		printf("Greska u otvaranju datoteke!");
		return s;
	}
	while(!feof(fp))

	{
		for (i = 0; i < broj_redaka; i++) {

		fscanf(fp, "%d ", &s[i].abs_bodovi);
		fscanf(fp, "%s ", s[i].ime);
		fscanf(fp, "%s ", s[i].prezime);
	}
	}
	return s;
}

int ispis(student* s, int broj_redaka)
{
	int i;
	printf("Lista je prazna");
	for(i=0; i<broj_redaka;i++)
	{
		printf(" %s %s %d %f\n",s[i].ime, s[i].prezime,s[i].aps_bodovi,s[i].rel_bofovi);
	}
	return 0;
}

int max_bodovi(student* s, int broj_redaka)
{
	int i,max;
	max=s[0].abs_bodovi;
	for(i=1;i<broj_redaka;i++)
	{
		if(s[i].aps_bodovi>max)
			max=s[i].aps_bodovi;
}
	return max;
}
student* racunajRelativne(student* s,int broj_redaka, int max)
{
	int i;
	for(i=0;i<broj_redaka;i++)
	{
		s[i].rel_bodovi=(float)s[i].aps_bodovi/max *100;
	}
	return s;
}
