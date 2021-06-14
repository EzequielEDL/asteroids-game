#include "star.h"
#include "color.h"
#include "screen.h"
#include <windows.h>
#include <conio.h>


using namespace Color;
using namespace Screen;

star::star(int _x, int _y){
    x = _x;
    y = _y;
}

void star::decorate(){
    paint("wt5");
    setFrame(x, y); printf(".");
}

void star::movement(){
    paint("bl");
    setFrame(x, y); printf(" ");
  	y++;
  	if(y > 26){
  		x = rand()%74+3;
  		y = 4;
  	}
  	decorate();
}

void star::crash(class nave &N){
	if(x>=N.X() && x<N.X()+3 && y>=N.Y() && y<N.Y()+1){
		N.decorate();
		if(x>=3 && x<=77 && y==25){
			x=rand()%71+4;
			y=4;
			N.decorate();
		}else{
			y+=2;
		}
	}
}
