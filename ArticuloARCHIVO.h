#ifndef ARTICULOARCHIVO_H_INCLUDED
#define ARTICULOARCHIVO_H_INCLUDED

#include<iostream>
#include<cstring>
#include"Articulo.h"

class ArchivoArticulo{
private:
    char _nombre[30];
public:
    ArchivoArticulo(const char*n){ strcpy(_nombre,n); }
    const char*getNombre(){ return _nombre; }
    bool ListarRegistros();
    bool AgregarRegistros(Articulo);
    int BuscarRegistro(const char*);
    Articulo LeerRegistro(int);
    bool ModificarRegistro(int,Articulo);
};
bool ArchivoArticulo::ListarRegistros(){
    system("cls");
    Articulo regArticulo;
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    while(fread(&regArticulo,sizeof(Articulo),1,p)){
        regArticulo.Mostrar();
        std::cout<<"\n********************************\n";
    }
    fclose(p);
    system("pause");
    system("cls");
    return true;
}
bool ArchivoArticulo::AgregarRegistros(Articulo regArticulo){
    system("cls");
    FILE*p=fopen(_nombre,"ab");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    bool escribio=fwrite(&regArticulo,sizeof(Articulo),1,p);
    fclose(p);
    if(escribio){
        std::cout<<"\n\tRegistro agregado.\n";
    }
    system("pause");
    system("cls");
    return true;
}
int ArchivoArticulo::BuscarRegistro(const char*cod){
    int cont=0;
    Articulo regArticulo;
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return -2;
    }
    while(fread(&regArticulo,sizeof(Articulo),1,p)){
        if(strcmp(regArticulo.getCodigo(),cod)==0){
            fclose(p);
            return cont;
        }
        cont++;
    }
    fclose(p);
    return -1;
}
Articulo ArchivoArticulo::LeerRegistro(int pos){
    Articulo regArticulo;
    regArticulo.setEstado(false);
    FILE*p=fopen(_nombre,"rb");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return regArticulo;
    }
    fseek(p,sizeof(Articulo)*pos,0);
    fread(&regArticulo,sizeof(Articulo),1,p);
    fclose(p);
    return regArticulo;
/*
    int cont=0;
    while(fread(&regArticulo,sizeof(Articulo),1,p)){
        if(cont==pos){
            fclose(p);
            return regArticulo;
        }
        cont++;
    }
    fclose(p);
    regArticulo.setEstado(false);
    return regArticulo;
*/
}
bool ArchivoArticulo::ModificarRegistro(int pos, Articulo regArticulo){
    regArticulo.setEstado(false);
    FILE*p=fopen(_nombre,"rb+");
    if(p==NULL){
        std::cout<<"\nError de archivo\n";
        system("pause");
        return false;
    }
    fseek(p,sizeof(Articulo)*pos,0);
    bool escribio=fwrite(&regArticulo,sizeof(Articulo),1,p);
    fclose(p);
    return escribio;
}
#endif // ARTICULOARCHIVO_H_INCLUDED
