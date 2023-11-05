#ifndef ITEMCARRITO_H_INCLUDED
#define ITEMCARRITO_H_INCLUDED

class itemCarrito{
private:
    int codigoArticulo;
    int cantidad;
public:
    itemCarrito(int cod=0,int cant=0){
        codigoArticulo=cod;
        cantidad=cant;
    }
    bool Cargar(float&);
    void Mostrar();
    void setCodigoArticulo(int c){
        if(c>=1 && c<=9999){ codigoArticulo=c; }
        else{ codigoArticulo=-1; }
    }
    void setCantidad(int c){
        if(c>0){ cantidad=c; }
        else{ cantidad=-1; }
    }
    int getCodigoArticulo(){ return codigoArticulo; }
    int getcantidad(){ return cantidad; }
};
bool itemCarrito::Cargar(float&total){
    int x=28;
    int y=17;
    gotoxy(x,y);
    rlutil::setColor(15);
    cout<<"Codigo";
    rlutil::setColor(8);
    cout<<" - Numerico (1~9999) -";
    rlutil::setColor(15);
    cls((x+4),++y,10);
    gotoxy((x+4),y);
    cout<<(int_fast8_t)26<<" ";
    cin>>codigoArticulo;// Si el codigo no cumple con el rango o no existe, entonces:
    while((codigoArticulo<1 || codigoArticulo>9999) || !verificarCodigoProducto(codigoArticulo)){
        gotoxy(35,19);
        rlutil::setColor(4);
        cout<< "Codigo incorrecto";
        gotoxy(28,20);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(33,y,25);
        gotoxy(34,y);
        cin>> codigoArticulo;
        if(codigoArticulo==0){ return -1; }
        cls(35,19,25);// Borra "Codigo incorrecto"
        cls(28,20,33);// Borra ingrese nuevamente (0 para salir)"
    }
    Producto producto=obtenerProducto(codigoArticulo);
    gotoxy(10,24);
    producto.Mostrar();
    gotoxy(x,++y);
    cout<<"Cantidad";
    cls((x+4),++y,10);
    gotoxy((x+4),y);
    cout<<(int_fast8_t)26<<" ";
    cin>>cantidad;// Si ingreso una cantidad <1 entonces:
    while(cantidad<1){
        gotoxy(36,21);
        rlutil::setColor(4);
        cout<< "Valor invalido";
        gotoxy(28,22);
        cout<<"ingrese nuevamente (0 para salir)";
        rlutil::setColor(15);
        cls(34,y,25);
        gotoxy(34,y);
        cin>>cantidad;
        if(cantidad==0){ return -1; }
        cls(36,21,25);// Borra "Valor invalido"
        cls(28,22,33);// Borra ingrese nuevamente (0 para salir)"
    }
    producto.setCantidadMenosIgual(cantidad);
    setCantidadEnDisco(producto);
    gotoxy(10,24);
    producto.Mostrar();
    total+=producto.getPrecio()*cantidad;
    return true;
}
void itemCarrito::Mostrar(){
        rlutil::setColor(8);
        cout<<" Codigo de producto: ";
        rlutil::setColor(15);
        cout<<codigoArticulo;
        rlutil::setColor(8);
        cout<<" Cantidad: ";
        rlutil::setColor(15);
        cout<<cantidad;
}

#endif // ITEMCARRITO_H_INCLUDED
