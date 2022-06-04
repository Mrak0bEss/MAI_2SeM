#include "func .h"
int main()
{   
    int i;
    char c;
    struct Node* root = createTree();
    while(true)
    {
        scanf("%c", &c);
        if (c=='+'){
            scanf("%d", &i);
            root = insert(root, i);
        }
        if (c=='-'){
            scanf("%d", &i);
            root = Remove(root, i);
        }
        if (c=='p'){
            print(root);
            
        }
        if (c=='h'){
            printf("\n%d\n", Height(root));
            
        }
        if (c=='f'){
            break;
        }
        
    }
    
    
   // root = Remove(root, i);
   // system("pause");
}