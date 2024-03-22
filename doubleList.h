#ifndef DOUBLELIST_H_INCLUDED
#define DOUBLELIST_H_INCLUDED
#include <iostream>
#include<stdio.h>
#include <string.h>
using namespace std;

struct mahasiswa {
    string nama;
    int nim;
};

typedef struct elemen *address;
struct elemen {
    mahasiswa info;
    address next;
    address prev;
};

struct list_integer{
    address first;
    address last;
};

void createlist(list_integer &l);
address createelm(string nama, int nim);
void insertFirst(list_integer &l,address p);
void insertLast(list_integer &l,address p);
void insertAfter(list_integer &l,address p,string sebelum);
void deleteFirst(list_integer &l,address &p);
void deleteLast(list_integer &l,address &p);
void deleteAfter(list_integer &l,address &p,string cari);
void cetak_list(list_integer l);

#endif // DOUBLELIST_H_INCLUDED
