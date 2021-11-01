#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct CvorLista;
typedef struct CvorLista *Lista;
struct CvorLista
{
	char ime[50];
	char prezime [50];
	int god;
	Lista next;
};

void Ispis (Lista);
void UnosP(Lista, char *, char *, int);
void UnosK(Lista, char *, char *, int);
Lista Trazi (Lista, char *);
Lista Trazi_Prethodni (Lista, char *);
void Brisi (Lista, char *);
void Unos_Ispred(Lista, char *, char *, char *, int);
void Unos_Iza(Lista, char *, char *, char *, int);
void Sort (Lista);
void Unos_Dat (Lista);
void Citaj_Dat(Lista);

int main()
{
	int odluka;
	char xime[50], xprezime[50], trazeni [50];
	int xgod;
	Lista pronadjeni;
	CvorLista head;
	head.next=NULL;
	do
	{
		printf("IZBORNIK:\nProgram za vas:\n");
		printf("\n1) ispisuje listu");
		printf("\n2) dinamicki dodaje novi element na pocetak liste");
		printf("\n3) dinamicki dodaje novi element na kraj liste");
		printf("\n4) pronalazi element u listi (po prezimenu)");
		printf("\n5) brise element iz liste");
		printf("\n6) dinamicki dodaje novi element iza odredjenog elementa");
		printf("\n7) dinamicki dodaje novi element ispred odredjenog elementa");
		printf("\n8) sortira listu po prezimenima osoba");
		printf("\n9) upisuje listu u datoteku");
		printf("\n10) cita listu iz datoteke");
		printf("\n11) kraj programa");
		printf("\n\nVas odabir:\t");
		scanf("%d", &odluka);
		fflush(stdin);
		switch(odluka)
		{
		case 1:
			{
				printf("\nVasa lista je:\n");
				Ispis(&head);
				break;
			}
		case 2:
			{
				printf("\nUnesite ime osobe koju zelite unijeti:\t");
				gets(xime);
				fflush(stdin);
				printf("\nUnesite prezime osobe koju zelite unijeti:\t");
				gets(xprezime);
				fflush(stdin);
				printf("\nUnesite godinu rodenja osobe koju zelite unijeti:\t");
				scanf("%d", &xgod);
				UnosP(&head, xime, xprezime, xgod);
				break;
			}
		case 3:
			{
				printf("\nUnesite ime osobe koju zelite unijeti:\t");
				gets(xime);
				fflush(stdin);
				printf("\nUnesite prezime osobe koju zelite unijeti:\t");
				gets(xprezime);
				fflush(stdin);
				printf("\nUnesite godinu rodenja osobe koju zelite unijeti:\t");
				scanf("%d", &xgod);
				UnosK(&head, xime, xprezime, xgod);
				break;
			}
		case 4:
			{
				printf("\nUnesite prezime osobe koju zelite pronaci:\t");
				gets(trazeni);
				fflush(stdin);
				pronadjeni=Trazi(&head, trazeni);
				if(pronadjeni!=NULL)
					printf("\nPodaci osobe koju ste trazili:\n%s\t%s\t%d", pronadjeni->ime, pronadjeni->prezime, pronadjeni->god);
				break;
			}
		case 5:
			{
				printf("\nUnesite prezime osobe koju zelite obrsati:\t");
				gets(trazeni);
				fflush(stdin);
				Brisi(&head, trazeni);
				break;
			}
		case 6:
			{
				printf("\nUnesite prezime osobe iza koje zelite unositi:\t");
				gets(trazeni);
				fflush(stdin);
				printf("\nUnesite ime osobe koju zelite unijeti:\t");
				gets(xime);
				fflush(stdin);
				printf("\nUnesite prezime osobe koju zelite unijeti:\t");
				gets(xprezime);
				fflush(stdin);
				printf("\nUnesite godinu rodenja osobe koju zelite unijeti:\t");
				scanf("%d", &xgod);
				Unos_Iza(&head, trazeni, xime, xprezime, xgod);
				break;
			}
		case 7:
			{
				printf("\nUnesite prezime osobe ispred koje zelite unositi:\t");
				gets(trazeni);
				fflush(stdin);
				printf("\nUnesite ime osobe koju zelite unijeti:\t");
				gets(xime);
				fflush(stdin);
				printf("\nUnesite prezime osobe koju zelite unijeti:\t");
				gets(xprezime);
				fflush(stdin);
				printf("\nUnesite godinu rodenja osobe koju zelite unijeti:\t");
				scanf("%d", &xgod);
				Unos_Ispred(&head, trazeni, xime, xprezime, xgod);
				break;
			}
		case 8:
			{
				Sort(&head);
				break;
			}
		case 9:
			{
				Unos_Dat(&head);
				printf("\nLista je ucitana u datoteku!");
				break;
			}
		case 10:
			{
				Citaj_Dat(&head);
				printf("\nLista je procitana iz datoteke!");
				break;
			}
		case 11:
			{
				break;
			}
		default:
			{
				printf("\nPogresan unos! Pokusaj ponovo!");
				break;
			}
		}
	printf("\n\n");
	}while(odluka!=11);
	return 0;
}

