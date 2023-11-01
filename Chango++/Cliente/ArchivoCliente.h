#ifndef ARCHIVOCLIENTE_H_INCLUDED
#define ARCHIVOCLIENTE_H_INCLUDED

int contarRegistros();
bool agregarCliente();
bool modificarCliente(Cliente reg, int pos);

class ArchivoCliente
{

private:

    char nombre[30];

public:

    ArchivoCliente (const char* n) {strcpy(nombre,n);}

     Cliente leerRegistro(int pos){

       Cliente reg;
       FILE *p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Cliente)*pos,0);
       fread(&reg, sizeof(reg),1,p);
       fclose(p);
       return reg;
   }

   int contarRegistros(){
        FILE *p;
        p=fopen(nombre, "rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Cliente);
    }

    bool agregarCliente(){

    Cliente reg;
    bool cargo, modifico;

    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return false;

     cargo = reg.Cargar();
     if(cargo)
     {
    modifico = fwrite(&reg, sizeof(Cliente), 1, p);
    fclose(p);
    return modifico;

     }

     else return cargo;


    }

    bool modificarCliente(Cliente reg, int pos){

    bool modifico;
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL) return false;

    fseek(p,sizeof(Cliente)*pos,0);
    modifico=fwrite(&reg, sizeof(Cliente), 1, p);

    fclose(p);

    return modifico;


    }
};

#endif // ARCHIVOCLIENTE_H_INCLUDED