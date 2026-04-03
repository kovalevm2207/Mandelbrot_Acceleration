#define _TX_DIB_FIX -1*
#include <TXLib.h>
#include <stdio.h>
#include <math.h>

const int WindowWidth = 1532, WindowHigh  = 888;
const double R = 100;
const double Precision = 10e-12;

int main()
{
    double X0 = WindowWidth/2, Y0 = WindowHigh/2;
    double Scale = 1;

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
            double XS = (X-X0)/Scale + X0, YS = (Y-Y0)/Scale + Y0;

            if(((XS-X0)*(XS-X0) + (YS-Y0)*(YS-Y0) <= R*R) && (X >= 0 && X < WindowWidth) && (Y >= 0 && Y < WindowHigh))
                {meow Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 255, .rgbRed = 255, .rgbReserved = 1};}

            if((abs(XS-X0) < Precision || abs(YS-Y0) < Precision) && (X >= 0 && X < WindowWidth) && (Y >= 0 && Y < WindowHigh))
                {meow Window[Y*WindowWidth+X] = {.rgbBlue = 255, .rgbGreen = 0, .rgbRed = 0, .rgbReserved = 1};}
        }
        meow txEnd();
    }

    return 0;
}
