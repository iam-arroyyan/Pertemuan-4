#include <iostream>
#include <stdlib.h>
#include <string.h>
#include"doubleList.h"
using namespace std;


int main()
{
    list_integer l;
    createlist(l);
    int nim,pilihan;
    string nama;
    address p;
    bool stop=false;
    while(!stop)
    {
        system("cls");
        cout<<"==DATA MAHASISWA==\n"<<endl;
        cout<<"1. Insert First"<<endl;
        cout<<"2. Insert Last"<<endl;
        cout<<"3. Insert After"<<endl;
        cout<<"4. Delete First"<<endl;
        cout<<"5. Delete Last"<<endl;
        cout<<"6. Delete After"<<endl;
        cout<<"7. View Data"<<endl;
        cout<<"8. Keluar"<<endl;
        cout<<"Masukkan pilihan anda : ";
        cin>>pilihan;
        if(pilihan==1)
        {
            cout<<"Masukkan Nama : ";
            cin>>nama;
            cout<<"Masukkan Nim  : ";
            cin>>nim;
            p=createelm(nama, nim);
            insertFirst(l,p);
        }
        else if(pilihan==2)
        {
            cout<<"Masukkan Nama : ";
            cin>>nama;
            cout<<"Masukkan Nim : ";
            cin>>nim;
            p=createelm(nama, nim);
            insertLast(l,p);
        }
        else if(pilihan==3)
        {
            cout<<"Masukkan Nama : ";
            cin>>nama;
            cout<<"Masukkan Nim : ";
            cin>>nim;
            cout<<"Masukkan pilihan Nama sebelumnya : ";
            string sebelum;
            cin>>sebelum;
            p=createelm(nama, nim);
            insertAfter(l,p,sebelum);
        }
        else if(pilihan==4)
        {
            deleteFirst(l,p);
            cout<<"Nama "<<p->info.nama<<" akan dihapus"<<endl;
            system("pause");
        }
        else if(pilihan==5)
        {
            deleteLast(l,p);
            cout<<"Nama "<<p->info.nama<<" akan dihapus"<<endl;
            system("pause");
        }
        else if(pilihan==6)
        {
            cout<<"Masukkan pilihan Nama yang akan dihapus : ";
            string cari;
            cin>>cari;
            deleteAfter(l,p,cari);
            if (p->info.nama != cari)
            {
                cout<<"Data yang dicari tidak ada"<<endl;
            }
            else
            {
                cout<<"Nama "<<p->info.nama<<" akan dihapus"<<endl;
            }
            system("pause");
        }
        else if(pilihan==7)
        {
            cetak_list(l);
            system("pause");
        }
        else if(pilihan==8)
        {
            stop = true;
        }
    }
    return 0;
}
