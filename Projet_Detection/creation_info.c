#include "structure.h"
#include "mon_string.h"
#include <stdio.h>
#include <stdlib.h>



/*les fonctions de recuperation reprennent le meme fonctionnement, j'ai alors seulement commenté le premier
 * les fonctions de comparaison reprennent aussi le meme fonctionnement.
 *
 */
char* read_file_ascii(const char* path){
    FILE*fp = fopen(path, "r");
    if (!fp){
        printf("Error loading file '%s'\n",path);
        return NULL;
    }

    fseek(fp,0,SEEK_END);
    int size = ftell(fp);
    fseek(fp,0,SEEK_SET);

    char*buf = malloc(sizeof(char)*(size + 1));
    fread(buf,sizeof(char),size,fp);
    fclose(fp);

    buf[size]='\0';
    return buf;
}           //code empreinté depuis un youtubeur, a fin de lire le contenu d'un fichier et de le mettre dans une variable

void get_info_core(information *tab, const char* path1, FILE *fichier2){
    //fonction qui recup les metadats core.xml
    int n = 0,k = 0;
    int j, i;
    char wrd[100];      //les noms de balise ne depasse pas 100 caracteres

    unsigned char *str = read_file_ascii(path1);        //met tout le fichier dans la variable str

    while(!feof(fichier2)) {            // on compare ligne par ligne
        fscanf(fichier2, " %[^\n]s\n", wrd);
        if(est_dans_iter(str,wrd)<0){       //petit test personnel
            //printf("cela ne s'y trouve pas\n");
        }
        else{
            for(j=0;j <= strlen_iter(str);j++) {        //boucle for de 0 a la longueur des caracteres selectionné.
                if (j>=est_dans_iter(str,wrd)){         //la focntion est_dans_iter -> renvoi la case du mot si elle se trouve dans str
                    if(str[j] != '<'){                             //si oui, on met tout ce qu'on peut tant que ne croise pas la balise de fermture '<'
                        //printf("%c",str[j]);
                        /*
                        if (isunderscore(str[j]))
                            str[j] = ' ';*/
                        if(n==0){
                            tab->titre[k] = str[j];
                        }
                        if(n==1){
                            tab->sujet[k] = str[j];
                        }
                        if(n==2){
                            tab->creator[k] = str[j];
                        }
                        if(n==3){
                            tab->descriptions[k] = str[j];
                        }
                        if(n==4){
                            tab->dernier[k] = str[j];
                        }
                        if(n==5){
                            tab->revisions[k] = str[j];
                        }
                        if(n==6){
                            tab->creation[k] = str[j];
                        }
                        if(n==7){
                            tab->modification[k] = str[j];
                        }
                        if(n==8){
                            tab->categorie[k] = str[j];
                        }
                        if(n==9){
                            tab->langue[k] = str[j];
                        }
                        k++;
                    }
                    else{
                        n++;
                        k = 0;
                        break;
                    }
                }
            }
            //printf("\n");
            //printf("%d\n",j);
        }
    }
    free(str);      // liberation de la place
}       //fonction qui recup les metadats core.xml

