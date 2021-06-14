#include <windows.h>
#include <MMSystem.h>
#include "color.h"
#include "screen.h"
#include <stdio.h>
#include <stdio.h>
#include <conio.h>

#include <Mmsystem.h>
//#include <mciapi.h>

//these two headers are already included in the <Windows.h> header
#pragma comment(lib, "Winmm.lib")


using namespace Screen;
using namespace Color;


namespace Util
{
    void setFrame(int x, int y){
        HANDLE var;
        var=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.Y=y;
        dwPos.X=x;
        SetConsoleCursorPosition(var,dwPos);
    }

    int pause(){
        int x=15,y=8;
        int var2=0;
        bool var=true;
            for(int j=5;j<=11;j++){
                for(int i=14;i<=65;i++){
                    setFrame(i,j);paint("wt");printf("%c",219);
                }
            }
            setFrame(x+19,y-2);paint("wt3");printf("GAME PAUSED");
            setFrame(x+2,y);printf("Continue game");
            setFrame(x+2,y+2);printf("Exit to menu");
            setFrame(x,y);paint("wt4");printf(">");
            while(var!=false){
                if(kbhit()){
                    char tecla=getch();
                    if(tecla==DOWN&&y<=8){
                        setFrame(x,y);paint("wt3");printf(" ");
                        y=y+2; var2=1;
                        Sleep(20);
                        setFrame(x,y);paint("wt4");printf(">");
                        Beep(100,300);
                    }
                    if(tecla==UP&&y>=10){
                        setFrame(x,y);paint("wt3");printf(" ");
                        y=y-2; var2=0;
                        Sleep(20);
                        setFrame(x,y);paint("wt4");printf(">");
                        Beep(100,300);
                    }
                    if(tecla==ENTER) var=false;
                }
            }
            for(int j=5;j<=11;j++){
                for(int i=14;i<=65;i++){
                    setFrame(i,j);paint("bl");printf("%c",219);
                }
            }

        return var2;
    }

    int cursorMenu(){
        int x=4,y=7;
        setFrame(x,y);paint("wt2");printf(">");
        bool var=true;
        int count_menu=600000;
        while(var!=false){
            if(count_menu==600000){
                //PlaySound(TEXT("./sounds/music_menu.wav"),NULL,SND_ASYNC);
                count_menu=0;
            }
            Sleep(95);
            count_menu=count_menu+100;

            if(kbhit()){
                char tecla=getch();
                if(tecla==UP&&y>7){
                    setFrame(x,y);paint("wt2");printf(" ");
                    y=y-3;
                    Sleep(20);
                    setFrame(x,y);paint("wt2");printf(">");
                    Beep(100,300);
                }
                if(tecla==DOWN&&y<13){
                    setFrame(x,y);paint("wt2");printf(" ");
                    y=y+3;
                    Sleep(20);
                    setFrame(x,y);paint("wt2");printf(">");
                    Beep(100,300);
                }
                if(tecla==ENTER){
                    Beep(900,300);
                    var=false;
                }
            }
        }
        return y;
    }

