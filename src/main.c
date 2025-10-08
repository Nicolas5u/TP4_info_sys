#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// main du projet TP4llll

int main(){
  char rep[255];
  printf ("interpréteur-de-commande-de-Nicolas$ ");
  
  /*
  char * buffer = (char*) malloc(sizeof(rep));
  */
  
  fgets(rep, sizeof(rep), stdin);
  // on enlève l'élément \0 qui était l'avant dernier élément du char
  char * pos_pb = strchr(rep,'\n');
  * pos_pb = '\0';
  
  if (strcmp(rep, "exit") == 0){
      printf ("tu as tapé exit pour sortir de l'interpréteur de commande de Nicolas\n ");
      return 1;
  }
  
  char * argv[] = {rep,NULL};
  execvp(argv[0],argv);
  perror("execvp");
  
  return 1;
}
