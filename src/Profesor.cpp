#include "../include/Profesor.h"

/// ===================== Override =====================

std::string Profesor::getFullName() { return Nume+" "+Prenume; }

/// ===================== Constuctori ======================

Profesor::Profesor(std::string Nume_, std::string Prenume_, std::string email_) : Nume(Nume_), Prenume(Prenume_), email(email_){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const Profesor &p){
    os << "Profesor: " << "Nume & Prenume: " << p.Nume << " " << p.Prenume << " // Email: " << p.email << std::endl;
    return os;
}

/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, Profesor &p){

    std::cout << "Profesor: Nume:";
    is >> p.Nume;
    std::cout << "Prenume:";
    is >> p.Prenume;
    std::cout << "Email:";
    is >> p.email;
    return is;
}

/// ===================== Destructori ======================

Profesor::~Profesor() {}

/// ====================== Alte functii =====================

std::string Profesor::getEmail(){ return email;}

