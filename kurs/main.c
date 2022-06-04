#include "func.h"
int main()
{
    struct Person p;
    char c;
    printf("Press key (Add +, Delete -, Search ?,Print p,Random r, Exit E)\n");
    while(scanf("\n%c", &c))
    {
        if (c == 'E')
        {
            break;
        }
        if (c == '+')
        {
            Add(&p);
        }
        if (c == '?')
        {
            time_t t0 = time(0);
            search();
            time_t t1 = time(0);
            unsigned time_in_seconds = difftime(t1, t0);
            printf("%d sec\n",time_in_seconds);
        }
        if (c == '-')
        {
            time_t t0 = time(0);
            delete();
            time_t t1 = time(0);
            unsigned time_in_seconds = difftime(t1, t0);
            printf("%d sec\n",time_in_seconds);
        }
        if (c == 'r')
        {
            time_t t0 = time(0);
            random();
            time_t t1 = time(0);
            unsigned time_in_seconds = difftime(t1, t0);
            printf("%d sec\n",time_in_seconds);
        }
        if (c == 'p')
        {
            time_t t0 = time(0);
            printfile();
            time_t t1 = time(0);
            unsigned time_in_seconds = difftime(t1, t0);
            printf("%d sec\n",time_in_seconds);
        }
        printf("Press key (Add +, Delete -, Search ?,Print p,Random r, Exit E)\n");
    }
    //random();
}