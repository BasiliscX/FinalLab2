#ifndef SUBMENUPROVEEDORES_H_INCLUDED
#define SUBMENUPROVEEDORES_H_INCLUDED


void menuProveedores(){
    bool menu=true;
    char eleccion;

    while(menu){
    rlutil::cls();
    rlutil::setColor(8);
    boxAnimation(1,1,3,79,44,0);
    changoPP(15,7);
    int x,y;
    x=28;
    y=20;
    textBoxAnimation(x,y,"MENU DE PROVEEDORES",2,0);

    x=20;
    y=27;
    rlutil::setColor(8);
    boxAnimation(x,y,1,36,12);
    rlutil::setColor(15);
    x+=1;

        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar proveedor");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar proveedor por CUIT");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los proveedores");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un proveedor");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu proncipal");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : menuProductos(); break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            default: menu=false; break;
        }
    }
}


#endif // SUBMENUPROVEEDORES_H_INCLUDED
