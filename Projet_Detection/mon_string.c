#include <stdio.h>
#include <stdlib.h>

int strlen_iter(char *str_source){          //fonction qui recuperer la longueur de la source
    int add = 0;
    while(str_source[add] != '\0'){
        add++;
    }
    //printf("affiche taille focntion %d\n",add);
    return add;
}           //fonction qui recuperer la longueur de la source

int est_dans_iter(char *chai, char *cher){      //renvoie la case du mot cherché dans la source
    int len = strlen_iter(chai);
    int add = 0;
    int add2 = 0;
    while( add != len){
        if(chai[add] == cher[add2]){
            add++;
            add2++;
            if(cher[add2] =='\0'){
                //printf("cela s'y trouve\n");
                return add;
            }
        }
        else{
            add++;
            add2 = 0;
        }
    }
    //printf("cela ne s'y trouve pas\n");
    return -1;
}           //renvoie la case du mot cherché dans la source

int est_dans_iter_nb(char *chai, char *cher){           //renvoie le nombre de fois du mot se trouvant dans la source
    int len = strlen_iter(chai);
    int add = 0;
    int add2 = 0;
    int add3 = 0;
    while( add < len){
        if(chai[add] == cher[add2]){
            add++;
            add2++;
            if(cher[add2] =='\0'){
                //printf("cela s'y trouve\n");
                add3++;
                //printf("--> %d\n",add3);
            }
        }
        else{
            add++;
            add2 = 0;
        }
    }
    //printf("cela ne s'y trouve pas\n");
    return add3;
}        //renvoie le nombre de fois du mot se trouvant dans la source

char * get_ligne(FILE * fp){                    //permet d'avoir tous les caracteres meme les whitespace d'un ficheir
    /* Open the file for reading */
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;

    /* Get the first line of the file. */
    line_size = getline(&line_buf, &line_buf_size, fp);
    line_size = getline(&line_buf, &line_buf_size, fp);
    //printf("pas ici : %s",line_buf);
    return line_buf;
    free(line_buf);

}                           //permet d'avoir tous les caracteres meme les whitespace d'un ficheir

int isspace(int c){                     //c'etait pour eviter les espaces blanc, mais pas utilisé, on remplacé les espaces blancs par des underscord _
    return ((c == ' ') || (c == '\n') || (c == '\t'));
}                                   //c'etait pour eviter les espaces blanc, mais pas utilisé, on remplacé les espaces blancs par des underscord _

int isunderscore(int c){                            //remplacer les underscore _ par des espaces pour revenir a l'affichage
    return (c == '_');
}                               //remplacer les underscore _ par des espaces pour revenir a l'affichage

int atoi (const char *nptr){                        //rendre un nombre string en int
    return (int) strtol (nptr, (char **) NULL, 10);
}                           //rendre un nombre string en int