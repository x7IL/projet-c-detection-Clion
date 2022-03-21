#ifndef CREATION_INFOS_H_INCLUDED
#define CREATION_INFOS_H_INCLUDED

char* read_file_ascii(const char* path);
void get_info_core(information *tab, const char* path1, FILE *fichier2);
void get_info_app(information *tab,const char* path1,FILE *fichier4);
int get_nombre_police();
void get_info_police(police *tab,const char* path1);
int get_id_nombre();
void met_id_struct(id *tab);
int get_nom_id_nombre();
void met_nom_id_struct(nom_id *tab);
void verifi(nom_id *tab,id * tab2,nom_id_bis *tab3);
void comparaison(nom_id *tab, nom_id_bis *tab2);
int get_nombre_embed();
void get_embed(embed* tab);
int get_image_id_nombre();
void get_target_image(Image_ID_bis *tab);
int get_target_image_nombre();
void get_id_image(Image_ID *tab);
void get_target_image_bis(Image_ID_bisbis *tab);
void concatene(Image_ID_bis *tab, Image_ID_bisbisbis *tab2);
void verifi_lien(Image_ID_bisbis *tab2,Image_ID_bisbisbis_lien *tab);
void conclusion(Image_ID_bisbis *tab, Image_ID_bisbisbis_lien *tab2);
void suppVBA();
int test_vba();
#endif // CREATION_INFOS_H_INCLUDED

