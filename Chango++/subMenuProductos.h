#ifndef SUBMENUPRODUCTOS_H_INCLUDED
#define SUBMENUPRODUCTOS_H_INCLUDED

void menuProductos(){
    bool menu=true;
    int eleccion;

    while(menu){
    rlutil::cls();
    rlutil::setColor(8);
    boxAnimation(1,1,3,79,44,0);
    changoPP(15,7);
    int x,y;
    x=30;
    y=20;
    textBoxAnimation(x,y,"MENU DE PRODUCTOS",2,0);

    x=26;
    y=25;
    rlutil::setColor(8);
    boxAnimation(x,y,1,26,14);
    rlutil::setColor(15);
    x+=1;

        rlutil::hidecursor();
        y=26;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar producto");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar producto por nombre");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los productos");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un producto");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - volver al menu proncipal");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case 1 : menuProductos(); break;
            case 2 : break;
            case 3 : break;
            case 4 : break;
            case 5 : break;
            default: menu=false; break;
        }
    }
}

#endif // SUBMENUPRODUCTOS_H_INCLUDED
