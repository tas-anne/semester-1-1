#include<stdio.h>
struct clubinfo
{
    char name[30];
    int year;
    int revenue;
    struct clubinfo *club;
};
struct contract
{
    char player[30];
    int age;
    int rating;
    int salary;
    char pos[15];
};

int main()
{
    struct clubinfo person1;
    struct contract person2;
    char s[1000];
    struct clubinfo *club=&person1;
    printf("Club information\n");
    printf("Name of the club:");
    scanf("%s",&club->name);
    printf("Year of formation:");
    scanf("%s",&club->year);
    printf("Yearly revenue in million Euros:");
    scanf("%s",&club->revenue);
    printf("Name of the club:");
    getchar();
    gets(s);
    printf("Player information:\n");
    printf("Player name:");
    gets(person2.player);
    printf("age of the player:");
    getchar();
    gets(person2.age);
    printf("Rating:");
    fflush(stdin);
    getchar();
    gets(person2.rating);
    printf("salary:");
    fflush(stdin);
    getchar();
    gets(person2.salary);
    printf("Position:");
    fflush(stdin);
    getchar();
    gets(person2.pos);

}
