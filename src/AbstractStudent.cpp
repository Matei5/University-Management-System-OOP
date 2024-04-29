#include "../include/AbstractStudent.h"


/// ===================== Override =====================

std::string AbstractStudent::getFullName() { return Nume+" "+Prenume; }

/// ===================== Constuctori ======================

AbstractStudent::AbstractStudent(std::string Nume_, std::string Prenume_, float nota_) : Nume(Nume_),Prenume(Prenume_),nota(nota_){}

/// ===================== Destructori ======================

AbstractStudent::~AbstractStudent() {};

/// ====================== Alte functii =====================

float AbstractStudent::getNota() const { return nota;}
void AbstractStudent::setNota(float n) { nota = n; }

