#ifndef FUNCIONESPRODUCTOS_H_INCLUDED
#define FUNCIONESPRODUCTOS_H_INCLUDED


void listarProductos();
int verificarCodigoPos(int codigo);
bool mostrarXcodigo();
bool modificarPrecioProducto();
int*vectorDeCodigosProductos();

void listarProductos(){ ///muestra todos los productos

Producto reg;
ArchivoProducto archiProd("Productos.dat");
int cantReg= archiProd.contarRegistros();

for(int i=0; i<cantReg; i++){

    reg=archiProd.leerRegistro(i);
    reg.Mostrar();
    cout<<endl;
}

}

int verificarCodigoPos(int codigo){ ///verifica la posicion de un producto por codigo

Producto reg;
ArchivoProducto archiProd("Productos.dat");
int cantReg = archiProd.contarRegistros();

for(int i=0; i<cantReg; i++){

   reg = archiProd.leerRegistro(i);
    if(reg.getCodigo() == codigo && reg.getEstado()) {
        return i;
    }

}
return -1;

}

bool mostrarXcodigo(){///muestra a un proveedor segun ID

Producto reg;
ArchivoProducto archiProd("Productos.dat");
int codigo,pos;

cout<<"Ingrese el codigo del producto a mostrar: "<<endl;
cin>> codigo;
cout<<endl;
pos=verificarCodigoPos(codigo);

if(pos == -1) return false;

reg=archiProd.leerRegistro(pos);
reg.Mostrar();
cout<<endl;

return true;

}



bool modificarPrecioProducto(){   ///modifica precio segun codigo

Producto reg;
float nuevoPrecio;
ArchivoProducto archiProd("Productos.dat");
int codigo, pos;
bool modificoP;

cout<<"Ingrese el CODIGO del producto a modificar: "<<endl;
cin>>codigo;
pos=verificarCodigoPos(codigo);
if(pos==-1) return false;

reg =archiProd.leerRegistro(pos);
cout<<"Nuevo precio: "<<endl;
cin>>nuevoPrecio;
cout<<endl;

reg.setPrecio(nuevoPrecio);
modificoP=archiProd.modificarProducto(reg,pos);


return modificoP;

}

bool verificarCodigoProducto(int codigo){///verifica si existe un producto con ese codigo

Producto reg;
ArchivoProducto archiProd("Productos.dat");

int cantRegprod = archiProd.contarRegistros();

for(int i=0; i<cantRegprod; i++){

    reg = archiProd.leerRegistro(i);
    if(reg.getCodigo() == codigo && reg.getEstado()) {
        return true;
    }

}
return false;



}
int*vectorDeCodigosProductos(){// Devuelve un vector con los numeros de ID con estado true
    ArchivoProducto archivo("Productos.dat");
    Producto reg;
    int t=archivo.contarRegistros();
    int*vectorCodigos=new int[t]{0};
    int cont=0;
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getEstado()){
            vectorCodigos[cont++]=reg.getCodigo();
        }
    }
    return vectorCodigos;
}


#endif // FUNCIONESPRODUCTOS_H_INCLUDED
