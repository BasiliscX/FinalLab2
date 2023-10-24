#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

class Cliente{
private:
    static int contador;
    int ID;
    char apellido[30];
    DatosPersona datosCliente;
    int contadorCarritos;//Para ventas
    float acumuadorCompras;//Para ventas
    bool estado;
public:
    Cliente();
    bool Cargar(const char*);
    void Mostrar();
    void setApellido(const char*a){ strcpy(apellido,a); }
    void setContadorCarritos(int c){ contadorCarritos+=c; }
    void setAcumuladorCompras(int c){ acumuadorCompras+=c; }
    void setEstado(bool e){ estado=e; }
    int getID(){ return ID; };
    const char*getApellido(){ return apellido; }
    int getContadorCarritos(){ return contadorCarritos; }
    int getAcumuladorCompras(){ return acumuadorCompras; }
    bool getEstado(){ return estado; }
};
Cliente::Cliente(){
    setContadorCarritos(0);
    setAcumuladorCompras(0);
    setEstado(false);
}
int Cliente::contador=0;
bool Cliente::Cargar(const char*DNI){
    char a[30];
    cout<<"\n\t\t\tApellido ";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>a;
    datosCliente.Cargar(DNI);
    ID=++contador;
    {
        char eleccion;
        int x=62;
        int y=24;
        rlutil::setColor(8);
        gotoxy(x,y);
        cout<<(char)180;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)217;
        gotoxy(--x,y);
        cout<<(char)196;
        gotoxy(--x,y);
        cout<<(int_fast8_t)17;
        x-=36;
        boxAnimation(x,y,1,35,2,0);
        rlutil::setColor(15);
        gotoxy(++x,++y);
        textAnimation("Los datos son correctos? (S/N)");
        cout<<" "<<(int_fast8_t)26<<" ";
        cin>>eleccion;
        eleccion=tolower(eleccion);
        if(eleccion!='s'){
            ID=--contador;
            return false;
        }
        else{
            setApellido(a);
            setEstado(true);
        }
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(int_fast8_t)16;
        rlutil::setColor(15);
    }
    return true;
}

#endif // CLIENTE_H_INCLUDED
