#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct player
{
    char name[100];
    int age;
    int rating;
    float salary;
    char position[100];
    char team[100];
    struct player *next;//for adding player
};

struct player *head = NULL;//// player dr ll er head
struct club
{
    char name[100];
    int year;
    float revenue;
    struct club *next;//club add korte
    struct player*players;
} ;

struct club *root = NULL;//club er ll er head

void insert()
{
    char name[100];
    int year;
    float revenue;
    int p;
    printf("Enter Name: ");
    getchar();
    gets(name);
    printf("Enter Year of Formation: ");
    scanf("%d", &year);
    printf("Enter Yearly revenue: ");
    scanf("%f", &revenue);
    printf("Enter position in list: ");
    scanf("%d", &p);
    int found = 0;
    int cnt = 1;
    struct club *cur = root;
    while(cur != NULL)
    {
        if(cnt == p-1)
        {
            found = 1;
            break;
        }
        cnt++;
        cur = cur->next;
    }
    if(found && p != 1)
    {
        struct club *node = (struct club *)malloc(sizeof(struct club));
        strcpy(node->name, name);//as its a string
        node->year = year;
        node->revenue = revenue;
        node->next = cur->next;
        cur->next = node;
    }
    else
    {
        if(root==NULL && p == 1)
        {
            struct club *node = (struct club *)malloc(sizeof(struct club));
            strcpy(node->name, name);
            node->year = year;
            node->revenue = revenue;
            node->next = NULL;
            root = node;
        }
        else if(p == 1)
        {
            struct club *node = (struct club *)malloc(sizeof(struct club));
            strcpy(node->name, name);
            node->year = year;
            node->revenue = revenue;
            node->next = root;
            root = node;
        }
        else
        {
            printf("Can't insert a club in the position.");
        }
    }
}

