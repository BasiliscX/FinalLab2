#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED
int autonumericoID();
bool verificarDNIproveedor(int dni);

class Proveedor:public DatosPersona{
private:
    int ID;
    bool estado;
public:
    Proveedor(int dni=0 ,const char*nombre="0",const char*telefono="0", const char*direccion="0"){
        setDNI(dni);
        setNombre(nombre);
        setTelefono(telefono);
        setDireccion(direccion);
        setEstado(true);
    }
    //métodos
    bool Cargar();
    void Mostrar();
    //set
    void setID(int i){ID=i; }
    void setEstado(bool e){ estado=e; }
    //get
    int getID(){ return ID; };
    bool getEstado(){ return estado; }
};
bool Proveedor::Cargar(){
    int x,y;
    bool verifico;
    ID=autonumericoID();// genera el ID autonumérico

    x=25;
    y=12;
    gotoxy(x,y);
    rlutil::setColor(15);
    cout<<"ID ";
    rlutil::setColor(8);
    cout<<"generado automaticamente";
    rlutil::setColor(15);
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" "<<ID;
    gotoxy(x,++y);
    cout<<"DNI";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cin>>DNI;

    verifico=verificarDNIproveedor(DNI);// verifica que el dni no esté ingresado
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
        if(DNI==0){ return false; }
        cls(31,17,30);
        cls(28,18,34);
    }
    gotoxy(x,++y);
    cout<<"Nombre";
    gotoxy((x+4),++y);
    cout<<(int_fast8_t)26<<" ";
    cargarCadena(nombre,29);

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
    {// Pregunta si los datos son correctos
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        rlutil::setColor(15);
        rlutil::hidecursor();
        cout<<" DATOS INGRESADOS CORRECTAMENTE!\n";
        rlutil::anykey();

    }
    estado=true;
    return true;
}

void Proveedor::Mostrar()
{
    cout<<"ID : "<<ID<<endl;
    cout<<"DNI : "<<endl;
    cout<<DNI<<endl;

    cout<<"Nombre : "<<endl;
    cout<<nombre<<endl;

    cout<<"Telefono : "<<endl;
    cout<<telefono<<endl;

    cout<<"Direccion : "<<endl;
    cout<<direccion<<endl;


}

#endif // PROVEEDOR_H_INCLUDED
