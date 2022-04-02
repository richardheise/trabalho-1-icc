#ifndef NEWTON_H
#define NEWTON_H

#include "mathLib.h"

#define NUM_METHODS 3
#define NEWTON_EXACT 0
#define NEWTON_INEXACT 1
#define NEWTON_LU 2
#define BLOCK_SIZE 5

typedef struct S_OUTPUT{
    double** output;
    int newtonExact;
    int newtonInexact;
    int newtonLU;
}output;

typedef struct S_SL {
    function* f;
    double** Hi;
    double* Gi;
    double* nGi;
    double* Xinit;
    double* Xi;
    double* deltai;
    output* out;
    unsigned int d;
    double eps;
    unsigned int maxIter;
} sl;

sl* slConstructor(char* func);

void slDestructor(sl* linSys);

void newtonDefault(sl* linSys);

void resetSl(sl* linSys);

sl* copySl(sl* linSys);

output* outputConstructor(int maxIter);

void newtonMod(sl* linSys);

void newtonGS(sl* linSys);

void handleSlInit(sl** linSys, int i, char* buffer);

#endif 