#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Queue {
    unsigned home;
    int* elements;
    unsigned capacity;
    unsigned size; 
    unsigned max; 
};
void initQueue(struct Queue* q)
{
    q->capacity =2;
    q->size =0;
    q->home=0;
    q->max=0;
    q->elements= (int*)malloc(sizeof(int) * q->capacity);

}
bool isEmpty(struct Queue* q)
{
    return !q->size;
}
void push(struct Queue* q, int element)
{
    if(q->size == q->capacity)
    {
        q->capacity *= 2;
        q->elements=(int*)realloc(q->elements, sizeof(int) * q->capacity);
    }
    q->size++;
    if (q->size==1)
    {
        q->max=-1;
    }
    q->elements[++q->max] = element;
    
}
int pop(struct Queue* q)
{
    q->size--;
    int r = q->elements[q->home++];
    if (q->size == 0)
    {
        initQueue(q);
    }

    return r;
    
} 
int Size(struct Queue* q)
{
    return q->size;
}


void procedure(struct Queue* q, struct Queue* w)
{
    if(q->size + w->size >= q->capacity)
    {
        q->capacity +=w->capacity; ;
        q->elements=(int*)realloc(q->elements, sizeof(int) * q->capacity);
    }   
    while(!isEmpty(w))
    {
        push(q,pop(w));
    }
}
void printQueue(struct Queue* q)
{
    if(!isEmpty(q))
    {
    for (int i = q->home; i<=q->max;i++)
    {
        printf("%d ", q->elements[i]);
    }
    }
}
