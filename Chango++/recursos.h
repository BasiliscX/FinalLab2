#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include <cctype>

void changoPP(int,int);
int facturacion();
bool soloDigitos();

void changoPP(int x,int y){
rlutil::setColor(14);
gotoxy(x,y);
cout<<" _____ _";
gotoxy(x,++y);
cout<<"/  __ \\ |                             _     _";
gotoxy(x,++y);
cout<<"| /  \\/ |__   __ _ _ __   __ _  ___ _| |_ _| |_";
gotoxy(x,++y);
cout<<"| |   | '_ \\ / _` | '_ \\ / _` |/ _ \\_   _|_   _|";
gotoxy(x,++y);
cout<<"| \\__/\\ | | | (_| | | | | (_| | (_) ||_|   |_|";
gotoxy(x,++y);
cout<<"\\_____/_| |_|\\__,_|_| |_|\\__, |\\___/";
gotoxy(x,++y);
cout<<"                          __/ |";
gotoxy(x,++y);
cout<<"                         |___/";
rlutil::setColor(15);
}

int facturacion(){
    int x,y;
    char eleccion;
    x=52;
    y=32;
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,13,4);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation("\'p\' - Pagos");
    gotoxy(x,++y);
    textAnimation("\'v\' - Ventas");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case 'p': return -1;
        case 'v': return -2;
        default : break;
    }
    return 0;
}

bool soloDigitos(const char*cadena){
    for (int i=0;cadena[i]!='\0';i++){
        if (!isdigit(cadena[i])){
            return false;
        }
    }
    return true;
}

#endif // RECURSOS_H_INCLUDED
