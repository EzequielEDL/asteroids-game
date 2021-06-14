#include <iostream>
#include <string>
#include <windows.h>


using namespace std;

void setColor(int colorNumber)
{
    HANDLE col;
	col=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(col, colorNumber);
}

int getColorNumber (const char *strInput)
{
    if (strcmp(strInput, "yell") == 0)   { return 238; }
    if (strcmp(strInput, "cian") == 0)   { return 187; }
    if (strcmp(strInput, "purple") == 0) { return 221; }
    if (strcmp(strInput, "blue") == 0)   { return 25;  }
    if (strcmp(strInput, "gr") == 0)  	 { return 8;   }
    if (strcmp(strInput, "gr2") == 0)  	 { return 128; }
    if (strcmp(strInput, "gr3") == 0)  	 { return 15;  }
    if (strcmp(strInput, "rd") == 0)  	 { return 12;  }
    if (strcmp(strInput, "vd") == 0)  	 { return 10;  }
    if (strcmp(strInput, "az") == 0)  	 { return 26;  }
    if (strcmp(strInput, "az2") == 0)  	 { return 28;  }
    if (strcmp(strInput, "az3") == 0)  	 { return 17;  }
    if (strcmp(strInput, "bl") == 0)  	 { return 0;   }
    if (strcmp(strInput, "mu") == 0)  	 { return 3;   }
    if (strcmp(strInput, "mu2") == 0)  	 { return 4;   }
    if (strcmp(strInput, "wt") == 0)  	 { return 31;  }
    if (strcmp(strInput, "wt2") == 0)  	 { return 48;  }
    if (strcmp(strInput, "wt3") == 0)  	 { return 240; }
    if (strcmp(strInput, "wt4") == 0)  	 { return 252; }
    if (strcmp(strInput, "wt5") == 0)  	 { return 15;  }
    if (strcmp(strInput, "rd2") == 0)  	 { return 3;   }
    if (strcmp(strInput, "rd3") == 0)  	 { return 0;   }
    if (strcmp(strInput, "rd4") == 0)  	 { return 79;  }
}

namespace Color
{
    void paint(const char *colorName)
    {
        setColor(getColorNumber(colorName));
    }
}

