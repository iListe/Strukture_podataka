/*Napisati program koji pomoæu vezanih listi (stabala) predstavlja strukturu direktorija.
Omoguæiti unos novih direktorija i pod-direktorija, ispis sadržaja direktorija i
povratak u prethodni direktorij. Toènije program treba preko menija simulirati
korištenje DOS naredbi: 1- "md", 2 - "cd dir", 3 - "cd..", 4 - "dir" i 5 – izlaz.*/

#include <stdio.h>
#include <stdlib.h> //malloc()
#include <string.h> //strcpy()

struct CvorStablo;
struct CvorLista;
typedef CvorStablo * Stablo;
typedef CvorLista * Lista;
struct CvorStablo
{
	char ime [50];
	Stablo dijete;
	Stablo brat;
};
struct CvorLista
{
	Stablo naddirektorij;
	Lista next;
};

void Md (Stablo, char *);
Stablo Cd (Stablo, char *, Lista stog);
Stablo Cd_ (Stablo, Lista stog);
void Dir (Stablo);
void Push (Lista, Stablo);
Stablo Pull (Lista);

int main()
{
	Stablo direktorij=(Stablo)malloc(sizeof(CvorStablo));
	direktorij->brat=direktorij->dijete=NULL;
	CvorLista Stog;
	Stog.next=NULL;
	char odluka;
	char xime[50];
	do{
		printf("Odaberite naredbu:");
		printf("\n1)md\t\t->Stvara novi direktrorij");
		printf("\n2)cd dir\t->Ulazi u direktorij");
		printf("\n3)cd..\t\t->vraca se na prethodnu raaziju direktroija");
		printf("\n4)dir\t\t->Ispisuje trenutnu razinu direkorija");
		printf("\n5)Izlaz");
		printf("\nVasa odluka:\t");
		fflush(stdin);
		scanf("%c", &odluka);
		switch(odluka)
		{
		case '1':
			{
				printf("\nUnesi ime novog direktorija:\t");
				fflush(stdin);
				gets(xime);
				Md(direktorij, xime);
				break;
			}
		case '2':
			{
				printf("\nUnesi ime direktorija u kojeg zelite uci:\t");
				fflush(stdin);
				gets(xime);
				direktorij=Cd(direktorij, xime, &Stog);
				break;
			}
		case '3':
			{
				direktorij=Cd_(direktorij, &Stog);
				break;
			}
		case '4':
			{
				printf("\nDirektoriji na trenutnoj razini:\n");
				Dir(direktorij);
				break;
			}
		case '5':
			{
				break;
			}
		default:
			{
				printf("Pogresan unos! Pokusaj ponovo!");
				break;
			}
		}
	printf("\n\n");
	}while(odluka!='5');
	return 0;
}

void Md (Stablo dir, char *xime)
{
	Stablo q=(Stablo)malloc(sizeof(CvorStablo));
	strcpy(q->ime, xime);
	q->dijete=NULL;
	q->brat=NULL;
	if(dir->dijete==NULL)
		dir->dijete=q;
	else
	{
		if(strcmp(dir->dijete->ime, xime)>0)
		{
			q->brat=dir->dijete;
			dir->dijete=q;
		}
		else
		if(strcmp(dir->dijete->ime, xime)==0)
			printf("\nDirektorij s tim imenom vec postoji");
		else
		{
			dir=dir->dijete;
			while(dir->brat!=NULL&&strcmp(dir->brat->ime, xime)<0)
				dir=dir->brat;
			if(dir->brat==NULL||strcmp(dir->brat->ime, xime)>0)
			{
				q->brat=dir->brat;
				dir->brat=q;
			}
			else
				printf("\nDirektorij s tim imenom vec postoji");
		}
	}
}
Stablo Cd (Stablo dir, char *xime, Lista stog)
{
	Stablo pom;
	if(dir->dijete==NULL)
	{
		printf("\nTrenutni direktorij nema poddirektorija!");
		return dir;
	}
	pom=dir->dijete;
	while(pom!=NULL&&strcmp(pom->ime, xime)!=0)
		pom=pom->brat;
	if(pom==NULL)
	{
		printf("\nDirektorij kojeg pokusavate otvoriti ne postoji!");
		return dir;
	}
	Push(stog, dir);
	return pom;
}
Stablo Cd_ (Stablo dir, Lista stog)
{
	Stablo x=Pull(stog);
	if(x==NULL)
	{
		printf("\nNalazite se na najvisoj razini direktorija!");
		return dir;
	}
	return x;
}
void Dir (Stablo dir)
{
	if(dir->dijete==NULL)
	{
		printf("\nMapa je prazna");
		return;
	}
	dir=dir->dijete;
	while(dir!=NULL)
	{
		printf("%s\t", dir->ime);
		dir=dir->brat;
	}
}
void Push (Lista stog, Stablo xel)
{
	Lista q =(Lista)malloc(sizeof(CvorLista));
	q->naddirektorij=xel;
	q->next=stog->next;
	stog->next=q;
}
Stablo Pull (Lista stog)
{
	Lista temp;
	Stablo xel;
	temp=stog->next;
	xel=stog->next->naddirektorij;
	stog->next=stog->next->next;
	free(temp);
	return xel;
}