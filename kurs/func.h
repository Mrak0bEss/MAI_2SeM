#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include <time.h>
enum Gender {Woman = 1 , Man};
struct Mark
{
    unsigned MatAn;
    unsigned LinAl;
    unsigned Diskra;
    unsigned Inf;
};
struct Person
{
    char Name[50];
    char Surname[50];
    enum Gender gender;
    unsigned Group;
    struct Mark marks; 

    
};
void Add(struct Person* p)
{
    FILE* fl=fopen("kurs.bin", "ab");
    printf("Enter Group:");
    scanf("%d", &p->Group);
    printf("\nEnter Name:");
    scanf("%s", p->Name);
    printf("\nEnter Surname:");
    scanf("%s", p->Surname);
    printf("Enter gender(Woman-1/Man-2):");
    scanf("%d", &p->gender);
    printf("\nEnter mark for MatAn:");
    scanf("%d", &p->marks.MatAn);
    printf("\nEnter mark for LinAl:");
    scanf("%d", &p->marks.LinAl);
    printf("\nEnter mark for Diskra:");
    scanf("%d", &p->marks.Diskra);
    printf("\nEnter mark for Inf:");
    scanf("%d", &p->marks.Inf);
    fwrite(p,sizeof(*p),1,fl);
    fclose(fl);
}
void search()
{
    unsigned counter = 0;
    FILE* fl=fopen("kurs.bin", "rb");
    struct Person p;
    while(fread(&p, sizeof(p),1,fl) == 1)
    {
        if ((p.gender==1)&&(p.marks.MatAn>3)&&(p.marks.Diskra>3)&&(p.marks.LinAl>3)&&(p.marks.Inf>3))
        {
            counter++;
        }
    }
    printf("Stipentya est y %d studentok\n", counter);
    fclose(fl);
}
void delete()
{
    struct Person d;
    
    printf("Enter query for delete (for miss enter 0)");
    printf("Enter Group:");
    scanf("%d", &d.Group);
    printf("\nEnter Name:");
    scanf("%s", d.Name);
    printf("\nEnter Surname:");
    scanf("%s", d.Surname);
    printf("Enter gender(Woman-1/Man-2):");
    scanf("%d", &d.gender);
    printf("\nEnter mark for MatAn:");
    scanf("%d", &d.marks.MatAn);
    printf("\nEnter mark for LinAl:");
    scanf("%d", &d.marks.LinAl);
    printf("\nEnter mark for Diskra:");
    scanf("%d", &d.marks.Diskra);
    printf("\nEnter mark for Inf:");
    scanf("%d", &d.marks.Inf);
    FILE* fl=fopen("kurs.bin", "rb");
    FILE* fs=fopen("kurs1.bin", "ab");
    struct Person p;
    while(fread(&p, sizeof(p),1,fl) == 1)
    {
        if (!(((d.Group!=0)&&(d.Group==p.Group))||((d.Name!="0")&&(strcmp(d.Name,p.Name)==0))||((d.Surname!="0")&&(strcmp(d.Surname,p.Surname)==0))||((d.gender!=0)&&(d.gender== p.gender))))
        {
            //printf("----%s-0---\n", p.Name);
            fwrite(&p,sizeof(p),1,fs);
        }

    }
  // fl=fs;
    fclose(fl);
    fclose(fs);
    remove("kurs.bin");
    rename("kurs1.bin", "kurs.bin");
}
void printfile()
{
    struct Person p;
    FILE* fl=fopen("kurs.bin", "rb");
    printf("+----------------------------------------------+------+-----------+-------+\n");
    printf("|                    NAME                      | Group|  Gender   | Marks |\n");
    printf("+----------------------------------------------+------+-----------+-------+\n");

        while (fread(&p, sizeof(p), 1, fl) == 1)
        {
            printf("|%20s %25s|%6d|",
            p.Surname,
            p.Name,
            p.Group
            );
            if (p.gender==1)
            {
                printf("  Woman    |");
            } else printf("   Man     |");
            printf("%d %d %d %d|", p.marks.MatAn,p.marks.LinAl,p.marks.Diskra,p.marks.Inf);
            printf("\n+----------------------------------------------+------+-----------+-------+\n");
        }
    fclose(fl);
}
void random()
{

    //time_t t0 = time(0);
    FILE* fl=fopen("kurs.bin", "ab"); 
    srand(time(NULL));
    int n;
    char c[27];
    printf("Enter nuber of stubents : ");
    scanf("%d", &n);
    for (int i =1; i<=n;i++)
    {
        struct Person p;
        int len;
        len = 4+ rand()%15;
       // printf("%d\n", len);
        for (int j=0; j<len;j++)
        {
            p.Name[j]=97+rand()%23;
        }
        len = 4+ rand()%15;
        for (int j=0; j<len;j++)
        {
            p.Surname[j]=97+rand()%23;
        }
        p.Group=1+rand()%10;
        p.gender=1+rand()%2;
       // printf("%d\n",p.gender);
       p.marks.Diskra=2 + rand()%4;
       p.marks.MatAn=2 + rand()%4;
       p.marks.LinAl=2 + rand()%4;
       p.marks.Inf=2 + rand()%4;
       fwrite(&p,sizeof(p),1,fl);
        for (int j=0;j<50;j++)
        {
            p.Name[j]='\0';
            p.Surname[j]='\0';
        }
        p.Group=0;
        p.gender=0;
        p.marks.Diskra=0;
        p.marks.MatAn=0;
        p.marks.LinAl=0;
        p.marks.Inf=0;
    }
    fclose(fl);
    //time_t t1 = time(0);
    //unsigned time_in_seconds = difftime(t1, t0);
  //  printf("%d sec\n",time_in_seconds);

}