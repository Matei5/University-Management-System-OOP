#ifndef POO_PROIECT2_FROM1_PROFESOR_H
#define POO_PROIECT2_FROM1_PROFESOR_H

#include "Ipersoana.h"

class Profesor : public Ipersoana{
private:
    std::string Nume;
    std::string Prenume;
    std::string email;
public:
    Profesor(std::string Nume_ = "", std::string Prenume_ = "", std::string email = "");

    friend std::ostream& operator<<(std::ostream& os, const Profesor &p);
    friend std::istream& operator>>(std::istream& is,  Profesor &p);
    Profesor& operator=(const Profesor&);

    std::string getEmail();
    std::string getFullName() override;

    ~Profesor();

private:

};

#endif //POO_PROIECT2_FROM1_PROFESOR_H
