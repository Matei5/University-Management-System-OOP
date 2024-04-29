#include "../include/Exception.h"

const char* Exception::what() const noexcept {
        return "Dynamic cast fail.";
}
