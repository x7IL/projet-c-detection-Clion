#include<stdlib.h>
#include<stdio.h>
#include "structure.h"
#include "creation_infos.h"
#include "crea_struct.h"
#include "affichage.h"
#include "mon_string.h"


/*

                Projet Bachelor CyberSecurite année 2022-2023
                Commentaire commenté par William Xu
                Le code a été codé par William XU soutenu par les recherches de Jules Boissel.
                Une presentation du code par l'auteur est preferable.


*/

//ce script nous permet de compresser le fichier word et de le decompresser, a fin d'acceder aux fichiers XML
#define SHELLSCRIPT "\
#!/bin/bash                             \n\
#pwd                                    \n\
echo \"Copie du fichier\"               \n\
file_doc=`ls *.docx *.dotm`              \n\
for i in $file_doc                      \n\
    do                                      \n\
        cp $i general.zip                       \n\
    done                                    \n\
echo \"copie terminé\"                  \n\
unzip general.zip -d general\
"
//Script fonction personnelle, a fin supprimer les fichiers créé plus rapidement
#define SHELLSCRIPT2 "\
#!/bin/bash   \n\
cd .\.\   \n\
cd \Projet_C\n\
rm -Rf general.zip\n\
rm -Rf general\n\
"
//Script qui change la place des fichiers lié au VBA dans le dfichier Sortie_VBA. a fin de montrer a l';utilisateur
#define SHELLSCRIPT_VBA"\
#!/bin/bash \n\
#pwd \n\
mv general/word/_rels/vbaProject.bin.rels Sorti_VBA/ \n\
mv general/word/vbaData.xml Sorti_VBA \n\
mv general/word/vbaProject.bin Sorti_VBA \n\
cd Sorti_VBA \n\
ls -a \n\
"

//a fin de transformer les fichiers xml en un Word .docx, apres la supprimation des macros
#define SHELLSCRIPT_WORD"\
#!/bin/bash \n\
cd general \n\
zip -r Fichier_Securise * \n\
cp Fichier_Securise.zip Fichier_Securise.docx\n\
"

