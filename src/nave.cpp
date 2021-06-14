#include "nave.h"
#include "screen.h"
#include "color.h"
#include <windows.h>
#include <conio.h>


using namespace Color;
using namespace Screen;

nave::nave(int _x, int _y, int _health, int _life){
    x = _x;
    y = _y;
    health = _health;
    life = _life;
}

int nave::X() {
    return x;
}

int nave::Y() {
    return y;
}

void nave::movement() {
	if(kbhit()) {
        removeDecorate();
        char key = getch();

        if(key == LEFT && x > 3) x--;
        if(key == RIGHT && x + 3 < 77) x++;
        if(key == UP && y > 4) y--;
        if(key == DOWN && y + 3 < 28) y++;

        decorate();
        decorateHealth();
    }
}

void nave::decorate() {
    paint("rd");
	setFrame(x, y );  printf(" %c ", 182);
	setFrame(x, y+1); printf("%c%c%c", 174, 190, 175);
}

void nave::decorateHealth() {
	paint("az");
	setFrame(50, 2);  printf("Life %i", life);
	paint("az2");
	setFrame(64, 2); printf("Health:");
	setFrame(72, 2); printf("       ");

	for(int i=0; i < health; i++) {
        setFrame(72+i, 2); printf("#");
	}
}

void nave::removeDecorate() {
    paint("bl");
	setFrame(x, y);   printf("   ");
	setFrame(x, y+1); printf("   ");
}

void nave::die() {
	if(health == 0){
		removeDecorate();
    paint("rd");
		setFrame(x, y  ); printf(" * ");
		setFrame(x, y+1); printf(" * ");
		Beep(200, 100); Beep(500, 150);

		removeDecorate();
    paint("rd");
		setFrame(x, y  ); printf("***");
		setFrame(x, y+1); printf("***");
		Beep(200, 100); Beep(500, 150);

		removeDecorate();
		life--;
		health = 3;
		decorateHealth();
		decorate();
	}
}

int nave::gameover() {
	if(life == 0) {

		for (int i=0; i < 2; i++) {
			removeDecorate();
      paint("rd");
			setFrame(x, y-1); printf(" * ");
			setFrame(x, y	 ); printf("***");
			setFrame(x, y+1); printf(" * ");
			Beep(200, 100); Beep(500, 150);

			removeDecorate();

      paint("rd");
			setFrame(x, y-1); printf("***");
			setFrame(x, y	 ); printf("* *");
			setFrame(x, y+1); printf("***");
			Beep(500, 100); Beep(600, 150);
		}

		removeDecorate();
		Beep(200, 100); Beep(100, 150);
		limits();
	}

	return life;
}

void nave::resetLife() {
	if(life == 0) life = 3;
}

void nave::subHealth() {
	health--;
}
