#ifndef FUNCIONESCLIENTES_H_INCLUDED
#define FUNCIONESCLIENTES_H_INCLUDED

int autonumericoClienteID();
void listarClientes();
int verificarIdClientePos(int ID);
bool mostrarClienteXid();
bool modificarNombreCliente(int id);
bool modificarApellidoCliente();
int verificarDniClientePos(int dni);
int*vectorDeID_clientes();

int autonumericoClienteID() ///funcion que genera id autonumerico
{
  ArchivoCliente archiCli("Clientes.dat");
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
ArchivoCliente archiCli("Clientes.dat");
int cantReg= archiCli.contarRegistros();

for(int i=0; i<cantReg; i++){

    reg=archiCli.leerRegistro(i);
    reg.Mostrar();
    cout<<endl;
}

}

int verificarIdClientePos(int id){/// revisa la posicion del cliente segun ID

Cliente reg;
ArchivoCliente archiCli("Clientes.dat");
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
ArchivoCliente archiCli("Clientes.dat");
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
bool modificarNombreCliente(){///modifica el nombre del cliente segun ID

Cliente reg;
char nombreClienteNuevo[30];
ArchivoCliente archiCli("Clientes.dat");
int id, pos;
bool modificoN;

cout<<"Ingrese el id del cliente a modificar: "<<endl;
cin>>id;
pos=verificarIdClientePos(id);
if(pos==-1) return false;

reg =archiCli.leerRegistro(pos);
cout<<"Nuevo nombre: "<<endl;
cargarCadena(nombreClienteNuevo,29);
cout<<endl;

reg.setNombre(nombreClienteNuevo);
modificoN=archiCli.modificarCliente(reg,pos);


return modificoN;

}

bool modificarApellidoCliente(){  ///modifica el apellido del cliente segun ID

Cliente reg;
char apellidoClienteNuevo[30];
ArchivoCliente archiCli("Clientes.dat");
int id, pos;
bool modificoA;

cout<<"Ingrese el id del cliente a modificar: "<<endl;
cin>>id;
pos=verificarIdClientePos(id);
if(pos==-1) return false;

reg =archiCli.leerRegistro(pos);
cout<<"Nuevo apellido: "<<endl;
cargarCadena(apellidoClienteNuevo,29);
cout<<endl;

reg.setApellido(apellidoClienteNuevo);
modificoA=archiCli.modificarCliente(reg,pos);


return modificoA;

}
/**
int verificarDniClientePos( int dni){///verifica la posicion del cliente segun DNI

Cliente reg;
ArchivoCliente archiCli("Clientes.dat");
int cantReg = archiCli.contarRegistros();

for(int i=0; i<cantReg; i++){

   reg = archiCli.leerRegistro(i);
    if(reg.getDNI()==dni&& reg.getEstado()) {
        return i;
    }

}
return -1;

}
*/

bool verificarDNIcliente(const char*dni){///verifica si existe cliente con ese DNI

Cliente reg;
ArchivoCliente archiCli("Clientes.dat");

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
    ArchivoCliente archivo("Clientes.dat");
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

#endif // FUNCIONESCLIENTES_H_INCLUDED