void get_info_app(information *tab,const char* path1,FILE *fichier4){       //fonction qui recup les metadats app.xml      //meme fonctionnement que get_info_core
    int n = 0,k = 0;
    int j, i;
    //unsigned char str[5000];
    char wrd[20];

    unsigned char *str = read_file_ascii(path1);        //on met tous les caracteres du fichier dans str
    /*
    while (str[i]) {
        if (isspace(str[i]))

            str[i] = '_';
        i++;
    }
    */
    while (!feof(fichier4)) {
        fscanf(fichier4, " %[^\n]s\n", wrd);
        if (est_dans_iter(str, wrd) < 0) {
            //printf("cela ne s'y trouve pas\n");
        } else {
            for (j = 0; j <= strlen_iter(str); j++) {
                if (j >= est_dans_iter(str, wrd)) {
                    if (str[j] != '<') {
                        //printf("%c",str[j]);
                        if (isunderscore(str[j]))
                            str[j] = ' ';

                        if (n == 0) {
                            tab->templatee[k] = str[j];
                        }
                        if (n == 1) {
                            tab->totaltime[k] = str[j];
                        }
                        if (n == 2) {
                            tab->pages[k] = str[j];
                        }
                        if (n == 3) {
                            tab->word[k] = str[j];
                        }
                        if (n == 4) {
                            tab->charactere[k] = str[j];
                        }
                        if (n == 5) {
                            tab->application[k] = str[j];
                        }
                        if (n == 6) {
                            tab->docsecurity[k] = str[j];
                        }
                        if (n == 7) {
                            tab->lignes[k] = str[j];
                        }
                        if (n == 8) {
                            tab->paragraphe[k] = str[j];
                        }
                        if (n == 9) {
                            tab->scalecrop[k] = str[j];
                        }
                        if (n == 10) {
                            tab->manager[k] = str[j];
                        }
                        if (n == 11) {
                            tab->company[k] = str[j];
                        }
                        if (n == 12) {
                            tab->liensupdate[k] = str[j];
                        }
                        if (n == 13) {
                            tab->espace[k] = str[j];
                        }
                        if (n == 14) {
                            tab->share_doc[k] = str[j];
                        }
                        if (n == 15) {
                            tab->lienbase[k] = str[j];
                        }
                        if (n == 16) {
                            tab->lienchange[k] = str[j];
                        }
                        if (n == 17) {
                            tab->version[k] = str[j];
                        }
                        k++;
                    } else {
                        n++;
                        k = 0;
                        break;
                    }
                }
            }
        }
    }
    free(str);
}       //fonction qui recup les metadats app.xml      //meme fonctionnement que get_info_core

int get_nombre_police(){            //renvoi le nombre de polices dans le fichier
    char wrd[] = "w:name=\"";

    unsigned char *str;
    FILE *fichier3  = fopen("general/word/fontTable.xml", "r");

    str= get_ligne(fichier3);       //get_ligne pris et modifié d'un code source, il recupere les caracteres du fichier et le met dans la var str
    //printf("-->%s\n",str);
    //printf("taille %d\n",strlen_iter(str));

    //printf("FDP %d\n",est_dans_iter_nb(str,wrd));
    fclose(fichier3);                   //on ferme le fichier ouvert

    return est_dans_iter_nb(str,wrd);           //est_dan_iter_nb nous renvoi el nombre de fois le mot cherché dans str

}           //renvoi le nombre de polices dans le fichier

void get_info_police(police *tab,const char* path1){        //fonction qui recupere les metadata du word/fontTable.xml      //meme fonctionnement que get info_core et get_info_app
    int l=0,k=0;
    int i,j;
    char wrd[] = "w:name=\"";
    int found;
    int p = 0;
    unsigned char *str = read_file_ascii(path1);

    //printf("\n");

    //printf("%s\n", strlen_iter(str));

    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                //break;
            }
        }

        // If word have been found then print found message
        if (found == 1) {
            //printf("'%s' found at index: %d \n", wrd, i);
            while(str[i+8+k]!='"'){
                //printf("%c",str[i+8+k]);
                 tab[p].nom[k] = str[i+8+k];
                 //printf("%c",tab[p].nom[k]);
                k++;
                l++;
            }
            //printf(" %s",tab[p].nom);
            k=0;
            l=0;
            p++;
        }
    }
    free(str);
}           //fonction qui recupere les metadata du word/fontTable.xml      //meme fonctionnement que get info_core et get_info_app

int get_id_nombre(){        //fonction qui renvoi le nombre d'id des liens trouvés dans le fichier Document.xml.rels

    //meme fonctionnement que get_nombre_police
    char wrd[] = "<w:hyperlink r:id=\"";

    unsigned char *str;
    FILE *fichier3  = fopen("general/word/document.xml", "r");


    str= get_ligne(fichier3);
    //printf("-->%s\n",str);
    //printf("taille %d\n",strlen_iter(str));

    //printf("FDP %d\n",est_dans_iter_nb(str,wrd));
    fclose(fichier3);

    return est_dans_iter_nb(str,wrd);
}              //fonction qui renvoi le nombre d'id des liens trouvés dans le fichier Document.xml.rels

