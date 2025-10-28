#include <stdlib.h>
#include <math.h>

#include "Ponto.h"

Ponto *criaPonto(double x, double y) {
    Ponto *p = malloc(sizeof(Ponto));
    p->x = x;
    p->y = y;
    return p;
}

double distancia(Ponto *a, Ponto *b) {
    return sqrt((a->x - b->x)*(a->x - b->x) + (a->y - b->y)*(a->y - b->y));
}