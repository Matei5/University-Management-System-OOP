#include "../include/AbstractStudent.h"

std::ostream& operator<<(std::ostream& os, const AbstractStudent &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
       << " // Nota: " << s.nota;
    os << std::endl;
    return os;
}

/// ===================== Override =====================

std::string AbstractStudent::getFullName() { return Nume+" "+Prenume+"\n"; }

/// ===================== Constuctori ======================

AbstractStudent::AbstractStudent(std::string Nume_, std::string Prenume_, float nota_) : Nume(Nume_),Prenume(Prenume_),nota(nota_){}

/// ===================== Destructori ======================

AbstractStudent::~AbstractStudent() {};

/// ====================== Alte functii =====================

float AbstractStudent::getNota() const { return nota;}
void AbstractStudent::setNota(float n) { nota = n; }

