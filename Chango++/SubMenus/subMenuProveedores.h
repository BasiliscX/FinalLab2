#ifndef SUBMENUPROVEEDORES_H_INCLUDED
#define SUBMENUPROVEEDORES_H_INCLUDED

void menuProveedores();
bool agregarProveedor();

void menuProveedores(){
    ArchivoProveedor archivoProveedor("Proveedores.dat");
    bool menu=true;
    char eleccion;
    int velocidad=0;
    int x,y;

    while(menu){
    {// Recuadros y titulo
        rlutil::cls();
        rlutil::setColor(8);
        boxAnimation(1,1,3,79,44,0);
        boxAnimation(2,2,1,77,42,0);
        /**
        ▄▄▄▄▄▄▄▄
        █┌────┐█
        █│    │█
        █└────┘█
        ▀▀▀▀▀▀▀▀
        */
        changoPP(15,7);
        x=28;
        y=20;
        textBoxAnimation(x,y,"MENU DE PROVEEDORES",2,0);
        /**
        ╔═══════════════════╗
        ║MENU DE PROVEEDORES║
        ╚═══════════════════╝
        */
    }
    {// Menu de seleccion
        x=20;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,36,14,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar proveedor por CUIT",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los proveedores",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - Eliminar datos de proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu proncipal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
         ┌───────────────────────────────────┐
         │1 - Agregar proveedor              │
         │                                   │
         │2 - Listar proveedor por CUIT      │
         │                                   │
         │3 - Listar todos los proveedores   │
         │                                   │
         │4 - Modificar datos de un proveedor│
         │                                   │
         │5 - Eliminar datos de proveedor    │
         │                                   │
         │0 - volver al menu proncipal       │
         │                                   │
         │    Eleccion:                      │
         └───────────────────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProveedor(); break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            case '5' : break;
            default: menu=false; break;
        }
    }
}
bool agregarProveedor(){
    rlutil::cls();
    int x,y;
        ArchivoProveedor archivoProveedor("Proveedores.dat");

    {// Recuadros y titulo con flechas
        textBoxAnimation(28,4,"AGREGAR PROVEEDOR");
        /**
        ╔═════════════════╗
        ║AGREGAR PROVEEDOR║
        ╚═════════════════╝
        */
        textBoxAnimation(9,8,"PROVEEDOR",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        /**
        ┌─────────┐
        │PROVEEDOR│
        └─────────┤
                  └───►
        */
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,11,0);
        gotoxy(++x,++y);
    }

    archivoProveedor.agregarProveedor();

    if(false){
        {/// REEMPLAZAR CON producto.Cargar()!!!!
            char CUIT[12];
            rlutil::setColor(15);
            cout<<"\n\t\t\tNro de CUIT";
            rlutil::setColor(8);
            cout<<" (Numerico, sin \'-\')\n\t\t\t\t";
            rlutil::setColor(15);
            cout<<"  "<<(int_fast8_t)26<<" ";
            cin>>CUIT;
            if(!soloDigitos(CUIT)){
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
            Proveedor proveedor;
            if(true){
                /**
                    Se graba en Proveedores.dat
                */
                int x=26;
                int y=28;
                rlutil::hidecursor();
                rlutil::setColor(8);
                boxAnimation(x,y,1,33,2,1);
                rlutil::setColor(15);
                gotoxy(++x,++y);
                cout<<"ID generado para el proveedor: "<<proveedor.getID();
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
    }

    return true;
}


#endif // SUBMENUPROVEEDORES_H_INCLUDED
