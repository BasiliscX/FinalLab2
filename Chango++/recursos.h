#ifndef RECURSOS_H_INCLUDED
#define RECURSOS_H_INCLUDED

#include <cctype>

void changoPP(int,int);
int modificarDatos();
int modificarPrecio();
bool soloDigitos();
void cargarCadena(char *pal, int tam);

void changoPP(int x,int y){
    /**
     _____ _
     /  __ \ |                             _     _
     | /  \/ |__   __ _ _ __   __ _  ___ _| |_ _| |_
     | |   | '_ \ / _` | '_ \ / _` |/ _ \_   _|_   _|
     | \__/\ | | | (_| | | | | (_| | (_) ||_|   |_|
     \_____/_| |_|\__,_|_| |_|\__, |\___/
                               __/ |
                              |___/
    */
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

int modificarDatos(){// cartel recuadrado para entrar a Telefono o Direccion
    int x,y;
    char eleccion;
    x=56;
    y=34;
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,16,4);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation("\'T\' - Telefono");
    gotoxy(x,++y);
    textAnimation("\'D\' - Direccion");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    /**
    ├►┌───────────────┐
    │ │'T' - Telefono │
    │ │'D' - Direccion│
    │ │Eleccion:      │
    │ └───────────────┘
    */
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case 't': return -1;
        case 'd': return -2;
        default : break;
    }
    return 0;
}
int modificarPrecio(){// cartel recuadrado para entrar a Telefono o Direccion
    int x,y;
    char eleccion;
    x=56;
    y=34;
    rlutil::setColor(8);
    gotoxy(x,y);
    cout<<(char)195;
    gotoxy(++x,y);
    cout<<(int_fast8_t)16;
    boxAnimation(++x,y,1,15,4);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    textAnimation("\'P\' - Precio");
    gotoxy(x,++y);
    textAnimation("\'C\' - Cantidad");
    gotoxy(x,++y);
    textAnimation("Eleccion: ");
    /**
    ├►┌──────────────┐
    │ │'P' - Precio  │
    │ │'C' - Cantidad│
    │ │Eleccion:     │
    │ └──────────────┘
    */
    cin>>eleccion;
    eleccion=tolower(eleccion);
    switch(eleccion){
        case 'p': return -1;
        case 'c': return -2;
        default : break;
    }
    return 0;
}
bool soloDigitos(const char*cadena){// Evalua si los caracteres ingresados son numeros
    for (int i=0;cadena[i]!='\0';i++){
        if (!isdigit(cadena[i])){
            return false;
        }
    }
    return true;
}
void cargarCadena(char *pal, int tam)
{
    int i;
    fflush (stdin);
    for(i=0; i<tam;i++){
        pal[i]=cin.get();
        if(pal[i]=='\n')break;
    }
    pal[i]='\0';
    fflush(stdin);
}

#endif // RECURSOS_H_INCLUDED
