#ifndef SUBMENUPRODUCTOS_H_INCLUDED
#define SUBMENUPRODUCTOS_H_INCLUDED

void menuProductos();
bool agregarProducto();

void menuProductos(){
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
    x=30;
    y=20;
    textBoxAnimation(x,y,"MENU DE PRODUCTOS",2,0);

    x=21;
    y=27;
    rlutil::setColor(8);
    boxAnimation(x,y,1,35,12,velocidad);
    rlutil::setColor(15);
    x+=1;

        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar producto",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar producto por codigo",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los productos",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un producto",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu principal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProducto(); break;
            case '2' : break;
            case '3' : break;
            case '4' : break;
            default: menu=false; break;
        }
    }
}
bool agregarProducto(){
    rlutil::cls();
    int x,y;
    Producto producto;

    textBoxAnimation(28,4,"AGREGAR PRODUCTOS");
    textBoxAnimation(10,8,"Producto",1);
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
    boxAnimation(x,y,1,38,21,0);
    gotoxy(++x,++y);

    char c[4];
    rlutil::setColor(15);
    cout<<"\n\t\t\tCodigo";
    rlutil::setColor(8);
    cout<<" (4 caracteres)\n\t\t\t\t";
    rlutil::setColor(15);
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>c;
    if(strlen(c)>4){
        cout<<"\n\t\t\t\tINCORRECTO\n\t\t\t\tINTENTAR NUEVAMENTE";
        rlutil::anykey();
        return false;
    }
    int vP[10]={0};
    /**
        se debe buscar en Proveedores.dat los ID de proveedor
        y guardar los valores en int vP[10]; para poder cargar
        porductos deproveedores existentes.
    */
    producto.Cargar(c,vP);
    return true;
}

#endif // SUBMENUPRODUCTOS_H_INCLUDED
