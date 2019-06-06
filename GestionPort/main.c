/* ---------------------------
 Lab : 10
 File : main.c
 Author(s) : Yanick Thomann & Robin Reuteler
 Date : 06.06.2019
 
 Goal : Mettre en oeuvre les structures et les unions
 --------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include "gestionPort.h"


int main(void)
{
    Bateau b1 = saisirBateau();
    placerBateau(&b1);
    Bateau b2 = saisirBateau();
    placerBateau(&b2);
    afficherPlace(0);
    afficherPort();
    libererPlace("VD123");
    afficherPort();
    afficherDetails("vd123");
    //    libererPlace("vd123");
    //    afficherPlace(0);
    
    
    return (EXIT_SUCCESS);
}

