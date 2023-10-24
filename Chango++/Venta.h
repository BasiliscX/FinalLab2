#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED

class Venta{
private:
    char cliente[8];
    char codigoArticulo[4];
    int cantidad;
    float total;
    bool estado;
public:
    Venta();
    Venta(const char*,const char*,int,float);
    void setCliente(const char*c){ strcpy(cliente,c); }
    void setCodigoArticulo(const char*c){
        if(strlen(c)<=4){ strcpy(codigoArticulo,c); }
        else { strcpy(codigoArticulo,"-1"); }
    }
    void setCantidad(int c){
        if(c>0){ cantidad=c; }
        else{ cantidad=-1; }
    }
    void setTotal(float t){
        if(t>0){ total=t; }
        else{ total=-1; }
    }
    void setEstado(bool e){ estado=e; }
    const char*getCliente(){ return cliente; }
    const char*getCodigoArticulo(){ return codigoArticulo; }
    int getcantidad(){ return cantidad; }
    float getTotal(){ return total; }
    bool getEstado(){ return estado; }
};
Venta::Venta(){
    total=0;
    setEstado(false);
}
/**
    Cada venta se carga desde el constructor
    en Ventas.dat quedaria asi:

        cliente   | codigo | cantidad | total |    fecha
        34096106     aaaa       12      4.000   11/10/2023
        34096106     bbbb       07      1.000   11/10/2023
           -1        cccc       01      12.000  11/10/2023
*/
Venta::Venta(const char*DNI,const char*codigo,int cantidad,float total){
    setCliente(DNI);
    setCodigoArticulo(codigo);
    setCantidad(cantidad);
    setTotal(total);
    Fecha fechaCompra();//Constructor que establece la fecha de sistema
    setEstado(true);
}

#endif // VENTA_H_INCLUDED
