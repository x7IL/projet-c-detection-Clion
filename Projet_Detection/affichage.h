#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

void affichage_core(information *tab);
void affichage_app(information *tab);
void affichage_police(police *tab, int n);
void affichage_id_test(id *tab, int n);
void affichage_nom_id_test(nom_id *tab, int n);
void affichage_nom_id_bis_test(nom_id_bis *tab, int n);
void affichage_image_id_bis(Image_ID_bis  *tab, int n);
void affichage_image_id(Image_ID *tab, int n);
void affichage_image_id_nom_bisbis(Image_ID_bisbis *tab, int n);
void affichage_image_id_nom_bisbisbis(Image_ID_bisbisbis *tab, int n);
void affichage_image_id_nom_bisbisbis_lien(Image_ID_bisbisbis_lien *tab, int n);

#endif // AFFICHAGE_H_INCLUDED
