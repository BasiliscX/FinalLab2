#ifndef ARTICULO_H_INCLUDED
#define ARTICULO_H_INCLUDED

#include<iostream>
#include<cstring>

class Articulo{
private:
    char codigo[4];
    int tipo;
    int ID_proveedor;//siempre consultar si existe el proveedor
    char nombre[30];
    float precio;
    int cantidad;
    bool estado;
public:
    Articulo(const char*, const char*,float, bool);
    bool Cargar(const char*,int*,int);
    void Mostrar();
    void setCodigo(const char*c){
        if(strlen(c)==4){ strcpy(codigo,c); }
        else { strcpy(codigo,"-1"); }
    }
    void setTipo(int t){
        if(t>=1 && t<=6){ tipo=t; }
        else{ tipo=-1; }
    }
    void setID_proveedor(int id){ ID_proveedor=id; }
    void setNombre(const char*n){ strcpy(nombre,n); }
    void setPrecio(float p){
        if(p>0){ precio=p; }
        else { precio=-1; }
    }
    void setCantidad(int c){
        if(c>0){ cantidad=c; }
        else{ cantidad=-1; }
    }
    void setEstado(bool e){ estado=e; }
    const char*getCodigo(){return codigo;}
    int getTipo(){ return tipo; }
    int getID_porveedor(){ return ID_proveedor; }
    const char*getNombre(){return nombre;}
    float getPrecio(){return precio;}
    bool getEstado(){return estado;}
};
Articulo::Articulo(const char*cod="AAAA", const char*nom="Articulo", float pre=9.0, bool est=false){
    setCodigo(cod);
    setNombre(nom);
    setPrecio(pre);
    setEstado(est);
}
/**borrar: const char*cod="null",*/
bool Articulo::Cargar(const char*cod="null",int vP[]={0},int tam=10){
    char c[4];
    char tipo;
    int t, can;
    int ID_p;
    char n[30];
    float p;
    rlutil::setColor(15);

    int vPp[10]={1,12,32,4,11,23,33,12,3,5};///Para pruebas

    cout<<"\n\t\t\tTipo de producto";
    rlutil::setColor(8);
    cout<<"\n\t\t\t(-1 alimentos, 2 bebidas, 3 P. Hogar,";
    cout<<"\n\t\t\t4 Higiene, 5 electronica, 6 otros-)\n\t\t\t\t";
    rlutil::setColor(15);
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>tipo;
    switch(tipo){
        case '1': t=1; break;
        case '2': t=2; break;
        case '3': t=3; break;
        case '4': t=4; break;
        case '5': t=5; break;
        case '6': t=6; break;
        default : cout<<"\n\t\t\t\tINCORRECTO\n\t\t\t\tINTENTAR NUEVAMENTE"; rlutil::anykey(); return false;
    }
    cout<<"\n\t\t\tID de proveedor";
    rlutil::setColor(8);
    cout<<"\n\t\t\t - disponibles\n\t\t\t";
    for(int i=0;i<tam;i++){// Recibo como parametro un array con los ID disponibles, y los imprimo para eleguir entre ellos
        if(vPp[i]>0){
            cout<<"|"<<vPp[i];
        }
        cout<<"|";
    }
    rlutil::setColor(15);
    cout<<"\n\t\t\tEleccion";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>ID_p;
    {// Bloque en que evaluo si el ID de proveedor existe en el array
        bool existe=false;
        for(int i=0;i<tam;i++){
            if(ID_p==vPp[i]){
                existe=true;
                break;
            }
        }
        if(!existe){
            cout<<"\n\t\t\t\tINCORRECTO\n\t\t\t\tINTENTAR NUEVAMENTE";
            rlutil::anykey();
            return false;
        }
    }
    cout<<"\n\t\t\tNombre  ";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>n;
    cout<<"\n\t\t\tprecio  ";
    cout<<" "<<(int_fast8_t)26<<" ";    cin>>p;
    cout<<"\n\t\t\tCantidad";
    cout<<" "<<(int_fast8_t)26<<" ";    cin>>can;
    {// Animacion y recuadro de pregunta si los datos ingresados son correctos, si no lo son entonces salimos
        char eleccion;
        int x=62;
        int y=32;
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
        if(eleccion!='s'){ return false; }
        rlutil::setColor(8);
        gotoxy(--x,++y);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)179;
        gotoxy(x,++y);
        cout<<(char)192<<(int_fast8_t)16;
        rlutil::setColor(15);
    }
    setCodigo(c);
    setTipo(t);
    setID_proveedor(ID_p);
    setNombre(n);
    setPrecio(p);
    setCantidad(can);
    setEstado(true);
    rlutil::hidecursor();
    cout<<" DATOS INGRESADOS CORRECTAMENTE!\n";
    rlutil::anykey();
    return true;
}
void Articulo::Mostrar(){
}
#endif // ARTICULO_H_INCLUDED
