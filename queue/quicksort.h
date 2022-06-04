#include"func.h"
int last(struct Queue* q, int end)//Элемент с индексом end
{
    int k[q->size];
    int r;
    int b = q->home;
    int e = q->max;
    for(int i = b;i <= e;i++)
    {
        k[i]=pop(q);
    }
    for(int i = b;i <= e;i++)
    {
        push(q,k[i]);
        if (i == end)
        {
            r = k[i];
        }
    }
    return r;
}
int first(struct Queue* q, int left)//Элемент с индексом left
{   
    int k[q->size];
    int r;
    int b = q->home;
    int e = q->max;
    for(int i = b;i <= e;i++)
    {
        k[i]=pop(q);
    }
    for(int i = b;i <= e;i++)
    {
        push(q,k[i]);
        if (i == left)
        {
            r = k[i];
        }
    }
    return r;
}
void Swap(struct Queue* q, int left, int right) 
{
    int k[q->size];
    int l;
    int r;
    int begin = q->home;
    int fin = q->max;
    for(int i = begin;i <= fin;i++)
    {
        k[i]=pop(q);
        
    }   
    for(int i = begin;i <= fin;i++)
    {
        if(i == left)
        {
            push(q,k[right]);
        }else if(i == right)
        {
            push(q,k[left]);
        } else
        push(q, k[i]);
        
    }  
    
          
}
int partSort(struct Queue* q, int left, int right)
{
    int k = (first(q,q->home)+last(q,q->max))/2;
    int end = right;
    while (left < right)
    {
        while ((left < right)&&(first(q,left) <= k))
        {
            left++;
        }
        while ((left < right)&&(last(q,right)>=k))
        {
            right--;
        }
        Swap(q,left, right);
    }
    Swap(q,left, end);
    return left;
}
void quickSort(struct Queue* q, int left, int right)
{
    if(isEmpty(q))
    {
        return;
    }
    if (left >= right)
    {
        return;
    }
    int p = partSort(q,left,right);
    struct Queue w,e;
    initQueue(&w);
    initQueue(&e);
    for(int i = left;i <= right;i++)
    {
        if(i<=p-1)
        {
            push(&w,pop(q));
        } else{
            push(&e,pop(q));
        }
    }
    quickSort(&w,w.home,w.max);
    quickSort(&e,e.home,e.max);
    initQueue(q);
    procedure(q,&w);
    procedure(q,&e);
}
// 1 54 2 534 3425 322 2