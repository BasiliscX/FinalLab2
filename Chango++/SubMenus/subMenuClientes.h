#ifndef SUBMENUCLIENTES_H_INCLUDED
#define SUBMENUCLIENTES_H_INCLUDED

void menuClientes();
bool agregarCliente();
bool listarClientePorID();
bool listarTodosClientes();
bool MOdificarClientePorID(const char*);
bool eliminarClientePorID();

void menuClientes(){
    bool menu=true;
    char eleccion;
    int velocidad=0;
    int x,y;

    while(menu){
    {// recuadro y Titulo
        rlutil::cls();
        rlutil::setColor(8);
        boxAnimation(1,1,3,79,44,0);
        boxAnimation(2,2,1,77,42,0);
        changoPP(15,7);
        x=30;
        y=20;
        textBoxAnimation(x,y,"MENU DE CLIENTES",2,0);
        /**
        ╔════════════════╗
        ║MENU DE CLIENTES║
        ╚════════════════╝
        */
    }
    {// Menu seleccion
        x=21;
        y=27;
        rlutil::setColor(8);
        boxAnimation(x,y,1,34,12,velocidad);
        rlutil::setColor(15);
        x+=1;
        rlutil::hidecursor();
        y=28;
        rlutil::locate(x,y);
        textAnimation("1 - Agregar cliente",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("2 - Listar cliente por ID",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("3 - Listar todos los clientes",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("4 - Modificar datos de un cliente",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("5 - ELiminar datos de un cliente",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("0 - volver al menu proncipal",velocidad);
        y+=2;
        rlutil::locate(x,y);
        textAnimation("\tEleccion: ");
    }
        rlutil::showcursor();
        cin>>eleccion;
        switch(eleccion){
            case '1' : agregarCliente(); break;
            case '2' : listarClientePorID(); break;
            case '3' : listarTodosClientes(); break;
            case '4' :
                switch(modificarDatos()){
                    case -1: MOdificarClientePorID("Telefono"); break;
                    case -2: MOdificarClientePorID("Direccion"); break;
                    default: break;
                }
                break;
            case '5' : eliminarClientePorID(); break;
            default: menu=false; break;
        }
    }
}
bool agregarCliente(){
    rlutil::cls();
    int x,y;
    ArchivoCliente archivo("Clientes.dat");
    {// Recuadros y titulo con flechas
        textBoxAnimation(29,4,"AGREGAR CLIENTE");
        /**
        ╔═══════════════╗
        ║AGREGAR CLIENTE║
        ╚═══════════════╝
        */
        textBoxAnimation(11,8,"CLIENTE",1);
        x=19;
        y=10;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(char)196<<(char)196<<(int_fast8_t)16;
        /**
        ┌───────┐
        │CLIENTE│
        └───────┤
                └───►
        */
        x=23;
        y=10;
        gotoxy(x,y);
        x++;
        y++;
        rlutil::setColor(8);
        boxAnimation(x,y,1,38,13,0);
        gotoxy(++x,++y);
    }
    archivo.agregarCliente();
    return true;
}
bool listarClientePorID(){
    rlutil::cls();
    ArchivoCliente archivo("Clientes.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    {// Titulo y recuadros con flechas
        textBoxAnimation(26,4,"LISTAR CLIENTES POR ID",2,velocidad);
        /**
        ╔══════════════════════╗
        ║LISTAR CLIENTES POR ID║
        ╚══════════════════════╝
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
        vectorID=vectorDeID_clientes();
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
        cout<<"ID del cliente";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
        /**
            │
            └──►ID del proveedor
                    →
        */
    }
    cin>> id;
    pos=verificarIdClientePos(id);
    if(pos==-1){
        gotoxy((x+10),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    Cliente cliente=archivo.leerRegistro((id-1));
    cliente.Mostrar();
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool listarTodosClientes(){
    rlutil::cls();
    ArchivoCliente archivo("Clientes.dat");
    int x,y,t=archivo.contarRegistros();
    int velocidad=0;
    x=24;
    y=4;
    textBoxAnimation(x,y,"LISTAR TODOS LOS CLIENTES",2,velocidad);
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
        Cliente cliente=archivo.leerRegistro(i);
        cliente.Mostrar();
        cout<<endl;
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool MOdificarClientePorID(const char*campo){
    rlutil::cls();
    ArchivoCliente archivo("Clientes.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    {// Titulo y recuadros con flechas
        textBoxAnimation(25,4,"MODIFICAR CLIENTE POR ID",2,velocidad);
        /**
        ╔════════════════════════╗
        ║MODIFICAR CLIENTE POR ID║
        ╚════════════════════════╝
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
        vectorID=vectorDeID_clientes();
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
        cout<<"ID del cliente";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
        /**
            │
            └──►ID del cliente
                    →
        */
    }
    cin>> id;
    pos=verificarIdClientePos(id);
    if(pos==-1){
        gotoxy((x+10),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    Cliente cliente=archivo.leerRegistro((id-1));
    cliente.Mostrar();
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
    if(strcmp(campo,"Telefono")==0){// Modifico el telefono del cliente
        gotoxy((x+4),(y+2));
        char telefonoClienteNuevo[30];
        cout<<"Nuevo telefono: ";
        cargarCadena(telefonoClienteNuevo,29);
        cliente.setTelefono(telefonoClienteNuevo);
        archivo.modificarCliente(cliente,(id-1));
        cliente=archivo.leerRegistro((id-1));
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        cliente.Mostrar();
    }
    if(strcmp(campo,"Direccion")==0){// Modifico la direccion del cliente
        gotoxy((x+4),(y+2));
        char direccionClienteNuevo[30];
        cout<<"Nueva direccion: ";
        cargarCadena(direccionClienteNuevo,29);
        cliente.setDireccion(direccionClienteNuevo);
        archivo.modificarCliente(cliente,(id-1));
        cliente=archivo.leerRegistro((id-1));
        gotoxy((x+4),(y+2));
        rlutil::setColor(14);
        cout<<"DATOS MODIFICADOS EXITOSAMENTE!           \n";
        rlutil::setColor(15);
        cliente.Mostrar();
    }
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}
bool eliminarClientePorID(){
    rlutil::cls();
    ArchivoCliente archivo("Clientes.dat");
    int t=archivo.contarRegistros();
    int x,y,y2=0;
    int velocidad=0;
    {// Titulo y recuadros con flechas
        textBoxAnimation(25,4,"ELIMINAR CLIENTE POR ID",2,velocidad);
        /**
        ╔═══════════════════════╗
        ║ELIMINAR CLIENTE POR ID║
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
        vectorID=vectorDeID_clientes();
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
        cout<<"ID del cliente";
        gotoxy((x+8),++y);
        cout<<(int_fast8_t)26<<" ";
        /**
            │
            └──►ID del cliente
                    →
        */
    }
    cin>> id;
    pos=verificarIdClientePos(id);
    if(pos==-1){
        gotoxy((x+10),y);
        rlutil::setColor(4);
        rlutil::hidecursor();
        rlutil::anykey("INCORRECTO, INTENTAR LUEGO");
        rlutil::setColor(15);
        return false;
    }
    Cliente cliente=archivo.leerRegistro((id-1));
    cliente.Mostrar();
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
    cliente.setEstado(false);
    archivo.modificarCliente(cliente,(id-1));
    gotoxy((x+4),y);
    rlutil::setColor(14);
    cout<<"DATOS ELIMINADOS EXITOSAMENTE!           \n";
    rlutil::hidecursor();
    rlutil::anykey();
    return true;
}

#endif // SUBMENUCLIENTES_H_INCLUDED
