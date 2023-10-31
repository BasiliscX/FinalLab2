#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{             //MIO
private:
    char codigo[4];
    int tipo;
    int ID_proveedor;//siempre consultar si existe el proveedor
    char nombre[30];
    float precio;
    int cantidad;
    bool estado;
public:
    Producto(const char*, const char*,float, bool);//prototipo constructor

    //métodos
    bool Cargar(const char*,int*,int);
    void Mostrar();

    //set
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

    //get
    const char*getCodigo(){return codigo;}
    int getTipo(){ return tipo; }
    int getID_porveedor(){ return ID_proveedor; }
    const char*getNombre(){return nombre;}
    float getPrecio(){return precio;}
    bool getEstado(){return estado;}
};

Producto::Producto(const char*cod="AAAA", const char*nom="Articulo", float pre=9.0, bool est=false){
    setCodigo(cod);
    setNombre(nom);
    setPrecio(pre);
    setEstado(est);
}
/**borrar: const char*cod="null",*/
bool Producto::Cargar(const char*cod="null",int vP[]={0},int tam=10){
    char c[4];
    char tipo;
    int t, can;
    int ID_p;
    char n[30];
    float p;
    rlutil::setColor(15);
    if(strcmp(cod,"null")==0){/// A borrar
        cout<<"\n\t\t\tCodigo";
        rlutil::setColor(8);
        cout<<" (4 caracteres)\n\t\t\t\t";
        rlutil::setColor(15);
        cout<<" "<<(int_fast8_t)26<<" ";
        cin>>c;
    }

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
    for(int i=0;i<tam;i++){
        if(vPp[i]>0){
            cout<<"|"<<vPp[i];
        }
        cout<<"|";
    }
    rlutil::setColor(15);
    cout<<"\n\t\t\tEleccion";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>ID_p;
    {
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
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>p;
    cout<<"\n\t\t\tCantidad";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>can;
    {
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
void Producto::Mostrar(){

    cout<<"código : "<<endl;
    cout<<codigo<<endl;
    cout<<"tipo : "<<endl;
    cout<<tipo<<endl;
    cout<<"ID proveedor : "<<endl;
    cout<<ID_proveedor<<endl;
    cout<<"nombre : "<<endl;
    cout<<nombre<<endl;
    cout<<"precio : "<<endl;
    cout<<precio<<endl;
    cout<<"cantidad : "<<endl;
    cout<<cantidad<<endl;
}

#endif // PRODUCTO_H_INCLUDED
