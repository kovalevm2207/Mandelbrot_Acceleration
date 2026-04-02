#include <TXLib.h>
#include <stdio.h>

// 16:9

const int WindowWidth = 1532;
const int WindowHigh  = 888;
const int R           = 100;
const int XC          = WindowWidth/2;
const int YC          = WindowHigh/2;

int main()
{
    txCreateWindow(WindowWidth, WindowHigh, false);
    RGBQUAD* Window = txVideoMemory();
    txSetFillColor(TX_BLACK);
    txTextCursor(false);
    txClear();

    for (int Y = 0; Y < WindowWidth; Y++)
    {
        for (int X = 0; X < WindowWidth; X++)
        {
            if((X-XC)*(X-XC) + (Y-YC)*(Y-YC) <= R*R)
            {
                Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 255, .rgbRed = 255, .rgbReserved = 1};
            }
        }
    }

    return 0;
}
