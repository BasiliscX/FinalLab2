#include<iostream>
using namespace std;
#include"rlutil.h"
#include"rlutilPlusPlus.h"
#include"recursos.h"
#include"subMenuProductos.h"
#include"subMenuProveedores.h"
#include"subMenuClientes.h"
#include"subMenuVentas.h"
#include"subMenuPagos.h"

int main(){
rlutil::setConsoleTitle("Chango++");
system("mode con cols=80 lines=45");
    int x,y;
    bool menu=true;
    char eleccion;

    while(menu){
    rlutil::cls();
    rlutil::setColor(8);
    boxAnimation(1,1,3,79,44,0);
    boxAnimation(2,2,1,77,42,0);
    changoPP(15,7);
    x=31;
    y=20;
    textBoxAnimation(x,y,"MENU PRINCIPAL",2,0);

    x=26;
    y=25;
    rlutil::setColor(8);
    boxAnimation(x,y,1,26,14);
    rlutil::setColor(15);
    x+=1;

        rlutil::hidecursor();
        y=26;
        rlutil::locate(x,y);
        textAnimation("1 - Menu de productos");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Menu de proveedores");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Menu de clientes");
        y+=2;        rlutil::locate(x,y);
        textAnimation("4 - Menu de facturacion");
        y+=2;
        rlutil::locate(x,y);        textAnimation("5 - Menu de configuracion");
        y+=2;        rlutil::locate(x,y);
        textAnimation("0 - Salir");
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : menuProductos(); break;
            case '2' : menuProveedores(); break;
            case '3' : menuClientes(); break;
            case '4' :
                switch(facturacion()){
                    case -1: menuPagos();break;
                    case -2: menuVentas(); break;
                    default: break;
                }
                break;
            case '5' : break;
            default: menu=false; break;
        }
    }
return 0;
}
