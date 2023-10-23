#ifndef DATOSPERSONA_H_INCLUDED
#define DATOSPERSONA_H_INCLUDED
/*
nombre (string)
DNI/CUIT (int)
telefono (string)
direccion (string)

*/
class DatosPersona{
private:
    char nombre[30];
    int DNI_CUIT;
    char telefono[30];
    char direccion[30];
public:
    DatosPersona(const char*,int,const char*,const char*);
    bool Cargar(int,char);
    void Mostrar();
    void setNombre(const char*n){ strcpy(nombre,n); }
    void setDNI_CUIT(unsigned int n){ DNI_CUIT=n; }
    void setTelefono(const char*t){ strcpy(telefono,t); }
    void setDireccion(const char*d){ strcpy(direccion,d); }
    const char*getNombre(){ return nombre; }
    int getDNI_CUIT(){ return DNI_CUIT; }
    const char*getTelefono(){ return telefono; }
    const char*getDireccion(){ return direccion; }
};
DatosPersona::DatosPersona(const char*n="-",int num=1,const char*t="-",const char*d="-"){
    setNombre(n);
    setDNI_CUIT(num);
    setTelefono(t);
    setDireccion(d);
}
bool DatosPersona::Cargar(int num=0,char DNI_CUIT='d'){
    char n[30];
    char t[30];
    char d[30];
    if(num==0){
        if(DNI_CUIT=='d'){//Para DNI
            rlutil::setColor(15);
            cout<<"\n\t\t\tNro de DNI";
            rlutil::setColor(8);
            cout<<" (Numerico, sin \'.\')\n\t\t\t\t";
            rlutil::setColor(15);
            cout<<"  "<<(int_fast8_t)26<<" ";
            cin>>num;
        }
        if(DNI_CUIT=='c'){//Para CUIT
            rlutil::setColor(15);
            cout<<"\n\t\t\tNro de CUIT";
            rlutil::setColor(8);
            cout<<" (Numerico, sin \'-\')\n\t\t\t\t";
            rlutil::setColor(15);
            cout<<"  "<<(int_fast8_t)26<<" ";
            cin>>num;
        }
    }
    cout<<"\n\t\t\tNombre   ";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>n;
    cout<<"\n\t\t\tTelefono ";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>t;
    cout<<"\n\t\t\tDireccion";
    cout<<" "<<(int_fast8_t)26<<" ";
    cin>>d;
    setNombre(n);
    setDNI_CUIT(num);
    setTelefono(t);
    setDireccion(d);
    return true;
}

#endif // DATOSPERSONA_H_INCLUDED
