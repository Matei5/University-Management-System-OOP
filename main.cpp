#include "header.h"
#include "include/Examen.h"
#include "include/Profesor.h"
#include "include/StudentAn1.h"

/// ===================== Override =====================

std::string AbstractStudent::getFullName() { return Nume+" "+Prenume; }
std::string Profesor::getFullName() { return "Lector "+Nume+" "+Prenume; }

/// ==================== Var Statice ======================

int StudentAn1::an = 1;
int StudentAn2::an = 2;

/// ===================== Constuctori ======================

AbstractStudent::AbstractStudent(std::string Nume_, std::string Prenume_, float nota_) : Nume(Nume_),Prenume(Prenume_),nota(nota_){}
StudentAn1::StudentAn1(std::string Nume_, std::string Prenume_, float nota_) : AbstractStudent(Nume_, Prenume_, nota_){}
StudentAn1::StudentAn1(const StudentAn1 &other) : AbstractStudent(other) {}
StudentAn1::StudentAn1(StudentAn1 &&other) : AbstractStudent(other.Nume,other.Prenume,other.nota) {}
StudentAn2::StudentAn2(std::string Nume_, std::string Prenume_, float nota_) : AbstractStudent(Nume_, Prenume_, nota_){}
Profesor::Profesor(std::string Nume_, std::string Prenume_, std::string email_) : Nume(Nume_), Prenume(Prenume_), email(email_){}
Examen::Examen(int zi_, int luna_, int an_, int ora_, int timpDeLucruInMinute_, int nrSubiecte_) : an(an_), luna(luna_), zi(zi_),ora(ora_), timpDeLucruInMinute(timpDeLucruInMinute_), nrSubiecte(nrSubiecte_){}
MaterieAn1::MaterieAn1(std::string numeMaterie_, int semestru_, std::vector<StudentAn1> Studenti_, const Examen& examen_, const Examen& restanta_, const Profesor& profesor) : semestru(semestru_), numeMaterie(numeMaterie_), Studenti(Studenti_), examen(examen_), restanta(restanta_), cadruDidactic(profesor){}

/// ===================== cout << ======================

std::ostream& operator<<(std::ostream& os, const AbstractStudent &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
       << " // Nota: " << s.nota;
    os << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const StudentAn1 &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
       << " // Nota: " << s.nota << " // An: " << s.getAn();
    os << std::endl;
    return os;
}
std::ostream& operator<<(std::ostream& os, const StudentAn2 &s){
    os << "Student: " << "Nume & Prenume: " << s.Nume << " " << s.Prenume
       << " // Nota: " << s.nota << " // An: " << s.getAn();
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

std::istream& operator>>(std::istream& is, StudentAn1 &s){

    std::cout << "Student: Nume:";
    is >> s.Nume;
    std::cout << "Prenume:";
    is >> s.Prenume;
    std::cout << "Nota:";
    is >> s.nota;
    return is;
}
std::istream& operator>>(std::istream& is, StudentAn2 &s){

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
    std::cout << "Minute de lucru: ";
    is >> e.timpDeLucruInMinute;
    std::cout << "Numar de subiecte:";
    is >> e.nrSubiecte;

    return is;
}

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

AbstractStudent::~AbstractStudent() {}
StudentAn1::~StudentAn1()  {}
StudentAn2::~StudentAn2() {}
Profesor::~Profesor() {}
Examen::~Examen() {}
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
    else Studenti[nrStud].setNota(2*prevNota);
    return Studenti[nrStud].getNota();
}

std::string Profesor::getEmail(){ return email;}

int Examen::getAn() const { return an; }

float AbstractStudent::getNota() const { return nota;}
void AbstractStudent::setNota(float n) { nota = n; }
StudentAn1 StudentAn1::operator+(float n){ nota += n; return *this; }
StudentAn2 StudentAn2::operator+(float n){ nota += n; return *this; }
int StudentAn1::getAn()  {return StudentAn1::an;}
int StudentAn2::getAn()  {return StudentAn2::an;}

/// Afisare

void AbstractStudent::Afisare() const {
    std::cout << "| Student de an necunoscut: ";
}
void StudentAn1::Afisare() const {
    std::cout << "| Student An 1: ";
}
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

void StudentAn2::Afisare() const {
    std::cout << "| Student An 2: ";
}

/// Exceptie

const char* Exception::what() const noexcept {
    return "Dynamic cast fail.";
}

/// ====================== Cod ============================

int menu(){
    std::cout << "| OPTIUNI: \n";
    std::cout << "| 1. Nota\n";
    std::cout << "| 2. Contenstatie\n";
    std::cout << "| 3. Participa la examenul de restanta\n";
    std::cout << "| 4. Email profesor\n";
    std::cout << "| 5. Schimba profesor\n";
    std::cout << "| 6. Schimba numar student\n";
    std::cout << "| 7. Print Materie\n";
    std::cout << "| 8. Adauga student\n";
    std::cout << "| 9. Exit\n";
    std::cout << "|>-------------------------\n";
    std::cout << "| Introduce numarul optiunii dorite: ";

    int m;
    std::string n;
    std::cin >> n;
    std::cout << "\n";

    try{
        if((int) n[0] > 57 || (int) n[0] <49) throw (int) n[0] - 48;
        m = (int) n[0] - 48;
        return m;
    }
    catch(int e){
        std::cout << "Catched input " << e << "; Exiting... \n";
        return 9;
    }

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

    MaterieAn1 POO = MaterieAn1();
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
                StudentAn1 newStudent = StudentAn1();
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

    std::vector<AbstractStudent*> Studenti;

    try {
        Studenti.push_back(dynamic_cast<AbstractStudent*>(new StudentAn1("Minca", "Gica", 5)));
        Studenti.push_back(dynamic_cast<AbstractStudent*>(new StudentAn2("Maria", "Maria", 2)));
        Studenti.push_back(new StudentAn1("Costel", "Nicu", 8));
        Studenti.push_back(new StudentAn2("Pascu", "Teleman", 2));
    } catch (const Exception& e) {
        std::cerr << "Failed to cast: " << e.what() << std::endl;
    }

    for(AbstractStudent* student: Studenti){
        student->Afisare();
        std::cout << student->getFullName() << " // Nota: " << student->getNota() << "\n";
    }

    for(AbstractStudent* student: Studenti) delete student;

}

int main() {

    std::cout << "| OPTIUNI: \n| 1. Meniu\n| 2. Extra Proiect 2\n| Other. Stop\n";
    std::cout << "|>-------------------------\n| Introduce un nr:";
    int a; std::cin >> a;

    if(a==1) run();
    else if(a==2) test();

    return 0;
}