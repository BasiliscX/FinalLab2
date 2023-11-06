#include<iostream>
#include<cstdlib>
using namespace std;
#include"rlutil.h"
#include"rlutilPlusPlus.h"
#include"recursos.h"
#include"clasesDatos.h"
#include"SubMenus/menuConfiguracion.h"
#include"SubMenus/subMenuProveedores.h"
#include"SubMenus/subMenuProductos.h"
#include"SubMenus/subMenuClientes.h"
#include"SubMenus/subMenuVentas.h"
#include"SubMenus/MenuReportes.h"

int main(){
rlutil::setConsoleTitle("Chango++");
system("mode con cols=80 lines=45");
    int x,y, velocidad=0;
    bool menu=true;
    char eleccion;

    while(menu){
    {// Recuadro y Titulo
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
        x=31;
        y=20;
        textBoxAnimation(x,y,"MENU PRINCIPAL",2,0);
        /**
        ╔══════════════╗
        ║MENU PRINCIPAL║
        ╚══════════════╝
        */
    }
    {// Menu seleccion
        x=26;
        y=25;
        rlutil::setColor(8);
        boxAnimation(x,y,1,26,16,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=26;
        rlutil::locate(x,y);
        textAnimation("1 - Menu de proveedores",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Menu de productos",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Menu de clientes",velocidad);
        y+=2;        rlutil::locate(x,y);
        textAnimation("4 - Menu de ventas",velocidad);
        y+=2;        rlutil::locate(x,y);
        textAnimation("5 - Reportes",velocidad);
        y+=2;
        rlutil::locate(x,y);        textAnimation("6 - Menu de configuracion",velocidad);
        y+=2;        rlutil::locate(x,y);
        textAnimation("0 - Salir",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
        ┌─────────────────────────┐
        │1 - Menu de proveedores  │
        │                         │
        │2 - Menu de productos    │
        │                         │
        │3 - Menu de clientes     │
        │                         │
        │4 - Menu de ventas       │
        │                         │
        │5 - Reportes             │
        │                         │
        │6 - Menu de configuracion│
        │                         │
        │0 - Salir                │
        │                         │
        │      Eleccion:          │
        └─────────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : menuProveedores(); break;
            case '2' : menuProductos(); break;
            case '3' : menuClientes(); break;
            case '4' : menuVentas(); break;
            case '5' : MenuReportes(); break;
            case '6' : MenuConfiguracion(); break;
            default: menu=false; break;
        }
    }
return 0;
}
