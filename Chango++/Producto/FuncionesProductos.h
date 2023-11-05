#ifndef FUNCIONESPRODUCTOS_H_INCLUDED
#define FUNCIONESPRODUCTOS_H_INCLUDED

int verificarCodigoPos(int codigo);
int*vectorDeCodigosProductos();
bool setCantidadEnDisco(Producto);

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
Producto obtenerProducto(int codigo){
    Producto reg;
    ArchivoProducto archivo("Productos.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getCodigo() == codigo && reg.getEstado()) {
            return reg;
        }
    }
    return reg;
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
bool setCantidadEnDisco(Producto producto){
    ArchivoProducto archivo("Productos.dat");
    return archivo.modificarProducto(producto,verificarCodigoPos(producto.getCodigo()));
}

#endif // FUNCIONESPRODUCTOS_H_INCLUDED
