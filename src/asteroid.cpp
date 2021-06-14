#include "asteroid.h"
#include "nave.h"
#include "color.h"
#include "screen.h"
#include <windows.h>
#include <conio.h>


using namespace Color;
using namespace Screen;

asteroid::asteroid(int _x, int _y){
  x = _x;
  y = _y;
}

void asteroid::decorate() {
    paint("vd");
    setFrame(x, y);
    printf("%c", 184);
}

void asteroid::movement(){
    paint("bl");
    setFrame(x, y); printf(" ");
  	y++;

    if(y>26){
  		x=rand()%74+3;
  		y=4;
  	}
    decorate();
}

void asteroid::crash(class nave &N){
	if(x >= N.X() && x < N.X()+3 && y >= N.Y() && y < N.Y()+1){
		N.subHealth();
		N.decorateHealth();
		N.removeDecorate(); Beep(1000,200);
        N.decorate();        Beep(900,200);
        N.removeDecorate(); Beep(1000,200);
        N.decorate();
		x = rand()%71+4;
		y = 4;
	}
}