void Ispis (Lista s)
{
	if(s->next==NULL)
	{
		printf("Lista je prazna");
		return;
	}
	s=s->next;
	while(s!=NULL)
	{
		printf("\n%s\t%s\t%d", s->ime, s->prezime, s->god);
		s=s->next;
	}
}
void UnosP(Lista s, char *xime, char *xprezime, int xgod)
{
	Lista q=(Lista)malloc(sizeof(CvorLista));
	q->god=xgod;
	strcpy(q->ime, xime);
	strcpy(q->prezime, xprezime);
	q->next=s->next;
	s->next=q;
}
void UnosK(Lista s, char *xime, char *xprezime, int xgod)
{
	Lista q=(Lista)malloc(sizeof(CvorLista));
	q->god=xgod;
	strcpy(q->ime, xime);
	strcpy(q->prezime, xprezime);
	while(s->next!=NULL)
		s=s->next;
	q->next=s->next;
	s->next=q;
}
Lista Trazi (Lista s, char *trazeni)
{
	if(s->next==NULL)
	{
		printf("Lista je prazna");
		return NULL;
	}
	s=s->next;
	while(s!=NULL&&strcmp(s->prezime, trazeni))
		s=s->next;
	if(s==NULL)
		printf("\nElement s prezimenom %s ne postoji!", trazeni);
	return s;
}
Lista Trazi_Prethodni (Lista s, char *trazeni)
{
	while(s->next!=NULL&&strcmp(s->next->prezime, trazeni))
		s=s->next;
	if(s->next==NULL)
	{
		printf("\nElement s prezimenom %s ne postoji!", trazeni);
		return NULL;
	}
	return s;
}
void Brisi (Lista s, char *trazeni)
{
	Lista temp;
	s=Trazi_Prethodni(s, trazeni);
	if(s!=NULL)
	{
		temp=s->next;
		s->next=s->next->next;
		free(temp);
	}
}
void Unos_Ispred(Lista s, char *trazeni, char *xime, char *xprezime, int xgod)
{
	s=Trazi_Prethodni(s, trazeni);
	if(s!=NULL)
		UnosP(s, xime, xprezime, xgod);
}
void Unos_Iza(Lista s, char *trazeni, char *xime, char *xprezime, int xgod)
{
	s=Trazi(s, trazeni);
	if(s!=NULL)
		UnosP(s, xime, xprezime, xgod);
}
void Sort (Lista s)
{
	Lista i, j, prev_j, end, temp;
	end=NULL;
	i=s;
	while(i->next!=end)
	{
		prev_j=i;
		j=i->next;
		while(j->next!=end)
		{
			if(strcmp(j->prezime, j->next->prezime)>0)
			{
				temp=j->next;
				j->next=temp->next;
				temp->next=j;
				prev_j->next=temp;
				j=temp;
			}
			prev_j=prev_j->next;
			j=j->next;
		}
		end=j;
	}
}
void Unos_Dat (Lista s)
{
	FILE *datoteka;
	char ime_datoteke[50];
	printf("\nUnesite ime datoteke u koju zelite upisati Vase podatke:\t");
	gets(ime_datoteke);
	fflush(stdin);
	datoteka=fopen(ime_datoteke, "w");
	if(datoteka==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		return;
	}
	if(s->next==NULL)
	{
		printf("Lista je prazna");
		fclose(datoteka);
		return;
	}
	s=s->next;
	while(s!=NULL)
	{
		fprintf(datoteka, "\n%s\t%s\t%d", s->ime, s->prezime, s->god);
		s=s->next;
	}
	fclose(datoteka);
}
void Citaj_Dat(Lista s)
{
	FILE *datoteka;
	char xime[50], xprezime[50];
	int xgod;
	char ime_datoteke[50];
	printf("\nUnesite ime datoteke iz koje zelite procitati podatke:\t");
	gets(ime_datoteke);
	fflush(stdin);
	datoteka=fopen(ime_datoteke, "r");
	if(datoteka==NULL)
	{
		printf("\nGreska pri otvaranju datoteke!");
		return;
	}
	while(feof(datoteka)==0)
	{
		fscanf(datoteka, "%s%s%d", xime, xprezime, &xgod);
		UnosK(s, xime, xprezime, xgod);
	}
}
