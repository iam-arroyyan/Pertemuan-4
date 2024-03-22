#include"doubleList.h"
#include <iostream>
#include <string.h>
using namespace std;

void createlist(list_integer &l)
{
    l.first = NULL;
    l.last = NULL;
}
address createelm(string nama, int nim)
{
    address P = new elemen;
    P->info.nama = nama;
    P->info.nim = nim;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertFirst(list_integer &l,address p)
{
    if ((l.first == NULL)&& (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->next = l.first;
        l.first->prev = p;
        l.first = p;
    }
}

void insertLast(list_integer &l,address p)
{
    if ((l.first == NULL)&& (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
    }
}

void insertAfter(list_integer &l,address p,string sebelum)
{
    if ((l.first == NULL)&& (l.last == NULL))
    {
        l.first = p;
        l.last = p;
    }
    else
    {
        address q = l.first;
        while((q->next != NULL)&&(q->info.nama != sebelum))
        {
            q = q->next;
        }
        if (q->info.nama == sebelum)
        {
            p->next = q->next;
            p->prev = q;
            q->next->prev = p;
            q->next = p;
        }
    }
}

void deleteFirst(list_integer &l,address &p)
{
    p = l.first;
    if ((l.first != NULL)&& (l.last != NULL))
    {
        if(l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.first = p->next;
            p->next = NULL;
            l.first->prev = NULL;
        }
    }
}

void deleteLast(list_integer &l,address &p)
{
    p = l.last;
    if ((l.first != NULL)&& (l.last != NULL))
    {
        if(l.first == l.last)
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            l.last = l.last->prev;
            p->prev = NULL;
            l.last->next = NULL;
        }
    }
}

void deleteAfter(list_integer &l,address &p,string cari)
{
    p = l.first;
    if ((l.first != NULL)&& (l.last != NULL))
    {
        if((l.first == l.last)&& (l.first->info.nama == cari))
        {
            l.first = NULL;
            l.last = NULL;
        }
        else
        {
            address q;
            while ((p->next != NULL)&&(p->info.nama != cari))
            {
                q = p;
                p = p->next;
            }
            if (p->info.nama == cari)
            {
                if (p == l.first)
                {
                    deleteFirst(l,p);
                }
                else if ( p == l.last)
                {
                    deleteLast(l,p);
                }
                else
                {
                    q->next = p->next;
                    p->next->prev = q;
                    p->next = NULL;
                    p->prev = NULL;
                }
            }
        }
    }
}

void cetak_list(list_integer l)
{

    if ((l.first == NULL)&&(l.last == NULL))
    {
        cout<<"not found";
    }
    else
    {
        address current = l.first;
        while(current->next!= NULL)
        {
            cout<<"Nama : "<<current->info.nama<<endl;
            cout<<"NIM  : "<<current->info.nim<<endl;
            current=current->next;
        }
        cout<<"Nama : "<<current->info.nama<<endl;
        cout<<"NIM  : "<<current->info.nim<<endl;
    }
    cout<<endl;
}
