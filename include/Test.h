#ifndef TEST_H
#define TEST_H

#include <assert.h>



class Test
{
    public:
        Test();
        virtual ~Test();

        void test_creation_grille_si_vide();
        void case_occupee();
        void deplacement_a_gauche();//a ameliorer
        void deplacement_a_droite();//a ameliorer
        void limite_gauche();
        void limite_droite();
        void limite_bas();
        void limite_haut();

        void collision_avec_une_piece();

        void voir_position_reelles();

        void afficher_message_ok();

    protected:

    private:
};

#endif // TEST_H
