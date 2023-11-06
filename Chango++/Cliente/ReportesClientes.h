#ifndef REPORTESCLIENTES_H_INCLUDED
#define REPORTESCLIENTES_H_INCLUDED

void MenuReportesClientes();

void MenuReportesClientes(){
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
        x=30;
        y=20;
        textBoxAnimation(x,y,"REPORTES DE CLIENTES",2,0);
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
        textAnimation("1) BUSCAR CLIENTE POR NOMBRE",velocidad);
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
            case'1': break;
            case'2': break;
            case'3': break;
            default: menu=false; break;
        }
    }
}


#endif // REPORTESCLIENTES_H_INCLUDED
