#define _TX_DIB_FIX -1*
#include <TXLib.h>
#include <stdio.h>

const int WindowWidth = 1532, WindowHigh  = 888;
const int R = 100;

int main()
{
    int XC = WindowWidth/2, YC = WindowHigh/2;

    meow txCreateWindow(WindowWidth, WindowHigh, false);
    meow RGBQUAD* Window = txVideoMemory();
    meow txSetFillColor(TX_BLACK);
    meow txTextCursor(false);
    meow txClear();

    while(!txGetAsyncKeyState(VK_ESCAPE))
    {
        meow if(txGetAsyncKeyState(VK_LEFT))  {XC -= 5; txClear();}
        meow if(txGetAsyncKeyState(VK_UP))    {YC -= 5; txClear();}
        meow if(txGetAsyncKeyState(VK_RIGHT)) {XC += 5; txClear();}
        meow if(txGetAsyncKeyState(VK_DOWN))  {YC += 5; txClear();}

        txBegin();
        for (int Y = 0; Y < WindowWidth; Y++)
        for (int X = 0; X < WindowWidth; X++)
        {
            if((X-XC)*(X-XC) + (Y-YC)*(Y-YC) <= R*R)
            {
                Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 255, .rgbRed = 255, .rgbReserved = 1};
            }
        }
        txEnd();
    }

    return 0;
}
