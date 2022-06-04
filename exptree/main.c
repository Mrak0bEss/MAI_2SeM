#include "func.h"
int main()
{
    struct Node *n;
    char *s;
   // int i=0;
    
    while(true)
    {
     // i=0;
     // int *b = &i;
    printf("Enter expression ( W - for exit): ");
    s=getString();
    if(*s=='W')
    {
      break;
    }
    n=makeTreeFromExpression(s);
    print(n);
    free(s);
    printf("\n");
    destroyTree(n);
    }
  
  //3^2--->9
}