void delete()
{
    printf("Enter Club to delete: ");
    char name[100];
    getchar();
    gets(name);
    int found = 0;
    struct club *cur = root;
    struct  club *pre = NULL;
    while(cur != NULL)
    {
        if(!strcmp(cur->name,name))
        {
            found = 1;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    if(found)
    {
        if(cur == root)
        {
            struct club *temp = root;
            root = root->next;
            free(temp);
        }
        else
        {
            pre->next = cur->next;
            free(cur);
        }
    }
    else
    {
        printf("There is no such Club.");
    }
}

void swap()
{
    int pos1, pos2;
    printf("Give positions:");
    scanf("%d %d", &pos1, &pos2);
    int max ;
    if(pos1 > pos2)
    {
        max=pos1;
    }
    else
    {
        max=pos2;
    }
    int found = 0;
    int c = 1;//ll er pos no 1 theke khoja shuru korchi
    struct club *temp = root;
    while(temp!=NULL)
    {
        if(c==max)
        {
            found = 1;
            break;
        }
        c++;
        temp = temp->next;
    }
    if(!found)
    {
        printf("Given positions are not valid");
        return;
    }
    struct club *prev1 = NULL;
    struct club *cur1 = root;
    c = 1;
    while(c!=pos1)
    {
        prev1 = cur1;
        cur1 = cur1->next;
        c++;
    }
    struct club *prev2 = NULL;
    struct club *cur2 = root;
    c = 1;
    while(c!=pos2)
    {
        prev2 = cur2;
        cur2 = cur2->next;
        c++;
    }
    if(prev1!=NULL)
        prev1->next = cur2;
    else
        root = cur2;//1st position e change korle lage
    if(prev2!=NULL)
        prev2->next = cur1;
    else
        root = cur1;//2nd positione
    temp = cur2->next;
    cur2->next = cur1->next;
    cur1->next = temp;
}
//adding nodes/players at the end
void addplayer()
{
    printf("Player Name: ");
    char name[100];
    getchar();
    gets(name);
    int age;
    printf("Age of Player: ");
    scanf("%d", &age);
    int rating;
    printf("Player rating: ");
    scanf("%d", &rating);
    float salary;
    printf("Player salary: ");
    scanf("%f", &salary);
    char position[100];
    printf("Position: ");
    getchar();
    gets(position);
    char team[100];
    printf("Club contract: ");
    gets(team);
    if(head==NULL)
    {
        struct player *temp;
        temp = (struct player *)malloc(sizeof(struct player));
        strcpy(temp->name, name);
        temp->age = age;
        temp->rating = rating;
        temp->salary = salary;
        strcpy(temp->position, position);
        strcpy(temp->team, team);
        temp->next = NULL;
        head = temp;
    }
    else
    {
        struct player *temp;
        temp = head;
        while(temp->next!=NULL)
        {
            temp = temp->next;
        }
        struct player *nw;
        nw = (struct player *)malloc(sizeof(struct player));
        strcpy(nw->name, name);
        nw->age = age;
        nw->rating = rating;
        nw->salary = salary;
        strcpy(nw->position, position);
        strcpy(nw->team, team);
        nw->next = NULL;
        temp->next = nw;
    }
}

void delplayer()
{
    printf("Player Name: ");
    char name[100];
    getchar();
    gets(name);
    int found = 0;
    struct  player *cur = head;
    struct player *pre = NULL;
    while(cur != NULL)
    {
        if(strcmp(cur->name,name)==0)
        {
            found = 1;
            break;
        }
        pre = cur;
        cur = cur->next;
    }
    if(found)
    {
        if(cur == head)
        {
            struct player *temp = head;
            head = head->next;
            free(temp);
        }
        else
        {
            pre->next = cur->next;
            free(cur);
        }
    }
    else
    {
        printf("There is no such player.");
    }
}

void print()
{
    if(root==NULL)
    {
        printf("No clubs to show!");
    }
    else
    {
        printf("Showing Club list:\n");
        struct club *cur = root;//root nile root er value hariye feltam
        while(cur!=NULL)
        {
            printf("%s\n", cur->name);
            printf("%d\n", cur->year);
            printf("%f\n", cur->revenue);
            struct  player *temp = head;//player er link list e dhuklam
            int isplayer = 0;
            //mil ache kina check korte
            while(temp!=NULL)
            {
                if(!strcmp(cur->name,temp->team))//player er team club namer shathe mile naki khujbo
                {
                    isplayer = 1;
                    break;
                }
                temp = temp->next;//porer ta   check kore nilam
            }
            temp = head;//abr notun loop e jawar jonno
            if(isplayer)
            {
                printf("List of Players in contract:\n ");
                while(temp!=NULL)
                {
                    if(!strcmp(cur->name,temp->team))
                    {
                        printf("%s ", temp->name);

                        printf("Age: %d , Rating: %d , Salary: %f , Position: %s\n ", temp->age, temp->rating, temp->salary, temp->position);

                    }
                    temp = temp->next;//pore o eki team er player ache kina dekhte
                }
            }
            else
            {
                printf("No player contracts!\n");
            }
            cur = cur->next;//club linked list ghure ashte
        }
    }
}


int main()
{
    printf("La Liga Database Initializing...");
    while(1)
    {
        printf("What do you want to do?\n1.Create Club\n2.Delete Club\n3.View club info\n4.Swap\n5.Addplayer\n6.delete player\n");
        printf("Choice: ");
        int ch;
        scanf("%d", &ch);
        if(ch==1)
        {
            insert();

        }
        else if(ch==2)
        {
            delete ();

        }
        else if(ch==3)
        {
            print();

        }
        else if(ch==4)
        {
            swap();

        }
        else if(ch==5)
        {
            addplayer();

        }
        else if(ch==6)
        {
            delplayer();

        }
        else
        {
            printf("La Liga Database Terminating....\n");

            break;
        }
        printf("...................\n");
    }
    return 0;
}
