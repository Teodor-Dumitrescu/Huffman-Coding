#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;


struct nod
{
    nod *st,*dr;
    int fr;
    char s;
    int fii;
    nod *st1,*dr1;
    char cod[100];
};
nod *t;
char zero[]="zero";

struct litere
{
    char lit;
    char cod[10];
};
litere vector_litere[30];
void adaugare(nod *&prim,nod *&sec)
{

    if(prim==NULL)
    {
        prim=sec;
        prim->st=NULL;
        prim->dr=NULL;
        prim->fii=0;
    }
    else
    {
        prim->fii++;
        if(prim->st==NULL)
        {
            adaugare(prim->st,sec);
            if(prim->fr>prim->st->fr)
            {
                int aux_int;
                char aux_s;

                aux_int=prim->fr;
                prim->fr=prim->st->fr;
                prim->st->fr=aux_int;

                aux_s=prim->s;
                prim->s=prim->st->s;
                prim->st->s=aux_s;

                nod *aux_st1,*aux_dr1;
                aux_st1=prim->st1;
                aux_dr1=prim->dr1;
                prim->st1=prim->st->st1;
                prim->dr1=prim->st->dr1;
                prim->st->st1=aux_st1;
                prim->st->dr1=aux_dr1;
                sec=prim;
            }
        }
        else if(prim->dr==NULL)
        {
            adaugare(prim->dr,sec);
            if(prim->fr>prim->dr->fr)
            {
                int aux_int;
                char aux_s;

                aux_int=prim->fr;
                prim->fr=prim->dr->fr;
                prim->dr->fr=aux_int;

                aux_s=prim->s;
                prim->s=prim->dr->s;
                prim->dr->s=aux_s;

                nod *aux_st1,*aux_dr1;
                aux_st1=prim->st1;
                aux_dr1=prim->dr1;
                prim->st1=prim->dr->st1;
                prim->dr1=prim->dr->dr1;
                prim->dr->st1=aux_st1;
                prim->dr->dr1=aux_dr1;
                sec=prim;
            }
        }
        else if(prim->st->fii==prim->dr->fii)
        {
            adaugare(prim->st,sec);
            if(prim->fr>prim->st->fr)
            {
                int aux_int;
                char aux_s;

                aux_int=prim->fr;
                prim->fr=prim->st->fr;
                prim->st->fr=aux_int;

                aux_s=prim->s;
                prim->s=prim->st->s;
                prim->st->s=aux_s;

                nod *aux_st1,*aux_dr1;
                aux_st1=prim->st1;
                aux_dr1=prim->dr1;
                prim->st1=prim->st->st1;
                prim->dr1=prim->st->dr1;
                prim->st->st1=aux_st1;
                prim->st->dr1=aux_dr1;
                sec=prim;
            }
        }
        else if(prim->st->fii>prim->dr->fii)
        {
            int toti=prim->fii+1;
            while(toti>3)
                toti=toti/2;
            if(toti==2)
            {
                adaugare(prim->st,sec);
                if(prim->fr>prim->st->fr)
                {
                    int aux_int;
                    char aux_s;

                    aux_int=prim->fr;
                    prim->fr=prim->st->fr;
                    prim->st->fr=aux_int;

                    aux_s=prim->s;
                    prim->s=prim->st->s;
                    prim->st->s=aux_s;

                    nod *aux_st1,*aux_dr1;
                    aux_st1=prim->st1;
                    aux_dr1=prim->dr1;
                    prim->st1=prim->st->st1;
                    prim->dr1=prim->st->dr1;
                    prim->st->st1=aux_st1;
                    prim->st->dr1=aux_dr1;
                    sec=prim;
                }
            }
            if(toti==3)
            {
                adaugare(prim->dr,sec);
                if(prim->fr>prim->dr->fr)
                {
                    int aux_int;
                    char aux_s;

                    aux_int=prim->fr;
                    prim->fr=prim->dr->fr;
                    prim->dr->fr=aux_int;

                    aux_s=prim->s;
                    prim->s=prim->dr->s;
                    prim->dr->s=aux_s;

                    nod *aux_st1,*aux_dr1;
                    aux_st1=prim->st1;
                    aux_dr1=prim->dr1;
                    prim->st1=prim->dr->st1;
                    prim->dr1=prim->dr->dr1;
                    prim->dr->st1=aux_st1;
                    prim->dr->dr1=aux_dr1;
                    sec=prim;
                }
            }
        }
    }
}
void decapitare(nod *&prim,int &aux_int,char &aux_s,nod *&aux_st1,nod *&aux_dr1)
{
    if(prim->st==NULL && prim->dr==NULL)
    {
        aux_int=prim->fr;
        aux_s=prim->s;
        aux_st1=prim->st1;
        aux_dr1=prim->dr1;
        prim=NULL;
    }
    else
    {
        prim->fii--;
        if(prim->dr==NULL)
        {
            decapitare(prim->st,aux_int,aux_s,aux_st1,aux_dr1);
        }
        else if(prim->st->fii>prim->dr->fii)
        {
            int noduri=prim->fii+2;
            while(noduri>3)
                noduri=noduri/2;
            if(noduri==2)
            {
                decapitare(prim->st,aux_int,aux_s,aux_st1,aux_dr1);
            }
            else
            {
                decapitare(prim->dr,aux_int,aux_s,aux_st1,aux_dr1);
            }
        }
        else if(prim->st->fii==prim->dr->fii)
        {
            decapitare(prim->dr,aux_int,aux_s,aux_st1,aux_dr1);
        }
    }
}
void echilibrare(nod *&prim)
{
    if(prim==NULL)
        return;
    if(prim->st!=NULL && prim->dr!=NULL)
    {
        if(prim->fr>prim->st->fr || prim->fr>prim->dr->fr)
        {
            if(prim->st->fr<prim->dr->fr)
            {
                int aux_int;
                char aux_s;
                aux_int=prim->st->fr;
                prim->st->fr=prim->fr;
                prim->fr=aux_int;
                aux_s=prim->st->s;
                prim->st->s=prim->s;
                prim->s=aux_s;

                nod *aux_st1,*aux_dr1;
                aux_st1=prim->st1;
                aux_dr1=prim->dr1;
                prim->st1=prim->st->st1;
                prim->dr1=prim->st->dr1;
                prim->st->st1=aux_st1;
                prim->st->dr1=aux_dr1;

                echilibrare(prim->st);
            }
            else if(prim->st->fr>prim->dr->fr)
            {
                int aux_int;
                char aux_s;
                aux_int=prim->dr->fr;
                prim->dr->fr=prim->fr;
                prim->fr=aux_int;
                aux_s=prim->dr->s;
                prim->dr->s=prim->s;
                prim->s=aux_s;

                nod *aux_st1,*aux_dr1;
                aux_st1=prim->st1;
                aux_dr1=prim->dr1;
                prim->st1=prim->dr->st1;
                prim->dr1=prim->dr->dr1;
                prim->dr->st1=aux_st1;
                prim->dr->dr1=aux_dr1;

                echilibrare(prim->dr);
            }
        }
    }
    else if(prim->st!=NULL && prim->dr==NULL)
    {
        if(prim->fr>prim->st->fr)
        {
            int aux_int;
            char aux_s;
            aux_int=prim->st->fr;
            prim->st->fr=prim->fr;
            prim->fr=aux_int;
            aux_s=prim->st->s;
            prim->st->s=prim->s;
            prim->s=aux_s;

            nod *aux_st1,*aux_dr1;
            aux_st1=prim->st1;
            aux_dr1=prim->dr1;
            prim->st1=prim->st->st1;
            prim->dr1=prim->st->dr1;
            prim->st->st1=aux_st1;
            prim->st->dr1=aux_dr1;
        }
    }
}
void SRD(nod *prim)
{
    if(prim!=NULL)
    {
        SRD(prim->st);
        cout<<"Character: "<<prim->s<<"  frequency: "<<prim->fr<<" sons: "<<prim->fii<<endl;
        SRD(prim->dr);
    }
}

