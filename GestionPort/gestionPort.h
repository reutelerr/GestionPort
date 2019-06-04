//
//  gestionPort.h
//  GestionPort
//
//  Created by Robin Reuteler on 28.05.19.
//  Copyright © 2019 RobinReuteler. All rights reserved.
//

#ifndef gestionPort_h
#define gestionPort_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define VIDER_BUFFER while(getchar()!='\n');

const size_t CAPACITE = 40;
typedef char NoPlaque[6];
enum typeBateau{Moteur, Rame, Voile};

struct BateauMoteur
{
    unsigned nbMoteurs;
    double puissance;
};

struct BateauRame
{
    unsigned nbRames;
};

struct BateauVoile
{
    double surfaceVoiles;
};

union DetailsBateau
{
    struct BateauMoteur moteurs;
    struct BateauRame rames;
    struct BateauVoile voiles;
};

struct Bateau
{
    NoPlaque id;
    double longueur;
    enum typeBateau type;
    union DetailsBateau details;
};

typedef struct Bateau port[CAPACITE];

struct Bateau saisirBateau(void)
{
    struct Bateau bateau;
    printf("\nSaisissez les détails du bateau");
    
        printf("\nNuméro de plaque : ");
        scanf("%s", bateau.id);
        VIDER_BUFFER
    
    do
    {
        printf("\nLongueur du bateau : ");
        scanf("%lf", &bateau.longueur);
        VIDER_BUFFER
    }while(bateau.longueur <= 0);
    
    do
    {
        printf("\nType (0: Moteur, 1: Rame ou 2: Voile): ");
        scanf("%d", &bateau.type);
        VIDER_BUFFER
    }while(0 <= bateau.type && bateau.type <= 2);
    
    
    switch(bateau.type)
    {
        case Moteur :
            printf("\nNombre de moteurs : ");
            scanf("%u", &bateau.details.moteurs.nbMoteurs);
            do
            {
                printf("\nPuissance totale des moteurs : ");
                scanf("%lf", &bateau.details.moteurs.puissance);
            }while(bateau.details.moteurs.puissance < 0);
            
        case Rame :
            printf("\nNombre de rames : ");
            scanf("%u", &bateau.details.rames.nbRames);
            
        case Voile :
            do
            {
                printf("\nSurface totale des voiles : ");
                scanf("%lf", &bateau.details.voiles.surfaceVoiles);
            }while(bateau.details.voiles.surfaceVoiles < 0);
            
    }
    return bateau;
}






#endif /* gestionPort_h */
