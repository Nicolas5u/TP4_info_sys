#include "commande_simple.h"

void gestion_commande_simple(char *rep){

    char * argv[] = {rep,NULL};
    execvp(argv[0],argv);
    perror("execvp");
    return;
}

// on enlève l'élément \0 qui était l'avant dernier élément du char
void enleve_entree_commande(char *rep){
      char * pos_pb = strchr(rep,'\n');
      * pos_pb = '\0';
      return;
}
