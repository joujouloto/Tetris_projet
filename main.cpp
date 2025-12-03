#include <iostream>
#include <random>


#include "Figure.h"
#include "Grille.h"
#include "Couleur.h"
#include "Position.h"
#include "Carre.h"
#include "Barre.h"

#include "JFigure.h"

#define LARGEUR_PREMIERE_FENETRE 640
#define HAUTEUR_PREMIERE_FENETRE 860
#define ORIGINE_POS_X_PREMIERE_FENETRE 750
#define ORIGINE_POS_Y_PREMIERE_FENETRE 50

#define UNE_SECONDE 1000

#define SDL_MAIN_USE_CALLBACKS 1  /* use the callbacks instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>


using namespace std;


int temps_courant = 0;
int dernier_temps = 0;
int tour = 1;



//On déclare la fenêtre principale

SDL_Window *fenetre_principale;

//On déclare le rendu qui va permettre de dessiner dans la fenêtre principale

SDL_Renderer *rendu_fenetre_principale;



random_device rd;
mt19937 gen(rd());

uniform_int_distribution<> dis(0, 4);//le nombre aléatoire peut tomber entre 1 et 10


Grille grille;

int x_barre = 6;
int y_barre = 4;

int x_carre = 2;
int y_carre = 0;

int x_jfigure = 2;
int y_jfigure = 12;



Carre un_carre(x_carre,y_carre,orange);
Barre une_barre(x_barre,y_barre,gris_clair);
JFigure une_jfigure(x_jfigure,y_jfigure,violet);




void dessiner_case(SDL_FRect rect,int pos_x, int pos_y, int cellule_taille, Couleur c)
{
    rect.x = pos_x;
    rect.y = pos_y;
    rect.w = cellule_taille ;
    rect.h = cellule_taille;

    int r,g,b;
    r = c.rouge;
    g = c.vert;
    b = c.bleu;

    const SDL_FRect * const_rect = &rect;



    SDL_SetRenderDrawColor(rendu_fenetre_principale, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(rendu_fenetre_principale, const_rect);

    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderRects(rendu_fenetre_principale,const_rect,1);

}

void dessiner_grille()
{
    SDL_FRect rects[grille.nb_lignes][grille.nb_colonnes];




    for(int ligne = 0 ; ligne < grille.nb_lignes ; ligne++)
    {

        for(int colonne = 0 ; colonne < grille.nb_colonnes ; colonne++)
        {
            Couleur c = Couleur (grille.contenu[ligne][colonne]);
            dessiner_case(rects[ligne][colonne],colonne*grille.taille_pixels_cellule, ligne*grille.taille_pixels_cellule, grille.taille_pixels_cellule,c);

        }




    }
}


SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[])
{

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }



    if (!SDL_CreateWindowAndRenderer("Tetris", LARGEUR_PREMIERE_FENETRE, HAUTEUR_PREMIERE_FENETRE, SDL_WINDOW_RESIZABLE, &fenetre_principale, &rendu_fenetre_principale)) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Couldn't create window and renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

     if(!SDL_SetWindowPosition(fenetre_principale, ORIGINE_POS_X_PREMIERE_FENETRE, ORIGINE_POS_Y_PREMIERE_FENETRE))
    {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Peut pas changer la position de la fenêtre %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    SDL_SetAppMetadata("Tetris", "1.0", "tetris");


    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);  /* black, full alpha */


    SDL_RenderPresent(rendu_fenetre_principale);



    /* clear the window to the draw color. */
    //SDL_RenderClear(rendu_fenetre_principale);



     return SDL_APP_CONTINUE;
}

/* This function runs when a new event (mouse input, keypresses, etc) occurs. */
SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event)
{
    if (event->type == SDL_EVENT_QUIT) {
        return SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
    }
    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once per frame, and is the heart of the program. */
SDL_AppResult SDL_AppIterate(void *appstate)
{

    temps_courant = SDL_GetTicks();


	 /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(rendu_fenetre_principale, 150, 150, 150, SDL_ALPHA_OPAQUE);  /* black, full alpha */
    SDL_RenderClear(rendu_fenetre_principale);  /* start with a blank canvas. */



    un_carre.dessiner(&grille);
    une_barre.dessiner(&grille);
    une_jfigure.dessiner(&grille);


    dessiner_grille();


    SDL_RenderPresent(rendu_fenetre_principale);

    if(temps_courant > 1.5*UNE_SECONDE + dernier_temps   )
    {

        dernier_temps = temps_courant;

        une_barre.effacer(&grille);
        une_barre.descendre();
        une_barre.rotation();


        un_carre.effacer(&grille);
        un_carre.descendre();


        une_jfigure.effacer(&grille);
        une_jfigure.descendre();
        une_jfigure.rotation();


        grille.afficher();
        cout << endl << endl;


    }


    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

    /* SDL will clean up the window/renderer for us. */


}





