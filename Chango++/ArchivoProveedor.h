#ifndef ARCHIVOPROVEEDOR_H_INCLUDED
#define ARCHIVOPROVEEDOR_H_INCLUDED

class ArchivoProveedor
{
private:
    char nombre[30];

public:
    ArchivoProveedor (const char* n) {strcpy(nombre,n);}

    //métodos
    bool ListarProveedores();
    bool AgregarProveedor(Proveedor);
    int BuscarRegistro(int ID);
    Proveedor LeerRegistro(int);
    bool ModificarProveedor(int,Proveedor);
    int ContarRegistros();

};


bool ArchivoProveedor::ListarProveedores(){
    system("cls");
    Proveedor reg;
    FILE*p=fopen(nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    while(fread(&reg,sizeof(Proveedor),1,p)){
        reg.Mostrar();

    }
    fclose(p);
    system("pause");
    system("cls");
    return true;
}

bool ArchivoProveedor::AgregarProveedor(Proveedor reg){
    system("cls");
    FILE*p=fopen(nombre,"ab");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    bool escribio=fwrite(&reg,sizeof(Proveedor),1,p);
    fclose(p);
    if(escribio){
        std::cout<<"\n\tRegistro agregado.\n";
    }
    system("pause");
    system("cls");
    return true;
}

int ArchivoProveedor::BuscarRegistro(int ID){
    int cont=0;
    Proveedor reg;
    FILE*p=fopen(nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return -2;
    }
    while(fread(&reg,sizeof(Proveedor),1,p)){
        if(reg.getID()== ID ){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

Proveedor ArchivoProveedor::LeerRegistro(int pos){
    Proveedor reg;
    reg.setEstado(false);
    FILE*p=fopen(nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return reg;
    }
    fseek(p,sizeof(Proveedor)*pos,0);
    fread(&reg,sizeof(Proveedor),1,p);
    fclose(p);
    return reg;
/*
    int cont=0;
    while(fread(&reg,sizeof(Proveedor),1,p)){
        if(cont==pos){
            fclose(p);
            return reg;
        }
        cont++;
    }
    fclose(p);
    reg.setEstado(false);
    return reg;
*/
}

bool ArchivoProveedor::ModificarProveedor(int pos, Proveedor reg){
    reg.setEstado(false);
    FILE*p=fopen(nombre,"rb+");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    fseek(p,sizeof(Proveedor)*pos,0);
    bool escribio=fwrite(&reg,sizeof(Proveedor),1,p);
    fclose(p);
    return escribio;
}
 int ArchivoProveedor::ContarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Proveedor);
    }


#endif // ARCHIVOPROVEEDOR_H_INCLUDED
