#ifndef LIENZO_H
#define LIENZO_H


void reservaMemoria(char** & m, int nf, int nc);

void liberaMemoria(char** & m, int nf, int nc);

char **extrae(char **m, int ori_x, int ori_y, int nf, int nc);

void imprime(char **m, int nf, int nc);

void rellenar(char **m, int nf, int nc, char simbolo);

void dibujarCuadrado(char **m, int nf, int nc, int x, int y, int lado);

char** combinar(char **A, int nf_A, int nc_A, char **B, int nf_B, int nc_B, int & nf_C, int & nc_C);

#endif
