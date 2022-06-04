#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>

union Token {
    unsigned value;
    char operation;
};
struct Stack {
    union Token* nodes;
    unsigned capacity;
    unsigned size; 
};
void initStack(struct Stack* q)
{
    q->capacity =2;
    q->size =0;
    q->nodes= (union Token*)malloc(sizeof(union Token) * q->capacity);

}

void push(struct Stack* q, union Token element)
{
    if(q->size == q->capacity)
    {
        q->capacity *= 2;
        q->nodes=(union Token*)realloc(q->nodes, sizeof(union Token) * q->capacity);
    }
    q->nodes[q->size++] = element;
}
union Token pop(struct Stack* q)
{
    if(!q->size) {
        union Token tok;
        return tok;
    }
    return q->nodes[--q->size];
    
} 
bool isEmpty(struct Stack* q)
{
    return !q->size;
}
union Token top(struct Stack* q)
{
    return q->nodes[q->size-1];
}