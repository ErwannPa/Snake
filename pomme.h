#ifndef _POMME_H_
#define _POMME_H_

#include <stdlib.h>
#include <stdio.h>
#include "types.h"

int random_case_pomme (int tab[N][N]);
coord place_dans_le_vide(int tab[N][N], int p_case);
coord place_pomme(int tab[N][N]);
int pomme_absente (int tab[N][N]);
char radar_pomme (coord pomme, coord serpent[XY]);

#endif /* _POMME_H_ */