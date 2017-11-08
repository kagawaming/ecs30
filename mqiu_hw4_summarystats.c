/*Ming Qiu*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdio_ext.h>
/*variable declaration*/
int i,j,k;
int check;
double number[30],sort,mean,sum,f,g;
double a=2147483648;

int main()
{
  printf("How many numbers (atleast 2) ? \n");
  /*clear the entry*/
  for(;;)
  {
    check=scanf("%lf", &f);
    j=f;
    g=j;
    if((check==0)||((f<2) && (f>-a)))
    {
      printf("wrong entry, please try again: \n");
      __fpurge(stdin);
    }
    if((f<a) && (f>=2))
    {
      break;
    }
    if(f>a)
    {
      printf("overflow entry, please try again: \n");
      __fpurge(stdin);
    }
    if(f<-a)
    {
      printf("underflow entry, please try again: \n");
      __fpurge(stdin);
    }
    if(f>g)
    {
      printf("you should enter an integer, please try agian: \n");
      __fpurge(stdin);
    }
  }
  /*print out the input prompt*/
  k=j-1;
  for(i=0;i<j;i++)
  {
    printf("Enter a number (%d more to enter) \n", k);
    scanf("%lf", &number[i]);
    k--;
  }
  /*sort the numbers in the array from smallest to greatest left to right*/
  for(i=0;i<j;i++)
  {
    for(k=i+1;k<j;k++)
    {
      if(number[i]>number[k]){
      sort=number[i];
      number[i]=number[k];
      number[k]=sort;}
    }
  }
  /*calculate the sum, mean*/
  sum=0;
  for(i=0;i<j;i++)
  sum+=number[i];
  mean=sum/j;
  printf("* * OK, Got it \n");
  printf("Of these %d numbers: \n", j);
  /*print the result*/
  printf("Smallest: %.2f, Biggest: %.2f, 2nd Biggest: %.2f, Mean: %.2f \n", number[0],number[j-1], number[j-2],mean);
  return 0;
}
