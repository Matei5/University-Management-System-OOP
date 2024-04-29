#ifndef POO_PROIECT2_FROM1_EXAMEN_H
#define POO_PROIECT2_FROM1_EXAMEN_H

#include <iostream>

class Examen{
private:
    int an;
    int luna;
    int zi;
    int ora; // format militar ex: 1100
    int timpDeLucruInMinute;
    int nrSubiecte;
public:
    Examen(int zi_ = 0, int luna_ = 0, int an_ = 0, int ora_ = 0, int timpDeLucruInMinute_ = 0, int nrSubiecte_ = 0);

    friend std::ostream& operator<<(std::ostream& os, const Examen &e);
    friend std::istream& operator>>(std::istream& is,  Examen &e);

    int getAn() const;

    ~Examen();

private:

};

#endif //POO_PROIECT2_FROM1_EXAMEN_H
