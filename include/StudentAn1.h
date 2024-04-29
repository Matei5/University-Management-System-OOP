#ifndef POO_PROIECT2_FROM1_STUDENTAN1_H
#define POO_PROIECT2_FROM1_STUDENTAN1_H

#include <iostream>
#include "AbstractStudent.h"

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

#endif //POO_PROIECT2_FROM1_STUDENTAN1_H
