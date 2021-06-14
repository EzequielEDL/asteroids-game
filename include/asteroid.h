#ifndef ASTEROID_H
#define ASTEROID_H
#include <string>
#include "nave.h"


using std::string;

class asteroid
{
    int x, y;

    public:
        asteroid(int _x, int _y);
        void decorate();
		void movement();
		void crash(class nave &N);

    protected:

    private:
};

#endif // ASTEROID_H
