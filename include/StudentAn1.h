#ifndef POO_PROIECT2_FROM1_STUDENTAN1_H
#define POO_PROIECT2_FROM1_STUDENTAN1_H

#include "AbstractStudent.h"

class StudentAn1 : public AbstractStudent{
private:
    static int an;
public:
    StudentAn1(std::string Nume = "", std::string Prenume = "", float nota_ = 0);
    StudentAn1(const StudentAn1& other);
    StudentAn1(StudentAn1&& other);

    friend std::ostream& operator<<(std::ostream& os, const StudentAn1 &s);
    friend std::istream& operator>>(std::istream& is, StudentAn1 &s);
    StudentAn1 operator+(float n);
    StudentAn1& operator=(const StudentAn1& other);
    StudentAn1& operator=(StudentAn1&& other);

    static int getAn();
    void Afisare() const override;

    ~StudentAn1() override;

private:
};

#endif //POO_PROIECT2_FROM1_STUDENTAN1_H
