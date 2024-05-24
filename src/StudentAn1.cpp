#include "../include/StudentAn1.h"

/// ==================== Var Statice ======================

int StudentAn1::an = 1;

/// ===================== Constuctori ======================

StudentAn1::StudentAn1(std::string Nume_, std::string Prenume_, float nota_) : AbstractStudent(Nume_, Prenume_, nota_){}
StudentAn1::StudentAn1(const StudentAn1 &other) : AbstractStudent(other) {}
StudentAn1::StudentAn1(StudentAn1 &&other) : AbstractStudent(other.Nume,other.Prenume,other.nota) {}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const StudentAn1 &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
       << " // Nota: " << s.nota << " // An: " << StudentAn1::an;
    os << std::endl;
    return os;
}

/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, StudentAn1 &s){

    std::cout << "Student: Nume:";
    is >> s.Nume;
    std::cout << "Prenume:";
    is >> s.Prenume;
    std::cout << "Nota:";
    is >> s.nota;
    return is;
}

/// ===================== Destructori ======================

StudentAn1::~StudentAn1() {}

/// ====================== Alte functii =====================

StudentAn1 StudentAn1::operator+(float n){ nota += n; return *this; }
int StudentAn1::getAn()  {return StudentAn1::an;}
StudentAn1& StudentAn1::operator=(const StudentAn1 &other) {
    Nume = other.Nume;
    Prenume = other.Prenume;
    nota = other.nota;
    return *this;
}
StudentAn1& StudentAn1::operator=(StudentAn1 &&other) {
    if(this != &other){
        Nume = other.Nume;
        Prenume = other.Prenume;
        nota = other.nota;
    }
    return *this;
}
