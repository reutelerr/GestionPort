/* ---------------------------
 Lab : 10
 File : gestionPort.h
 Author(s) : Yanick Thomann & Robin Reuteler
 Date : 06.06.2019
 
 Goal : Mettre en oeuvre les structures et les unions
 --------------------------- */

#include "gestionPort.h"

const char* const typeBateauNom[3] = {"Moteur", "Rame", "Voile"};
Port port = {NULL};

Bateau saisirBateau(void) {
    Bateau bateau;
    printf("\nSaisissez les details du bateau");
    
    int ok = 0;
    do{
        printf("\nNumero de plaque : ");
        ok = scanf("%s", bateau.id);
        VIDER_BUFFER
    } while ((!ok || strlen(bateau.id) != 5 || !plaqueUnique(bateau.id))
             && printf("Saisie invalide"));
    
    
    do {
        printf("\nLongueur du bateau : ");
        ok = scanf("%lf", &bateau.longueur);
        VIDER_BUFFER
    } while ((!ok || bateau.longueur <= 0)
             && printf("Saisie invalide"));
    
    do {
        printf("\nType (0: Moteur, 1: Rame ou 2: Voile): ");
        ok = scanf("%d", &bateau.type);
        VIDER_BUFFER
    } while ((!ok ||  0 > bateau.type || bateau.type > 2)
             && printf("Saisie invalide"));
    
    
    switch (bateau.type) {
        case Moteur:
            do {
                printf("\nNombre de moteurs : ");
                ok = scanf("%u", &bateau.details.moteurs.nbMoteurs);
                VIDER_BUFFER
            } while ((!ok || bateau.details.moteurs.nbMoteurs <= 0)
                     && printf("Saisie invalide"));
            
            do {
                printf("\nPuissance totale des moteurs : ");
                ok = scanf("%lf", &bateau.details.moteurs.puissance);
                VIDER_BUFFER
            } while ((!ok || bateau.details.moteurs.puissance <= 0)
                     && printf("Saisie invalide"));
            break;
        case Rame:
            do {
                printf("\nNombre de rames : ");
                ok = scanf("%u", &bateau.details.rames.nbRames);
                VIDER_BUFFER
            } while ((!ok || bateau.details.rames.nbRames <= 0)
                     && printf("Saisie invalide"));
            break;
        case Voile:
            do {
                printf("\nSurface totale des voiles : ");
                ok = scanf("%lf", &bateau.details.voiles.surfaceVoiles);
                VIDER_BUFFER
            } while ((!ok || bateau.details.voiles.surfaceVoiles <= 0)
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

void parcourt(void(* f)(unsigned)) {
    for(unsigned i = 0; i < CAPACITE; ++i){
        f(i);
    }
}


void afficherPort(void) {
    printf("Affichage du port\n");
    parcourt(afficherPlace);
}

bool plaqueUnique(NoPlaque plaqueID)
{
    for (unsigned i = 0; i<CAPACITE; ++i)
    {
        if(port[i] != NULL && strcmp(plaqueID, port[i]->id)==0)
        {
            return false;
        }
    }
    return true;
}
