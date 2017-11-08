#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"test_trolls.c"
#include"findpath.c"


  int main()
  {
    int x,y,z,st[200],a,b,c;
    char code;
    int i,j,k,l,m,n,u[100],p[100];
    int sum=0;
    int counter[9];
    char maze[30][30],mazecp[30][30];
    char line[120];
    char encoding[40];
    char array[10][40];
    for (i = 0; i < 30; i++)
    {
         for (j = 0; j < 30; j++)
         {
             maze[i][j] = '.';
         }
    }
    while(fgets(line,120,stdin))
    {
      if(sscanf(line,"%d %d @%c", &x, &y, &code)<3)
      exit(1);
      if (x < 0 || x > 30 || y < 0 || y > 30)
      exit(1);
      if (code=='\n')
      exit(1);
      if (x==0 || y==0)
      {
        break;
      }
      maze[x-1][y-1]=code;
    }


    for(i=0;i<30;i++)
    {
      for(j=0;j<30;j++)
        {
          mazecp[i][j]=maze[i][j];
        }
    }

    i=0;
    while(fgets(line,120,stdin))
    {
      sscanf(line,"%d %s", &z, &encoding);
      if (z!=i)
      exit(1);
      strcpy(array[z],encoding);
      ++i;
    }
    if (i!=8)
    exit(1);
    

    for(i=0;i<30;i++)
    {
      if (maze[0][i]!='.')
      {
        y=i;
        k=i;
        x=0;
      }
    }

    findpath(x,y,maze,st,a,b);
    x=0;
    y=k;
    a=0;
    b=0;

    test_trolls(x,y,maze,st,a,b);
    m=0;
    for(i=0;i<30;i++)
      {
        if(maze[10][i]!='.')
        {
          m++;
        }
      }
    if(m==0)
      {
        printf("no path found!\n");
        return 0;
      }

    for(i=0;i<30;i++)
        {
          for(j=0;j<30;j++)
          {
            if (maze[i][j]=='0')
            {
              maze[i][j]='.';
            }
          }
        }

    for(i=0;i<30;i++)
      {
        for(j=0;j<30;j++)
        {
          if (maze[i][j]=='0')
          {
            maze[i][j]='*';
          }
        }
      }

    for (i = 0; i < 30; i++)
      {
        for (j = 0; j < 30; j++)
          {
            printf("%c", maze[j][i]);
          }
        printf("\n");
      }
    k=0;
    for(i=0;i<30;i++)
      {
        for(j=0;j<30;j++)
          {
            if (maze[i][j]=='*')
              {
                u[k]=i;
                p[k]=j;
                k++;
              }
          }
      }

    for (i=0;i<8;i++)
    {
      counter[i]=0;
    }

    for(i=0;i<k;i++)
    {
       code=mazecp[u[i]][p[i]];
       for(j=0;j<8;j++)
       {
         c=1;
         c=c<<j;
         if((code & c)==0)
         {
             counter[j]=counter[j];
         }
         else
         {
             counter[j]++;
         }
       }
    }

    for (i=0;i<8;i++)
    printf("%d %s\n",counter[i],array[i]);
    return 0;
  }
