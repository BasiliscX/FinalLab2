#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

int autonumericoClienteID();
void listarClientes();
int verificarIdClientePos(int ID);
bool mostrarClienteXid();
bool modificarNombreCliente(int id);
bool modificarApellidoCliente();
int verificarDniClientePos(const char*);
int*vectorDeID_clientes();

int autonumericoClienteID() ///funcion que genera id autonumerico
{
  ArchivoCliente archiCli("dat\\Clientes.dat");
  int cantReg=0;

  cantReg = archiCli.contarRegistros();


    if (cantReg == 0) return 1;

    else
    {
        Cliente reg;
        reg = archiCli.leerRegistro(cantReg-1);
        return reg.getID()+1;
    }
}

void listarClientes(){ ///muestra todos los clientes

Cliente reg;
ArchivoCliente archiCli("dat\\Clientes.dat");
int cantReg= archiCli.contarRegistros();

for(int i=0; i<cantReg; i++){

    reg=archiCli.leerRegistro(i);
    reg.Mostrar();
    cout<<endl;
}

}

int verificarIdClientePos(int id){/// revisa la posicion del cliente segun ID

Cliente reg;
ArchivoCliente archiCli("dat\\Clientes.dat");
int cantReg = archiCli.contarRegistros();

for(int i=0; i<cantReg; i++){

   reg = archiCli.leerRegistro(i);
    if(reg.getID() == id && reg.getEstado()) {
        return i;
    }

}
return -1;

}

bool mostrarClienteXid(){///muestra cliente segun ID

Cliente reg;
ArchivoCliente archiCli("dat\\Clientes.dat");
int id,pos;

cout<<"Ingrese el id del cliente a mostrar: "<<endl;
cin>> id;
cout<<endl;
pos=verificarIdClientePos(id);

if(pos == -1) return false;

reg=archiCli.leerRegistro(pos);
reg.Mostrar();
cout<<endl;

return true;

}
int verificarDniClientePos(const char*dni){///verifica la posicion del cliente segun DNI
    Cliente reg;
    ArchivoCliente archivo("dat\\Clientes.dat");
    int cantReg = archivo.contarRegistros();
    for(int i=0; i<cantReg; i++){
       reg = archivo.leerRegistro(i);
        if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()) {
            return i;
        }
    }
    return -1;
}

bool verificarDNIcliente(const char*dni){///verifica si existe cliente con ese DNI

Cliente reg;
ArchivoCliente archiCli("dat\\Clientes.dat");

int cantReg = archiCli.contarRegistros();

for(int i=0; i<cantReg; i++){

    reg = archiCli.leerRegistro(i);
    if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()) {
        return true;
    }

}
return false;
}
int*vectorDeID_clientes(){// Devuelve un vector con los numeros de ID con estado true
    ArchivoCliente archivo("dat\\Clientes.dat");
    Cliente reg;
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
Cliente obtenerCliente(const char*dni){
    Cliente reg;
    ArchivoCliente archivo("dat\\Clientes.dat");
    int t=archivo.contarRegistros();
    for(int i=0;i<t;i++){
        reg=archivo.leerRegistro(i);
        if(strcmp(reg.getDNI(),dni)==0 && reg.getEstado()) {
            return reg;
        }
    }
    return reg;
}

#endif // FUNCIONESCLIENTES_H_INCLUDED
