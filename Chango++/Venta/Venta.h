#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
int autonumericoVentaID();
float ImporteTotal(int);

class Venta{
private:
    int ID;
    char DNI_cliente[30];
    int codigoArticulo;
    int cantidad;
    float total;
    static float valorTotal;
    bool estado;
public:
    Venta();
    Venta(const char*,int,int,float);
    int Cargar(const char*);
    void Mostrar();
    //set
    void setDNI_cliente(const char*c){ strcpy(DNI_cliente,c); }
    void setCodigoArticulo(int c){
        if(c>=1 && c<=9999){ codigoArticulo=c; }
        else{ codigoArticulo=-1; }
    }
    void setCantidad(int c){
        if(c>0){ cantidad=c; }
        else{ cantidad=-1; }
    }
    void setTotal(float t){
        if(t>=0){ total=t; }
        else{ total=-1; }
    }
    void setValorTotal(float t){
        if(t>=0){ valorTotal=t; }
        else{ total=-1; }
    }
    void setEstado(bool e){ estado=e; }

    //get
    int getID(){ return ID; }
    const char*getCliente(){ return DNI_cliente; }
    int getCodigoArticulo(){ return codigoArticulo; }
    int getcantidad(){ return cantidad; }
    float getTotal(){ return total; }
    bool getEstado(){ return estado; }
};

float Venta::valorTotal=0;

Venta::Venta(){
    setEstado(false);
}
/**
    Cada venta se carga desde el constructor
    en Ventas.dat quedaria asi:

        ID  cliente   | codigo | cantidad | total |    fecha
         1  34096106     aaaa       12      4.000   11/10/2023
         2  34096106     bbbb       07      1.000   11/10/2023
         3     -1        cccc       01      12.000  11/10/2023
*/
Venta::Venta(const char*DNI,int codigo,int cantidad,float total){
    setDNI_cliente(DNI);
    setCodigoArticulo(codigo);
    setCantidad(cantidad);
    setTotal(total);
    Fecha fechaCompra();//Constructor que establece la fecha de sistema
    setEstado(true);
}
int Venta::Cargar(const char*DNI){
    ID=autonumericoVentaID();
    int x,y;
    char continuar;
    strcpy(DNI_cliente,DNI);
    {// Bloque de carga de ventas
        x=24;
        y=15;
        gotoxy(x,y);
        rlutil::setColor(8);
        cout<<(char)195;
        gotoxy(x,++y);
        cout<<(char)192<<(char)196<<(int_fast8_t)16;
        boxAnimation(27,16,1,35,5,0);
    }
        x=28;
        y=17;
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
        gotoxy(10,24);
        producto.setCantidadMenosIgual(cantidad);
        setCantidadEnDisco(producto);
        producto.Mostrar();


        estado=true;
        total=producto.getPrecio()*cantidad;

        {// Valor total
            valorTotal+=total;
            gotoxy(25,31);
            rlutil::setColor(5);
            cout<<"Total : ";
            rlutil::setColor(9);
            cout<<"$ ";
            rlutil::setColor(15);
            cout<<valorTotal<<endl;
        }

        rlutil::setColor(8);
        gotoxy(25,28);
        cout<<"ID de venta: ";
        rlutil::setColor(15);
        cout<<ID;
        rlutil::setColor(9);
        cout<<"\n\n\t  total en producto $ ";
        rlutil::setColor(15);
        cout<<total<<endl;
        rlutil::setColor(14);
        cout<<"\n\n\n\t\t   Presione \'+\' para agregar productos: ";
        rlutil::hidecursor();
        rlutil::setColor(15);
        cin>>continuar;
        if(continuar!='+'){
            /**
                debo emitir el total con Importe Total()
                y poner contador=0;
            */
            valorTotal=0;
            return 0;
        }
        cls(10,30,50);
        cls(10,33,50);
        cls(10,34,50);
        rlutil::showcursor();
        return 1;
}
void Venta::Mostrar(){
    if(estado){
        rlutil::setColor(8);
        cout<<"\n\tID de venta: ";
        rlutil::setColor(14);
        cout<<ID;
        rlutil::setColor(8);
        cout<<"  DNI Cliente: ";
        rlutil::setColor(15);
        cout<<DNI_cliente;
        rlutil::setColor(8);
        cout<<" Codigo de producto: ";
        rlutil::setColor(15);
        cout<<codigoArticulo;
        rlutil::setColor(8);
        cout<<" Cantidad: ";
        rlutil::setColor(15);
        cout<<cantidad;
        rlutil::setColor(8);
        cout<<"\n\t\t\tTotal: ";
        rlutil::setColor(15);
        cout<<total;
    }
}

#endif // VENTA_H_INCLUDED
