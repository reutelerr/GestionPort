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

typedef enum {
    Moteur, Rame, Voile
} typeBateau;
char* typeBateauNom[3] = {"Moteur", "Rame", "Voile"};

typedef struct {
    unsigned nbMoteurs;
    double puissance;
} BateauMoteur;

typedef struct {
    unsigned nbRames;
} BateauRame;

typedef struct {
    double surfaceVoiles;
} BateauVoile;

typedef union {
    BateauMoteur moteurs;
    BateauRame rames;
    BateauVoile voiles;
} DetailsBateau;

typedef struct {
    NoPlaque id;
    double longueur;
    typeBateau type;
    DetailsBateau details;
} Bateau;


typedef Bateau* Port[CAPACITE];
Port port = {NULL};

/*---------------------------------------------------------------------------------*/

/* Fonctions ----------------------------------------------------------------------*/
Bateau saisirBateau(void) {
    Bateau bateau;
    printf("\nSaisissez les details du bateau");
    
    do{
        printf("\nNumero de plaque : ");
        scanf("%s", bateau.id);
        VIDER_BUFFER
    } while (strlen(bateau.id) != 5
             && printf("Saisie invalide"));
    
    
    do {
        printf("\nLongueur du bateau : ");
        scanf("%lf", &bateau.longueur);
        VIDER_BUFFER
    } while (bateau.longueur <= 0
             && printf("Saisie invalide"));
    
    do {
        printf("\nType (0: Moteur, 1: Rame ou 2: Voile): ");
        scanf("%d", &bateau.type);
        VIDER_BUFFER
    } while (0 < bateau.type && bateau.type > 2
             && printf("Saisie invalide"));
    
    
    switch (bateau.type) {
        case Moteur:
            do {
                printf("\nNombre de moteurs : ");
                scanf("%u", &bateau.details.moteurs.nbMoteurs);
                VIDER_BUFFER
            } while (bateau.details.moteurs.nbMoteurs <= 0
                     && printf("Saisie invalide"));
            
            do {
                printf("\nPuissance totale des moteurs : ");
                scanf("%lf", &bateau.details.moteurs.puissance);
                VIDER_BUFFER
            } while (bateau.details.moteurs.puissance <= 0
                     && printf("Saisie invalide"));
            break;
        case Rame:
            do {
                printf("\nNombre de rames : ");
                scanf("%u", &bateau.details.rames.nbRames);
                VIDER_BUFFER
            } while (bateau.details.rames.nbRames <= 0
                     && printf("Saisie invalide"));
            break;
        case Voile:
            do {
                printf("\nSurface totale des voiles : ");
                scanf("%lf", &bateau.details.voiles.surfaceVoiles);
                VIDER_BUFFER
            } while (bateau.details.voiles.surfaceVoiles <= 0
                     && printf("Saisie invalide"));
            break;
    }
    return bateau;
}

bool placerBateau(Bateau* bateau) {
    for (unsigned i = 0; i < CAPACITE; ++i) {
        if (port[i] == NULL) {
            port[i] = bateau;
            return true;
        }
    }
    return false;
}

bool libererPlace(NoPlaque id) {
    for (unsigned i = 0; i < CAPACITE; ++i) {
        if (port[i] != NULL && strcmp(port[i]->id, id) == 0) {
            port[i] = NULL;
            return true;
        }
    }
    return false;
}

void afficherDetails(NoPlaque id) { // Fonctionne uniquement si le bateau est parqué !
    for (unsigned i = 0; i < CAPACITE; ++i) {
        if (port[i] != NULL && strcmp(port[i]->id, id) == 0) {
            // Afficher tous les détails
            printf("No plaque : %s\n", port[i]->id);
            printf("Type : %s\n", typeBateauNom[port[i]->type]);
            printf("Longueur : %f \n", port[i]->longueur);
            switch (port[i]->type) {
                case 0:
                    printf("Nb moteurs : %u \n",
                           port[i]->details.moteurs.nbMoteurs);
                    printf("Puissance : %f \n",
                           port[i]->details.moteurs.puissance);
                    break;
                case 1:
                    printf ("Nb rames: %u\n",
                            port[i]->details.rames.nbRames);
                    break;
                case 2:
                    printf("Surface voiles : %f\n",
                           port[i]->details.voiles.surfaceVoiles);
                    break;
            }
            return;
        }
    }
    printf("Aucun bateau ayant ce numéro de plaque dans le port.\n");
}

void afficherPlace(unsigned noPlace) {
    if (noPlace < 0 && noPlace >= CAPACITE) {
        printf("Cette place n'est pas dans le port");
    } else {
        
        printf("No place : %u \n", noPlace);
        
        if (port[noPlace] == NULL) {
            printf("- \n");
        } else {
            printf("\tNo plaque : %s\n", port[noPlace]->id);
            printf("\tType : %s\n", typeBateauNom[port[noPlace]->type]);
            printf("\tLongueur : %f \n", port[noPlace]->longueur);
        }
    }
}

void parcourir(Port port, size_t taillePort, void(* f)(unsigned)) {
    for(unsigned i = 0; i < taillePort; ++i){
        f(i);
    }
}


void afficherPort(void) {
    parcourir(port, CAPACITE, afficherPlace);
}







#endif /* gestionPort_h */
