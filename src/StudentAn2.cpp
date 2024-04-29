#include "../include/StudentAn2.h"

/// ==================== Var Statice ======================

int StudentAn2::an = 2;

/// ===================== Constuctori ======================

StudentAn2::StudentAn2(std::string Nume_, std::string Prenume_, float nota_) : AbstractStudent(Nume_, Prenume_, nota_){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const StudentAn2 &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
       << " // Nota: " << s.nota << " // An: " << StudentAn2::an;
    os << std::endl;
    return os;
}

/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, StudentAn2 &s){

    std::cout << "Student: Nume:";
    is >> s.Nume;
    std::cout << "Prenume:";
    is >> s.Prenume;
    std::cout << "Nota:";
    is >> s.nota;
    return is;
}

/// ===================== Destructori ======================

StudentAn2::~StudentAn2() {}
================ Alte functii =====================

StudentAn2 StudentAn2::operator+(float n){ nota += n; return *this; }
int StudentAn2::getAn()  {return StudentAn2::an;}
