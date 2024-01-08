#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    printf("Student Information System Initializing.\n");

    char id[10];
    int choice;
    FILE *sp,*cp,*mp;
    char st_name[100];
    char st_add[100];

    while(1)
    {
        printf("Enter your student ID:\t");
        scanf("%s",id);


        if(strcmp(id,"0") == 0)
        {
            break;
        }



        if((sp = fopen("students.txt","r"))== NULL)
        {
            printf("Can not open the student file\n");
            break;
        }
        char roll[100];
        char store[100];
        char course[100];
        int find_it =0;
        while(fgets(roll,100,sp) != NULL)
        {
            roll[strlen(roll)-1]= 0;
            if(strcmp(roll,id) == 0)
            {
                find_it=1;
                break;
            }

        }

        if(find_it==0)
        {
            printf("Student ID not found!\n");
            fclose(sp);
            continue;
        }

        fgets(st_name,100,sp);
        fgets(st_add,100,sp);
        fclose(sp);


        int year;
        year =2000+ id[1]-'0' + 10*(id[0]-'0');


        char program[100];
        if(id[5]=='1')
        {
            strcpy(program, "Bachelor of Science\n");
        }
        else if(id[5]=='2')
        {
            strcpy(program, "Higher Diploma\n");
        }
        else
        {
            strcpy(program, "Invalid\n");
        }


        char department[100];
        if(id[4]=='1')
        {
            strcpy(department,"MCE\n");
        }
        else if(id[4]=='2')
        {
            strcpy(department,"EEE\n");
        }
        else if(id[4]=='3')
        {
            strcpy(department,"TVE\n");
        }
        else if(id[4]=='4')
        {
            strcpy(department,"CSE\n");
        }
        else
        {
            strcpy(department, "Invalid\n");
        }



        printf("Displaying Student Information:\n");
        printf("Name:\t\t%s",st_name);
        printf("Address:\t%s",st_add);
        printf("Student ID:\t%s\n",id);
        printf("Year of Admission: %d\n",year);
        printf("Program: %s",program);
        printf("Department: %s",department);
        printf("CGPA:\t");


        if((mp = fopen("marks.txt","r")) == NULL)
        {
            printf("can not open the file!!!\n");
            break;
        }

        float total_gp=0;
        float count_course_num=0;
        float marks;
        float credit;

     while(fgets(roll,100,mp) !=NULL)
        {
            roll[strlen(roll)-1] = 0;
            if(strcmp(roll,id) == 0)
            {
                fgets(course,100,mp);

                if((cp = fopen("course.txt","r"))== NULL)
                {
                    printf("Can not found !!!\n");
                    break;
                }
                int flag=0;
                char n_c[100];
                while(fgets(n_c,100,cp) != NULL)
                {
                    if(strcmp(n_c,course) == 0)
                    {
                        fscanf(cp,"%f",&credit);
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                   printf("Can not match\n");
                    fclose(cp);
                    break;
                }

                fclose(cp);

                fscanf(mp,"%f",&marks);

                float gp= marks/credit;

                if(gp<40)
                {
                    gp=0;
                }
                else if(gp<50)
                {
                    gp=2;
                }
                else if(gp<60)
                {
                    gp=2.5;
                }
                else if(gp<70)
                {
                    gp=3;
                }
                else if(gp<80)
                {
                    gp=3.5;
                }
                else
                {
                    gp=4;
                }

                total_gp += gp;
                count_course_num+=1;

            }
        }

        fclose(mp);

        if(credit==0)
        {
            printf("%f\n Not enrolled in any course\n",credit);
        }

        else
        {
            printf("%.2f\n",total_gp/count_course_num);
        }


        printf("Do you want to see your result in details?\n");
        printf("1.\tYes\n2.\tNo\nEnter Choice:\t");
        scanf("%d",&choice);
        if(choice==1)
        {


            if(( mp = fopen("marks.txt","r")) == NULL)
            {
                printf("Can not open!!!\n");
                break;
            }

            float marks;
            float credit;

            while(fgets(roll,100,mp) !=NULL)
            {
                roll[strlen(roll)-1] = 0;
                if(strcmp(roll,id) == 0)
                {
                    fgets(course,100,mp);

                    cp = fopen("course.txt","r");
                    if(cp == NULL)
                    {
                        printf("course.txt doesn't exist\n");
                        break;
                    }
                    int flag=0;
                    char co_n[100];
                    while(fgets(co_n,100,cp) != NULL)
                    {
                        if(strcmp(co_n,course) == 0)
                        {
                            fscanf(cp,"%f",&credit);
                            flag=1;
                            break;
                        }
                         strcpy(store,co_n);

                    }

                    if(flag==0)
                    {

                        fclose(cp);
                        break;
                    }

                    fclose(cp);

                    fscanf(mp,"%f",&marks);

                    float gp= marks/credit;
                    char grade[3];


                    if(gp<40)
                    {
                        gp=0;
                        strcpy(grade,"F");
                    }
                    else if(gp<50)
                    {
                        gp=2;
                        strcpy(grade,"C");
                    }
                    else if(gp<60)
                    {
                        gp=2.5;
                        strcpy(grade,"B");
                    }
                    else if(gp<70)
                    {
                        gp=3;
                        strcpy(grade,"A-");
                    }
                    else if(gp<80)
                    {
                        gp=3.5;
                        strcpy(grade,"A");
                    }
                    else
                    {
                        gp=4;
                        strcpy(grade,"A+");
                    }

                    printf("Course:\t\t\t%s",store);
                    printf("Course ID:\t\t%s",course);
                    printf("Course Credit:\t\t%.2f\n",credit);
                    printf("Attained Marks:\t\t%.0f\n",marks);
                    printf("Attained Grade:\t\t%s\n",grade);
                    printf("Attained Grade Point:\t%.2f\n",gp);
                }
            }

            fclose(mp);

        }
    }
    printf("Student Information System Terminating.\n");
    return 0;
}

