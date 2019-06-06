/* ---------------------------
 Lab : 10
 File : gestionPort.h
 Author(s) : Yanick Thomann & Robin Reuteler
 Date : 06.06.2019
 
 Goal : Mettre en oeuvre les structures et les unions
 --------------------------- */

#ifndef gestionPort_h
#define gestionPort_h

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define VIDER_BUFFER while(getchar()!='\n');
#define CAPACITE 40

typedef char NoPlaque[6];

typedef enum {
    Moteur, Rame, Voile
} typeBateau;


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


Bateau saisirBateau(void);

/**
 * @brief place un bateau dans le port
 *
 * @param bateau le pointeur vers le bateau à placer
 * @return vrai si le bateau a pu être placé, faux sinon
 */
bool placerBateau(Bateau* bateau);

/**
 * @brief libère une place dans le port
 *
 * @param id le numéro de plaque du bateau à retirer
 * @return vrai si le bateau a pu être retiré, faux sinon
 */
bool libererPlace(NoPlaque id);

/**
 * @brief affiche les détails d'un bateau
 *
 * @param id le numéro de plaque du bateau à afficher
 * @return aucun
 */
void afficherDetails(NoPlaque id);

/**
 * @brief affiche une des places du port
 *
 * @param noPlace le numéro de la place à afficher
 * @return aucun
 */
void afficherPlace(unsigned noPlace);

/**
 * @brief parcourt le port et effectue un traitement pour chaque place
 *
 * @param f un pointeur vers une fonction qui prend un numéro de place en paramètre
 * @return aucun
 */
void parcourt(void(* f)(unsigned));

/**
 * @brief affiche toutes les places du port
 *
 * @return aucun
 */
void afficherPort(void);

/**
 * @brief vérifie si le numéro de plaque passé en paramètre existe déja (dans le port)
 *
 * @param plaqueID le numéro de plaque à vérifier
 * @return vrai si le numéro est unique, faux sinon
 */
bool plaqueUnique(NoPlaque plaqueID);

/* Fonctions ----------------------------------------------------------------------*/


#endif /* gestionPort_h */
