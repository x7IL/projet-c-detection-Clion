#include "structure.h"
#include <stdio.h>
#include <stdlib.h>

/* Partie personnelle pour les debogages
 *
 *
 *
 */
void affichage_core(information *tab){
    if(tab->titre[0] == '\0'){
        printf("Titre                       : pas de données\n");
    }
    else{
        printf("Titre                       : %s\n",tab->titre);
    }
    if(tab->sujet[0] == '\0'){
        printf("Sujet                       : pas de données\n");
    }
    else{
        printf("Sujet                       : %s\n",tab->sujet);
    }
    if(tab->creator[0] == '\0'){
        printf("Créateur                    : pas de données\n");
    }
    else{
        printf("Créateur                    : %s\n",tab->creator);
    }
    if(tab->descriptions[0] == '\0'){
        printf("Descriptions                : pas de données\n");
    }
    else{
        printf("Descriptions                : %s\n",tab->descriptions);
    }
    if(tab->dernier[0] == '\0'){
        printf("Dernier ayant modifié       : pas de données\n");
    }
    else{
        printf("Dernier ayant modifie2      : %s\n",tab->dernier);
    }
    if(tab->revisions[0] == '\0'){
        printf("Nombre de revisions         : pas de données\n");
    }
    else{
        printf("Nombre de revisoins         : %s\n",tab->revisions);
    }
    if(tab->creation[0] == '\0'){
        printf("Création du doc             : pas de données\n");
    }
    else{
        printf("Création du doc             : %s\n",tab->creation);
    }
    if(tab->modification[0] == '\0'){
        printf("Derniere modification       : pas de données\n");
    }
    else{
        printf("Derniere modification       : %s\n",tab->modification);
    }
    if(tab->categorie[0] == '\0'){
        printf("Categorie                   : pas de données\n");
    }
    else{
        printf("Categorie                   : %s\n",tab->categorie);
    }
    if(tab->langue[0] == '\0'){
        printf("Langue                      : pas de données\n");
    }
    else{
        printf("Langue                      : %s\n",tab->langue);
    }

}

void affichage_app(information *tab){
    if(tab->templatee[0] == '\0'){
        printf("Template                    : pas de données\n");
    }
    else{
        printf("Template                    : %s\n",tab->templatee);
    }
    if(tab->totaltime[0] == '\0'){
        printf("Nombre de fois ouvert       : pas de données\n");
    }
    else{
        printf("Nombre de fois ouvert       : %s\n",tab->totaltime);
    }
    if(tab->pages[0] == '\0'){
        printf("Pages                       : pas de données\n");
    }
    else{
        printf("Pages                       : %s\n",tab->pages);
    }
    if(tab->word[0] == '\0'){
        printf("Mots                        : pas de données\n");
    }
    else{
        printf("Mots                        : %s\n",tab->word);
    }
    if(tab->charactere[0] == '\0'){
        printf("Caractere                   : pas de données\n");
    }
    else{
        printf("Caractere                   : %s\n",tab->charactere);
    }
    if(tab->application[0] == '\0'){
        printf("Applications                : pas de données\n");
    }
    else{
        printf("Applications                : %s\n",tab->application);
    }
    if(tab->docsecurity[0] == '\0'){
        printf("Docsecurity                 : pas de données\n");
    }
    else{
        printf("Docsecurity                 : %s\n",tab->docsecurity);
    }
    if(tab->lignes[0] == '\0'){
        printf("lignes                      : pas de données\n");
    }
    else{
        printf("lignes                      : %s\n",tab->lignes);
    }
    if(tab->paragraphe[0] == '\0'){
        printf("Paragraphe                  : pas de données\n");
    }
    else{
        printf("Paragraphe                  : %s\n",tab->paragraphe);
    }
    if(tab->scalecrop[0] == '\0'){
        printf("Scalecrop                   : pas de données\n");
    }
    else{
        printf("Echelle                     : %s\n",tab->scalecrop);
    }
    if(tab->manager[0] == '\0'){
        printf("Manager                     : pas de données\n");
    }
    else{
        printf("Manager                     : %s\n",tab->word);
    }
    if(tab->company[0] == '\0'){
        printf("Compagnie                   : pas de données\n");
    }
    else{
        printf("Compagnie                   : %s\n",tab->company);
    }
    if(tab->liensupdate[0] == '\0'){
        printf("Liens update                : pas de données\n");
    }
    else{
        printf("Liens update                : %s\n",tab->liensupdate);
    }
    if(tab->espace[0] == '\0'){
        printf("Nombre d'espaces            : pas de données\n");
    }
    else{
        printf("Nombre d'espaces            : %s\n",tab->espace);
    }
    if(tab->share_doc[0] == '\0'){
        printf("fichier sur share_doc       : pas de données\n");
    }
    else{
        printf("fichier sur share_doc       : %s\n",tab->share_doc);
    }
    if(tab->lienbase[0] == '\0'){
        printf("Lien de base                : pas de données\n");
    }
    else{
        printf("Lien de base                : %s\n",tab->lienbase);
    }
    if(tab->lienchange[0] == '\0'){
        printf("Lien changé                 : pas de données\n");
    }
    else{
        printf("Lien changé                 : %s\n",tab->lienchange);
    }
    if(tab->version[0] == '\0'){
        printf("version                     : pas de données\n");
    }
    else{
        printf("version                     : %s\n",tab->version);
    }

}

void affichage_police(police *tab, int n){
    int i;
    printf("Voici les polices du word:\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].nom);
    }
}

void affichage_id_test(id *tab, int n){         //ici ca marche
    int i = 0;
    printf("Voici les id hyperliens :\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID);
    }
}

void affichage_nom_id_test(nom_id *tab, int n){
    int i;
    printf("Voici les noms des liens visible :\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID_nom);
    }
}

void affichage_nom_id_bis_test(nom_id_bis *tab, int n){
    int i = 0;
    printf("Voici les noms des liens visible :\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID_nom_bis);
    }
}

void affichage_image_id_bis(Image_ID_bis  *tab, int n){
    int i;
    printf("Voici les image/id se trouvant dans le Document.xml.rels\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID_image_bis);
    }
}

void affichage_image_id(Image_ID *tab, int n){
    int i;
    printf("Voici les ID se trouvant dans le Document.xml.rels\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID_image);
    }
}

void affichage_image_id_nom_bisbis(Image_ID_bisbis *tab, int n){
    int i;
    printf("Voici les ID se trouvant dans le Document.xml.rels\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID_image_bisbis);
    }
}

void affichage_image_id_nom_bisbisbis(Image_ID_bisbisbis *tab, int n){
    int i;
    printf("Voici les ID se trouvant dans le Document.xml.rels\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID_image_bisbisbis);
    }
}

void affichage_image_id_nom_bisbisbis_lien(Image_ID_bisbisbis_lien *tab, int n){
    int i;
    printf("Voici les ID se trouvant dans le Document.xml.rels\n");
    for(i=0;i<n;i++){
        printf("    -%s\n",tab[i].ID_image_bisbisbis_lien);
    }
}
