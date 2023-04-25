#include "main.h"


int main(){
    int tab[N][N];
    int taille,depl,valeur,load_dem,timing;
    char dem='d',car_pomme, save_dem;
    FILE* fichier = NULL;
    coord tete,pomme;
    coord serpent[XY];
    srand(time(NULL));
    MLV_create_window( "Snake", "snake", 1200, 800 );
    do{
        taille=1;
        depl=1;
        timing=600;
        dem='d';
        valeur=menu_mlv();
        MLV_clear_window(MLV_COLOR_BLACK);
        MLV_actualise_window();
        printf("%d\n",valeur);

        if (valeur==2){
            load_dem=chargement_partie_mlv();
            if (load_dem==1)
                fichier = fopen("save1.txt", "r");
            else if (load_dem==2)
                fichier = fopen("save2.txt", "r");
            else if (load_dem==3)
                fichier = fopen("save3.txt", "r");
            if(fichier==NULL){
                printf("Vous tentez d'ouvrir un fichier inexistant\n");
                exit(EXIT_FAILURE);
            }
            if( (taille=charger_partie(fichier,&pomme,serpent)) == -1){
                printf("Erreur le fichier de save ne contient pas les bonnes informations\n");
                fclose(fichier);
                exit(EXIT_FAILURE);
            }
            fclose(fichier);      
            place_serpent_pomme(serpent,tab,taille,pomme);
        }
        
        else if(valeur==1){
            plateau(tab);
            contour_plateau_2 (tab);
            /*tab devient le plateau du jeu snake */
 
            tete.x=4;
            tete.y=Y/2-1;
            /*coordonnees aléatoires pour le spawn de la tête du serpent */

            tab[tete.y][tete.x]=3;
            /*place la tête du serpent */

            taille=creer_serpent(serpent,tete);
            /* le serpent est un tableau de coordonnees avec la tete en indice 0
               on y récupère sa taille initialiser à 1 */
            pomme=place_pomme(tab);
            /* la pomme est initialisé */

        
        }


    
    
        do{
            /*s'il n'y a pas de pomme one en crée une et la place*/
            if (pomme_absente(tab))
                pomme=place_pomme(tab);
            aff_plateau_mlv(tab,taille);    

            /*on récupère le caractère qui nous dit s'il y a une pomme à côté de la tete*/
            car_pomme=radar_pomme(pomme,serpent);
            MLV_wait_milliseconds(timing);

            /*on recupere la demande de deplacement */
            dem=demande_direction(dem);

            /*si la pomme est au bon endroit alors on la mange
              et le serpent s'aggrandi sinon on déplace simplement le serpent
              (il n' y a que les coordonnées du tableau serpent qui sont modifiées)*/

            if (car_pomme==dem){
                taille=aggrandi_serpent (serpent,pomme,taille);
                if (timing>=300)
                    timing-=50;
                else if (timing>=80)
                    timing-=20;
            }           
            else{
                depl=deplacer (serpent,dem,taille);
                /*si le deplacement vaut 0, on entre dans la sauvegarde de partie*/
                if (depl==0){
                    fichier=NULL;
                    printf("Dans quel slot souhaitez-vous sauvegarder votre partie ?(1 | 2 | 3) ");
                    save_dem=getchar();
                    f_buffer();
                    if (save_dem=='1')
                        fichier = fopen("save1.txt", "w");   
                    else if (save_dem=='2')
                        fichier = fopen("save2.txt", "w");  
                    else if (save_dem=='3')
                        fichier = fopen("save3.txt", "w");
                    else{
                        printf("Erreur : vous tentez de sauvegarder votre partie dans un fichier non conforme");
                        exit(EXIT_FAILURE);
                    }
                    if(fichier==NULL){
                        printf("Vous tentez d'ouvrir un fichier inexistant\n");
                        exit(EXIT_FAILURE);
                    }
                    sauvegarder(fichier,taille,pomme,serpent);
                    printf("Votre sauvegarde a bien été effectuée\nMerci d'avoir jouer\n\n");
                    fclose(fichier);
                    exit(EXIT_SUCCESS);
                }
            }

            /*ici on place le serpent et la pomme dans le tableau*/
            place_serpent_pomme(serpent,tab,taille,pomme);
        


        }
        while (tete_vivante(tab));
        printf("Votre score est de %d\n",taille);
    }
    while(1);
    MLV_free_window();

    
    exit(EXIT_SUCCESS);
}