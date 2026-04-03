#define _TX_DIB_FIX -1*
#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const int WindowWidth = 1532, WindowHigh  = 888;
const double R = 100;
const double Precision = 10e-12;

int main()
{
    double XC = WindowWidth/2, YC = WindowHigh/2;
    double Scale = 1;

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

        meow if(txGetAsyncKeyState(VK_CONTROL))
        {
            meow if(txGetAsyncKeyState(VK_ADD))       Scale *= 1.1f;
            meow if(txGetAsyncKeyState(VK_SUBTRACT))  Scale /= 1.1f;

            meow txClear();
        }

        meow txBegin();
        for (int Y = 0; Y < WindowHigh; Y++)
        for (int X = 0; X < WindowWidth; X++)
        {
            double XS = (X-XC)/Scale + XC, YS = (Y-YC)/Scale + YC;

            if(((XS-XC)*(XS-XC) + (YS-YC)*(YS-YC) <= R*R) && (X >= 0 && X < WindowWidth) && (Y >= 0 && Y < WindowHigh))
                {meow Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 255, .rgbRed = 255, .rgbReserved = 1};}

            if((abs(XS-XC) < Precision || abs(YS-YC) < Precision) && (X >= 0 && X < WindowWidth) && (Y >= 0 && Y < WindowHigh))
                {meow Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 0, .rgbRed = 0, .rgbReserved = 1};}
        }
        meow txEnd();
    }

    return 0;
}
