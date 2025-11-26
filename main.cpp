#include <iostream>
#include <random>


#include "Figure.h"
#include "Grille.h"
#include "Couleur.h"
#include "Position.h"

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

enum Forme {Carre, Barre, LFigure, SFigure, TFigure};

int temps_courant = 0;
int dernier_temps = 0;
int tour = 1;



//On déclare la fenêtre principale

SDL_Window *fenetre_principale;

//On déclare le rendu qui va permettre de dessiner dans la fenêtre principale

SDL_Renderer *rendu_fenetre_principale;

//texture pour dessiner dans la fenêtre
static SDL_Texture *texture = NULL;

static int texture_largeur = 0;

static int texture_hauteur = 0;

random_device rd;
mt19937 gen(rd());

uniform_int_distribution<> dis(0, 4);//le nombre aléatoire peut tomber entre 1 et 10
Figure ma_figure(/*dis(gen)*/SFigure);

Grille grille;

void dessiner_carre(SDL_FRect rect,int pos_x, int pos_y, int cellule_taille, Couleur c)
{
    rect.x = pos_x;
    rect.y = pos_y;
    rect.w = cellule_taille ;
    rect.h = cellule_taille;

    int r,g,b;
    r = c.rouge;
    g = c.vert;
    b = c.bleu;



    SDL_SetRenderDrawColor(rendu_fenetre_principale, r, g, b, SDL_ALPHA_OPAQUE);  /* blue, full alpha */
    SDL_RenderFillRect(rendu_fenetre_principale, &rect);

}

