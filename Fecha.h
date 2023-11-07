#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include<iostream>
#include<cstring>

class Fecha{
private:
    int dia;
    int mes;
    int anio;
public:
    Fecha(int,int,int);
    void Cargar();
    void Mostrar();
    void setDia(int d){
        if(d>0 && d<32) { dia=d; }
        else { dia=-1; }
    }
    void setMes(int m){
        if(m>0 && m<13) { mes=m; }
        else { mes=-1; }
    }
    void setAnio(int a){
        if(a>1889 && a<9999) { anio=a; }
        else { anio=-1; }
    }
    int getDia() { return dia; }
    int getMes() { return mes; }
    int getAnio(){ return anio; }
    bool operator==(Fecha);
    bool operator==(const char*);
    bool operator<(Fecha);
    void operator+=(int);
};

Fecha::Fecha(int d=1, int m=1, int a=1900){
    Fecha::setDia(d);
    Fecha::setMes(m);
    Fecha::setAnio(a);
}
void Fecha::Cargar(){
    int d,m,a;
    std::cout<<"\n\tDia: ";
    std::cin>>d;
    std::cout<<"\n\tMes: ";
    std::cin>>m;
    std::cout<<"\n\tAnio: ";
    std::cin>>a;
    Fecha::setDia(d);
    Fecha::setMes(m);
    Fecha::setAnio(a);
}
void Fecha::Mostrar(){
    std::cout<<"\n\tDia: ";
    std::cout<<Fecha::getDia();
    std::cout<<"\n\tMes: ";
    std::cout<<Fecha::getMes();
    std::cout<<"\n\tAnio: ";
    std::cout<<Fecha::getAnio();
}
bool Fecha::operator==(Fecha aux){
    if(dia!=aux.getDia()){ return false; }
    if(mes!=aux.getMes()){ return false; }
    if(anio!=aux.getAnio()){ return false; }
    return true;
}
bool Fecha::operator<(Fecha aux){
    if(anio>aux.getAnio()){ return false; }
    if(mes>aux.getMes()){ return false; }
    if(dia>=aux.getDia() && mes>=aux.getMes()){ return false; }
    return true;
}
void Fecha::operator+=(int dias){
    int mesAux=0,anioAux=0;
    while((dia+dias)>=31){
        if((dia+dias)>=31){
            mesAux++;
            dias-=31;
        }
        if(mesAux>=12){
            anioAux++;
            mesAux-=12;
        }
    }
    dia+=dias;
    mes+=mesAux;
    anio+=anioAux;
}
bool Fecha::operator==(const char*m){
    char meses[12][20];
    strcpy(meses[0],"enero");
    strcpy(meses[1],"febrero");
    strcpy(meses[2],"marzo");
    strcpy(meses[3],"abril");
    strcpy(meses[4],"mayo");
    strcpy(meses[5],"junio");
    strcpy(meses[6],"julio");
    strcpy(meses[7],"agosto");
    strcpy(meses[8],"septiembre");
    strcpy(meses[9],"octubre");
    strcpy(meses[10],"noviembre");
    strcpy(meses[11],"diciembre");
    for(int i=0;i<12;i++){
        if(strcmp(meses[i],m)==0 && (mes-1)==i){
            return true;
        }
    }
    return false;
}

#endif // FECHA_H_INCLUDED
