#ifndef STRUCTURE_H_INCLUDED
#define STRUCTURE_H_INCLUDED
#include "structure.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct information{
    char titre[1000];
    char sujet[1000];
    char creator[1000];
    char descriptions[2000];
    char dernier[1000];
    char revisions[1000];
    char creation[1000];
    char modification[1000];
    char categorie[1000];
    char langue[1000];
    char templatee[1000];
    char totaltime[1000];
    char pages[1000];
    char word[1000];
    char charactere[1000];
    char application[1000];
    char docsecurity[1000];
    char lignes[1000];
    char paragraphe[1000];
    char scalecrop[100];
    char manager[100];
    char company[100];
    char liensupdate[100];
    char espace[100];
    char share_doc[100];
    char lienbase[100];
    char lienchange[100];
    char version[100];
} information;      //stock les informations app et core.xml

typedef struct police{
    char nom[1000000];
}police;            //stock les informations des polices

typedef struct id{
    char ID[5000000];
}id;                    // stock les id des liens hypertexte

typedef struct nom_id{
    char ID_nom[1000000];
}nom_id;            //stock le nom du lien hypertexte

typedef struct nom_id_bis{
    char ID_nom_bis[1000000];
}nom_id_bis;        //stock les liens hypertexte

typedef struct embed{
    char Id_embed[10000000];
}embed;                 //stock le lien caché dans l'image

typedef struct Image_ID{
    char ID_image[1000000];
}Image_ID;              //stock tous les id du fichier document.xml.rels dans le ficheir

typedef struct Image_ID_bis{
    char ID_image_bis[1000000];
}Image_ID_bis;          //stock l'id de l'image dans la structure

typedef struct Image_ID_bisbis{
    char ID_image_bisbis[10000000];
}Image_ID_bisbis;       //stock le mnom de l'image dans la structure

typedef struct Image_ID_bisbisbis{
    char ID_image_bisbisbis[1000000];
}Image_ID_bisbisbis;        //structure qui sert de re stockage pour la concatenation

typedef struct Image_ID_bisbisbis_lien{
    char ID_image_bisbisbis_lien[10000000];
}Image_ID_bisbisbis_lien;       //si l'id,l'image et le lien correspondent, on met tout dans cette structure afin de l'afficher via conclusion
#endif // STRUCTURE_H_INCLUDED
