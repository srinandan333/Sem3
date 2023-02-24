typedef struct student
{
        char srn[20];
        char name[20];
        int sem;
        struct marks
        {
                int marks1;
                int marks2;
                int marks3;
                int marks4;
                int marks5;
                char s1[20];
                char s2[20];
                char s3[20];
                char s4[20];
                char s5[20];
         }mar;
                
}stu;

void read(stu *a,int n);
void disp(stu *a,int n);
void avg(stu *a,char *s,int n);
void sort(stu *a,int n);
void disp1(stu *a,int n);