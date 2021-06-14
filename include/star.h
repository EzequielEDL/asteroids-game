#ifndef STAR_H
#define STAR_H
#include <string>
#include "nave.h"


using std::string;

class star
{
    int x, y;

    public:
        star(int _x, int _y);
        void decorate();
        void movement();
        void crash(class nave &N);

    protected:

    private:
};

#endif // STAR_H
