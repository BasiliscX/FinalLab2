#ifndef PROVEEDOR_H_INCLUDED
#define PROVEEDOR_H_INCLUDED

/*
id (int -autonumérico-)
datosProveedor (DatosPersona)
producto[] (Productos)
*/
class Proveedor{
private:
    static int contador;
    int ID;
    DatosPersona datosProveedor;
public:
    bool Cargar(int);
    void Mostrar();
    int getID(){ return ID; };
};
int Proveedor::contador=0;
bool Proveedor::Cargar(int CUIT){
    datosProveedor.Cargar(CUIT);
    ID=++contador;
    {
        char eleccion;
        int x=62;
        int y=22;
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

#endif // PROVEEDOR_H_INCLUDED
