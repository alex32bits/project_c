#include <stdio.h>
#include <stdlib.h>

typedef struct elem{
    int info;
    struct elem *urm;
}elem;


// typedef struct{
//     elem *ultim;
// }lst;
// lst ult;

elem *new_nod(int n)
{ 
    elem *p;
    p=(elem*)malloc(1*sizeof(elem));
    if(p==NULL)
    {
        perror(NULL);
        exit(-1);
    }
    p->info=n;
    p->urm=NULL;
    return p;
}
elem *adaugaInceput(elem *lista,int n)
{   
    elem *nod;
    nod=new_nod(n);
    nod->urm=lista;
    lista=nod;
    return lista;
}

elem *adaugaSfarsit(elem *lista,int n)
{elem *q,*nod;
    if(lista==NULL)
    {
        lista=new_nod(n);
    }
    else
    {
      for(q=lista;q->urm!=NULL;q=q->urm);
      nod=new_nod(n);
      q->urm=nod;
    }
    
   return lista; 
}
void afisare(elem *lista)
{
    elem *p;
    for(p=lista;p!=NULL;p=p->urm)
    {
        printf("%d-->",p->info);
    }
    printf("\n");
}

//apl 7.1
int egale(elem *l1,elem *l2)
{ 
    elem *p1,*p2;
    
    p1=l1;
    p2=l2;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->info!=p2->info)
        {
            return 0;
        }
        p1=p1->urm;
        p2=p2->urm;
    }

    if(p1==NULL && p2==NULL)
       return 1;
    else    
       return 0;
}
//apl 7.2

elem *invers(elem *lista)
{
    elem *p;
    elem *cur;
    elem *q;
    for(p=NULL,cur=lista,q=lista->urm;cur->urm!=NULL;)//q->urm
    {
        cur->urm=p;
        p=cur;
        cur=q;
        q=q->urm;
    }
    cur->urm=p;
    lista=cur;
 
    return lista;
}

//apl 7.3

int exista(elem *lista,int val)
{
    for(elem*p=lista;p!=NULL;p=p->urm)
    {
        if(p->info==val)
        return 1;
    }
    return 0;
}

elem *reuniune(elem *lista1,elem *lista2)
{
   elem *rez=NULL;
   while(lista1!=NULL)
   {
    if(exista(rez,lista1->info)==0)
    {
        rez=adaugaSfarsit(rez,lista1->info);
    }
    lista1=lista1->urm;  
   }

   while(lista2!=NULL)
   {
    if(exista(rez,lista2->info)==0)
    {
        rez=adaugaSfarsit(rez,lista2->info);;
    }
    lista2=lista2->urm;
   }
   return rez;

}

//7.4
elem *sterge(elem *lista,int n)
{
    elem *p;
    elem *f;
    if(lista==NULL)
    {
        return NULL;
    }
    if(lista->info==n)
    {
        f=lista;
        lista=lista->urm;
        free(f);
        return lista;
        
    }
    for(p=lista;p->urm!=NULL ;p=p->urm)
    {
        if(p->urm->info==n)
        {
         f=p->urm;
         p->urm=p->urm->urm;
         free(f);
         return lista;
        }    
    }
   return lista;
}


//7.5
int egale2(elem* lista1,elem* lista2)
{
    elem *p1=lista1;
    elem *p2=lista2;

    while(p1!=NULL)
    {
       if(exista(lista2,p1->info)==0)
       {
        return 0;
       }
       p1=p1->urm;
    }

    while(p2!=NULL)
    {
       if(exista(lista1,p2->info)==0)
       {
        return 0;
       }
       p2=p2->urm;
    }
    return 1;
}


//functie pentru a adauga sortat in lista de produse
//Complexitate O(n) n-nr de produse
elem* adauga_sortat(elem* lista, int val)
{
	elem* p = new_nod(val);
    if (lista == NULL)
		return p;
	if (lista->info > p->info)
	{
		p->urm = lista;
		lista = p;
		return lista;
	}
	elem* q;
	for (q = lista; q->urm != NULL; q = q->urm)
	{
		if (q->urm->info > p->info)
		{
			p->urm = q->urm;
			q->urm = p;
			return lista;
		}
	}
	q->urm = p;
	return lista;
}

int main()
{
elem *lista1=NULL;
    lista1=adaugaInceput(lista1,2);
    lista1=adaugaInceput(lista1,3);
    lista1=adaugaInceput(lista1,1);
    lista1=adaugaSfarsit(lista1,97);
    lista1=adaugaSfarsit(lista1,99);
    printf("lista 1:");
    afisare(lista1);

elem *lista2=NULL;
    lista2=adaugaInceput(lista2,3);
    lista2=adaugaInceput(lista2,1);
    lista2=adaugaInceput(lista2,2);
    lista2=adaugaSfarsit(lista2,99);
    printf("lista 2:");
    afisare(lista2);

elem *lista3=NULL;
lista3=adauga_sortat(lista3,100);
lista3=adauga_sortat(lista3,5);
lista3=adauga_sortat(lista3,10);
lista3=adauga_sortat(lista3,3);
lista3=adauga_sortat(lista3,1);
printf("lista 3:");
afisare(lista3);

int sel;

printf("val meniu: ");
scanf("%d",&sel);
while(sel!=0)
{
    
    switch(sel)
    {
        case 1:
        {
            printf("l1 si l2 sunt egale: %d\n",egale(lista1,lista2));
            printf("\n");
            break;
        }
        case 2:
        {   printf("lista1 inainte de inversare: ");
            afisare(lista1);
            lista1=invers(lista1);
            printf("\n");
            printf("dupa inversare: ");
            afisare(lista1);
            printf("\n");
            break;
        }
        case 3:
        {
            printf("l1:");
            afisare(lista1);
            printf("l2:");
            afisare(lista2);
            elem *uni=reuniune(lista1,lista2);
            printf("\n");
            printf("reuniune: ");
            afisare(uni);
            printf("\n");
            break;
        }

        case 4:
        {    
            printf("lista3: ");
            afisare(lista3);
            printf("ce val vrei sa stergi: ");
            int s;
            scanf("%d",&s);
            lista3=sterge(lista3,s);
            printf("\nlista3 dupa stergere: ");
            afisare(lista3);
            printf("\n");
            break;
        }
        case 5:
        {
            printf("l1 si l2 contin aceleasi elemente: %d\n",egale2(lista1,lista2));
            printf("\n");
            break;
        }
        case 6:
        {
            afisare(lista3);
            printf("ce vrei sa adaugi: ");
            int new=0;
            scanf("%d",&new);
            lista3=adauga_sortat(lista3,new);
            afisare(lista3);
            printf("\n");
            break;
        }
    }
    printf("val meniu: ");
    scanf("%d",&sel);
}


return 0;

}