void met_id_struct(id *tab){
    int i=0,j=0;
    char wrd[] = "<w:hyperlink r:id=\"";            //balise de comparaison
    int found = 0;
    int compteur = 0;
    int m=0;

    unsigned char *str = read_file_ascii("general/word/document.xml");          //on met tous les caracteres dans str
    //free(str);
    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {     //on fait une boucle for de 0 a longueur du fichier - longueur de la balise pour eviter le debordement
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {        //boucle qui va nous permettre de savoir si la suite de caractere et bien == a la balise
            // If word is not matched we just gonna crush you on a buche on fire
            if (str[i + j] != wrd[j]) {             //si le caractere correspond pas, on break et on passe au caractere i++
                found = 0;
                break;
            }
        }
        // If word have been found then print found message to ask my crush to be my wife
        if (found == 1) {               //si trouvé alors on creer une boucle qui va l'ajouter a la struct
            //printf("'%s' found at index: %d \n", wrd, i);
            while(str[i+m+19] !='"'){           // 19, la longueur de la balise
                //printf("%c",str[i+m+19]);               //<----------------------
                tab[compteur].ID[m] = str[i+m+19];
                m++;
            }
            //printf("test : %s\n",tab[compteur].ID);     //<----------------------
            m=0;
            printf("\n");
            compteur++;
        }
        found = 0;
    }
    free(str);

}           //fonction qui recup les id des liens et le met dans une struct

int get_nom_id_nombre(){            //fonction non utilisé, mais reprend le principe des fonctions get_nombre_police et get_id_nombre
    int i=0,j=0,k=0,m=0;
    char wrd[] = "<w:hyperlink r:id=\"";
    char wrd2[] = "<w:t>";
    int found, found2;
    int boolean = 0;
    int compteur = 1;

    unsigned char *str = read_file_ascii("general/word/document.xml");

    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                break;
            }
        }
        // If word have been found then print found message
        if (found == 1) {
            //printf("'%s' found at index: %d \n", wrd, i);
            boolean == 1;
            //printf("\n");
        }

        if (boolean == 1){
            found2 = 1;
            for (k = 0; k < strlen_iter(wrd2); k++) {
                // If word is not matched
                if (str[i + k] != wrd2[k]) {
                    found2 = 0;
                    break;
                }
            }
            if (found2 == 1) {
                //printf("'%s' found at index: %d \n", wrd2, i);

                //printf("\n");
                boolean = 0;
                compteur++;
                break;
            }
        }
    }
    free(str);
    //printf("pitié bug pas %d\n",compteur);
    return compteur;
}            //fonction non utilisé, mais reprend le principe des fonctions get_nombre_police et get_id_nombre

void met_nom_id_struct(nom_id *tab){            //fonction qui met le nom de l'hyperlien dans la struct     //meme fonctionnement que met_id_struct
    int i=0,j=0,k=0,m=0;
    char wrd[] = "<w:hyperlink r:id=\"";            //comparaison balise 1      si on trouve, alors on passe a la balise 2, puisqu'il y bcp trop de balise "<w:t>"
    char wrd2[] = "<w:t>";                          //comparaison balise 2
    int found, found2;
    int boolean = 0;
    int compteur = 0;

    unsigned char *str = read_file_ascii("general/word/document.xml");
    //free(str);

    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                break;
            }
        }
        if (boolean == 1){
            found2 = 1;
            for (k = 0; k < strlen_iter(wrd2); k++) {
                // If word is not matched
                //printf("%d - ",i);
                if (str[i + k] != wrd2[k]) {
                    found2 = 0;
                    break;
                }
            }

            if (found2 == 1) {
                //printf("'%s' found 2found at index: %d \n", wrd2, i);
                //printf("%d-",i);
                while(str[i+m+5] != '<'){
                    //printf("%c",str[i+m+5]);

                    tab[compteur].ID_nom[m] = str[i+m+5];
                    m++;
                }
                //printf("%s\n",tab[compteur].ID_nom);
                m=0;

                //printf("\n");
                boolean = 0;
                compteur++;

            }
        }
            // If word have been found then print found message
        else if(found == 1) {
            //printf("'%s' found 1found at index: %d \n", wrd, i);
            boolean = 1;
            //printf("\n");
        }

    }
    free(str);
}       //fonction qui met le nom de l'hyperlien dans la struct

