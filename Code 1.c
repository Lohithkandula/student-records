#include<stdio.h>
#include<string.h>
#include<time.h>
#define max 100
struct students{
int roll;
char name[max];
char course[max];
int age;
}s[max];
int main(){
clock_t start,end;
double time;
start=clock();
FILE *file;
file=fopen("binarysearchfile","w");
int i,j;
int n;
printf("enter no of students:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("\nenter roll no :");
scanf("%d",&s[i].roll);
fflush(stdin);
printf("enter name :");
scanf("%s",&s[i].name);
printf("enter course :");
scanf("%s",&s[i].course);
printf("enter age :");
scanf("%d",&s[i].age);
}
struct students temp;
for(j=1;j<n;j++){
for(i=0;i<n-1;i++){
if(s[j].roll<s[i].roll){
temp=s[j];
s[j]=s[i];
s[i]=temp;
}
}
}
fprintf(file,"ROLL_NUMBER NAME COURSE age\n");
for( i=0;i<n;i++){
fprintf(file, "%d %s %s %d\n",s[i].roll,s[i].name,s[i].course,s[i].age);
}
fclose(file);
char ch[max];
FILE *file1,*index;
file1=fopen("binarysearchfile","r");
index=fopen("index","w");
int array[n];
if(index==NULL)
{
printf("Can't open the file.\n");
}
else
{
for( i=0;i<n;i++)
{
array[i]=s[i].roll;
}
for( i=0;i<n;i++)
{
fprintf(index,"%d\n",array[i]);}
}
fclose(file1);
fclose(index);
char check[100];
char num[100];
index=fopen("index","r");
int count,flag=0;
int ns,low,high,mid;
//Binary Search
int number;
printf("Enter the Roll number to be searched: ");
scanf("%d",&number);
low = 0;
high = n - 1;
mid = (low+high)/2;
while (low <= high) {
if(array[mid] < number)
low = mid + 1;
else if (array[mid] == number) {
printf("Given roll number found\n");
printf("Roll no: %d\t\tName: %s\t\tCourse: %s\t\tAge:
%d\n",s[mid].roll,s[mid].name,s[mid].course,s[mid].age);
break;
}
else
high = mid - 1;
mid = (low + high)/2;
}
if(low > high)
printf("Given roll number not found\n");
fclose(index);
end=clock();
time=(end - start)/CLOCKS_PER_SEC;
printf("Time taken for this whole execution %f seconds\n",time);
return 0;
}
