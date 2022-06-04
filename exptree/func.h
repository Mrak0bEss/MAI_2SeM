#include"stack.h"

struct Node
{
    char operation;
    unsigned value;
    struct Node* left;
    struct Node* right;
};

struct Node* createTree()
{
    struct Node* root = NULL;
    return root;
}
char *getString() // СТРОКА ЛЮБОЙ ДЛИННЫ
{
    int i=0;
    int cap = 1;
    char *s=(char*)malloc(sizeof(char));
    char c =getchar();
    while (c != '\n')
    {
        s[i++]=c;
        if(i >= cap){
            cap*=2;
            s=(char*)realloc(s,cap * sizeof(char));
        }
        c= getchar();
    }
    s[i++]='\0';
    return s;

}
bool isOperator(union Token tok)
{
    switch (tok.operation)
    {
    case '+': case '-' : case '*': case '/' :
        return true;
        break;
    default:
        return false;
        break;
    }

}
bool isLeftBracket(union Token tok)
{
        if(tok.operation=='('){
        return true;
        } else return false;
}
bool isRightBracket(union Token tok)
{
        if(tok.operation==')'){
        return true;
        } else return false;
}
bool isOperand(union Token tok)
{
      if (!(isLeftBracket(tok)||isRightBracket(tok)||isOperator(tok)))
      {
        return true;
      } else return false;
}

struct Node* createNode(union Token tok)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (isOperand(tok)){
    node->value = tok.value;
    if (tok.operation=='0')
    {
        node->operation='0';
    }
    node->left=node->right=NULL;
     
    } else if(isOperator(tok)){
        node->operation = tok.operation;
    node->left=node->right=NULL;
    }
    return node;
}
struct Node* buildTreeFromStack(struct Stack *expression)
{
    if (isEmpty(expression)) {
        return NULL;
    }
    union Token tok = pop(expression);
    //printf(" - %d", tok.value);         
    struct Node *n = createNode(tok);   
    if(isOperand(tok))
    {
        n->left = NULL;
        n->right = NULL;
    } else{
        n->right = buildTreeFromStack(expression);
        n->left = buildTreeFromStack(expression);
        
    }
    
    return n;
}
union Token parseFromString(const char** expression)
{
    union Token tok;
    tok.operation=**expression;
    if(isdigit(**expression)&&(**expression!='0'))
    {
        tok.value=(int)**expression - 48;
    }
    return tok;

}
int priority(union Token tok)
{
    switch (tok.operation)
    {
    case ')': case '(' :
        return 3;
        break;
    case '*': case '/':
        return 2;
        break;
    case '+': case '-':
        return 1;
        break;
    default:
      //  return 0;
        break;
    }
}

struct Node* makeTreeFromExpression(const char* expression)//3-5
{
    unsigned i=0;
    struct Stack operators;
    struct Stack operands;
    initStack(&operands);
    initStack(&operators);
    union Token tok;
    union Token degree;
    int k;
    bool emptyOper=true;;
    while(*expression)
    {
        tok = parseFromString(&expression);
        *expression++;
            if (tok.operation == '^'){
                degree = parseFromString(&expression);3^4
                *expression++;
                tok = pop(&operands);
                k=tok.value;
               if (degree.operation == '0') {tok.value =1;}
               else if(tok.operation=='0')
               {
                   tok.operation='0';
               }
               else{
               for (int i =1; i<degree.value; i++)
               {
                   tok.value*=k;
               }
               }
               push(&operands, tok);
            } else {            
            if(isOperand(tok)) {
         
             push(&operands, tok);
        
            } else if(isOperator(tok)) {
             while(emptyOper && (priority(top(&operands)) >= (priority(tok)))) {
                push(&operands, pop(&operators));
            }
            
              push(&operators, tok);
               emptyOper=true;
          } else if(isLeftBracket(tok)){
              push(&operators,tok);
        
        } else if(isRightBracket(tok)) {
            union Token operatorsTop;
            operatorsTop.operation = pop(&operators).operation;
         
            while ( (!isLeftBracket(operatorsTop)))
            {
               push(&operands,operatorsTop);
                operatorsTop = pop(&operators);
            }
            if(isLeftBracket(operatorsTop)){
            }
        }
        }
        
        
    }
    while(!isEmpty(&operators)) {
        push(&operands, pop(&operators));
    }//35-
    
    return buildTreeFromStack(&operands);
}
void print(struct Node* root){
      
   if (root == NULL){
        return;
    }
    print(root->left);
     
    if (root->operation=='+'||root->operation=='-'||root->operation=='*'||root->operation=='/'||root->operation=='0')
    {
        printf("%c", root->operation);
          
       
    }else
    if ((root->value>0 && root->value<=1000000))
    { 
        printf("%d", root->value);
        
    }
    
          print(root->right);
      
}
void destroyTree(struct Node* root)
{
    if (root != NULL)
    {
        destroyTree(root->left);
        destroyTree(root->right);
    }
    free(root);
}