int main(){
    // Si le programme a ete lancé, il faut supprimer mannuellement les fichiers creer par le programme etc
    //system(SHELLSCRIPT);



    //fonction a utilite personnel, pour supprimer les fichiers creer plus rapidement
    //system(SHELLSCRIPT2);
    FILE *fichier3  = fopen("les_tetes.txt", "r"); // read only         //Fichier ayant les Balises pour trouver et recuperer les metadatas de type App.xml
    FILE *fichier4  = fopen("les_tetes2.txt", "r"); // read only        //Fichier ayant les Balises pour trouver et recuperer les metadatas de type Core.xml
    FILE *fichier5  = fopen("general/word/fontTable.xml", "r"); // read only        //Fichier a fin de recuperer la metadata des polices.
    //Partie 1

    information *tab;           //initialise la structure a fin de recuperer les metadatas App.xml et Core.xml
    tab = creer_info();         //Methode vu en cours a fin de creer le tableau

    //on recupere les données
    get_info_core(tab,"general/docProps/core.xml",fichier3);
    get_info_app(tab,"general/docProps/app.xml",fichier4);
    //c'est la meme chose pour les polices

    police *tab2;
    tab2 = creer_info_police(get_nombre_police());
    get_info_police(tab2,"general/word/fontTable.xml");

    //apres la recuperation des donnees, on affiche tout cela via aux fonctions affichage se trouvant dans affichage.h
    affichage_police(tab2,get_nombre_police(fichier5));
    affichage_core(tab);
    affichage_app(tab);


    if ( test_vba()>=1){        //test_vba est ecrit de facona  savoir si il y a une macro ou non. si elle renvoi 1 alors oui, 0 == non
         suppVBA();
         printf("Sorti de la macro\n");
         system(SHELLSCRIPT_VBA);
         printf("Preparation du fichier sécurisé\n");
         system(SHELLSCRIPT_WORD);
         printf("Fichier créer\n");
    }

    if (get_id_nombre()>0){         //get_id_nombre me permet d'avoir le nombre de liens present dans le word via les ID "rId"+numero
        /* 1) focntion Initilisation de la variable qui va servir de tableau                //1
         * 2) fonction On creer le tableau et on le met dans la variable                    //2
         * 3) Recuperation des donnees, puis mis automatiquement dans le tab/structure      //3
         * */


        //on creer une struct qui stock les id des liens. Dans le fichier word/document.xml
        id *tab3;       //1
        tab3 = creer_id_stock(get_id_nombre());         //2
        met_id_struct(tab3);            //3

        //on creer une struct qui stock les noms visible des liens. Dans le fichier word/document.xml
        nom_id *tab4;       //1
        tab4 = creer_nom_id_stock(get_id_nombre());     //2
        met_nom_id_struct(tab4);        //3

        //on creer une struct qui stock le lien arriere du lien hypertext. Dans le fichier word/_rels/document.xml.rels
        nom_id_bis *tab5;       //1
        tab5 = creer_nom_id_bis_stock(get_id_nombre());     //2

        //Fonction qui differencie les hyperliens sans modifications et ceux où le nom visible a ete modifié. et le met directement dans la structure tab5
        verifi(tab4,tab3,tab5);     //3

        //Fonction qui compare si le lienhypertexte est bien le meme, qu'il n'y a pas eu d'obfuscation
        comparaison(tab4,tab5);


        //fonction d'affichage, utilité debogage
        //affichage_id_test(tab3,get_id_nombre());            //affiche les id trouve
        //affichage_nom_id_test(tab4,get_id_nombre());        //affiche les noms des hyperliens visible
        //affichage_nom_id_bis_test(tab5,get_id_nombre());    //affiche le lien qui s'y cache
    }

    if (get_nombre_embed()>0){      //fonction qui nous renvoi 1 ou 0 si il y a des images d'ou on a caché le lien
        /* 1) focntion Initilisation de la variable qui va servir de tableau
         * 2) fonction On creer le tableau et on le met dans la variable
         * 3) Recuperation des donnees, puis mis automatiquement dans le tab/structure
         * */

        embed *tab6;        //1
        tab6 = creer_embed_stock(get_nombre_embed());       //2
        get_embed(tab6);            //3
        //printf("ici?\n");

        Image_ID *tab7;         //1
        tab7 = creer_image_id_stock(get_image_id_nombre());     //2
        //printf("taille image%d\n",get_image_id());
        get_id_image(tab7);         //3

        Image_ID_bis *tab8;         //1
        tab8 = creer_image_id_stock_bis(get_target_image_nombre());         //2
        //printf("compteur %d\n",get_target_image_nombre());
        get_target_image(tab8);     //3


        Image_ID_bisbis  *tab9;         //1
        tab9 = creer_image_id_stock_bisbis(get_target_image_nombre());          //2
        get_target_image_bis(tab9);         //3


        //char wrrd[] = "rId6\"_Type=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships/image\"_Target=\"media/image1.png\"/><Relationship_Id=\"";
        //printf("longeur %d\n", strlen_iter(wrrd));
        Image_ID_bisbisbis  *tab10;         //1
        tab10 = creer_image_id_stock_bisbisbis(get_target_image_nombre());      //2
        //printf("test concatent\n");
        concatene(tab8,tab10);          //3
        //printf("test concatent\n");

        Image_ID_bisbisbis_lien *tab11;         //1
        tab11 = creer_image_id_stock_bisbisbis_lien(get_target_image_nombre());         //2
        verifi_lien(tab10,tab11);           //3


        conclusion(tab9,tab11);

        //apres la recuperation des donnees, on affiche tout cela via aux fonctions affichage se trouvant dans affichage.h
        //affichage_image_id(tab7,get_image_id_nombre());                     //affiche tous les Id du fichier Document.xml.rels
        //affichage_image_id_bis(tab8,get_target_image_nombre());               //---> afficher l'id de l'image
        //affichage_image_id_nom_bisbis(tab9,get_target_image_nombre());        //----> afficher le nom de l'image
        //affichage_image_id_nom_bisbisbis(tab10,get_target_image_nombre());        //afficher l'id du lien hypertexte de l'image, bug mais marche
        //affichage_image_id_nom_bisbisbis_lien(tab11,get_target_image_nombre());     //affiche le lien du lien hypertexte caché.
    }
    //printf("%d",get_nombre_embed());

    //on ferme les fichiers avec les balises (les_tetes.txt .. )
    fclose(fichier3);
    fclose(fichier4);
    //system(SHELLSCRIPT2);
    return EXIT_SUCCESS;
}
