#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED

void menuVentas();
void carteInicio(int);
bool agregarVenta();

void menuVentas(){
    bool menu=true;
    char eleccion;
    int velocidad=0;

    while(menu){
    rlutil::cls();
    rlutil::setColor(8);
    boxAnimation(1,1,3,79,44,0);
    boxAnimation(2,2,1,77,42,0);
    changoPP(15,7);
    int x,y;
    x=31;
    y=20;
    textBoxAnimation(x,y,"MENU DE VENTAS",2,0);

    x=24;
    y=27;
    rlutil::setColor(8);
    boxAnimation(x,y,1,29,12,velocidad);
    rlutil::setColor(15);
    x+=1;

        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Cargar venta",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar Venta",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todas las ventas",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Eliminar venta",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu proncipal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarVenta(); break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            default: menu=false; break;
        }
    }
}
void carteInicio(int velocidad){
    rlutil::cls();
    textBoxAnimation(30,4,"AGREGAR VENTA",1,velocidad);
    textBoxAnimation(13,8,"VENTA",1,velocidad);
    int x=19;
    int y=10;
    gotoxy(x,y);
    rlutil::setColor(8);
    cout<<(char)180;
    gotoxy(x,++y);
    cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
    rlutil::setColor(15);
}
bool agregarVenta(){
    rlutil::cls();
    int x,y;
    int velocidad=1;
    carteInicio(velocidad);
    x=23;
    y=10;
    gotoxy(x,y);
    x++;
    y++;
    rlutil::setColor(8);
    boxAnimation(x,y,1,38,5,0);
    gotoxy(++x,++y);

    char eleccion;
    bool cliente=false;
    char DNI[8];
    rlutil::setColor(15);
    cout<<"Es cliente? (S/N): ";
    cin>>eleccion;
    eleccion=tolower(eleccion);
    if(eleccion=='s'){
        cout<<"\n\t\t\t\tDNI ";
        rlutil::setColor(8);
        cout<<"(Numerico, sin \'.\')\n\t\t\t\t\t";
        rlutil::setColor(15);
        cout<<(int_fast8_t)26<<" ";
        cin>>DNI;
        if(!soloDigitos(DNI)){
            cout<<"\n\t\t\t\tINCORRECTO\n\t\t\t\tINTENTAR NUEVAMENTE";
            rlutil::anykey();
            return false;
        }
        cliente=true;
    }
    else{
        carteInicio(0);
    }
    rlutil::setColor(8);
    boxAnimation(--x,--y,1,38,15,0);
    rlutil::setColor(15);
    gotoxy(++x,++y);
    /**
        Tengo que consultar en Articulos.dat:

            Codigo | Nombre | Precio | Cantidad
             aaaa   tomate     1200     300
             bbbb   cebolla    1000     200

        y guardar en memoria
        y pasar a venta.Cargar()
        o mejor pasar a un constructor:
            Venta venta(Codigo,Nombre,Precio,Cantidad);

        con los datos validados.
    */
    Venta venta;
    venta.Cargar(cliente);

    gotoxy(x,++y);
    rlutil::setColor(15);
    rlutil::hidecursor();
    cout<<" DATOS INGRESADOS CORRECTAMENTE!\n";
    rlutil::anykey();

    /**
        se debe buscar en Proveedores.dat los CUIT de proveedor
        y verificar que el ingresado sea inexistente.
        si existe, entonces c=-1
    if(c==-1){
        cout<<"\n\t\t\t\tINCORRECTO\n\t\t\t\tINTENTAR NUEVAMENTE";
        rlutil::anykey();
        return false;
    }
    */

        /**
    Cliente cliente;
    if(cliente.Cargar(DNI)){
            Se graba en Proveedores.dat
        int x=26;
        int y=30;
        rlutil::hidecursor();
        rlutil::setColor(8);
        boxAnimation(x,y,1,33,2,1);
        rlutil::setColor(15);
        gotoxy(++x,++y);
        cout<<"ID generado para el cliente: "<<cliente.getID();
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(int_fast8_t)16;
        rlutil::setColor(15);
        rlutil::hidecursor();
        cout<<" DATOS INGRESADOS CORRECTAMENTE!\n";
        rlutil::anykey();
    }
        */
    return true;
}


#endif // SUBMENUVENTAS_H_INCLUDED
