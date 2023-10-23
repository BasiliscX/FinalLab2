#ifndef SUBMENUPROVEEDORES_H_INCLUDED
#define SUBMENUPROVEEDORES_H_INCLUDED

void menuProveedores();
bool agregarProveedor();

void menuProveedores(){
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
    x=28;
    y=20;
    textBoxAnimation(x,y,"MENU DE PROVEEDORES",2,0);

    x=20;
    y=27;
    rlutil::setColor(8);
    boxAnimation(x,y,1,36,12,velocidad);
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
        textAnimation("0 - volver al menu proncipal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ",velocidad);
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProveedor(); break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            default: menu=false; break;
        }
    }
}
bool agregarProveedor(){
    rlutil::cls();
    int x,y;
    Articulo producto;

    textBoxAnimation(28,4,"AGREGAR PROVEEDOR");
    textBoxAnimation(9,8,"PROVEEDOR",1);
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
    boxAnimation(x,y,1,38,19,0);
    gotoxy(++x,++y);

    int c;
    rlutil::setColor(15);
    cout<<"\n\t\t\tNro de CUIT";
    rlutil::setColor(8);
    cout<<" (Numerico, sin \'-\')\n\t\t\t\t";
    rlutil::setColor(15);
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>c;
    /**
        se debe buscar en Proveedores.dat los CUIT de proveedor
        y verificar que el ingresado sea inexistente.
        si existe, entonces c=-1
    */
    if(c==-1){
        cout<<"\n\t\t\t\tINCORRECTO\n\t\t\t\tINTENTAR NUEVAMENTE";
        rlutil::anykey();
        return false;
    }
//    producto.Cargar(c,vP);
    return true;
}


#endif // SUBMENUPROVEEDORES_H_INCLUDED
