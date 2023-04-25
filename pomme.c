#include "pomme.h"



int random_case_pomme (int tab[N][N]){  /* Permet de choisir aléatoirement la case pour placer la pomme */
    int i,j,p_case = 0;
    for (i = 0; i < Y; i++){
        for (j = 0; j < X; j++)
        {
            if (tab[i][j] == 0){
                p_case++;
            }
        }
    }
    p_case = rand() % p_case;
    return p_case;
}




coord place_dans_le_vide(int tab[N][N], int p_case){ /* Place la pomme */
    int i, j;
    int tmp = -1;
    coord pomme;
    for (i = 0; i < Y; i++){
        for (j = 0; j < X; j++){
            if (tab[i][j] == 0){
                tmp++;
            }
            if (tmp == p_case){ 
                tab[i][j] = 4;
                pomme.x=j;
                pomme.y=i;
                return pomme;
            }
        }
    }
    return pomme;
}



coord place_pomme(int tab[N][N]){ /* Fusion des trois fonctions */
    int p_case;
    coord pomme;
    p_case=random_case_pomme(tab);
    pomme=place_dans_le_vide(tab,p_case);
    return pomme;
}



int pomme_absente (int tab[N][N]){ /* Permet de vérifier si la pomme est présente dans le plateau de jeu */
    int i,j;
    for (i = 0; i < Y; i++){
        for (j = 0; j < X; j++){
            if (tab[i][j] == 4)
                return 0;
        }
    }
    return 1;
}



char radar_pomme (coord pomme, coord serpent[X*Y]){ /* Renvoie un caractère correspondantà la position de la pomme si il se trouve dans une case adjacente au serpent */
    if (pomme.x+1 == serpent[0].x && pomme.y ==serpent[0].y)
        return 'q';
    if (pomme.x-1 == serpent[0].x && pomme.y ==serpent[0].y)
        return 'd';
    if (pomme.x == serpent[0].x && pomme.y+1 ==serpent[0].y)
        return 'z';
    if (pomme.x == serpent[0].x && pomme.y-1 ==serpent[0].y)
        return 's';
    return '0';
}