void verifi(nom_id *tab,id * tab2,nom_id_bis *tab3){
    int i=0,j=0,k=0,m=0,p=0;
    //char wrd = "Relationship Id=\"";
    char wrd2[] = "Target=\"";          //target le lien caché dans le fichier Documents.xml.rels
    int found, found2;
    int boolean = 0;
    int compteur = 0;

    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");
    //printf("%p\n",str);
    //free(str);

    for(p=0;p<get_id_nombre();p++) {

        compteur=0;
        found2 = 1;
        found = 0;
        for (i = 0; i < strlen_iter(str) - strlen_iter(tab2[p].ID); i++) {
            // Match word at current position
            found = 1;
            for (j = 0; j < strlen_iter(tab2[p].ID); j++) {
                //printf("test1\n");
                // If word is not matched
                if (str[i + j] != tab2[p].ID[j]) {
                    //printf("test2\n");
                    found = 0;
                    break;
                }
            }
            if (boolean == 1) {
                found2 = 1;
                for (k = 0; k < strlen_iter(wrd2); k++) {
                    // If word is not matched
                    //printf("%d - ",i);
                    if (str[i + k] != wrd2[k]) {
                        found2 = 0;
                        break;
                    }
                }
                if (found2 == 1) {
                    //printf("'%s' found 2found at index: %d \n", wrd2, i);
                    //printf("%d-",i);
                    while (str[i + m + 8] != '"') {
                        //printf("%c",str[i+m+8]);
                        tab3[p].ID_nom_bis[m] =  str[i+m+8];

                        //tab[compteur].ID_nom[m] = str[i+m+5];
                        m++;
                    }
                    m = 0;
                    compteur++;
                    printf("\n");
                    boolean = 0;
                }
            }
                // If word have been found then print found message
            else if (found == 1) {
                //printf("'%s' found 1found at index: %d \n", tab2[p].ID, i);
                boolean = 1;
                //printf("\n");
            }
        }
    }
    //printf("%p\n",str);
    free(str);
    //printf("%p\n",str);
}           //fonction qui rajoute dans la nouvelle struct tab3, si l'id se trouve bien dans word/document.xml.rels

void comparaison(nom_id *tab, nom_id_bis *tab2){
    int i = 0,k = 0;
    int boolean = 0;
    int boolean2 = 0;


    for(i=0;i<get_id_nombre();i++){
        boolean = 0;
        for(k=0;k< strlen_iter(tab[i].ID_nom);k++){
            if(tab[i].ID_nom[k] == tab2[i].ID_nom_bis[k]){
                boolean = 1;
            }
            if(tab2[i].ID_nom_bis[k] == '\0'){
                boolean2 = 1;
                break;
            }
            else{
                boolean = 0;
            }
            if(boolean == 0){
                printf("Derriere \"%s\" nous retrouvons ce lien \"%s\"\n",tab[i].ID_nom,tab2[i].ID_nom_bis);
                printf("`\n");
                break;
            }
        }
        if(boolean == 1){
            printf("Ce lien \"%s\" n'est pas un lien caché\n",tab[i].ID_nom);
            printf("\n");
        }
        if(boolean2 == 1){
            printf("Ce lien \"%s\" n'est pas un lien caché\n",tab[i].ID_nom);
            printf("\n");
            boolean2 = 0;
        }
    }
}           //fonction qui verifie si le lien visible et la meme que celle caché. parametre 1 : lien visible, parametre 2: id, parametre 3: lien caché

int get_nombre_embed(){
    char wrd[]= "http://schemas.openxmlformats.org/officeDocument/2006/relationships/hyperlink\" Target=\"";

    unsigned char *str;

    str = read_file_ascii("general/word/_rels/document.xml.rels");
    //printf("taille %d\n",strlen_iter(str));

    return est_dans_iter_nb(str,wrd);

}                           // renvoi le nombre 1 si des liens se trouve dans les images et 0 pour non

void get_embed(embed* tab){             //met le lien caché dans l'image dans la structure
    char wrd[]= "http://schemas.openxmlformats.org/officeDocument/2006/relationships/hyperlink\" Target=\"";

    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");

    int found;
    int compteur = 0;
    int i,p,j,m=0;

    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                break;
            }
        }
        // If word have been found then print found message
        if (found == 1) {
            //printf("'%s' found at index: %d \n", wrd, i);
            while(str[i+m+87] !='"'){           //87 longueur de la balise
                //printf("%c",str[i+m+87]);               //<----------------------
                tab[compteur].Id_embed[m] = str[i+m+87];
                m++;
            }
            //printf("test : %s\n",tab[compteur].ID);     //<----------------------
            m=0;
            //printf("\n");
            compteur++;
        }
        found = 0;
    }
    free(str);
}       //met le nom de l'image dans la structure

int get_image_id_nombre(){
    char wrd[]= "<Relationship Id=\"";

    unsigned char *str;

    str = read_file_ascii("general/word/_rels/document.xml.rels");
    //printf("taille %d\n",strlen_iter(str));

    return est_dans_iter_nb(str,wrd);

}           //renvoi le nombre d'ID de liens

