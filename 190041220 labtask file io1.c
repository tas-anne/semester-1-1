#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int choice()
{
    char name[30],address[50],stu_id[10],end[100];
    char id[10];
    printf("\nEnter your student ID: ");
    scanf("%s",id);
    if(!strcmp(id,"0"))//if the id is 0 then stop program
    {
        printf("Student Information System Terminating.\n");
        return 0;
    }
    strcat(id,"\n");//add new line,copy the newline character in the string
    FILE*fp,*gp,*hp;
    if((fp=fopen("student.txt","r"))==NULL)
    {
        printf("Can not open student file");
        exit(1);
    }
    if((gp=fopen("course.txt","r"))==NULL)
    {
        printf("Can not open student file");
        exit(1);
    }
    if((hp=fopen("marks.txt","r"))==NULL)
    {
        printf("Can not open student file");
        exit(1);
    }
    //fp file e
    int got=0;
    while(!feof(fp))
    {
        fgets(name,30,fp);
        fgets(address,50,fp);
        fgets(stu_id,30,fp);
        fgets(end,100,fp);
        if(!strcmp(stu_id,id))
        {
            got=1;
            break;
        }

    }
    if(!got)//id na paowa gele
    {
        printf("student id not found.\n");
        exit(1);
    }
    int year=2000;
    char program[100];
    char department[100];
    double cgpa;
    year=year+id[1]-'0'+10*(id[0]-'0');//2019 year
    //department check
    if(id[4]=='1') strcpy(department,"MCE\n");
    else if(id[4]=='2') strcpy(department,"EEE\n");
    else if(id[4]=='3') strcpy(department,"TVE\n");
    else if(id[4]=='4') strcpy(department, "CSE\n");
    else strcpy(department, "Invalid\n");

    //higher or bachelor
    if(id[5]=='1') strcpy(program, "Bachelor of Science\n");
    else if(id[5]=='2') strcpy(program, "Higher Diploma\n");
    else strcpy(program, "Invalid\n");

    char course[100];
    int marks,count=0;
    char test[100];
    while(!feof(gp))
    {

        fgets(stu_id,10,gp);
        fgets(course,100,gp);
        fscanf(gp,"%d",&marks);
        fgetc(gp);
        fgets(end,100,gp);
        if(!strcmp(stu_id,id))
        {
            calc(course,marks,&gpa,hp);
            count++;
        }

    }
    cgpa = (count)? gpa/(double)count:0;
    printf("Displaying student information:\nName:\t\t%s\nAddress:\t\t%s\nstudentID:\t\t%s\nYear of Admission:\t\t%d\nProgram:\t\t%s\nDepartment:\t\t%s\nCGPA:\t\t%.2lf\n",name,address,id,year,program,department,cgpa);
    printf("Do you want to see your result in details?\n1.\tYes\n2.\tNo\nEnter choice:\t");
    int c;
    scanf("%d",&c);
    getchar();
    if(c==1)
    {
        fseek(gp,0,SEEK_SET);
        while(!feof(gp))
        {

            fgets(stu_id,10,gp);
            fgets(course,100,gp);
            fscanf(gp,"%d",&marks);
            fgetc(gp);
            fgets(end,100,gp);
            if(!strcmp(stu_id,id))
            {
                course_gpa(course, marks, hp);
            }

        }

    }
    fclose(gp);
    fclose(hp);
    fclose(fp);
    return 1;
}
void calc(char course[],int marks,double*gpa,FILE*hp)
{
    fseek(hp,0,SEEK_SET);//0 holo the amount of data you have to skip,cp holo je file e seek korbo
    char course_name[100];
    char course_comp[100];
    char end[100];
    double final_marks,course_gpa;
    while(!feof(hp))
    {

        fgets(course_name,100,hp);
        fgets(course_cmp,100,hp);
        fscanf(hp,"%lf",&final_marks);
        fgetc(hp);
        fgets(end,100,hp);
        if(!strcmp(course_comp,course))
        {
            course_gpa=(double)marks/final_marks;
            if(course_gpa>=80)
            {
                *gpa=*gpa+4;

            }
            else if(course_gpa>=70)
            {
                *gpa=*gpa+3.5;

            }
            else if(course_gpa>=60)
            {
                *gpa=*gpa+3.0;

            }
            else if(course_gpa>=50)
            {
                *gpa=*gpa+2.5;

            }
            else if(course_gpa>=40)
            {
                *gpa=*gpa+2.0;

            }
        }

    }

}
void course_cgpa(char course[],int marks,FILE*hp)
{
    fseek(hp,0,SEEK_SET);
    char course_name[100];
    char course_comp[100];
    char end[100];
    double final_marks,course_gpa;
    while(!feof(hp))
    {

        fgets(course_name,100,hp);
        fgets(course_cmp,100,hp);
        fscanf(hp,"%lf",&final_marks);
        fgetc(hp);
        fgets(end,100,hp);
        if(!strcmp(course_comp,course))
        {
            char grade[100];
            double cg,course_gpa;
            course_gpa=(double)marks/final_marks;
            if(course_gpa>=80)
            {
                strcpy(grade,"A+");
                cg = 4.00;
            }
            else if(course_gpa>=70)
            {
                strcpy(grade,"A");
                cg = 3.50;
            }
            else if(course_gpa>=60)
            {
                strcpy(grade,"B");
                cg = 3.00;
            }
            else if(course_gpa>=50)
            {
                strcpy(grade, "C");
                cg = 2.50;
            }
            else if(course_gpa>=40)
            {
                strcpy(grade, "D");
                cg = 2.00;
            }
            else
            {
                strcpy(grade,"F");
                cg = 0;
            }
            printf("Course:\t\t%sCourse ID:\t\t%sAttained Marks:\t\t%d\nAttained Grade:\t\t%s\nAttained Grade Point:\t%.2lf\n",course_name,course,marks,grade,cg);
            return;
        }

    }

}
int main()
{
    printf("Student Information System Initializing.");
    while(1)
        if(!choice()) return 0;
}

