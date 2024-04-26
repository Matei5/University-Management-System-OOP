#include "header.h"
/// ===================== Override ===================== a

std::string Student::getFullName() { return Nume+" "+Prenume; }
std::string Profesor::getFullName() { return Nume+" "+Prenume; }


/// ===================== Constuctori ======================

Student::Student(std::string Nume_, std::string Prenume_, float nota_) : Nume(Nume_),Prenume(Prenume_),nota(nota_){}
Profesor::Profesor(std::string Nume_, std::string Prenume_, std::string email_) : Nume(Nume_), Prenume(Prenume_), email(email_){}
Examen::Examen(int zi_, int luna_, int an_, int ora_, int timpDeLucruInMinute_, int nrSubiecte_) : an(an_), luna(luna_), zi(zi_),ora(ora_), timpDeLucruInMinute(timpDeLucruInMinute_), nrSubiecte(nrSubiecte_){}
Materie::Materie(std::string numeMaterie_, int an_, int semestru_, std::vector<Student> Studenti_, Examen examen_, Examen restanta_, Profesor profesor) : an(an_), semestru(semestru_), numeMaterie(numeMaterie_), Studenti(Studenti_), examen(examen_), restanta(restanta_), cadruDidactic(profesor){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const Student &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
        << " // Nota: " << s.nota;
    os << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Profesor &p){
    os << "Profesor: " << "Nume & Prenume: " << p.Nume << " " << p.Prenume << " // Email: " << p.email << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Examen &e){
    os << "Examen: " << "Data: " << e.zi << "." << e.luna << "." << e.an << " la ora " << e.ora/100 << ":" << e.ora%100
        << " // Timp de lucru: " << e.timpDeLucruInMinute << " // Numar de subiecte: " << e.nrSubiecte << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const Materie &m){
    os << "Materie: " << "Denumire: " << m.numeMaterie << " // An: " << m.an << "; Sem: " << m.semestru
            << "\n          // Cadru didactic: " << m.cadruDidactic
            << "\n          // Examen: " << m.examen
            << "\n          // Examen de restante: " << m.restanta
            << "\n          // Studenti: " << "\n";
            for(const Student &stud: m.Studenti){
                os << "                         " << stud;
            }
    return os;
}
/// ===================== cin >> ======================

