#ifndef ARCHIVOVENTAS_H_INCLUDED
#define ARCHIVOVENTAS_H_INCLUDED

class ArchivoVentas
{
private:
    char nombre[30];

public:
    ArchivoVentas (const char* n) {strcpy(nombre,n);}


};



#endif // ARCHIVOVENTAS_H_INCLUDED
