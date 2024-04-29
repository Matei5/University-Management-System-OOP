#include "../include/MaterieAn1.h"

/// ===================== Constuctori ======================

MaterieAn1::MaterieAn1(std::string numeMaterie_, int semestru_, std::vector<StudentAn1> Studenti_, Examen examen_, Examen restanta_, Profesor profesor) : semestru(semestru_), numeMaterie(numeMaterie_), Studenti(Studenti_), examen(examen_), restanta(restanta_), cadruDidactic(profesor){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const MaterieAn1 &m){
    os << "Materie: " << "Denumire: " << m.numeMaterie << " // An: " << m.an << "; Sem: " << m.semestru
       << "\n          // Cadru didactic: " << m.cadruDidactic
       << "\n          // Examen: " << m.examen
       << "\n          // Examen de restante: " << m.restanta
       << "\n          // Studenti: " << "\n";
    for(const StudentAn1 &stud: m.Studenti){
        os << "                         " << stud;
    }
    return os;
}

/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, MaterieAn1 &m){

    std::cout << "Materie: Nume(legat):";
    is >> m.numeMaterie;
    std::cout << "Semestru:";
    is >> m.semestru;
    is >> m.cadruDidactic;
    is >> m.examen;
    is >> m.restanta;

    int n; StudentAn1 temp;
    std::cout << "Cati studenti sunt in clasa?:";
    std::cin >> n;
    std::cout << "\n";

    for(int i=0;i<n;i++){
        is >> temp;
        m.Studenti.push_back(temp);
        std::cout << "\n";
    }

    return is;
}


/// ===================== Destructori ======================

MaterieAn1::~MaterieAn1() {
    Studenti.clear();
}

/// ====================== Alte functii =====================

void MaterieAn1::contestatie(int nrStud) {
    float prevNota = Studenti[nrStud].getNota();
    if(prevNota < 5.5) Studenti[nrStud]=Studenti[nrStud]+1;
    else Studenti[nrStud]=Studenti[nrStud]+-1;
}

int MaterieAn1::getNumarStudenti(){ return Studenti.size();}
std::string MaterieAn1::getEmailProfesor(){ return cadruDidactic.getEmail();}
float MaterieAn1::getNotaStudent(int n){ return Studenti[n].getNota();}
int MaterieAn1::getAnRestanta() const { return restanta.getAn(); }
void MaterieAn1::schimbareProfesor(const Profesor &prof) { cadruDidactic = prof;}
MaterieAn1 MaterieAn1::operator+=(const StudentAn1 &s) { Studenti.push_back(s); return *this; }
float MaterieAn1::examenRestanta(int nrStud) {
    float prevNota = Studenti[nrStud].getNota();
    if(prevNota<3) Studenti[nrStud]=Studenti[nrStud]+prevNota*2;
    else Studenti[nrStud]=Studenti[nrStud]+prevNota;
    return Studenti[nrStud].getNota();
}