std::istream& operator>>(std::istream& is, Student &s){

    std::cout << "Student: Nume:";
    is >> s.Nume;
    std::cout << "Prenume:";
    is >> s.Prenume;
    std::cout << "Nota:";
    is >> s.nota;
    return is;
}
std::istream& operator>>(std::istream& is, Profesor &p){

    std::cout << "Profesor: Nume:";
    is >> p.Nume;
    std::cout << "Prenume:";
    is >> p.Prenume;
    std::cout << "Email:";
    is >> p.email;
    return is;
}
std::istream& operator>>(std::istream& is, Examen &e){

    std::cout << "Examen: Zi:";
    is >> e.zi;
    std::cout << "Luna:";
    is >> e.luna;
    std::cout << "An:";
    is >> e.an;
    std::cout << "Ora (in format militar):";
    is >> e.ora;
    std::cout << "Minute de lucru:";
    is >> e.timpDeLucruInMinute;
    std::cout << "Numar de subiecte:";
    is >> e.nrSubiecte;

    return is;
}
std::istream& operator>>(std::istream& is, Materie &m){

    std::cout << "Materie: Nume(legat):";
    is >> m.numeMaterie;
    std::cout << "An:";
    is >> m.an;
    std::cout << "Semestru:";
    is >> m.semestru;
    is >> m.cadruDidactic;
    is >> m.examen;
    is >> m.restanta;

    int n; Student temp;
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
Student::~Student() {

}
Profesor::~Profesor() {

}
Examen::~Examen() {

}
Materie::~Materie() {
    Studenti.clear();
}

/// ====================== Alte functii =====================

void Materie::contestatie(int nrStud) {
    float prevNota = Studenti[nrStud].getNota();
    if(prevNota < 5.5) Studenti[nrStud]=Studenti[nrStud]+1;
    else Studenti[nrStud]=Studenti[nrStud]+-1;
}

int Materie::getNumarStudenti(){ return Studenti.size();}
std::string Materie::getEmailProfesor(){ return cadruDidactic.getEmail();}
float Materie::getNotaStudent(int n){ return Studenti[n].getNota();}
int Materie::getAnRestanta() const { return restanta.getAn(); }
void Materie::schimbareProfesor(const Profesor &prof) { cadruDidactic = prof;}
Materie Materie::operator+=(const Student &s) { Studenti.push_back(s); return *this; }
float Materie::examenRestanta(int nrStud) {
    float prevNota = Studenti[nrStud].getNota();
    if(prevNota<3) Studenti[nrStud]=Studenti[nrStud]+prevNota*2;
    else Studenti[nrStud]=Studenti[nrStud]+prevNota;
    return Studenti[nrStud].getNota();
}

std::string Profesor::getEmail(){ return email;}

int Examen::getAn() const { return an; }

float Student::getNota() const { return nota;}
void Student::setNota(float n) { nota = n; }
Student Student::operator+(float n){ nota += n; return *this; }


/// ======================== Fara legatura cu clasele =======================

int menu(){
    std::cout << "| OPTIUNI: \n";
    std::cout << "| 1. Nota\n";
    std::cout << "| 2. Contenstatie\n";
    std::cout << "| 3. Participa la examenul de restanta\n";
    std::cout << "| 4. Email profesor\n";
    std::cout << "| 5. Schimba profesor\n";
    std::cout << "| 6. Schimba numar student\n";
    std::cout << "| 7. Print POO\n";
    std::cout << "| 8. Adauga student\n";
    std::cout << "| 9. Exit\n";
    std::cout << "|>-------------------------\n";
    std::cout << "| Introduce numarul optiunii dorite: ";

    int n;
    std::cin >> n;
    std::cout << "\n";

    return n;
}

char load(){
    std::cout << "|>-------------------------\n";
    std::cout << "| Introduci informatii pentru materie? (y/n):";

    char ans;
    std::cin >> ans;
    std::cout << "\n";

    switch(ans){
        case 'y':
        case 'Y': return 'y';
        case 'n':
        case 'N': return 'n';
        default:
            std::cout << "| Error: Caracter introdus nerecunoscut\n";
            return load();
    }
}

void run(){
    char a = load();

    Materie POO = Materie();
    if (a == 'y') {
        std::cin >> POO;
    }

    int nrStudent = -1;
    while (nrStudent == -1 && a == 'y') {
        std::cout << "|>-------------------------\n";
        if(POO.getNumarStudenti() == 0) {
            std::cout << "| Nu exista studenti! \n";
            break;
        }
        std::cout << "| Introduce numarul studentului (0-" << POO.getNumarStudenti() - 1
                  << "):";

        std::cin >> nrStudent;

        if (nrStudent < 0 || nrStudent >= POO.getNumarStudenti()) {
            std::cout << "| Error: Cod introdus nerecunoscut\n";
            nrStudent = -1;
        }
    }

    int option=-1;

    while (option != 9) {
        option = menu();
        switch (option) {
            case 1: {
                if(POO.getNumarStudenti() == 0) {
                    std::cout << "Nu sunt studenti!\n";
                    break;
                }
                else if(nrStudent == -1) { std::cout << "Schimba numarul de student (optiunea 6)!\n"; break;}
                std::cout << "Nota studentului este: " << POO.getNotaStudent(nrStudent) << "\n";
            }
                break;
            case 2: {
                if(POO.getNumarStudenti() == 0) {
                    std::cout << "Nu sunt studenti!\n";
                    break;
                }
                else if(nrStudent == -1) { std::cout << "Schimba numarul de student (optiunea 6)!\n"; break;}
                POO.contestatie(nrStudent);
                std::cout << "Nota noua dupa contestatie: " << POO.getNotaStudent(nrStudent) << "\n";
            }
                break;
            case 3: {
                if(POO.getNumarStudenti() == 0) {
                    std::cout << "Nu sunt studenti!\n";
                    break;
                }
                else if(nrStudent == -1) { std::cout << "Schimba numarul de student (optiunea 6)!\n"; break;}
                else if(POO.getNotaStudent(nrStudent)>5){ std::cout << "Nu are restanta!\n"; break;}
                else if(POO.getAnRestanta() == 3){ std::cout << "Nu a fost stabilita o resnta!\n"; break;}
                std::cout << "Nota noua dupa restanta:  " << POO.examenRestanta(nrStudent) << "\n";
            }
                break;
            case 4: {
                std::cout << "Email profesor: " << POO.getEmailProfesor() << "\n";
            }
                break;
            case 5:{
                Profesor prof;
                std::cin >> prof;
                POO.schimbareProfesor(prof);
            }
                break;
            case 6:{
                nrStudent = -1;
                while (nrStudent == -1) {
                    std::cout << "|>-------------------------\n";
                    if(POO.getNumarStudenti() == 0) {
                        std::cout << "| Nu exista studenti! \n";
                        break;
                    }
                    std::cout << "| Introduce numarul studentului (0-" << POO.getNumarStudenti() - 1
                              << "):";

                    std::cin >> nrStudent;

                    if (nrStudent < 0 || nrStudent >= POO.getNumarStudenti()) {
                        std::cout << "| Error: Cod introdus nerecunoscut\n";
                        nrStudent = -1;
                    }
                }
            }
                break;
            case 7: {
                std::cout << POO << "\n";
            }
                break;
            case 8: {
                Student newStudent = Student();
                std::cin >> newStudent;
                POO += newStudent;
            }
                break;
            case 9: {}
                break;
            default: {
                std::cout << "| Error: Numar introdus nerecunoscut\n";
                option = menu();
            }
        }

        char ans = 'a';

        while(ans == 'a' && option!=9){
            std::cout << "|>-------------------------\n";
            std::cout << "| Mai doresti sa faci vreo actiune? (y/n):";
            std::cin >> ans;
            std::cout << "\n";

            switch (ans) {
                case 'y': break;
                case 'n': {
                    option = 9;
                }
                    break;
                case 'Y': break;
                case 'N': {
                    option = 9;
                }
                    break;
                default: {
                    std::cout << "| Error: Caracter 1 introdus nerecunoscut\n";
                    ans = 'a';
                }
            }
        }
    }

}

void test(){

}

/// main prea mare
int main() {

    std::cout << "| Run: \n| 1. Exemplu\n| 2. Meniu\n| Other number. Stop";
    int a; std::cin >> a;

    if(a==1) test();
    else if(a==2) run();

    return 0;
}


/*
 git push -u origin main
*/