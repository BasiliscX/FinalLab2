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
    char DNI_CUIT[11];
    char telefono[30];
    char direccion[30];
public:
    DatosPersona(const char*,const char*,const char*,const char*);

    //métodos
    bool Cargar(const char*);
    void Mostrar();

    //set
    void setNombre(const char*n){ strcpy(nombre,n); }
    void setDNI_CUIT(const char*n){ strcpy(DNI_CUIT,n); }
    void setTelefono(const char*t){ strcpy(telefono,t); }
    void setDireccion(const char*d){ strcpy(direccion,d); }

    //get
    const char*getNombre(){ return nombre; }
    const char*getDNI_CUIT(){ return DNI_CUIT; }
    const char*getTelefono(){ return telefono; }
    const char*getDireccion(){ return direccion; }
};
DatosPersona::DatosPersona(const char*n="-",const char*num="-",const char*t="-",const char*d="-"){
    setNombre(n);
    setDNI_CUIT(num);
    setTelefono(t);
    setDireccion(d);
}
bool DatosPersona::Cargar(const char*num){
    char n[30];
    char t[30];
    char d[30];
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

void DatosPersona::Mostrar()
{
    cout<<"nombre : "<<endl;
    cout<<nombre<<endl;
    cout<<"DNI/CUIT : "<<endl;
    cout<<DNI_CUIT<<endl;
    cout<<"telefono : "<<endl;
    cout<<telefono<<endl;
    cout<<"direccion : "<<endl;
    cout<<direccion<<endl;
}

#endif // DATOSPERSONA_H_INCLUDED
