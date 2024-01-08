#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
    printf("Student Information System Initializing.\n");

    //je id tar jonno result khujbo
    char id[10];
    int choice;//whole result dekhbo kina
    FILE *sp,*cp,*mp;
    char st_name[100];//name
    char st_add[100];//address

    while(1)
    {//student id  input nibo
        printf("Enter your student ID:\t");
        scanf("%s",id);

        // id 0 hole terminate korbe program
        if(strcmp(id,"0") == 0)
        {
            break;
        }

        //students.txt file read korbe

        if((sp = fopen("students.txt","r"))== NULL)
        {
            printf("Can not open the student file\n");
            exit(1);//break dile o hobe
        }
        char roll[100];
        char store[100];
        char course[100];
        int find_it =0;

        //file read student.txt
        while(fgets(roll,100,sp) != NULL)//roll read korbo
        {
            roll[strlen(roll)-1]= 0;//amra compare korchi input er shathe .Input er moddhe newline thake na
//Tai file theke newline ta ke null  kore dicchi
//fgets new line keo ney character hishebe oita baad dite
            if(strcmp(roll,id) == 0)
            {
                find_it=1;
                break;
            }

        }
        //id na pele
        if(find_it==0)
        {
            printf("Student ID not found!\n");
            fclose(sp);
            continue;
        }

        fgets(st_name,100,sp);//student er nam print er jonno file theke read korchi
        fgets(st_add,100,sp);//address
        fclose(sp);

        //admission year  calculate
        int year;
        year =2000+ id[1]-'0' + 10*(id[0]-'0');//id[1]=9//fgets nilei new line store korbe tai(-)korar dorkar hoy na hoy ascii ney

        //degree b.sc. na higher dekhte
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

        //department check korte
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


//name ,address,student id ,department,admission year,program,department,cgpa print korte
        printf("Displaying Student Information:\n");
        printf("Name:\t\t%s",st_name);
        printf("Address:\t%s",st_add);
        printf("Student ID:\t%s\n",id);
        printf("Year of Admission: %d\n",year);
        printf("Program: %s",program);
        printf("Department: %s",department);
        printf("CGPA:\t");

//marks er file read korte


        if((mp = fopen("marks.txt","r")) == NULL)
        {
            printf("can not open the file!!!\n");
            break;
        }

        float total_gp=0;
        float count_course_num=0;
        float marks;
        float credit;

     while(fgets(roll,100,mp) !=NULL)//roll milabo course ki ache ta khujte
        {
            roll[strlen(roll)-1] = 0;
            if(strcmp(roll,id) == 0)
            {
                fgets(course,100,mp);
                //course er file read korbo oi course ta milate

                if((cp = fopen("course.txt","r"))== NULL)
                {
                    printf("Can not found !!!\n");
                    break;
                }
                int flag=0;
                char n_c[100];
                while(fgets(n_c,100,cp) != NULL)//course file er course ta read kore n_c te rakhbo
                {
                    if(strcmp(n_c,course) == 0)//course file er n_c er shathe mp file er course milabo
                    {
                        fscanf(cp,"%f",&credit);//credit->3.0 fgets read until a newline (and also stores it). fscanf  reads until any blank space and doesn't store it... fgets reads to a newline. fscanf only reads up to whitespace.
                        flag=1;
                        break;
                    }
                }

                if(flag==0)
                {
                   printf("Can not match\n");
                    fclose(cp);//eta dilam karon ekhanei kaj off hoye jabe jodi na mile
                    break;
                }

                fclose(cp);

                fscanf(mp,"%f",&marks);//

                float gp= marks/credit;//235/3=78.333

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

                total_gp += gp;//3.5+4
                count_course_num+=1;//2 ta course

            }
        }

        fclose(mp);

        if(credit==0)
        {
            printf("%f\n Not enrolled in any course\n",credit);
        }
        //CGPA first e print korte
        else
        {
            printf("%.2f\n",total_gp/count_course_num);//upore je cgpa ta print kore ashi choice deyar age
        }

////2nd step
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
                roll[strlen(roll)-1] = 0; //fgets new line shoho ney ja baad dite hocche
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
                         strcpy(store,co_n);//eta na korle co_n ta hariye jay(course file er program name lost hoye jay.dui ta e cse 4107 print hoy

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
                    printf("Attained Marks:\t\t%.0f\n",marks);//135 er por float ante chai na bole
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
