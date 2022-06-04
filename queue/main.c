#include"quicksort.h"
int main()
{
    struct Queue q;
    struct Queue w;
    initQueue(&q);
    initQueue(&w);
    int i;
    printf("Enter numbers (exit :-1)");
    scanf("%d", &i);
    while (i!=-1)
    {
        push(&q,i);
        scanf("%d", &i);
    }
  quickSort(&q,q.home,q.max);
  printQueue(&q);

}