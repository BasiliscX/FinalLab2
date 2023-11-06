#ifndef REPORTESPROVEEDORES_H_INCLUDED
#define REPORTESPROVEEDORES_H_INCLUDED

void MenuReportesProveedores();
bool buscarProveedorPorNombre();

void MenuReportesProveedores(){
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
        changoPP(15,7);
        x=28;
        y=20;
        textBoxAnimation(x,y,"REPORTES DE PROVEEDORES",2,0);
    }
    {// Menu seleccion
        x=24;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,32,10,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1) BUSCAR PROVEEDOR POR NOMBRE",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2) ",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3) ",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0) VOLVER AL MENU DE REPORTES",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case'1': buscarProveedorPorNombre(); break;
            case'2': break;
            case'3': break;
            default: menu=false; break;
        }
    }
}
bool buscarProveedorPorNombre(){
    rlutil::cls();
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    int x,y;
    x=24;
    y=4;
    textBoxAnimation(x,y,"BUSCAR PROVEEDOR POR NOMBRE");
        /**
        ╔═══════════════════════════╗
        ║BUSCAR PROVEEDOR POR NOMBRE║
        ╚═══════════════════════════╝
        */
    char nombre[30];
    x=9;
    y=8;
    gotoxy(x,y);
    textAnimation("Nombre a buscar: ");
    rlutil::setColor(14);
    cargarCadena(nombre,30);
    rlutil::setColor(15);
    /**
        averiguar si es un nombre valido
    */
    int pos=verificarNombreProveedorPos(nombre);
    if(pos==-1){
        gotoxy((x+17),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    Proveedor proveedor=archivo.leerRegistro(pos);
    proveedor.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}

#endif // REPORTESPROVEEDORES_H_INCLUDED
