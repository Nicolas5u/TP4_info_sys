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

int arguments(char *rep){
      int nbr_argu = 0;
      const char * separateur = " ,.-!";
      char * mots = strtok (rep, separateur);
      while (mots != NULL){
          printf("%s\n",mots);
          mots = strtok (rep, separateur);
          nbr_argu ++;
      }
      return nbr_argu;
}
