#ifndef MON_STRING_H_INCLUDED
#define MON_STRING_H_INCLUDED

int strlen_iter(char *str_source);
int est_dans_iter(char *chai, char *cher);
int est_dans_iter_nb(char *chai, char *cher);
char * get_ligne(FILE * fp);
int isspace(int c);
int isunderscore(int c);
int atoi (const char *nptr);


#endif // MON_STRING_H_INCLUDED
