#ifndef FUNCIONESPROVEEDORES_H_INCLUDED
#define FUNCIONESPROVEEDORES_H_INCLUDED

int autonumericoID();
int verificarIdPos(int ID);
int verificarNombreProveedorPos(const char*nombre);
int*vectorDeID_proveedores();

int autonumericoID(){ ///funcion que genera el id autonumerico
  ArchivoProveedor archiProv("dat\\Proveedores.dat");
  int cantReg=0;

  cantReg = archiProv.contarRegistros();


    if (cantReg == 0) return 1;

    else
    {
        Proveedor reg;
        reg = archiProv.leerRegistro(cantReg-1);
        return reg.getID()+1;
    }
}
int verificarIdPos(int id){ ///verifica la posicion de un proveedor por ID

Proveedor reg;
ArchivoProveedor archiProv("dat\\Proveedores.dat");
int cantReg = archiProv.contarRegistros();

for(int i=0; i<cantReg; i++){

   reg = archiProv.leerRegistro(i);
    if(reg.getID() == id && reg.getEstado()) {
        return i;
    }

}
return -1;

}
int verificarNombreProveedorPos(const char*nombre){ ///verifica la posicion de un proveedor por nombre
    Proveedor reg;
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    int t=archivo.contarRegistros();
    for(int i=0; i<t; i++){
       reg=archivo.leerRegistro(i);
        if(strcmp(reg.getNombre(),nombre)==0 && reg.getEstado()) {
            return i;
        }
    }
    return -1;
}
bool verificarDNIproveedor(const char*dni){///verifica si existe un proveedor con ese DNI

Proveedor reg;
ArchivoProveedor archiProv("dat\\Proveedores.dat");

int cantRegprov = archiProv.contarRegistros();

for(int i=0; i<cantRegprov; i++){

    reg = archiProv.leerRegistro(i);
    if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()) {
        return true;
    }

}
return false;
}
int*vectorDeID_proveedores(){// Devuelve un vector con los numeros de ID con estado true
    ArchivoProveedor archivo("dat\\Proveedores.dat");
    Proveedor reg;
    int t=archivo.contarRegistros();
    int*vectorID=new int[t]{0};
    int cont=0;
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(reg.getEstado()){
            vectorID[cont++]=reg.getID();
        }
    }
    return vectorID;
}
int validarIDproveedor(int id){ ///revisa que el id del proveedor sea existente
    Proveedor reg;
    ArchivoProveedor archiProv("dat\\Proveedores.dat");
    int cantReg = archiProv.contarRegistros();
    for(int i=0; i<cantReg; i++){
        reg= archiProv.leerRegistro(i);
        if (reg.getID() == id && reg.getEstado()) return id;
    }
    return -1;
}


#endif // FUNCIONESPROVEEDORES_H_INCLUDED
