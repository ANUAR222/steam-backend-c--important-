//
// Created by anuar on 11/04/2022.
//

#ifndef MAIN_CPP_DATE_H
#define MAIN_CPP_DATE_H


class Date {
    int dia;
    int mes;
    int anio;
public:
    Date();

    Date(int dia, int mes, int anio);

    void setDia(int dia);

    void setMes(int mes);

    void setAnio(int anio);

    int getDia() const;

    int getMes() const;

    int getAnio() const;

};


#endif //MAIN_CPP_DATE_H
