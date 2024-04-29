#ifndef POO_PROIECT2_FROM1_STUDENTAN2_H
#define POO_PROIECT2_FROM1_STUDENTAN2_H

#include <iostream>
#include "AbstractStudent.h"
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

#endif //POO_PROIECT2_FROM1_STUDENTAN2_H
