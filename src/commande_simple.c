#include "commande_simple.h"

void gestion_commande_simple(char *rep){

    char * argv[] = {rep,NULL};
    execvp(argv[0],argv);
    perror("execvp");
}
