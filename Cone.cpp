#include "Cone.h"

Cone::Cone() {
    ru = NULL;
    rd = NULL;
    h = NULL;
    v = NULL;
}

Cone::~Cone() {}

Cone::Cone(int32_t ru, int32_t rd, int32_t h) : ru(ru), rd(rd), h(h) {
    this->v = (3.14) * (rd * rd + rd * ru + ru * ru) / 3;
}

bool Cone::operator<(const Cone &cone) {
    if (this->v < cone.v) {
        return true;
    }
    else {
        return false;
    }
}

bool Cone::operator>(const Cone &cone) {
    if (this->v > cone.v) {
        return true;
    }
    else {
        return false;
    }
}

bool Cone::operator==(const Cone &cone) {
    if (this->v == cone.v) {
        return true;
    }
    else {
        return false;
    }
}

Cone::Cone(const Cone &cone) {
    this->rd = cone.rd;
    this->h = cone.h;
    this->ru = cone.ru;
    this->v = cone.v;
}

bool Cone::operator!=(const Cone &cone) {
    if (this->v != cone.v) {
        return true;
    }
    else {
        return false;
    }
}

Cone& Cone::operator=(const Cone &cone) {
    this->ru = cone.ru;
    this->rd = cone.rd;
    this->h = cone.h;

    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Cone &cone) {
    stream << cone.v;
    return stream;
}

