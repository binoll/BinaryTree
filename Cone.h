#include "headers.h"

class Cone {
public:
    Cone();

    Cone(int32_t ru,int32_t rd, int32_t h);

    Cone(const Cone &cone);

    ~Cone();

    bool operator<(const Cone &cone);

    bool operator>(const Cone &cone);

    bool operator==(const Cone &cone);

    bool operator!=(const Cone &cone);

    Cone& operator=(const Cone &cone);

    friend std::ostream& operator<<(std::ostream& stream, const Cone &cone);

private:
    int32_t ru;
    int32_t rd;
    int32_t h;
    int32_t v;
};