void get_id_image(Image_ID *tab){       //recupere tous les id du fichier dans la structure
    int i=0,j=0;
    char wrd[] = "<Relationship Id=\"";
    int found = 0;
    int compteur = 0;
    int m=0;

    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");
    //free(str);
    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                break;
            }
        }
        // If word have been found then print found message
        if (found == 1) {
            //printf("'%s' found at index: %d \n", wrd, i);
            while(str[i+m+18] !='"'){
                //printf("%c",str[i+m+18]);               //<----------------------
                tab[compteur].ID_image[m] = str[i+m+18];
                m++;
            }
            //printf("test : %s\n",tab[compteur].ID);     //<----------------------
            m=0;
            //printf("\n");
            compteur++;
        }
        found = 0;
    }
    free(str);

}       //recupere le nom de l'id dans la structure

void get_target_image(Image_ID_bis *tab){       //met l'ID de l'image dans la structure
    int i=0,j=0,k=0,m=0,jil=0;
    char wrd2[] = "<Relationship Id=\"";
    char wrd[] = "Target=\"media/";
    int found, found2;
    int boolean = 0;
    int compteur = 0;
    int compteur2 = 0;

    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");
    //free(str);

    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                break;
            }
        }
        if (boolean == 1){
            found2 = 1;
            for (k = 0; k < strlen_iter(wrd2); k++) {
                // If word is not matched
                //printf("%d - ",i);
                if (str[i + k] != wrd2[k]) {
                    found2 = 0;
                    break;
                }
            }

            if (found2 == 1) {
                //printf("'%s' found 2found at index: %d \n", wrd2, i);
                //printf("%d-",i);
                while(str[i+m+18-132] != '"'){      //123 nombre de caracteres de  char wrrd[] = "rId6\"_Type=\"http://schemas.openxmlformats.org/officeDocument/2006/relationships/image\"_Target=\"media/image1.png\"/><Relationship_Id=\"";
                    //printf("%c",str[i+m+8]);

                    tab[compteur].ID_image_bis[m] = str[i+m+18-132];
                    m++;
                }
                //printf("%s\n",tab[compteur].ID_nom);
                m=0;

                //printf("\n");
                boolean = 0;
                compteur++;

            }
        }
            // If word have been found then print found message
        else if(found == 1) {
            //printf("'%s' found 1found at index: %d \n", wrd, i);
            compteur2 ++;

            //printf("l'id lié a l'image %s\n",wrd);
            boolean = 1;
            //printf("\n");
        }

    }
    free(str);
}       //met le nom de l'image dans la structure

int get_target_image_nombre(){          //renvoi le nombre d'image
    int i=0,j=0,k=0,m=0;
    char wrd[] = "<Relationship Id=\"";
    char wrd2[] = "Target=\"media/";
    int found, found2;
    int boolean = 0;
    int compteur = 0;

    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");
    //free(str);

    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                break;
            }
        }
        if (boolean == 1){
            found2 = 1;
            for (k = 0; k < strlen_iter(wrd2); k++) {
                // If word is not matched
                //printf("%d - ",i);
                if (str[i + k] != wrd2[k]) {
                    found2 = 0;
                    break;
                }
            }

            if (found2 == 1) {
                //printf("'%s' found 2found at index: %d \n", wrd2, i);
                //printf("%d-",i);
                while(str[i+m+8] != '"'){
                    //printf("%c",str[i+m+8]);

                    //tab[compteur].ID_image_bis[m] = str[i+m+8];
                    m++;
                }
                //printf("%s\n",tab[compteur].ID_nom);
                m=0;

                //printf("\n");
                boolean = 0;
                compteur++;

            }
        }
            // If word have been found then print found message
        else if(found == 1) {
            //printf("'%s' found 1found at index: %d \n", wrd, i);
            boolean = 1;
            //printf("\n");
        }

    }
    free(str);
    return compteur;
}           //renvoi le nombre d'image

