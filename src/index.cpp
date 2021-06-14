#include "nave.h"
#include "asteroid.h"
#include "star.h"

#include "color.h"
#include "util.h"
#include "screen.h"

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <winUser.h>
#include <MMSystem.h>
#include <conio.h>

using namespace Util;
using namespace Color;
using namespace Screen;


void cursor(){
	HANDLE var;
	var=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize=10;
	cci.bVisible=false;

	SetConsoleCursorInfo(var,&cci);
}

void app(){

	system("color 1F");
	system("title Asteroids by Eze");
	cursor();
	int points=0;
	intro();

	nave N(36,24,3,3);
	asteroid A(10,4),A2(4,8),A3(15,10);

	int go=3,go2=3,go3=3;
	limits();
	bool game_over=true,exit=true,back=true;

	while(exit!=false){
		int var=menu();
		//OPTIONS
		if(var==10){
			setFrame(4,10);paint("wt2");printf(" ");
			for(int j=5;j<=25;j++){
				for(int k=9;k<=11;k++){
					setFrame(j,k);paint("rd3");printf("%c",219);
				}
			}
			for(int j=14;j<=25;j++){
				for(int k=9;k<=15;k++){
					setFrame(j,k);paint("rd3");printf("%c",219);
				}
			}
			back=true;
			setFrame(6,10);paint("rd2");printf("OPTIONS   ");setFrame(16,10);printf(" CONTROLS");setFrame(16,13);printf(" BACK");
			int y=10;
			int x=15;
			setFrame(x,y);paint("rd2");printf(">");
			while(back!=false){
				if(kbhit()){
					char tecla=getch();
					if(tecla==UP&&y>10){
						setFrame(x,y);paint("rd2");printf(" ");
						y=y-3;
						Sleep(20);
						setFrame(x,y);paint("rd2");printf(">");
						Beep(100,300);
					}
					if(tecla==DOWN&&y<13){
						setFrame(x,y);paint("rd2");printf(" ");
						y=y+3;
						Sleep(20);
						setFrame(x,y);paint("rd2");printf(">");
						Beep(100,300);
					}
					if(tecla==ENTER){
						Beep(900,300);
						if(y==10){
							int s2=50,c2=4;
							for(int c=c2;c<27;c++){
								for(int s=s2;s<77;s++){
									Sleep(0.8);
									setFrame(s,c);paint("mu2");printf("%c",219);
								}
								s2=s2-2;
							}
							setFrame(x+43,y-3);paint("rd4");printf("CONTROLS");
							for(int f=x+35;f<=73;f++){
								setFrame(f,y);printf("%c",219);
							}

							setFrame(x+40,y+2);printf("SPACE - PAUSE");
							setFrame(x+40,y+6);printf("UP ARROW");
							setFrame(x+44,y+8);printf("^");
							setFrame(x+44,y+9);printf("%c",219);
							setFrame(x+41,y+10);printf("<%c%c%c%c%c>",219,219,219,219,219);setFrame(x+50,y+10);printf("RIGHT ARROW");setFrame(x+30,y+10);printf("LEFT ARROW");
							setFrame(x+44,y+11);printf("%c",219);
							setFrame(x+44,y+12);printf("v");
							setFrame(x+39,y+14);printf("DOWN ARROW");

						}else{
							back=false;
						}
					}
				}

			}

		}
		//QUIT
		if(var==13){
			exit=false;
		}

		nave N(36,24,3,3);
		asteroid A(10,4),A2(4,8),A3(15,10);
		star S(10,4),S2(4,8),S3(15,10),S4(10,15),S5(4,8),S6(10,4),S7(15,10),S8(4,8),S9(10,15);
		game_over=true;
		cursor();

		decorateBackground();
		N.decorate();
		N.decorateHealth();
		points=0;
		setFrame(4,2);paint("az2");printf("Points %i",points);
		go=3,go2=3;

		//PLAY
		if(var==7){
			//PlaySound(TEXT("./sounds/music_game.wav"),NULL, SND_ASYNC);
			setFrame(39,14);paint("rd");printf("3");
			Sleep(1000);
			setFrame(39,14);paint("rd");printf("2");
			Sleep(1000);
			setFrame(39,14);paint("rd");printf("1");
			Sleep(1000);
			setFrame(39,14);paint("rd");printf(" ");
			int count_sleep=0;
			int count_point=0;
			int count_star=0;
			while(game_over!=false){
				if(count_star==12){
					count_star=0;
					S.movement();S.crash(N);
					S2.movement();S2.crash(N);
					S3.movement();S3.crash(N);
					S4.movement();S4.crash(N);
					S5.movement();S5.crash(N);
					S6.movement();S6.crash(N);
					S7.movement();S7.crash(N);
					S8.movement();S8.crash(N);
					S9.movement();S9.crash(N);
				}
				if(count_point==100){
					count_point=0;
					points+=5;
				}
				setFrame(4,2);paint("az2");printf("Points %i",points);
				if(count_sleep==4){
					count_sleep=0;
					A.movement();A.crash(N);
					A2.movement();A2.crash(N);
					A3.movement();A3.crash(N);
				}
				if(kbhit()){
					char tecla=getch();
					if(tecla==ESPACIO){
						go3=pause();
					}
					if(go3==1){
						game_over=false;
						go3=3;
					}
				}
				N.die();
				N.movement();
				go=N.gameover();
				Sleep(5);
				count_star+=1;
				count_sleep+=1;
				count_point+=1;
				if(go==0){
					go2=menu2();
					if(go2==1){
						game_over=false;
					}else{
						decorateBackground();
						N.decorate();
						N.decorateHealth();
						N.resetLife();
						points=0;
						setFrame(10,2);paint("az2");printf("                       ");
						//PlaySound(TEXT("./sounds/music_game.wav"),NULL,SND_ASYNC);
						setFrame(39,14);paint("rd");printf("3");
						Sleep(1000);
						setFrame(39,14);paint("rd");printf("2");
						Sleep(1000);
						setFrame(39,14);paint("rd");printf("1");
						Sleep(1000);
						setFrame(39,14);paint("rd");printf(" ");
					}
				}
			}
		}


	}
	outro();
}

namespace Index
{
    void run()
    {
        app();
    }


}
