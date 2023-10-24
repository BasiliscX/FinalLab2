#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

class Venta{
private:
    Cliente cliente;
    Fecha fechaCompra;
    char codigoArticulo[4];
    int cantidad;
//    Descuento descuento;
    float total;
    bool estado;
public:
    Venta();
    bool Cargar(bool);
    void Mostrar();
    void setCodigoArticulo(const char*c){
        if(strlen(c)==4){ strcpy(codigoArticulo,c); }
        else { strcpy(codigoArticulo,"-1"); }
    }
    void setCantidad(int c){
        if(c>0){ cantidad=c; }
        else{ cantidad=-1; }
    }
    void setEstado(bool e){ estado=e; }
    const char*getCodigoArticulo(){ return codigoArticulo; }
    int getcantidad(){ return cantidad; }
    float getTotal(){ return total; }
    bool getEstado(){ return estado; }
};
Venta::Venta(){
    total=0;
    setEstado(false);
}
bool Venta::Cargar(bool cliente){
    char c[4];
    int can;
    cout<<"\n\t\t\tCodigo de articulo";
    rlutil::setColor(8);
    cout<<" (4 caracteres)\n\t\t\t\t";
    rlutil::setColor(15);
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>c;
    cout<<"\n\t\t\tCantidad de articulo\n\t\t\t\t";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>c;

    return true;
}

#endif // VENTA_H_INCLUDED
