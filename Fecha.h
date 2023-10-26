#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

#include<iostream>
#include<ctime>

class Fecha{
private:
    int _dia;
    int _mes;
    int _anio;
    int dAct;
    int mAct;
    int aAct;
public:
    Fecha();
    Fecha(int,int,int);
    void Cargar();
    void Mostrar();
    void setDia(int d){
        if(d>=1 && d<=31) { _dia=d; }
        else { _dia=-1; }
    }
    void setMes(int m){
        if(m>=1 && m<=12) { _mes=m; }
        else { _mes=-1; }
    }
    void setAnio(int a){
        if(a>=1900 && a<=9999) { _anio=a; }
        else { _anio=-1; }
    }
    int getDia() { return _dia; }
    int getMes() { return _mes; }
    int getAnio(){ return _anio; }
    int getDiaActual() { return dAct; }
    int getMesActual() { return mAct; }
    int getAnioActual(){ return aAct; }
};
Fecha::Fecha(){
    time_t t=time(nullptr);
    tm*f=localtime(&t);
    dAct=f->tm_mday;
    mAct=f->tm_mon+1;
    aAct=f->tm_year+1900;
    Fecha::setDia(dAct);
    Fecha::setMes(mAct);
    Fecha::setAnio(aAct);
}
Fecha::Fecha(int d, int m, int a){
    Fecha::setDia(d);
    Fecha::setMes(m);
    Fecha::setAnio(a);
}
void Fecha::Cargar(){
    int d,m,a;
    bool cargar=true;
    while(cargar){
        std::cout<<"\n\tFecha actual:"<<dAct<<"/"<<mAct<<"/"<<aAct<<"\n";
        std::cout<<"\n\tDia: ";
        std::cin>>d;
        std::cout<<"\n\tMes: ";
        std::cin>>m;
        std::cout<<"\n\tAnio: ";
        std::cin>>a;

        if(a>=2000){
            if(a<aAct || (a==aAct && m<mAct) || (a==aAct && m==mAct && d<=dAct)){
                Fecha::setDia(d);
                Fecha::setMes(m);
                Fecha::setAnio(a);
                cargar=false;
            }
        }
        else{
            system("cls");
            std::cout<<"\n\t\tVALORES INCORRECTOS!\n";
        }
    }
}
void Fecha::Mostrar(){
    std::cout<<"\n\tDia: ";
    std::cout<<Fecha::getDia();
    std::cout<<"\n\tMes: ";
    std::cout<<Fecha::getMes();
    std::cout<<"\n\tAnio: ";
    std::cout<<Fecha::getAnio();
}

#endif // FECHA_H_INCLUDED
