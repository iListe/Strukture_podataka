#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 200

struct _student;
typedef struct _student* Position;
struct _student
{
	char ime[MAX];
	char prezime[MAX];
	int godina_rodenja;
	Position Next;
};

void Insert(Position);
void PrintList(Position);
void InsertEnd(Position);
Position FindPrez(Position);
void DeletePrez(Position);
void InsertAfter(Position);
void InsertBefore(Position);
void SortList(Position);
void Print(Position);
void Read(Position);

void main()
{
	struct _student head;
	Position studentF = NULL;
	char izbor = 0;

	head.Next->Next;

	while ((izbor) != 'K')
	{
		printf("\r\n\r\n");
		printf("Unos\r\n");
		printf("Ispis\r\n");
		printf("Unos na kraj\r\n");
		printf("Pronadi po prezimenu\r\n");
		printf("Izbrisi po prezimenu\r\n");

		scanf_s("%c", &izbor, 1);

		switch (izbor) {
		case '1':
			Insert(&head);
			break;
		case'2':
			PrintList(head.Next);
			break;
		case'3':
			InsertEnd(&head);
			break;
		case '4':
			studentF = FindPrez(head.Next);
			if (studentF != NULL)
			{
				printf("\r\n Trazeni student je: %s %s %d", studentF->ime, studentF->prezime, studentF->godina_rodenja);
			}
			else

				printf("\r\nStudent  s trazenim prezimen om nije pronaden\r\n");
		}
	}
}

void Insert(Position P)
{
	Position q;
	q = (Position)malloc(sizeof(struct _student));
	if (q == NULL)
	{
		printf("GRESKA! Aloakcije memorije nije uspila");
	}
	else
	{
		printf("Unesi ime,prezime i godinu rodenja studenta");
		scanf(" %s %s %d", q->ime[MAX], q->prezime[MAX], q->godina_rodenja);

		q->Next = P->Next;
		P->Next = q;
	}
}
void PrintList(Position P)
{
	if (P == NULL)
	{
		printf("Lista je prazna");
	}
	else
	{
		printf("U listi se nalaze:");
	}

	while (P != NULL)
	{
		printf(" %s %s %d", P->ime, P->prezime, P->godina_rodenja);
		P = P->Next;
	}
}

void InsertEnd(Position P)
{
	while (P->Next != NULL)
	{
		P = P->Next;
		Insert(P);
	}
}

Position FindPrez(Position P)
{
	char prez[MAX];
	printf("Unesi prezime koje trazis");
	scanf("%s", prez, MAX);
	while (P != NULL && _strcmpi(P->prezime, prez) != 0)
	{
		P = P->Next;
	}
	return P;
}

void DeletePrez(Position P)
{
	Position tmp;
	char prez[MAX];
	printf("Unesi prezime koje oces izbrisat");
	scanf("%s", prez[MAX]);

	while (P->Next != NULL && _strcmpi(P->Next->prezime, prez) != 0)
		P = P->Next;
		tmp = P->Next;
	
	if (tmp != NULL)
	{
		P->Next = tmp->Next;
		printf("Iz liste se brise: %s %s %d", tmp->ime, tmp->prezime, tmp->godina_rodenja);
		free(tmp);
	}
}
void InsertAfter(Position P)
{
	Position tmp;
	tmp = FindPrez(P);
	if (tmp != NULL)
	{
		Insert(tmp);
	}
}
void InsertBefore(Position P)
{
	Position tmp;
	tmp = FindPrez(P);
	if (tmp != NULL)
	{
		Insert(tmp);
	}
}
void SortList(Position P)
{
	Position i,j, p, k, end;
	end = NULL;
	while (P->Next != end) {
		i = P;
		k = i->Next;
		j = k->Next;

		while (j != end) {
			if (_strcmpi(k->prezime, j->prezime) > 0)
			{
				k->Next = j->Next;
				j->Next = k;
				i->Next = j;
			}
			else
			{
				i = k;
				k = i->Next;
				j = k->Next;
			}
			end = k;
		}
	}
}
void Read(Position P)
{
	FILE* fp;
	char file_name[MAX];
	Position q;
	printf("Unesi datoteku za citanje");
	scanf("%s", file_name[MAX]);

	fopen(&fp, file_name, "r");
	if (fp == NULL)
	{
		printf("Datoteka nije otvorena",file_name);
	}
	else {
		while (!feof(fp))
		{
			q = (Position)malloc(sizeof(struct _student));
			if (q == NULL)
			{
				printf("Memorija nije alocirana");
			}
			else {
				scanf(fp, "%s %s %d", q->ime[MAX], q->prezime[MAX], &q->godina_rodenja);
				q->Next = P->Next;
				P->Next = q;

			}
			fclose(fp);
		}
	}
}
void Print(Position P)
{
	FILE* fp;
	char file_name[MAX];
	printf("Unesi datoteku za upis");
	scanf("%s", file_name[MAX]);

	fopen(&fp, file_name, "w");
	if (fp == NULL)
	{
		printf("Datoteka nije otvorena");
	}
	else {
		while (P != NULL)
		{
			printf(fp, "%s %s %d", P->ime[MAX], P->prezime[MAX], &P->godina_rodenja);
			P = P->Next;
		}
		fclose(fp);
	}


}
