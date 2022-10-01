/***
SAYA TIDAK MEMAKAI CONIO.H DAN WINDOWS.H KARENA PACKAGE TERSEBUT TIDAK KOMPATIBLE DI OS LAPTOP SAYA (LINUX)
***/

#include<iostream>

using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];
int top = 1;
int maxSize = 10;

/*******************************************/
bool IsFull() {
    return top > maxSize;
}

bool IsEmpty() {
    return top <= 1;
}

void Push()
{
    if (IsFull()) {
        cout << "Stack is full" << endl;
        return;
    }
    int x = top;

    cout<<"Inputkan Jenis Barang    : ";
    cin>>kirim[x].jenis_brg;
    cout<<"Inputkan Berat           : ";
    cin>>kirim[x].berat;
    cout<<"Inputkan Kota Tujuan     : ";
    cin>>kirim[x].kota;

    top++;
}

void Pop()
{
    if (IsEmpty()) {
        cout << "Stack is empty" << endl;
        return;
    }
    int x = top-1;

    cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

    top--;
}

void Display()
{
    if (IsEmpty()) {
        cout << "Nothing to display" << endl;
        return;
    }

    cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=1; a<top; a++)
    {
        cout<<a<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }
    /*harus Ijin --> #include<conio.h>*/
}

void Top() {
    if (IsEmpty()) {
        cout << "Nothing in list" << endl;
        return;
    }
    int x = top-1;

    cout << "Top is " << kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

}

void Size() {
    cout << "Size of Stack is " << top-1 << endl;
}

int main()
{
    int pilih;
    do
    {

        cout<<"MENU UTAMA" << endl;
        cout<<"1. PUSH"<<endl;
        cout<<"2. POP"<<endl;
        cout<<"3. DISPLAY"<<endl;
        cout<<"4. ISFULL"<<endl;
        cout<<"5. ISEMPTY"<<endl;
        cout<<"6. TOP"<<endl;
        cout<<"7. SIZE"<<endl;
        cout<<"8. EXIT"<<endl;

        cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        switch(pilih) {
            case 1:
                Push();
                break;

            case 2:
                Pop();
                break;

            case 3:
                Display();
                break;

            case 4:
                if (IsFull()) {
                    cout << "Stack is full" << endl;
                } else {
                    cout << "Stack is not full" << endl;
                    cout << "You can Push" << endl;
                }
                break;

            case 5:
                if (IsEmpty()) {
                    cout << "Stack is empty" << endl;
                } else {
                    cout << "Stack is not empty" << endl;
                    cout << "You can Pop" << endl;
                }
                break;

            case 6:
                Top();
                break;

            case 7:
                Size();
                break;

        }
    }
    while(pilih!=8);
    return 0;
}
