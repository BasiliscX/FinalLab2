#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED

class ArchivoProducto{
private:
    char _nombre[30];
public:
    ArchivoProducto(const char*n){ strcpy(_nombre,n); }
    const char*getNombre(){ return _nombre; }


    bool ListarProductos();
    bool AgregarRegistros(Producto);
    int BuscarRegistro(const char*);
    Producto LeerRegistro(int);
    bool ModificarRegistro(int,Producto);
    int ContarRegistros();
};

bool ArchivoProducto::ListarProductos(){
    system("cls");
    Producto regProducto;
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    while(fread(&regProducto,sizeof(Producto),1,p)){
        regProducto.Mostrar();

    }
    fclose(p);
    system("pause");
    system("cls");
    return true;
}

bool ArchivoProducto::AgregarRegistros(Producto regProducto){
    system("cls");
    FILE*p=fopen(_nombre,"ab");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    bool escribio=fwrite(&regProducto,sizeof(Producto),1,p);
    fclose(p);
    if(escribio){
        std::cout<<"\n\tRegistro agregado.\n";
    }
    system("pause");
    system("cls");
    return true;
}

int ArchivoProducto::BuscarRegistro(const char*cod){
    int cont=0;
    Producto regProducto;
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return -2;
    }
    while(fread(&regProducto,sizeof(Producto),1,p)){
        if(strcmp(regProducto.getCodigo(),cod)==0){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}

Producto ArchivoProducto::LeerRegistro(int pos){
    Producto regProducto;
    regProducto.setEstado(false);
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return regProducto;
    }
    fseek(p,sizeof(Producto)*pos,0);
    fread(&regProducto,sizeof(Producto),1,p);
    fclose(p);
    return regProducto;
/*
    int cont=0;
    while(fread(&regProducto,sizeof(Producto),1,p)){
        if(cont==pos){
            fclose(p);
            return regProducto;
        }
        cont++;
    }
    fclose(p);
    regProducto.setEstado(false);
    return regProducto;
*/
}

bool ArchivoProducto::ModificarRegistro(int pos, Producto regProducto){
    regProducto.setEstado(false);
    FILE*p=fopen(_nombre,"rb+");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    fseek(p,sizeof(Producto)*pos,0);
    bool escribio=fwrite(&regProducto,sizeof(Producto),1,p);
    fclose(p);
    return escribio;
}
 int ArchivoProducto::ContarRegistros(){
        FILE *p;
        p=fopen(_nombre, "rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Producto);
    }

#endif // ARCHIVOPRODUCTO_H_INCLUDED