void get_target_image_bis(Image_ID_bisbis *tab){        //stock le nom de l'image dans la structure
    int i=0,j=0,k=0,m=0,jil=0;
    char wrd[] = "<Relationship Id=\"";
    char wrd2[] = "Target=\"media/";
    int found, found2;
    int boolean = 0;
    int compteur = 0;

    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");
    //free(str);

    for (i = 0; i < strlen_iter(str) - strlen_iter(wrd); i++) {
        // Match word at current position
        found = 1;
        for (j = 0; j < strlen_iter(wrd); j++) {
            // If word is not matched
            if (str[i + j] != wrd[j]) {
                found = 0;
                break;
            }
        }
        if (boolean == 1){
            found2 = 1;
            for (k = 0; k < strlen_iter(wrd2); k++) {
                // If word is not matched
                //printf("%d - ",i);
                if (str[i + k] != wrd2[k]) {
                    found2 = 0;
                    break;
                }
            }

            if (found2 == 1) {
                //printf("'%s' found 2found at index: %d \n", wrd2, i);
                //printf("%d-",i);
                while(str[i+m+14] != '"'){
                    //printf("%c",str[i+m+8]);

                    tab[compteur].ID_image_bisbis[m] = str[i+m+14];
                    m++;
                }
                //printf("%s\n",tab[compteur].ID_nom);
                m=0;

                //printf("\n");
                boolean = 0;
                compteur++;

            }
        }
            // If word have been found then print found message
        else if(found == 1) {
            //printf("'%s' found 1found at index: %d \n", wrd, i);

            //printf("l'id lié a l'image %s\n",wrd);
            boolean = 1;
            //printf("\n");
        }

    }
    free(str);
}       //stock le nom de l'image dans la structure

void concatene(Image_ID_bis *tab, Image_ID_bisbisbis *tab2){  //focntion decrementeur d'un string par ex = rId10, on veut rId9, on met 10 dans la fonction et elle nosu retourne 9
    int i,j;
    int jil=0;
    int boolean = 0;
    char test[3];
    for(i=0;i<get_target_image_nombre();i++){
        boolean = 0;
        //printf("--> %d\n",strlen_iter(tab[i].ID_image_bis));          //---> 4 test Jil.dotm
        for(j=0;j< strlen_iter(tab[i].ID_image_bis);j++) {
            if(j>1){        //si le carctere apres "rd" est >1, pas de probleme
                tab2[i].ID_image_bisbisbis[j] = tab[i].ID_image_bis[j];
                test[jil] = tab[i].ID_image_bis[j];
                //printf("%c",test[jil]);
                jil++;
                boolean = 1;            //pour eviter la derniere condition if
                //printf("%s\n",tab2[i].ID_image_bisbisbis);
            }
            else {         // sinon on entre dans le cas de 10-1 = 00 aulieu de 9
                tab2[i].ID_image_bisbisbis[j] = tab[i].ID_image_bis[j];
                //printf("%c", tab2[i].ID_image_bisbisbis[j]);
            }
            if(boolean == 1 && j <strlen_iter(tab[i].ID_image_bis)){

                tab2[i].ID_image_bisbisbis[j] = (atoi(test)-1);

            }
        }
        //printf("\n");
        //printf("\n-->%s\n",tab2[0].ID_image_bisbisbis);
        //printf("\nDMR\n");
        //printf("\n%s",tab[i].ID_image_bis);
        //printf("\n");
    }
}       //focntion decrementeur d'un string par ex = rId10, on veut rId9, on met 10 dans la fonction et elle nosu retourne 9

void verifi_lien(Image_ID_bisbis *tab2,Image_ID_bisbisbis_lien *tab){       //l'ajoute des id/nom d'image/lien sont dans l'odre
                                                                            //alors on verifi si l'id correspond bien au lien
    int i=0,j=0,k=0,m=0,p=0;
    //char wrd = "Relationship Id=\"";
    char wrd2[] = "Target=\"";
    int found, found2;
    int boolean = 0;
    int compteur = 0;

    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");
    //printf("%p\n",str);
    //free(str);
    for(p=0;p<get_target_image_nombre();p++) {

        compteur=0;
        found2 = 1;
        found = 0;
        for (i = 0; i < strlen_iter(str) - strlen_iter(tab2[p].ID_image_bisbis); i++) {
            // Match word at current position
            found = 1;
            for (j = 0; j < strlen_iter(tab2[p].ID_image_bisbis); j++) {
                //printf("test1\n");
                // If word is not matched
                if (str[i + j] != tab2[p].ID_image_bisbis[j]) {
                    //printf("test2\n");
                    found = 0;
                    break;
                }
            }
            if (boolean == 1) {
                found2 = 1;
                for (k = 0; k < strlen_iter(wrd2); k++) {
                    // If word is not matched
                    //printf("%d - ",i);
                    if (str[i + k] != wrd2[k]) {
                        found2 = 0;
                        break;
                    }
                }
                if (found2 == 1) {
                    //printf("'%s' found 2found at index: %d \n", wrd2, i);
                    //printf("%d-",i);
                    while (str[i + m + 8] != '"') {
                        //printf("%c",str[i+m+8]);
                        tab[p].ID_image_bisbisbis_lien[m] =  str[i+m+8];

                        //tab[compteur].ID_nom[m] = str[i+m+5];
                        m++;
                    }
                    m = 0;
                    compteur++;
                    //printf("\n");
                    boolean = 0;
                }
            }
                // If word have been found then print found message
            else if (found == 1) {
                //printf("'%s' found 1found at index: %d \n", tab2[p].ID_image_bisbis, i);
                boolean = 1;
                //printf("\n");
            }
        }
    }
    //printf("%p\n",str);
    free(str);
    //printf("%p\n",str);
}       //l'ajoute des id/nom d'image/lien sont dans l'odre
                                                                                //alors on verifi si l'id correspond bien au lien
