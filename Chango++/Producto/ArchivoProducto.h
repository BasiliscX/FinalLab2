#ifndef ARCHIVOPRODUCTO_H_INCLUDED
#define ARCHIVOPRODUCTO_H_INCLUDED

int contarRegistros();
bool agregarProveedor();
bool modificarProducto(Producto reg, int pos);

class ArchivoProducto
{

private:

    char nombre[30];

public:

    ArchivoProducto (const char* n) {strcpy(nombre,n);}

     Producto leerRegistro(int pos){

       Producto reg;
       FILE *p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Producto)*pos,0);
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
        return tam/sizeof(Producto);
    }

    bool agregarProducto(){

    Producto reg;
    bool cargo, modifico;

    FILE *p;
    p=fopen(nombre,"ab");
    if(p==NULL) return false;

     cargo = reg.Cargar();
     if(cargo)
     {
    modifico = fwrite(&reg, sizeof(Producto), 1, p);
    fclose(p);
    return modifico;

     }

     else return cargo;


    }

    bool modificarProducto(Producto reg, int pos){

    bool modifico;
    FILE *p;
    p=fopen(nombre,"rb+");
    if(p==NULL) return false;

    fseek(p,sizeof(Producto)*pos,0);
    modifico=fwrite(&reg, sizeof(Producto), 1, p);

    fclose(p);

    return modifico;


    }
};



#endif // ARCHIVOPRODUCTO_H_INCLUDED
