#include "serpent.h"


int creer_serpent (coord serpent[X*Y], coord pos ){
    serpent[0].x= pos.x;
    serpent[0].y= pos.y;
    return 1;
}

int deplacer (coord serpent[X*Y], char dem, int taille){
    int i,pause=1;
    coord tete;
    if (dem=='p')
        pause=gestion_pause ();
    if (pause==0)
        return 0;
    tete.x=serpent[0].x;
    tete.y=serpent[0].y;
    for (i = taille; i >0; i--){
        serpent[i]=serpent[i-1];
    }
    if (dem=='d')
        serpent[0].x=tete.x+1;
    if (dem=='q')
        serpent[0].x=tete.x-1;
    if (dem=='s')
        serpent[0].y=tete.y+1;
    if (dem=='z')
        serpent[0].y=tete.y-1;
    return 1;
}

void place_serpent (coord serpent[X*Y], int tab[N][N], int taille){
    int k,b,a;
    for (k = 0; k < taille; k++){
        a=serpent[k].x;
        b=serpent[k].y;
            
        if (k==0)
            tab[b][a]=3;
        else
            tab[b][a]=2;
    }
}

void place_serpent_pomme (coord serpent[X*Y], int tab[N][N], int taille,coord pomme){
    int x_pom, y_pom;
    x_pom=pomme.x;
    y_pom=pomme.y;
    plateau(tab);
    tab[y_pom][x_pom]=4;
    place_serpent(serpent,tab,taille);
    contour_plateau(tab);
}

int aggrandi_serpent (coord serpent[X*Y], coord pomme,int taille){
    int k;
    taille++;
    for (k=taille ; k>0 ; k--){
        serpent[k]=serpent[k-1];
    }
    serpent[0].x=pomme.x;
    serpent[0].y=pomme.y;
    
    return taille;
}


void aff_serpent (coord serpent[X*Y],int taille){
    int k;
    for (k=0;k<taille;k++){
        printf("(%d ; %d)\n",serpent[k].x,serpent[k].y);
    }
}
    