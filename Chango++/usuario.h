#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED

class Usuario{
private:
    char usuario[20];
    char contrasenia[10];
public:
    Usuario(const char*usuario="-",cons char*contrasenia="-"){
        this.usuario=usuario;
        this.contrasenia=contrasenia;
    }
    bool Cargar();
    bool Mostrar();
    void setUsuario(const char*u){ strcpy(usuario,u); }
    void setContrasenia(const char*c){ strcpy(contrasenia,c); }
    const char*getUsuario(){ return usuario; }
    const char*getContrasenia(){ return contrasenia; }
};
Usuario::Cargar(){
    int x,y;
    x=25;
    y=12;
    gotoxy(x,y);
    cout<<"Nombre de usuario";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cin>>usuario;
    verifico=verificarDNIcliente(DNI);// verifica que el dni no esté registrado
    while(verifico){
        gotoxy(31,17);
        rlutil::setColor(4);
        cout<< "El DNI ya esta registrado";
        gotoxy(28,18);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(31,y,30);
        gotoxy(31,y);
        cin>>DNI;
    verifico=verificarDNIproveedor(DNI);
        if(strcmp(DNI,"0")==0){ return false; }
        cls(31,17,30);
        cls(28,18,34);
    }
    gotoxy(x,++y);
    cout<<"Nombre";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(nombre,29);

    gotoxy(x,++y);
    cout<<"Apellido";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(apellido,29);

    gotoxy(x,++y);
    cout<<"Telefono";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(telefono,29);

    gotoxy(x,++y);
    cout<<"Direccion";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(direccion,29);
    {// Pregunta si los datos son correctos
        char eleccion;
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(char)195;
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
    {// mensaje final
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::hidecursor();
        rlutil::setColor(14);
        cout<<" DATOS INGRESADOS CORRECTAMENTE!\n";
        rlutil::setColor(15);
        rlutil::anykey();
    }
    estado=true;
    return true;
}

#endif // USUARIO_H_INCLUDED
