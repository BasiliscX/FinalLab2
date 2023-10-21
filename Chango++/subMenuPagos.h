#ifndef SUBMENUPAGOS_H_INCLUDED
#define SUBMENUPAGOS_H_INCLUDED

void menuPagos(){
    bool menu=true;
    char eleccion;

    while(menu){
    rlutil::cls();
    rlutil::setColor(8);
    boxAnimation(1,1,3,79,44,0);//recuadro grueso
    boxAnimation(2,2,1,77,42,0);//recuadro fino
    changoPP(15,7);//logo
    int x,y;
    x=30;
    y=20;
    textBoxAnimation(x,y,"MENU DE PAGOS",2,0);

    x=21;
    y=27;
    rlutil::setColor(8);
    boxAnimation(x,y,1,35,12);//recuadro de eleccion
    rlutil::setColor(15);
    x+=1;

        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar (..)");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar (..)");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos (..)");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar (..)");
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


#endif // SUBMENUPAGOS_H_INCLUDED
