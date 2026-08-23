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

        void afficher_message_ok();

    protected:

    private:
};

#endif // TEST_H
