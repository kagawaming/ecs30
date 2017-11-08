#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
  int i,j,k;
  int sum=0;
  int counter[9];
  char maze[30][30];
  char line[120];
  char input[10]="trolls";
  int z,c;
  char encoding[40];
  char array[10][40];
  for (i = 0; i < 30; i++) {
       for (j = 0; j < 30; j++) {
           maze[i][j] = '.';
       }
   }
  for (i=0;i<8;i++){
    counter[i]=0;
  }
  while(fgets(line,120,stdin)){
    int x,y;
    char code;
    if(sscanf(line,"%d %d @%c", &x, &y, &code)<3)
    exit(1);
    if (x < 0 || x > 30 || y < 0 || y > 30)
    exit(1);
    if (code=='\n')
    exit(1);
    if (x==0 || y==0){
      i=0;
 while(fgets(line,120,stdin)){
 sscanf(line,"%d %s", &z, &encoding);
 if (z!=i)
 exit(1);

 strcpy(array[z],encoding);
++i;}
if (i!=8)
exit(1);
if (i==8){
 sum+=counter[4];
 sum+=counter[6];
 sum+=counter[7];
 counter[8]=sum;
 strcpy(array[8],input);
for (i=0;i<9;i++)
printf("%d %s\n",counter[i],array[i]);}
return 0;
    }
    for(i=0;i<8;i++){
    c=1;
    c=c<<i;
    if((code & c)==0){
      continue;
    }else{
    counter[i]++;}}
maze[x-1][y-1]=code;}

    for (i = 0; i < 30; i++) {
      for (j = 0; j < 30; j++) {
          printf("%c", maze[j][i]);}
      printf("\n");}


  return 0;}
