#include<iostream>
#include<curses.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


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
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

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
    int x = top-1;

    gotoxy(20,15);cout<<"Inputkan Jenis Barang    :";
    cin>>kirim[x].jenis_brg;
    gotoxy(20,16);cout<<"Inputkan Berat           :";
    cin>>kirim[x].berat;
    gotoxy(20,17);cout<<"Inputkan Kota Tujuan     :";
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

    gotoxy(40,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();
}

void Display()
{
    if (IsEmpty()) {
        cout << "Nothing to display" << endl;
        return;
    }

    gotoxy(40,10);cout<<"Daftar Kiriman Paket"<<endl;
    for(int a=1; a<top; a++)
    {
        gotoxy(40,19-a);
        cout<<a<<" ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" ";
        cout<<kirim[a].kota<<endl;
    }
    gotoxy(40,20);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void Top() {
    if (IsEmpty()) {
        cout << "Nothing in list" << endl;
        return;
    }
    int x = top-1;

    gotoxy(40,13);
    cout << "Top is " << kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

    gotoxy(40,15);cout<<"Press Any Key...";
    getch();
}

void Size() {
    cout << "Size of Stack is " << top-1;
}

int main()
{
    int pilih;
    do
    {
        bersihlayar();
        gotoxy(1,1);cout<<"MENU UTAMA";
        gotoxy(1,2);cout<<"1. PUSH"<<endl;
        gotoxy(1,3);cout<<"2. POP"<<endl;
        gotoxy(1,4);cout<<"3. DISPLAY"<<endl;
        gotoxy(1,5);cout<<"4. ISFULL"<<endl;
        gotoxy(1,6);cout<<"5. ISEMPTY"<<endl;
        gotoxy(1,7);cout<<"6. TOP"<<endl;
        gotoxy(1,8);cout<<"7. SIZE"<<endl;
        gotoxy(1,9);cout<<"8. EXIT"<<endl;

        gotoxy(1,10);cout<<"Pilihan Anda [1-9] : ";
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
