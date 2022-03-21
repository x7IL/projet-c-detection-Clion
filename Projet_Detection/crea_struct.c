
#include <stdlib.h>
#include "structure.h"


//creer toutes les structures.

information *creer_info(){
    information *tab = malloc(sizeof(information)+1);
    tab->titre;
    tab->sujet;
    tab->creator;
    tab->descriptions;
    tab->dernier;
    tab->revisions;
    tab->creation;
    tab->modification;
    tab->categorie;
    tab->langue;
    tab->templatee;
    tab->totaltime;
    tab->pages;
    tab->word;
    tab->charactere;
    tab->application;
    tab->docsecurity;
    tab->lignes;
    tab->paragraphe;
    tab->scalecrop;
    tab->manager;
    tab->company;
    tab->liensupdate;
    tab->espace;
    tab->share_doc;
    tab->lienbase;
    tab->lienchange;
    tab->version;
    return tab;
}

police *creer_info_police(int n) {
    int i;
    police *tab = malloc(sizeof(police) * n + 1);
    for(i=0;i<=n;i++){
        tab[i].nom;
    }
    return tab;
}

id *creer_id_stock(int n){
    int i;
    id *tab = malloc(sizeof(id) * n + 1);
    for(i=0;i<n;i++){
        tab[i].ID;
    }
    return tab;
}

nom_id *creer_nom_id_stock(int n) {
    int i;
    nom_id *tab = malloc(sizeof(nom_id) * n + 1);
    for(i=0;i<n;i++){
        tab[i].ID_nom;
    }
    return tab;
}

nom_id_bis *creer_nom_id_bis_stock(int n) {
    int i;
    nom_id_bis *tab = malloc(sizeof(nom_id_bis) * n + 1);
    for(i=0;i<=n;i++){
        tab[i].ID_nom_bis;
    }
    return tab;
}

embed *creer_embed_stock(int n){
int i;
embed *tab = malloc(sizeof(embed)* n +1);
for (i=0;i<=n;i++){
    tab[i].Id_embed;
    }
    return tab;
}

Image_ID *creer_image_id_stock(int n){
    int i;
    Image_ID *tab = malloc(sizeof(Image_ID)* n +1);
    for (i=0;i<=n;i++){
        tab[i].ID_image;
    }
    return tab;
}

Image_ID_bis *creer_image_id_stock_bis(int n){
    int i;
    Image_ID_bis *tab = malloc(sizeof(Image_ID_bis)* n +1);
    for (i=0;i<=n;i++){
        tab[i].ID_image_bis;
    }
    return tab;
}

Image_ID_bisbis *creer_image_id_stock_bisbis(int n){
    int i;
    Image_ID_bisbis *tab = malloc(sizeof(Image_ID_bisbis)* n +1);
    for (i=0;i<=n;i++){
        tab[i].ID_image_bisbis;
    }
    return tab;
}

Image_ID_bisbisbis *creer_image_id_stock_bisbisbis(int n){
    int i;
    Image_ID_bisbisbis *tab = malloc(sizeof(Image_ID_bisbisbis)* n +1);
    for (i=0;i<=n;i++){
        tab[i].ID_image_bisbisbis;
    }
    return tab;
}

Image_ID_bisbisbis_lien *creer_image_id_stock_bisbisbis_lien(int n){
    int i;
    Image_ID_bisbisbis_lien *tab = malloc(sizeof(Image_ID_bisbisbis_lien)* n +1);
    for (i=0;i<=n;i++){
        tab[i].ID_image_bisbisbis_lien;
    }
    return tab;
}