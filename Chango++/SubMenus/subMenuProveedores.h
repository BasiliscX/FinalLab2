#ifndef SUBMENUPROVEEDORES_H_INCLUDED
#define SUBMENUPROVEEDORES_H_INCLUDED

void menuProveedores();
bool agregarProveedor();
bool listarProveedorPorID();
bool listarTodosLosProveedores();
bool MOdificarProveedorPorID(const char*);
bool eliminarProveedorPorID();

void menuProveedores(){
    ArchivoProveedor archivoProveedor("Proveedores.dat");
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
        x=28;
        y=20;
        textBoxAnimation(x,y,"MENU DE PROVEEDORES",2,0);
        /**
        ╔═══════════════════╗
        ║MENU DE PROVEEDORES║
        ╚═══════════════════╝
        */
    }
    {// Menu de seleccion
        x=20;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,36,14,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar proveedor por ID",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los proveedores",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - Eliminar datos de un proveedor",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu proncipal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
        /**
         ┌───────────────────────────────────┐
         │1 - Agregar proveedor              │
         │                                   │
         │2 - Listar proveedor por ID        │
         │                                   │
         │3 - Listar todos los proveedores   │
         │                                   │
         │4 - Modificar datos de un proveedor│
         │                                   │
         │5 - Eliminar datos de un proveedor │
         │                                   │
         │0 - volver al menu proncipal       │
         │                                   │
         │    Eleccion:                      │
         └───────────────────────────────────┘
        */
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarProveedor(); break;
            case '2' : listarProveedorPorID(); break;
            case '3' : listarTodosLosProveedores(); break;
            case '4' :
                switch(modificarDatos()){
                    case -1: MOdificarProveedorPorID("Telefono"); break;
                    case -2: MOdificarProveedorPorID("Direccion"); break;
                    default: break;
                }
                break;
            case '5' : eliminarProveedorPorID(); break;
            default: menu=false; break;
        }
    }
}
bool agregarProveedor(){
    rlutil::cls();
    int x,y;
    ArchivoProveedor archivoProveedor("Proveedores.dat");
    {// Recuadros y titulo con flechas
        textBoxAnimation(28,4,"AGREGAR PROVEEDOR");
        /**
        ╔═════════════════╗
        ║AGREGAR PROVEEDOR║
        ╚═════════════════╝
        */
        textBoxAnimation(9,8,"PROVEEDOR",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        /**
        ┌─────────┐
        │PROVEEDOR│
        └─────────┤
                  └───►
        */
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,11,0);
        gotoxy(++x,++y);
    }
    archivoProveedor.agregarProveedor();
    return true;
}
bool listarProveedorPorID(){
    rlutil::cls();
    ArchivoProveedor archivo("Proveedores.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    Proveedor proveedor;
    {// Titulo y recuadros con flechas
        textBoxAnimation(26,4,"LISTAR PROVEEDOR POR ID",2,velocidad);
        /**
        ╔═══════════════════════╗
        ║LISTAR PROVEEDOR POR ID║
        ╚═══════════════════════╝
        */
        textBoxAnimation(1,8,"ID disponibles",1,velocidad);
        y=10;
        x=23;
        gotoxy(x,y);
        rlutil::setColor(8);
        x=16;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)193<<(char)196<<(char)196<<(int_fast8_t)16;// flecha de "codigos disponibles"
        /**┌──────────────┐
           │ID disponibles│
           └──────────────┴──► | 1 | 2 | 3 | 4 | 5 | ...
        */
    }
    {// Imprimo los ID de proveedor existentes
        gotoxy((x+5),y);
        if(archivo.contarRegistros()==0){// Si aun no hay cargados proveedores
            gotoxy((x+10),y);
            rlutil::setColor(4);
            rlutil::hidecursor();
            rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
            rlutil::setColor(15);
            return false;
        }
        int*vectorID=new int[t]{0};
        vectorID=vectorDeID_proveedores();
        rlutil::setColor(15);
        for(int i=0;i<t;i++){
            cout<<"| ";
            if(vectorID[i]!=0){
                cout<<vectorID[i]<<" |";
                if(i%9==0&&i!=0){
                    gotoxy(21,++y);
                    y2++;
                }
            }
        }
        /**
        ─► | 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 10 |
           | 11 || 12 || 13 || 14 || 15 || 16 |
        */
    }
    y+=y2;//Si incremente una fila, entonces la sumo al posicionador de filas
    int id,pos;
    {
        x=16;
        y=10;
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)197;
        gotoxy(x,++y);
        cout<<(char)179;
        if(y2>0){
            for(int i=0;i<y2;i++){// para agrandar el bracito...
                gotoxy(x,++y);
                cout<<(char)179;
            }
        }
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<"ID del proveedor";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
        /**
            │
            └──►ID del proveedor
                    →
        */
    }
    cin>> id;
    pos=verificarIdPos(id);
    if(pos==-1){
        gotoxy((x+10),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    proveedor=archivo.leerRegistro((id-1));
    proveedor.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosLosProveedores(){
    rlutil::cls();
    ArchivoProveedor archivo("Proveedores.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS PROVEEDORES",2,velocidad);
    if(archivo.contarRegistros()==0){// Si aun no hay cargados proveedores
        gotoxy(25,10);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    gotoxy(1,8);
    for(int i=0;i<t;i++){
        Proveedor proveedor=archivo.leerRegistro(i);
        proveedor.Mostrar();
        cout<<endl;
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool MOdificarProveedorPorID(const char*campo){
    rlutil::cls();
    ArchivoProveedor archivo("Proveedores.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    Proveedor proveedor;
    {// Titulo y recuadros con flechas
        textBoxAnimation(24,4,"MODIFICAR PROVEEDOR POR ID",2,velocidad);
        /**
        ╔══════════════════════════╗
        ║MODIFICAR PROVEEDOR POR ID║
        ╚══════════════════════════╝
        */
        textBoxAnimation(1,8,"ID disponibles",1,velocidad);
        y=10;
        x=23;
        gotoxy(x,y);
        rlutil::setColor(8);
        x=16;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)193<<(char)196<<(char)196<<(int_fast8_t)16;// flecha de "codigos disponibles"
        /**┌──────────────┐
           │ID disponibles│
           └──────────────┴──► | 1 | 2 | 3 | 4 | 5 | ...
        */
    }
    {// Imprimo los ID de proveedor existentes
        gotoxy((x+5),y);
        if(archivo.contarRegistros()==0){// Si aun no hay cargados proveedores
            gotoxy((x+10),y);
            rlutil::setColor(4);
            rlutil::hidecursor();
            rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
            rlutil::setColor(15);
            return false;
        }
        int*vectorID=new int[t]{0};
        vectorID=vectorDeID_proveedores();
        rlutil::setColor(15);
        for(int i=0;i<t;i++){
            cout<<"| ";
            if(vectorID[i]!=0){
                cout<<vectorID[i]<<" |";
                if(i%9==0&&i!=0){
                    gotoxy(21,++y);
                    y2++;
                }
            }
        }
        /**
        ─► | 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 10 |
           | 11 || 12 || 13 || 14 || 15 || 16 |
        */
    }
    y+=y2;//Si incremente una fila, entonces la sumo al posicionador de filas
    int id,pos;
    {
        x=16;
        y=10;
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)197;
        gotoxy(x,++y);
        cout<<(char)179;
        if(y2>0){
            for(int i=0;i<y2;i++){// para agrandar el bracito...
                gotoxy(x,++y);
                cout<<(char)179;
            }
        }
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<"ID del proveedor";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
        /**
            │
            └──►ID del proveedor
                    →
        */
    }
    cin>> id;
    pos=verificarIdPos(id);
    if(pos==-1){
        gotoxy((x+10),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    proveedor=archivo.leerRegistro((id-1));
    proveedor.Mostrar();
    {// Pregunta si los datos son correctos
        char eleccion;
        y+=4;
        rlutil::setColor(8);
        gotoxy(--x,y);
        cout<<(char)218;
        for(int i=0;i<35;i++){ cout<<(char)196; }
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<" LOS DATOS SON CORRECTOS? S/N: ";
        cin>>eleccion;
        eleccion=tolower(eleccion);
        if(eleccion!='s'){ return false; }
    }
    if(strcmp(campo,"Telefono")==0){// Modifico el telefono del proveedor
        gotoxy((x+4),(y+2));
        char telefonoProveedorNuevo[30];
        cout<<"Nuevo telefono: ";
        cargarCadena(telefonoProveedorNuevo,29);
        proveedor.setTelefono(telefonoProveedorNuevo);
        archivo.modificarProveedor(proveedor,(id-1));
        proveedor=archivo.leerRegistro((id-1));
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        proveedor.Mostrar();
    }
    if(strcmp(campo,"Direccion")==0){// Modifico la direccion del proveedor
        gotoxy((x+4),(y+2));
        char direccionProveedorNuevo[30];
        cout<<"Nueva Direccion: ";
        cargarCadena(direccionProveedorNuevo,29);
        proveedor.setDireccion(direccionProveedorNuevo);
        archivo.modificarProveedor(proveedor,(id-1));
        proveedor=archivo.leerRegistro((id-1));
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);        cout<<"DATOS MODIFICADOS EXITOSAMENTE!          \n";
        rlutil::setColor(15);
        proveedor.Mostrar();
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool eliminarProveedorPorID(){
    rlutil::cls();
    ArchivoProveedor archivo("Proveedores.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    {// Titulo y recuadros con flechas
        textBoxAnimation(24,4,"ELIMINAR PROVEEDOR POR ID",2,velocidad);
        /**
        ╔═════════════════════════╗
        ║ELIMINAR PROVEEDOR POR ID║
        ╚═════════════════════════╝
        */
        textBoxAnimation(1,8,"ID disponibles",1,velocidad);
        y=10;
        x=23;
        gotoxy(x,y);
        rlutil::setColor(8);
        x=16;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)193<<(char)196<<(char)196<<(int_fast8_t)16;// flecha de "codigos disponibles"
        /**┌──────────────┐
           │ID disponibles│
           └──────────────┴──► | 1 | 2 | 3 | 4 | 5 | ...
        */
    }
    {// Imprimo los ID de proveedor existentes
        gotoxy((x+5),y);
        if(archivo.contarRegistros()==0){// Si aun no hay cargados proveedores
            gotoxy((x+10),y);
            rlutil::setColor(4);
            rlutil::hidecursor();
            rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
            rlutil::setColor(15);
            return false;
        }
        int*vectorID=new int[t]{0};
        vectorID=vectorDeID_proveedores();
        rlutil::setColor(15);
        for(int i=0;i<t;i++){
            cout<<"| ";
            if(vectorID[i]!=0){
                cout<<vectorID[i]<<" |";
                if(i%9==0&&i!=0){
                    gotoxy(21,++y);
                    y2++;
                }
            }
        }
        /**
        ─► | 1 || 2 || 3 || 4 || 5 || 6 || 7 || 8 || 9 || 10 |
           | 11 || 12 || 13 || 14 || 15 || 16 |
        */
    }
    y+=y2;//Si incremente una fila, entonces la sumo al posicionador de filas
    int id,pos;
    {
        x=16;
        y=10;
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)197;
        gotoxy(x,++y);
        cout<<(char)179;
        if(y2>0){
            for(int i=0;i<y2;i++){// para agrandar el bracito...
                gotoxy(x,++y);
                cout<<(char)179;
            }
        }
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<"ID del proveedor";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
        /**
            │
            └──►ID del proveedor
                    →
        */
    }
    cin>> id;
    pos=verificarIdPos(id);
    if(pos==-1){
        gotoxy((x+10),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    Proveedor proveedor=archivo.leerRegistro((id-1));
    proveedor.Mostrar();
    {// Pregunta si los datos son correctos
        char eleccion;
        y+=4;
        rlutil::setColor(8);
        gotoxy(--x,y);
        cout<<(char)218;
        for(int i=0;i<35;i++){ cout<<(char)196; }
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        cout<<" LOS DATOS SON CORRECTOS? S/N: ";
        cin>>eleccion;
        eleccion=tolower(eleccion);
        if(eleccion!='s'){ return false; }
    }
    proveedor.setEstado(false);
    archivo.modificarProveedor(proveedor,(id-1));
    gotoxy((x+4),y);
    rlutil::setColor(14);
    cout<<"DATOS ELIMINADOS EXITOSAMENTE!           \n";
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}

#endif // SUBMENUPROVEEDORES_H_INCLUDED