void dessiner_grille()
{
    SDL_FRect rects[grille.nb_lignes][grille.nb_colonnes];

    int compteur_couleur = 0;


    for(int ligne = 0 ; ligne < grille.nb_lignes ; ligne++)
    {

        for(int colonne = 0 ; colonne < grille.nb_colonnes ; colonne++)
        {
            Couleur c(compteur_couleur);
            dessiner_carre(rects[ligne][colonne], ligne*grille.taille_pixels_cellule, colonne*grille.taille_pixels_cellule, grille.taille_pixels_cellule,c);

            if(compteur_couleur==c.get_cellules_couleur().size()-1)
            {
                compteur_couleur=0;

            }else
            {
                compteur_couleur++;
            }
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

    /*
    SDL_Surface * surface_grille_jeu = NULL;

    char * chemin_image;

    SDL_asprintf(&chemin_image,"%s..\\..\\images\\grille.xcf" , SDL_GetBasePath());



    surface_grille_jeu = IMG_LoadXCF_IO(SDL_IOFromFile(chemin_image, "r"));

    if (!surface_grille_jeu) {
        SDL_Log("N'a pas pu charger le fichier grille.xcf: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    texture = SDL_CreateTextureFromSurface(rendu_fenetre_principale, surface_grille_jeu);
*/
    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);  /* black, full alpha */


/*

    if (!texture) {
        SDL_Log("Peut pas utiliser texture de grille: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_FRect dst_rect_grille;

    dst_rect_grille.x = 0;
    dst_rect_grille.y = 0;
    dst_rect_grille.w = LARGEUR_PREMIERE_FENETRE;
    dst_rect_grille.h = HAUTEUR_PREMIERE_FENETRE;
    SDL_RenderTexture(rendu_fenetre_principale, texture, NULL, &dst_rect_grille);
*/


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
/*
    temps_courant = SDL_GetTicks();

    SDL_Surface * surface_grille_jeu = NULL;

    char * chemin_image;

    SDL_asprintf(&chemin_image,"%s..\\..\\images\\grille.xcf" , SDL_GetBasePath());



    surface_grille_jeu = IMG_LoadXCF_IO(SDL_IOFromFile(chemin_image, "r"));

    if (!surface_grille_jeu) {
        SDL_Log("N'a pas pu charger le fichier grille.xcf: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    texture = SDL_CreateTextureFromSurface(rendu_fenetre_principale, surface_grille_jeu);

    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 0, SDL_ALPHA_OPAQUE);  /* black, full alpha */
/*
    if (!texture) {
        SDL_Log("Peut pas utiliser texture de grille: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    SDL_FRect dst_rect_grille;

    dst_rect_grille.x = 0;
    dst_rect_grille.y = 0;
    dst_rect_grille.w = LARGEUR_PREMIERE_FENETRE;
    dst_rect_grille.h = HAUTEUR_PREMIERE_FENETRE;
    SDL_RenderTexture(rendu_fenetre_principale, texture, NULL, &dst_rect_grille);



	//cout << dis(gen) << endl;

    if(temps_courant > 5*UNE_SECONDE + dernier_temps   )
    {


        //-----------------Affichage de carré

        SDL_Surface * surface_figure_tetris = NULL;


        SDL_asprintf(&chemin_image, ma_figure.get_adresse_image_associee(), SDL_GetBasePath());

        surface_figure_tetris = IMG_LoadXCF_IO(SDL_IOFromFile(chemin_image, "r"));

        if (!surface_figure_tetris) {
            SDL_Log("N'a pas pu charger le fichier  .xcf: %s", SDL_GetError());
            return SDL_APP_FAILURE;
        }




        texture = SDL_CreateTextureFromSurface(rendu_fenetre_principale, surface_figure_tetris);


        if (!texture) {
            SDL_Log("Peut pas utiliser texture de figure: %s", SDL_GetError());
            return SDL_APP_FAILURE;
        }

        SDL_FRect dst_rect_figure;



        dst_rect_figure.x = 100;
        //dst_rect_figure.y = 200;
        dst_rect_figure.w = texture->w/4;
        dst_rect_figure.h = texture->h/4;


        int origine_y_figure = 200;
        dernier_temps = temps_courant;

        dst_rect_figure.y = origine_y_figure +((tour-1)*(dst_rect_figure.h));

        cout << tour << endl;
        tour++;

        SDL_RenderTexture(rendu_fenetre_principale, texture, NULL, &dst_rect_figure);

        //--------------------------------------------------------------------


        SDL_DestroySurface(surface_figure_tetris);

        /* put the newly-cleared rendering on the screen. */
        /*SDL_RenderPresent(rendu_fenetre_principale);
    }
*/



/*
    for(int ligne = 0 ; ligne < 2 ; ligne++ )
    {
        for(int colonne = 0 ; colonne < 3 ; colonne++)
        {
            rects[ligne][colonne].x = origine_x;
            rects[ligne][colonne].y = origine_y;

            rects[ligne][colonne].w = rects[ligne][colonne].h = grille.taille_pixels_cellule;




            if(compteur_couleur==5)
            {
                compteur_couleur=0;

            }else
            {
                compteur_couleur++;
            }

            SDL_SetRenderDrawColor(rendu_fenetre_principale, couleur_cellule[compteur_couleur].rouge, couleur_cellule[compteur_couleur].vert, couleur_cellule[compteur_couleur].bleu, SDL_ALPHA_OPAQUE);  /* blue, full alpha */
      /*      SDL_RenderFillRect(rendu_fenetre_principale, &(rects[ligne][colonne]));


            origine_x++;
        }
        origine_y++;
        origine_x = 0;


    }*/

    /* those were rectangle _outlines_, really. You can also draw _filled_ rectangles! */
    /*rects[0].x = 400;
    rects[0].y = 50;
    rects[0].w = 100 ;
    rects[0].h = 50;

    SDL_SetRenderDrawColor(rendu_fenetre_principale, 0, 0, 255, SDL_ALPHA_OPAQUE);  /* blue, full alpha */
   // SDL_RenderFillRect(rendu_fenetre_principale, &rects[0]);



/*
    origine_x++;
    origine_y++;

    rects[0][1].x = origine_x;
    rects[0][1].y = origine_y;
*/
    /* as you can see from this, rendering draws over whatever was drawn before it. */
    SDL_SetRenderDrawColor(rendu_fenetre_principale, 150, 150, 150, SDL_ALPHA_OPAQUE);  /* black, full alpha */
    SDL_RenderClear(rendu_fenetre_principale);  /* start with a blank canvas. */



    dessiner_grille();




    SDL_RenderPresent(rendu_fenetre_principale);


    return SDL_APP_CONTINUE;  /* carry on with the program! */
}

/* This function runs once at shutdown. */
void SDL_AppQuit(void *appstate, SDL_AppResult result)
{

    /* SDL will clean up the window/renderer for us. */


}