    void imgMenu(){
        int x=50,y=13,i,j;

        //x: 50 - y: 2

        for(int l=0;l<100;l++){
            i=rand()%74+3;
            j=rand()%23+4;
            setFrame(i,j);paint("gr3");printf(".");
        }

        setFrame(x+6,y-6);paint("gr");printf("%c%c%c%c%c%c%c%c",220,220,220,220,220,220,220,220);
        setFrame(x+4,y-5);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,219,219,219,219,219,219,219,220);
        setFrame(x+3,y-4);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,219,219,219,219,219,219,219,219,219,220);
        setFrame(x+2,y-3);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,219,219,219,219,219,219,219,219,219,219,219,220);
        setFrame(x+1,y-2);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",220,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,220);

        setFrame(x+1,y-1);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        setFrame(x+1,y);paint("gr")  ;printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        setFrame(x+1,y+1);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);
        setFrame(x+1,y+2);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219);

        setFrame(x+1,y+3);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,219,223);
        setFrame(x+2,y+4);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,219,219,219,219,219,219,219,219,219,219,219,219,219,219,223);
        setFrame(x+3,y+5);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c",223,219,219,219,219,219,219,219,219,219,219,219,219,223);
        setFrame(x+4,y+6);paint("gr");printf("%c%c%c%c%c%c%c%c%c%c%c%c",223,219,219,219,219,219,219,219,219,219,219,223);
        setFrame(x+6,y+7);paint("gr");printf("%c%c%c%c%c%c%c%c",223,223,223,223,223,223,223,223);

        setFrame(x+4,y-4);paint("gr2");printf("      %c%c",219,223);
        setFrame(x+2,y-2);paint("gr2");printf("    %c%c      %c%c",219,223,219,223);
        setFrame(x+2,y);paint("gr2");printf(" %c%c      %c%c",219,223,219,223);
        setFrame(x+2,y+2);paint("gr2");printf("     %c%c      %c%c",219,223,219,223);
        setFrame(x+2,y+4);paint("gr2");printf("          %c%c",219,223);
        setFrame(x+4,y+5);paint("gr2");printf("   %c%c",219,223);

        setFrame(x,y+10);paint("rd");printf("ASTEROIDS");
    }

    int menu(){

        for(int f=2;f<78;f++){
            setFrame(f,2);paint("az3");printf("%c",219);
        }
        for(int j=4;j<=26;j++){
            for(int i=3;i<=76;i++){
                setFrame(i,j);paint("bl");printf("%c",219);
            }
        }
        imgMenu();
        int min=50,l=4,opc;
        while(l!=27){
            Sleep(10);
            for(int k=min;k>=3;k--){
                setFrame(k,l);paint("mu2");printf("%c",219);
            }
            l++;
            min=min-2;
        }
        min=46,l=4;
        while(l!=27){
            Sleep(10);
            for(int k=min;k>=3;k--){
                setFrame(k,l);paint("mu");printf("%c",219);
            }
            l++;
            min=min-2;
        }
        setFrame(6,7);paint("wt2");printf("PLAY");
        setFrame(6,10);paint("wt2");printf("OPTIONS");
        setFrame(6,13);paint("wt2");printf("QUIT");
        opc=cursorMenu();
        if(opc==7){
            return opc;
        }
        if(opc==10){
            return opc;
        }
        if(opc==13){
            return opc;
        }
    }

    int cursorMenu2(){
        int x=34,y=15;
        setFrame(x,y);paint("wt4");printf(">");
        bool var=true;
        int count=-2000;float ctd=30;
        //PlaySound(TEXT("./sounds/gameover.wav"),NULL,SND_ASYNC);
        while(var!=false){
            Sleep(50);
            if(count==1000){
                //PlaySound(TEXT("./sounds/countdown.wav"),NULL,SND_ASYNC);
                setFrame(45,14);printf("%.0f",ctd=ctd-1);
                count=0;
                if(ctd<=0){
                    x=39;
                    var=false;
                }
            }
            count=count+100;

            if(kbhit()){
                char tecla=getch();
                if(tecla==LEFT&&x>36){
                    setFrame(x,y);paint("wt3");printf(" ");
                    x=x-5;
                    Sleep(20);
                    setFrame(x,y);paint("wt4");printf(">");
                    Beep(100,300);
                }
                if(tecla==RIGHT&&x<39){
                    setFrame(x,y);paint("wt3");printf(" ");
                    x=x+5;
                    Sleep(20);
                    setFrame(x,y);paint("wt4");printf(">");
                    Beep(100,300);
                }
                if(tecla==ENTER) var=false;
            }
        }
        return x;
    }

    int menu2(){
        for(int j=12;j<=16;j++){
            for(int i=29;i<=48;i++){
                setFrame(i,j);paint("wt");printf("%c",219);
            }
        }
        setFrame(34,13);paint("wt3");printf("GAME OVER");
        setFrame(30,14);paint("wt3");printf("\tTry again?");
        setFrame(35,15);paint("wt3");printf("Yes");
        setFrame(40,15);paint("wt3");printf("No");
        int opc=cursorMenu2();

        if(opc==36){
            return 0;
        }
        if(opc==39){
            return 1;
        }
    }

    void intro(){
        int x=22,y=10,var=100;
        Sleep(2000);
        //PlaySound(TEXT("./sounds/intro.mp3"),NULL,SND_ASYNC);
        setFrame(x,y);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+12,y);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,220);Sleep(var);			setFrame(x+24,y);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+1);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+12,y+1);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+24,y+1);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+2);printf("%c%c%c",219,219,219);Sleep(var);										setFrame(x+12,y+2);printf("%c%c%c   %c%c%c",219,219,219,219,219,219);Sleep(var);					setFrame(x+24,y+2);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+3);printf("%c%c%c",219,219,219);Sleep(var);										setFrame(x+12,y+3);printf("%c%c%c   %c%c%c",219,219,219,219,219,219);Sleep(var);					setFrame(x+24,y+3);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+4);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+12,y+4);printf("%c%c%c   %c%c%c",219,219,219,219,219,219);Sleep(var);					setFrame(x+24,y+4);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+5);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+12,y+5);printf("%c%c%c   %c%c%c",219,219,219,219,219,219);Sleep(var);					setFrame(x+24,y+5);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+6);printf("%c%c%c",219,219,219);Sleep(var);										setFrame(x+12,y+6);printf("%c%c%c   %c%c%c",219,219,219,219,219,219);Sleep(var);					setFrame(x+24,y+6);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+7);printf("%c%c%c",219,219,219);Sleep(var);										setFrame(x+12,y+7);printf("%c%c%c   %c%c%c",219,219,219,219,219,219);Sleep(var);					setFrame(x+24,y+7);printf("%c%c%c",219,219,219);Sleep(var);
        setFrame(x,y+8);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+12,y+8);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+24,y+8);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);
        setFrame(x,y+9);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);	setFrame(x+12,y+9);printf("%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,223);Sleep(var);			setFrame(x+24,y+9);printf("%c%c%c%c%c%c%c%c%c",219,219,219,219,219,219,219,219,219);Sleep(var);
        setFrame(30,y+11);printf("G   A   M   E   S");Sleep(20);//PlaySound(TEXT("./sounds/outro.wav"),NULL,SND_ASYNC);
        Sleep(2000);
    }

    void outro(){
        for(int i=0;i<=11;i++){
            for(int j=0;j<=29;j++){
                setFrame(i,j);paint("wt");printf("%c",219);
                setFrame(i+12,j);paint("yell");printf("%c",219);
                setFrame(i+23,j);paint("cian");printf("%c",219);
                setFrame(i+34,j);paint("az");printf("%c",219);
                setFrame(i+46,j);paint("purple");printf("%c",219);
                setFrame(i+57,j);paint("az2");printf("%c",219);
                setFrame(i+68,j);paint("blue");printf("%c",219);
            }
        }
        Beep(1200,1000);
    }

}
