#ifndef _MYGL_H_
#define _MYGL_H_

#include <glm/glm.hpp>
#include "definitions.h"
#include <cmath>

void putPixel(glm::ivec2 pos, glm::vec4 cor)
{
    if (pos.x > IMAGE_WIDTH || pos.y > IMAGE_HEIGHT)
    {
        throw "Not possible to display";
    }
    int position = (4 * pos.x) + (4 * pos.y * IMAGE_WIDTH);
    FBptr[position] = cor.r;
    FBptr[++position] = cor.g;
    FBptr[++position] = cor.b;
    FBptr[++position] = cor.a;
}

void drawLine(glm::ivec2 pos1, glm::vec4 cor1, glm::ivec2 pos2, glm::vec4 cor2)
{
    int x = pos1.x;
    int y = pos1.y;
    int w = pos2.x - pos1.x;
    int h = pos2.y - pos1.y;
    int dx1 = 0, dy1 = 0, dx2 = 0, dy2 = 0;
    float dR = cor2.r - cor1.r, dG = cor2.g - cor1.g, dB = cor2.b - cor1.b, dA = cor2.a - cor1.a;
    float auxColor = sqrt(pow(w, 2) + pow(h, 2));

    float addR = dR / auxColor;
    float addG = dG / auxColor;
    float addB = dB / auxColor;
    float addA = dA / auxColor;

    float iniR = cor1.r;
    float iniG = cor1.g;
    float iniB = cor1.b;
    float iniA = cor1.a;

    if (w < 0)
    {
        dx1 = -1;
    }
    else if (w > 0)
    {
        dx1 = 1;
    }

    if (h < 0)
    {
        dy1 = -1;
    }
    else if (h > 0)
    {
        dy1 = 1;
    }

    if (w < 0)
    {
        dx2 = -1;
    }
    else if (w > 0)
    {
        dx2 = 1;
    }

    int longo = abs(w);
    int curto = abs(h);

    if (curto > longo)
    {
        longo = abs(h);
        curto = abs(w);
        if (h < 0)
            dy2 = -1;
        else if (h > 0)
            dy2 = 1;
        dx2 = 0;
    }

    int numerador = longo >> 1;
    for (int i = 0; i <= longo; i++)
    {
        putPixel(glm::ivec2(x, y), glm::vec4(round(iniR += addR), round(iniG += addG), round(iniB += addB), round(iniA += addA)));
        numerador += curto;
        if (longo < numerador)
        {
            numerador -= longo;
            x += dx1;
            y += dy1;
        }
        else
        {
            x += dx2;
            y += dy2;
        }
    }
}

void drawTriangle(glm::ivec2 pos1, glm::vec4 cor1, glm::ivec2 pos2, glm::vec4 cor2, glm::ivec2 pos3, glm::vec4 cor3)
{
    drawLine(pos1, cor1, pos2, cor2);
    drawLine(pos2, cor2, pos3, cor3);
    drawLine(pos3, cor3, pos1, cor1);
}

void round_and_round()
{

    double margem = 10;
    int centroX = 256;
    int centroY = 256;
    int tamanhoLinha = 256 - margem;
    int numLinhas = 200;

    double passosAngulo = (M_PI * 2) / numLinhas;

    for (int i = 1; i <= numLinhas; i++)
    {
        double theta = passosAngulo * i;
        int inicioX = (margem * cos(theta)) + centroX;
        int inicioY = (margem * sin(theta)) + centroY;
        int finalX = (tamanhoLinha * cos(theta)) + centroX;
        int finalY = (tamanhoLinha * sin(theta)) + centroY;

        drawLine(glm::ivec2(inicioX, inicioY), glm::vec4(255, 255, 255, 255), glm::ivec2(finalX, finalY), glm::vec4(255, 255, 255, 255));
    }
}

#endif // _MYGL_H_