void SRD1(nod *prim)
{
    if(prim!=NULL)
    {
        SRD1(prim->st1);
        cout<<"Character: "<<prim->s<<"  frequency: "<<prim->fr<<endl;
        SRD1(prim->dr1);
    }
}
void generare(nod *&prim)
{
    if(prim!=NULL)
    {
        if(strcmp(prim->cod,zero)==0)
        {
            if(prim->st1!=NULL)
            {
                prim->st1->cod[0]='1';
                prim->st1->cod[1]=0;
                prim->dr1->cod[0]='0';
                prim->dr1->cod[1]=0;
            }
        }
        else
        {
            if(prim->st1!=NULL)
            {
                strcpy(prim->st1->cod,prim->cod);
                int aux=strlen(prim->st1->cod);
                prim->st1->cod[aux]='1';
                prim->st1->cod[aux+1]=0;

                strcpy(prim->dr1->cod,prim->cod);
                prim->dr1->cod[aux]='0';
                prim->dr1->cod[aux+1]=0;
            }
        }
        if(prim->s!='2')
        {
            int i=1;
            while(vector_litere[i].lit!=prim->s)
                i++;
            strcpy(vector_litere[i].cod,prim->cod);
        }
        generare(prim->st1);
        generare(prim->dr1);
    }
}
void codificare(nod *prim,char litera)
{
     int i=1;
     while(vector_litere[i].lit!=litera)
        i++;
     cout<<vector_litere[i].cod;
}
void decodificare(nod *prim,char sir[100],int &valid)
{
    if(prim->s!='2')
    {
        cout<<prim->s;
    }
    else
    {
        if(sir[0]=='1')
        {
            strcpy(sir,sir+1);
            decodificare(prim->st1,sir,valid);
        }
        else if(sir[0]=='0')
        {
            strcpy(sir,sir+1);
            decodificare(prim->dr1,sir,valid);
        }
        else if(sir[0]==0)
        {
            valid=0;
        }

    }
}
int main()
{
    ifstream f("file.in");
    int n,i,aux_int;
    char aux_s;
    nod *secund,*aux_st1,*aux_dr1;
    nod *x,*y,*z;
    f>>n;
    for(i=1;i<=n;i++)
    {
        secund=new nod;
        f>>secund->s;
        vector_litere[i].lit=secund->s;
        f>>secund->fr;
        secund->st1=NULL;
        secund->dr1=NULL;
        adaugare(t,secund);
    }
    cout<<"HEAP:"<<endl;
    SRD(t);
    cout<<endl;
    for(i=1;i<=n-1;i++)
    {
        z=new nod;
        x=new nod;
        x->fr=t->fr;
        x->s=t->s;
        x->st1=t->st1;
        x->dr1=t->dr1;
        z->st1=x;
        z->fr=x->fr;
        decapitare(t,aux_int,aux_s,aux_st1,aux_dr1);
        t->fr=aux_int;
        t->s=aux_s;
        t->st1=aux_st1;
        t->dr1=aux_dr1;

        echilibrare(t);
        y=new nod;
        y->fr=t->fr;
        y->s=t->s;
        y->st1=t->st1;
        y->dr1=t->dr1;
        z->dr1=y;
        z->fr=z->fr+y->fr;
        decapitare(t,aux_int,aux_s,aux_st1,aux_dr1);
        if(t!=NULL)
        {
            t->fr=aux_int;
            t->s=aux_s;
            t->st1=aux_st1;
            t->dr1=aux_dr1;
            echilibrare(t);
        }
        z->s='2';
        adaugare(t,z);
    }
    cout<<"HUFFMAN TREE:"<<endl;
    SRD1(z);
    cout<<endl;
    strcpy(z->cod,"zero");
    generare(z);
    int optiune=0,lungime;
    char s[100];
    cout<<"MENIU"<<endl;
    cout<<"1.Encode"<<endl;
    cout<<"2.Decode"<<endl;
    cout<<"3.Exit"<<endl;
    while(optiune!=3)
    {
        cout<<"Choose: "<<endl;
        cin>>optiune;
        cin.get();
        if(optiune==1)
        {
            cout<<"Choose a word:"<<endl;
            cin.get(s,100);
            cin.get();
            lungime=strlen(s);
            cout<<"The word encoded:"<<endl;
            for(i=0;i<lungime;i++)
            {
                codificare(z,s[i]);
            }
            cout<<endl;
        }
        if(optiune==2)
        {
            cout<<"Choose the encoded sequence:"<<endl;
            cin.get(s,100);
            cin.get();
            int valid=1;
            while(s[0]!=0 && valid==1)
            {
                decodificare(z,s,valid);
            }
            if(valid==0)
                cout<<"IMPOSSIBILE"<<endl;
            else
                cout<<endl;

        }
    }
}





