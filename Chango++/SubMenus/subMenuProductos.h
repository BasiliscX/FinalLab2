#ifndef SUBMENUPRODUCTOS_H_INCLUDED
#define SUBMENUPRODUCTOS_H_INCLUDED

void menuProductos();
bool agregarProducto();
bool listarProductoCodigo();
bool listarTodosLosProductos();
bool modificarProductoPorCodigo();

void menuProductos(){
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
        x=30;
        y=20;
        textBoxAnimation(x,y,"MENU DE PRODUCTOS",2,0);
        /**
        ╔═════════════════╗
        ║MENU DE PRODUCTOS║
        ╚═════════════════╝
        */
    }
    {// Menu seleccion
        x=21;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,35,14,velocidad);
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
        textAnimation("5 - ELiminar un producto",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu principal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
        ┌──────────────────────────────────┐
        │1 - Agregar producto              │
        │                                  │
        │2 - Listar producto por codigo    │
        │                                  │
        │3 - Listar todos los productos    │
        │                                  │
        │4 - Modificar datos de un producto│
        │                                  │
        │5 - ELiminar un producto          │
        │                                  │
        │0 - volver al menu principal      │
        │                                  │
        │   Eleccion:                      │
        └──────────────────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProducto(); break;
            case '2' : listarProductoCodigo(); break;
            case '3' : listarTodosLosProductos(); break;
            case '4' : modificarProductoPorCodigo(); break;
            case '5' : break;
            default: menu=false; break;
        }
    }
}
bool agregarProducto(){
    rlutil::cls();
    int x,y;
    Producto producto;
    {// Titulo y recuadros con flechas
        textBoxAnimation(28,4,"AGREGAR PRODUCTOS");
        /**
        ╔═════════════════╗
        ║AGREGAR PRODUCTOS║
        ╚═════════════════╝
        */
        textBoxAnimation(10,8,"Producto",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        /**
        ┌────────┐
        │Producto│
        └────────┤
                 └───►
        */
    }
    {/// REEMPLAZAR CON producto.Cargar()!!
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
    }
    return true;
}
bool listarProductoCodigo(){
    rlutil::cls();
    int x,y;
    int velocidad=0;
    char codigo[4];
    Producto producto;
    {// Titulo y recuadros con flechas
        textBoxAnimation(24,4,"LISTAR PRODUCTO POR CODIGO",2,velocidad);
        /**
        ╔══════════════════════════╗
        ║LISTAR PRODUCTO POR CODIGO║
        ╚══════════════════════════╝
        */
        textBoxAnimation(1,8,"Codigos disponibles",1,velocidad);
        /**┌───────────────────┐
           │Codigos disponibles│
           └───────────────────┴──► (Aqui deberia haber una impresion de los codigos separados por '|') aaaa | bbbb | cccc | rrrr |
                                    Necesito recorrer Articulos.dat e imprimir los codigos existentes.
        */
        x=26;
        y=10;
        int y2=0;
        {/**  Ejemplo de prueba   */
            const char*ejemploDeCodigosDisponibles="aaaa | bbbb | cccc | dddd | eeee | ffff | gggg | hhhh | iiii | jjjj | kkkk | llll";
            gotoxy(x,y);
            int t=strlen(ejemploDeCodigosDisponibles);
            for(int i=0;i<t;i++){
                cout<<ejemploDeCodigosDisponibles[i];
                if(i%40==0&&i!=0){
                    cout<<"\n\t\t\t";
                    y++;
                    y2++;
                }
            }

        }/**  Fin de ejemplo de prueba   */

        x=23;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,35,3,0);
        x=21;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)193<<(char)196<<(char)196<<(int_fast8_t)16;// flecha de "codigos disponibles"
        x=21;
        gotoxy(x,y);
        cout<<(char)197;
        if(y2==0){// No lo intentes... u_u
            gotoxy(x,++y);
            cout<<(char)179;
        }
        else{
            for(int i=0;i<y2;i++){
                gotoxy(x,++y);
                cout<<(char)179;
            }
        }
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
    }
    {// Ingresar codigo
        /**
        │
        └─►┌──────────────────────────────────┐
           │Codigo de articulo (4 caracteres) │
           │    →                             │
           └──────────────────────────────────┘
        */
        x=25;
        gotoxy(x,++y);
        rlutil::setColor(15);
        cout<<"Codigo de articulo ";
        rlutil::setColor(8);
        cout<<"(4 caracteres)";
        gotoxy((x+4),++y);
        rlutil::setColor(15);
        cout<<(int_fast8_t)26<<" ";
        cin>>codigo;
    }
    /**
        debo validar que el codigo ingresado exista.
        si no existe debo salir.
    */
    if(strcmp(codigo,"null")==0){// por ejemplo:
        cls(x,y,30);
        gotoxy(++x,y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR NUEVAMENTE.");
        return false;
    }
    /**
        si existe debo buscarlo de articulos.dat, grabarlo en una variable de articulo y mostrar.
    */
    {// Fleca descendiente
        /**│
           └►*/
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(int_fast8_t)16;
    }
    // articulo.Mostrar();
    rlutil::setColor(15);
    cout<<"Nombre : Tomate";
    cout<<"\n\t\t\t Tipo   : 1";
    cout<<"\n\t\t\t Precio : 1.200";
    cout<<"\n\t\t\t Stock  : 300";
    cout<<"\n\t\t\t ID Proveedor : 4";
    rlutil::anykey();
    return true;
}
bool listarTodosLosProductos(){
    rlutil::cls();
    int x,y;
    int velocidad=0;
    Producto producto;
    {// Titulo y recuadros con flechas
        textBoxAnimation(24,4,"LISTAR TODOS LOS PRODUCTOS",2,velocidad);
        textBoxAnimation(9,8,"Productos",1);
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
    }
    /**
        debo buscar en articulos.dat y traer a memoria todos los articulos activos
        while(articulo=archivo.getArticulo());
    */
    /// ejemplo:
    int i=0;
    x++;
    while(i<4){
        rlutil::setColor(8);
        boxAnimation(x,y,1,30,6,0);
        gotoxy((x+1),++y);
        rlutil::setColor(15);
        cout<<"Nombre : Tomate";
        cout<<"\n\t\t\tTipo   : 1";
        cout<<"\n\t\t\tPrecio : 1.200";
        cout<<"\n\t\t\tStock  : 300";
        cout<<"\n\t\t\tID Proveedor : 4";
        i++;
        y+=6;
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool modificarProductoPorCodigo(){
    rlutil::cls();
    int x,y;
    int velocidad=0;
    char codigo[4];
    Producto producto;
    {// Titulo y recuadros con flechas
        textBoxAnimation(24,4,"MODIFICAR PRODUCTO POR CODIGO",2,velocidad);
        textBoxAnimation(2,8,"Productos",1);
        x=12;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        x=15;
        y=10;
        gotoxy(x,++y);
    }
    /**
        debo buscar en articulos.dat y traer a memoria todos los articulos activos
        while(articulo=archivo.getArticulo());
    */
    /// ejemplo:
    boxAnimation(x,y,1,55,7/**esto seria cantidad de registros+2*/,0);
    gotoxy(++x,++y);
    rlutil::setColor(15);
    cout<<"Codigo | Nombre | Tipo | Precio | Stock | ID proveedor";
    gotoxy(x,++y);
    cout<<" aaaa  | Tomate |  01  | 1.200  |  300  |    1";
    gotoxy(x,++y);
    cout<<" bbbb  | zapallo|  01  |  600   |  400  |    4";
    gotoxy(x,++y);
    cout<<" cccc  | cebolla|  01  | 1.400  |  100  |    2";
    gotoxy(x,++y);
    cout<<" dddd  | lechuga|  01  | 1.600  |  100  |    1";
    gotoxy(x,++y);
    cout<<" dddd  | lechuga|  01  | 1.600  |  100  |    1";
    /**
    Hasta aqui:
     ┌─────────┐
     │Productos│
     └─────────┤
               └─►┌──────────────────────────────────────────────────────┐
                  │Codigo | Nombre | Tipo | Precio | Stock | ID proveedor│
                  │ aaaa  | Tomate |  01  | 1.200  |  300  |    1        │
                  │ bbbb  | zapallo|  01  |  600   |  400  |    4        │
                  │ cccc  | cebolla|  01  | 1.400  |  100  |    2        │
                  │ dddd  | lechuga|  01  | 1.600  |  100  |    1        │
                  │ dddd  | lechuga|  01  | 1.600  |  100  |    1        │
                  └──────────────────────────────────────────────────────┘
    */
    {// Flecha descendiente
        /**│
           └►*/
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(int_fast8_t)16;
    }
    {// recuadro de seleccion de codigo
        x+=2;
        boxAnimation(x,y,1,40,2,0);
        x=18;
        y=21;
        gotoxy(x,y);
        rlutil::setColor(15);
        cout<<"Codigo del producto a modificar: ";
        cin>>codigo;
    }
    /**
        Tengo que validar el codigo ingresado con los de productos.dat, si no existe salgo:
    */
    if(strcmp(codigo,"null")==0){// por ejemplo:
        x=18;
        y=21;
        gotoxy(x,y);
        cls(x,y,39);
        gotoxy((x+3),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR NUEVAMENTE.");
        return false;
    }
    /**
        Si existe entonces debo abrir editarlo con la interfaz de agregar producto
    */
    rlutil::cls();
    {// Titulo y recuadros con flechas
        textBoxAnimation(28,4,"MODIFICAR PRODUCTO");
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
    }
    {/// REEMPLAZAR CON producto.Cargar()!!
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
    }

    //rlutil::hidecursor();
    rlutil::anykey();
    return true;
}

#endif // SUBMENUPRODUCTOS_H_INCLUDED
