#ifndef POO_PROIECT2_FROM1_EXCEPTION_H
#define POO_PROIECT2_FROM1_EXCEPTION_H

#include <stdexcept>

class Exception : public std::exception {
public:
    const char* what() const noexcept override;

};

#endif //POO_PROIECT2_FROM1_EXCEPTION_H
