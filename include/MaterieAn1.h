#ifndef POO_PROIECT2_FROM1_MATERIEAN1_H
#define POO_PROIECT2_FROM1_MATERIEAN1_H

#include "StudentAn1.h"
#include "Examen.h"
#include "Profesor.h"
#include <vector>

class MaterieAn1{
private:
    const int an = 1;
    int semestru;
    std::string numeMaterie;
    std::vector<StudentAn1> Studenti;
    Examen examen;
    Examen restanta;
    Profesor cadruDidactic;
public:
    MaterieAn1(std::string numeMaterie_ = "", int semestru_ = 0,  std::vector<StudentAn1> Studenti_ = {},
               Examen examen_ = Examen(), Examen restanta_ = Examen(), Profesor profesor = Profesor());

    friend std::ostream& operator<<(std::ostream& os, const MaterieAn1 &m);
    friend std::istream& operator>>(std::istream& is,  MaterieAn1 &m);
    MaterieAn1 operator+=(const StudentAn1 &s);

    int getNumarStudenti();
    std::string getEmailProfesor();
    float getNotaStudent(int n);
    int getAnRestanta() const;
    void schimbareProfesor(const Profesor &prof);
    void contestatie(int nrStud);
    float examenRestanta(int nrStud);


    ~MaterieAn1();

private:

};

#endif //POO_PROIECT2_FROM1_MATERIEAN1_H
