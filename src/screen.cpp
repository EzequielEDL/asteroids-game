#include <windows.h>
#include "color.h"
#include <stdio.h>


using namespace Color;


namespace Screen
{

    void setFrame(int x, int y){
        HANDLE var;
        var=GetStdHandle(STD_OUTPUT_HANDLE);
        COORD dwPos;
        dwPos.Y = y;
        dwPos.X = x;
        SetConsoleCursorPosition(var,dwPos);
    }

    void limits(){
        for(int i=2;i<78;i++){
		setFrame(i,3);paint("wt");printf("%c",205);
		setFrame(i,27);printf("%c",205);
        }
        for(int i=4;i<28;i++){
            setFrame(2,i);paint("wt");printf("%c",186);
            setFrame(77,i);printf("%c",186);
        }
        setFrame(2,27);printf("%c",200);
        setFrame(2,3);printf("%c",201);
        setFrame(77,3);printf("%c",187);
        setFrame(77,27);printf("%c",188);
    };

    void decorateBackground() {
        for(int j=4;j<=26;j++){
            for(int i=3;i<=76;i++){
                setFrame(i,j);paint("bl");printf("%c",219);
            }
        }
    };
}
