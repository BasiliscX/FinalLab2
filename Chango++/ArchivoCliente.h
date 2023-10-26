#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED


class ArchivoCliente
{
private:
    char nombre[30];

public:
    ArchivoCliente (const char* n) {strcpy(nombre,n);}

    //métodos
    bool ListarClientes();
    bool AgregarCliente(Cliente);
    int BuscarRegistro(int ID);
    Cliente LeerRegistro(int);
    bool ModificarCliente(int,Cliente);
    int ContarRegistros();



};


bool ArchivoCliente::ListarClientes(){
    system("cls");
    Cliente reg;
    FILE*p=fopen(nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    while(fread(&reg,sizeof(Cliente),1,p)){
        reg.Mostrar();

    }
    fclose(p);
    system("pause");
    system("cls");
    return true;
}

bool ArchivoCliente::AgregarCliente(Cliente reg){
    system("cls");
    FILE*p=fopen(nombre,"ab");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    bool escribio=fwrite(&reg,sizeof(Cliente),1,p);
    fclose(p);
    if(escribio){
        std::cout<<"\n\tRegistro agregado.\n";
    }
    system("pause");
    system("cls");
    return true;
}

int ArchivoCliente::BuscarRegistro(int ID){
    int cont=0;
    Cliente reg;
    FILE*p=fopen(nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return -2;
    }
    while(fread(&reg,sizeof(Cliente),1,p)){
        if(reg.getID()== ID ){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

Cliente ArchivoCliente::LeerRegistro(int pos){
    Cliente reg;
    reg.setEstado(false);
    FILE*p=fopen(nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return reg;
    }
    fseek(p,sizeof(Cliente)*pos,0);
    fread(&reg,sizeof(Cliente),1,p);
    fclose(p);
    return reg;
/*
    int cont=0;
    while(fread(&reg,sizeof(Cliente),1,p)){
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

bool ArchivoCliente::ModificarCliente(int pos, Cliente reg){
    reg.setEstado(false);
    FILE*p=fopen(nombre,"rb+");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    fseek(p,sizeof(Cliente)*pos,0);
    bool escribio=fwrite(&reg,sizeof(Cliente),1,p);
    fclose(p);
    return escribio;
}
 int ArchivoCliente::ContarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Cliente);
    }


#endif // ARCHIVOCLIENTE_H_INCLUDED
