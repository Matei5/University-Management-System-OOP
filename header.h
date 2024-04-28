#ifndef PROIECT1_HEADER_H
#define PROIECT1_HEADER_H
#include <iostream>
#include <vector>
#include <cstdlib>

class Ipersoana{
public:
    virtual std::string getFullName() = 0;
};

class AbstractStudent : public Ipersoana{
protected:
    std::string Nume;
    std::string Prenume;
    float nota;
public:
    std::string getFullName() override;
    virtual float getNota() const;
    virtual void setNota(float n);
    virtual ~AbstractStudent();
protected:
    AbstractStudent(std::string Nume = "", std::string Prenume = "", float nota_ = 0);
};

class StudentAn1 : public AbstractStudent{
private:
    static int an;
public:
    StudentAn1(std::string Nume = "", std::string Prenume = "", float nota_ = 0);

    friend std::ostream& operator<<(std::ostream& os, const StudentAn1 &s);
    friend std::istream& operator>>(std::istream& is, StudentAn1 &s);
    StudentAn1 operator+(float n);

    static int getAn();

    ~StudentAn1();

private:
};

class StudentAn2 : public AbstractStudent{
private:
    static int an;
public:
    StudentAn2(std::string Nume = "", std::string Prenume = "", float nota_ = 0);

    friend std::ostream& operator<<(std::ostream& os, const StudentAn2 &s);
    friend std::istream& operator>>(std::istream& is, StudentAn2 &s);
    StudentAn2 operator+(float n);

    static int getAn();

    ~StudentAn2();

private:
};

class Profesor : public Ipersoana{
private:
    std::string Nume;
    std::string Prenume;
    std::string email;
public:
    Profesor(std::string Nume_ = "", std::string Prenume_ = "", std::string email = "");

    friend std::ostream& operator<<(std::ostream& os, const Profesor &p);
    friend std::istream& operator>>(std::istream& is,  Profesor &p);

    std::string getEmail();
    std::string getFullName() override;

    ~Profesor();

private:

};

class Examen{
private:
    int an;
    int luna;
    int zi;
    int ora; // format militar ex: 1100
    int timpDeLucruInMinute;
    int nrSubiecte;
public:
    Examen(int zi_ = 0, int luna_ = 0, int an_ = 0, int ora_ = 0, int timpDeLucruInMinute_ = 0, int nrSubiecte_ = 0);

    friend std::ostream& operator<<(std::ostream& os, const Examen &e);
    friend std::istream& operator>>(std::istream& is,  Examen &e);

    int getAn() const;

    ~Examen();

private:

};

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

#endif //PROIECT1_HEADER_H
