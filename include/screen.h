#pragma once

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ENTER 13
#define ESPACIO 32


namespace Screen
{
    void setFrame(int x, int y);
    void limits();
    void decorateBackground();
}
