#ifndef _INITIALISATION_H_
#define _INITIALISATION_H_

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <MLV/MLV_all.h>
#include "types.h"


void f_buffer();
void plateau (int tab[N][N]);
void contour_plateau (int tab[N][N]);
void contour_plateau_2 (int tab[N][N]);

void aff_tab(int tab[N][N]);
coord random_spawn();
int tete_vivante (int tab[N][N]);
int demande_action();
int demande_direction(char dem);

#endif /* _INITIALISATION_H_ */