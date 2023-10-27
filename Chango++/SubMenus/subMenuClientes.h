#ifndef SUBMENUCLIENTES_H_INCLUDED
#define SUBMENUCLIENTES_H_INCLUDED

void menuClientes();
bool agregarCliente();

void menuClientes(){
    bool menu=true;
    char eleccion;
    int velocidad=0;
    int x,y;

    while(menu){
    {// recuadro y Titulo
        rlutil::cls();
        rlutil::setColor(8);
        boxAnimation(1,1,3,79,44,0);
        boxAnimation(2,2,1,77,42,0);
        changoPP(15,7);
        x=30;
        y=20;
        textBoxAnimation(x,y,"MENU DE CLIENTES",2,0);
        /**
        ╔════════════════╗
        ║MENU DE CLIENTES║
        ╚════════════════╝
        */
    }
    {// Menu seleccion
        x=21;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,34,12,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar cliente",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar cliente por DNI",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los clientes",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un cliente",velocidad);
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
            case '1' : agregarCliente(); break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            default: menu=false; break;
        }
    }
}
bool agregarCliente(){
    rlutil::cls();
    int x,y;
    Producto articulo;
    {// Titulo y flecha con recuadro de cargar
        textBoxAnimation(30,4,"AGREGAR CLIENTE");
        textBoxAnimation(11,8,"CLIENTE",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,13,0);
        gotoxy(++x,++y);
    }
    {/// REEMPLAZAR CON cliente.Cargar()!!
        char DNI[8];
        rlutil::setColor(15);
        cout<<"\n\t\t\tNro de DNI";
        rlutil::setColor(8);
        cout<<" (Numerico, sin \'.\')\n\t\t\t\t";
        rlutil::setColor(15);
        cout<<"  "<<(int_fast8_t)26<<" ";
        cin>>DNI;
        if(!soloDigitos(DNI)){
            cout<<"\n\t\t\t\tINCORRECTO\n\t\t\t\tINTENTAR NUEVAMENTE";
            rlutil::anykey();
            return false;
        }
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
        Cliente cliente;
        if(cliente.Cargar(DNI)){
            /**
                Se graba en Proveedores.dat
            */
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
    }
    return true;
}

#endif // SUBMENUCLIENTES_H_INCLUDED
