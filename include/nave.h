#ifndef NAVE_H
#define NAVE_H
#include <string>


using std::string;

class nave
{
    int x, y, life, health;

    public:
        nave(int _x, int _y, int _health, int _life);
        int X();
        int Y();
        void movement();
        void decorate();
        void decorateHealth();
        void removeDecorate();
        void die();
        int gameover();
        void resetLife();
        void subHealth();

    protected:

    private:
};

#endif // NAVE_H
