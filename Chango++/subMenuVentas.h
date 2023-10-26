#ifndef SUBMENUVENTAS_H_INCLUDED
#define SUBMENUVENTAS_H_INCLUDED

void menuVentas();
void carteInicio(int);
bool agregarVenta();
bool cargarArticulos(int,int,float&);
void menuVentas(){
    bool menu=true;
    char eleccion;
    int velocidad=0;

    while(menu){
    {// Recuadros y titulo
        rlutil::cls();
        rlutil::setColor(8);
        boxAnimation(1,1,3,79,44,0);
        boxAnimation(2,2,1,77,42,0);
        changoPP(15,7);
        int x,y;
        x=31;
        y=20;
        textBoxAnimation(x,y,"MENU DE VENTAS",2,0);
    }
    {// Menu seleccion
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
    }
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
void carteInicio(int velocidad){// Recuadros y titulo
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
    {// Recuadro de cargar venta
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,5,0);
        gotoxy(++x,++y);
    }
    {/// REEMPLAZAR CON ventas.Cargar()!!
        char eleccion;
        Cliente cliente;
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
            /**
                Necesito buscar en Clientes.dat si el ingreso en DNI matchea con los DNI cargados.
                - Si no existe entonces return false.
                - Si existe entonces guardo en objeto cliente.
            */
        }
        else{
            gotoxy((x+10),(y+2));
            cout<<"Cliente = -1";
        }
        y+=4;
        x=62;
        float total=0;
        while(cargarArticulos(x,y,total)){
        /**
            Aqui grabamos en Ventas.dat
        */
        }
    }
    return true;
}
bool cargarArticulos(int x,int y,float&total){/// REEMPLAZAR CON ventas.Cargar()!!!
    {// Bloque de flecha apuntando cargar ventas
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)217;
        gotoxy(--x,y);
        cout<<(char)196;
        gotoxy(--x,y);
        cout<<(int_fast8_t)17;
        x-=36;
    }
    {// Bloque de recuadro carga de articulo
        rlutil::setColor(8);
        boxAnimation(x,y,1,35,14,0);
        rlutil::setColor(15);
        gotoxy(++x,++y);
    }
    char codigo[5];
    int cantidad;
    cout<<"\n\t\t\tCodigo de articulo";
    rlutil::setColor(8);
    cout<<" (4 caracteres)\n\t\t\t\t";
    rlutil::setColor(15);
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>codigo;
/**
        Tengo que consultar en Articulos.dat si el codigo existe.

            - Si existe, traigo a memoria:

                    Codigo | Nombre | Precio | Cantidad
                     aaaa    tomate    1200      300

            - Sino salgo.
*/
    cout<<"\n\t\t\tArticulo\n\t\t\t\t";
    cout<<" "<<(int_fast8_t)26<<" "<</**articulo.getNombre();*/"Tomate";
    cout<<"\n\t\t\tPrecio\n\t\t\t\t";
    cout<<" "<<(int_fast8_t)26<<" "<</**articulo.getPrecio();*/"1.200";

    cout<<"\n\n\t\t\tCantidad de articulo\t\t\t\t";
    rlutil::setColor(8);
    cout<<"\n\t\t\t - disponibles: "<</**articulo.getCantidad()*/300<<"\n\t\t\t\t";
    rlutil::setColor(15);
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>cantidad;

    /**
        Tengo que verificar que la cantidad ingresada no exceda la existente

            - Si excede entonces
    */


    /**
        Tengo que tener un ciclo en el que cargue los Codigos y la cantidad
        y que corte cuando presiono la tecla Esc
    */

        /**
            Grabo en Ventas.dat las ventas que voy cargando.
            Salgo de venta.Cargar(cliente) con la tecla Esc.
        */

    y+=13;
    {// Bloque de flecha apuntando cargar ventas
        x+=34;
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)217;
        gotoxy(--x,y);
        cout<<(char)196;
        gotoxy(--x,y);
        cout<<(int_fast8_t)17;
        x-=33;
        boxAnimation(x,y,2,32,4,0);
        boxAnimation((x+2),++y,1,28,2,0);
    }
    rlutil::setColor(15);
    gotoxy((x+10),++y);

    total+=/**  articulo.getPrecio()*cantidad;    */10;
    cout<<"Total = "<<total;
    rlutil::hidecursor();
    gotoxy(x,(y+4));
    cout<<"Presione \'+\' para continuar";
    if(getch()!='+'){ return false; }
    {// borra partes de pantalla
        cls(x,(y+4),27);
        cls((x+11),(y-6),20);
        cls((x),(y-7),30);
        cls((x+11),(y-10),20);
        cls((x+11),(y-12),20);
        cls((x+11),(y-15),20);
    }
    return true;
}

#endif // SUBMENUVENTAS_H_INCLUDED
