#include "commande_simple.h"
// main du projet TP4 d'infomatique système

int main(){
  char rep[255];
  
  /*
  char * buffer = (char*) malloc(sizeof(rep));
  */
  
  while (strcmp(rep, "exit") != 0){
  
      printf ("interpréteur-de-commande-de-Nicolas$ ");
      
      // on récupère ce qui a été envoyé
      fgets(rep, sizeof(rep), stdin);
      
      // on enlève l'élément \0 qui était l'avant dernier élément du char
      char * pos_pb = strchr(rep,'\n');
      * pos_pb = '\0';
      
      if (strcmp(rep, "exit") == 0){
      printf ("tu as tapé exit pour sortir de l'interpréteur de commande de Nicolas\n ");
      return 0;
      }
  
      pid_t enfant_pid = fork();
      
      if (enfant_pid == -1){
          perror("fork");
          return 1;
      }
      
      if (enfant_pid == 0){
          // gestion des commandes simples
          gestion_commande_simple(rep);
          return 1;
      }else{
          waitpid(enfant_pid,NULL,0);
      }
      
      
  }
  
  
  
  
  return 0;
}