void conclusion(Image_ID_bisbis *tab, Image_ID_bisbisbis_lien *tab2){   //affichage, pr nous dire ce qu'il y a dans tel image etc. je voulais faire une interface graphique pour mieux alerter l;utilisateur mais par manque de temps je n'ai aps pu
    int i;
    for(i=0;i<get_target_image_nombre();i++){
        printf("l'image : %s = %s\n",tab[i].ID_image_bisbis,tab2[i].ID_image_bisbisbis_lien);
    }
    //system("mkdir resumer");
    //system("rm -R resumer");

}       //affichage, pr nous dire ce qu'il y a dans tel image etc. je voulais faire une interface graphique pour mieux alerter l;utilisateur mais par manque de temps je n'ai aps pu

void suppVBA(){         //fonction qui supprime la macro
    //on a remarqué qu'en supprimant la balise de la macro (VBA) cela desactivait la macro puisque, cela envoyé le path vers le fichier vba
    int j=0;
    int i;
    unsigned char *str = read_file_ascii("general/word/_rels/document.xml.rels");
    char str2[1000000];
    char wrd[] = "<Relationship Id=\"rId1\" Type=\"http://schemas.microsoft.com/office/2006/relationships/vbaProject\" Target=\"vbaProject.bin\"/>";        //balise
    //printf("%d\n", strlen_iter(str));
    //printf("%d\n", est_dans_iter(str,wrd));     //342 //122 // 464
    //removeAll(str,wrd);
    printf("Macro detected...\n");
    printf("Processing\n");

    for(i=0;i< strlen_iter(str);i++){

        //si i>=, cela veut dire qu'on est entrain de lire la balise, alors on incremente j, pour supprimer la case
        if(i>=(strlen_iter(str) - est_dans_iter(str,wrd)) -122 && j<122){       //tant que la i >= longueur des caracteres du fichier mis dans str   - a la derniere case de la balise     - sa longueur pour revenir au debut de la balise
            j++;
            //str2[i] = str[i];
            //printf("%c",str2[i]);
        }
        else{
            str2[i-j] = str[i];         //j represente le caractere a supprimer de la balise
            //printf("%c",str2[i-j]);
        }
    }
    //printf("\n%s",str2);
    //printf("\n%d", strlen_iter(str2));
    //printf("--> %s\n",str2);
    FILE *fichier2  = fopen("general/word/_rels/document.xml.rels", "w");
    fwrite(str2, 1, strlen_iter(str2), fichier2);           //apres avoir supp la balise, on re ecrit le fichier avec fwrite
    //printf("--> %s\n",str);
    printf("Macro has bee deleted\n");
    printf("No macro detected\n");
    fclose(fichier2);           //on ferme ke fichier ouvert
}           //fonction qui supprime la macro

int test_vba(){                 //fonction qui regarde si c'est un fichier avec macro ou pas
     char wrd[] = "<Relationship Id=\"rId1\" Type=\"http://schemas.microsoft.com/office/2006/relationships/vbaProject\" Target=\"vbaProject.bin\"/>";
     unsigned char * str  = read_file_ascii("general/word/_rels/document.xml.rels");
     return est_dans_iter(str,wrd);
}               //fonction qui regarde si c'est un fichier avec macro ou pas

