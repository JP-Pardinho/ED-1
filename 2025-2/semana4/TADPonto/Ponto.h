#ifndef PONTO_H     // Se PONTO_H ainda não foi definido
#define PONTO_H     // Define PONTO_H

typedef struct ponto {
     double x, y;
} Ponto;


Ponto *criaPonto(double x, double y);
double distancia(Ponto *a, Ponto *b);

#endif // PONTO_H
