#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED

class ArchivoVenta{
private:
    char nombre[30];
public:
    ArchivoVenta(const char*n){strcpy(nombre,n);}
    Venta leerRegistro(int pos){
       Venta reg;
       FILE*p;
       p=fopen(nombre,"rb");
       if(p==NULL) return reg;
       fseek(p,sizeof(Venta)*pos,0);
       fread(&reg, sizeof(reg),1,p);
       fclose(p);
       return reg;
   }
   int contarRegistros(){
        FILE*p;
        p=fopen(nombre,"rb");
        if(p==NULL) return -1;
        fseek(p,0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(Venta);
    }
    bool agregarVenta(const char*DNI){
        Venta reg;
        FILE*p;
        p=fopen(nombre,"ab");
        if(p==NULL) return false;
        bool cargo=reg.Cargar(DNI);
        if(cargo){
            fwrite(&reg,sizeof(Venta),1,p);
        }
        fclose(p);
        return cargo;
    }
    bool modificarVenta(Venta reg,int pos){
        FILE *p;
        p=fopen(nombre,"rb+");
        if(p==NULL) return false;
        fseek(p,sizeof(Producto)*pos,0);
        bool modifico=fwrite(&reg, sizeof(Producto), 1, p);
        fclose(p);
        return modifico;
    }
};



#endif // ARCHIVOVENTAS_H_INCLUDED
