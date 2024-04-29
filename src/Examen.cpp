#include "../include/Examen.h"

/// ===================== Constuctori ======================

Examen::Examen(int zi_, int luna_, int an_, int ora_, int timpDeLucruInMinute_, int nrSubiecte_) : an(an_), luna(luna_), zi(zi_),ora(ora_), timpDeLucruInMinute(timpDeLucruInMinute_), nrSubiecte(nrSubiecte_){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const Examen &e){
    os << "Examen: " << "Data: " << e.zi << "." << e.luna << "." << e.an << " la ora " << e.ora/100 << ":" << e.ora%100
       << " // Timp de lucru: " << e.timpDeLucruInMinute << " // Numar de subiecte: " << e.nrSubiecte << std::endl;
    return os;
}

/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, Examen &e){

    std::cout << "Examen: Zi:";
    is >> e.zi;
    std::cout << "Luna:";
    is >> e.luna;
    std::cout << "An:";
    is >> e.an;
    std::cout << "Ora (in format militar):";
    is >> e.ora;
    std::cout << "Minute de lucru: ";
    is >> e.timpDeLucruInMinute;
    std::cout << "Numar de subiecte:";
    is >> e.nrSubiecte;

    return is;
}

/// ===================== Destructori ======================

Examen::~Examen() {}

/// ====================== Alte functii =====================

int Examen::getAn() const { return an; }

