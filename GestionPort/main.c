//
//  main.c
//  GestionPort
//
//  Created by Robin Reuteler on 28.05.19.
//  Copyright © 2019 RobinReuteler. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "gestionPort.h"


int main()
{
    Bateau b1 = saisirBateau();
    Bateau b2 = saisirBateau();
    placerBateau(&b1);
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

