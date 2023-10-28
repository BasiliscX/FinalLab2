#ifndef FUNCIONESPROVEEDORES_H_INCLUDED
#define FUNCIONESPROVEEDORES_H_INCLUDED

int autonumericoID();
void listarProveedores();
int verificarIdPos(int ID);
bool mostrarXid();
int verificarDniPos(const char*dni);
int*vectorDeID_proveedores();

int autonumericoID() ///funcion que genera el id autonumerico
{
  ArchivoProveedor archiProv("Proveedores.dat");
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

void listarProveedores(){ ///muestra todos los proveedores

Proveedor reg;
ArchivoProveedor archiProv("Proveedores.dat");
int cantReg= archiProv.contarRegistros();

for(int i=0; i<cantReg; i++){

    reg=archiProv.leerRegistro(i);
    reg.Mostrar();
    cout<<endl;
}

}

int verificarIdPos(int id){ ///verifica la posicion de un proveedor por ID

Proveedor reg;
ArchivoProveedor archiProv("Proveedores.dat");
int cantReg = archiProv.contarRegistros();

for(int i=0; i<cantReg; i++){

   reg = archiProv.leerRegistro(i);
    if(reg.getID() == id && reg.getEstado()) {
        return i;
    }

}
return -1;

}

/** A migrar a submenuproveedores   */
bool mostrarXid(){///muestra a un proveedor segun ID

Proveedor reg;
ArchivoProveedor archiProv("Proveedores.dat");
int id,pos;

cout<<"Ingrese el id del proveedor a mostrar: "<<endl;
cin>> id;
cout<<endl;
pos=verificarIdPos(id);

if(pos == -1) return false;

reg=archiProv.leerRegistro(pos);
reg.Mostrar();
cout<<endl;

return true;

}

int validarIDproveedor(int id){ ///revisa que el id del proveedor sea existente

while(id<1 || id>10){
    cout<<"opcion incorrecta "<<endl;
        cout<< "Ingrese el id del proveedor (1-10) : "<<endl;
        cin>> id;
    }
Proveedor reg;
ArchivoProveedor archiProv("Proveedores.dat");

int cantReg = archiProv.contarRegistros();

for(int i=0; i<cantReg; i++){

reg= archiProv.leerRegistro(i);
if (reg.getID() == id && reg.getEstado()) return id;

}

return -1;


}
int verificarDniPos( const char*dni){ ///verifica la posicion del proveedor segun DNI

Proveedor reg;
ArchivoProveedor archiProv("Proveedores.dat");
int cantRegprov = archiProv.contarRegistros();

for(int i=0; i<cantRegprov; i++){

   reg = archiProv.leerRegistro(i);
    if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()) {
        return i;
    }

}
return -1;

}

bool verificarDNIproveedor(const char*dni){///verifica si existe un proveedor con ese DNI

Proveedor reg;
ArchivoProveedor archiProv("Proveedores.dat");

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
    ArchivoProveedor archivo("Proveedores.dat");
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


#endif // FUNCIONESPROVEEDORES_H_INCLUDED
