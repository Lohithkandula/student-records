#include<stdio.h>
#include<string.h>
struct student{
char s[25];
int roll;
char b[3];
int age;
};
int main()
{
char ch,word[50],stu[25],branch[3];
int i,j,k,r,a,n,c,tmp,m,p,o,l=0;
FILE *f;
f=fopen("f3.txt","w+");
printf("Enter the number of students data: ");
scanf("%d",&n);
struct student stude[n];
int ar[n];
for(i=0;i<n;i++){
printf("\nEnter the student name: ");
scanf("%s",stu);
strcpy(stude[i].s,stu);
fprintf(f,"Name : %s\n",stu);
printf("Enter the Roll Number: ");
scanf("%d",&r);
stude[i].roll=r;
fprintf(f,"Roll : %d\n",r);
printf("Enter the Branch name: ");
scanf("%s",branch);
strcpy(stude[i].b,branch);
fprintf(f,"Branch : %s\n",branch);
printf("Enter the age: ");
scanf("%d",&a);
stude[i].age=a;
fprintf(f,"Age : %d\n\n",a);
 }
for(i=0;i<n;i++)
ar[i]=stude[i].roll;
f=fopen("f3.txt","r");
printf("\nEnter the key value: ");
//scanf("%d",&k);
scanf("%d",&k);
for(i=0;i<n;i++){
if(stude[i].roll==k){
printf("Found!!\n");
printf("Name: %s\n",stude[i].s);
printf("Roll No: %d\n",stude[i].roll);
printf("Branch: %s\n",stude[i].b);
printf("Age: %d\n",stude[i].age);
l=1;
}
}
if(l==0){
printf("Not Found!!\n");
}
fclose(f);
}
