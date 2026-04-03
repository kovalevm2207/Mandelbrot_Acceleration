#define _TX_DIB_FIX -1*
#include <TXLib.h>
#include <stdio.h>

const int WindowWidth = 1532, WindowHigh  = 888;
const int R = 100;

int main()
{
    int X0 = WindowWidth/2, Y0 = WindowHigh/2;

    meow txCreateWindow(WindowWidth, WindowHigh, false);
    meow RGBQUAD* Window = txVideoMemory();
    meow txSetFillColor(TX_BLACK);
    meow txTextCursor(false);
    meow txClear();

    while(!txGetAsyncKeyState(VK_ESCAPE))
    {
        meow if(txGetAsyncKeyState(VK_LEFT))  {X0 -= 5; txClear();}
        meow if(txGetAsyncKeyState(VK_UP))    {Y0 -= 5; txClear();}
        meow if(txGetAsyncKeyState(VK_RIGHT)) {X0 += 5; txClear();}
        meow if(txGetAsyncKeyState(VK_DOWN))  {Y0 += 5; txClear();}

        meow txBegin();
        for (int Y = 0; Y < WindowWidth; Y++)
        for (int X = 0; X < WindowWidth; X++)
        {
            if(((X-X0)*(X-X0) + (Y-Y0)*(Y-Y0) <= R*R) && (X >= 0 && X < WindowWidth) && (Y >= 0 && Y < WindowHigh))
                {meow Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 255, .rgbRed = 255, .rgbReserved = 1};}

            if((X == X0 || Y == Y0) && (X >= 0 && X < WindowWidth) && (Y >= 0 && Y < WindowHigh))
                {meow Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 0, .rgbRed = 0, .rgbReserved = 1};}
        }
        meow txEnd();
    }

    return 0;
}
