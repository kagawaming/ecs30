#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int
findpath(int x, int y, char arr[30][30],int step[200], int terminal_x, int terminal_y)
{
  int i,near[8],ways, routex[200],routey[200],c;
  for(i=0;i<8;i++)
  {
    near[i]=0;
  }

    if (x==29){
      c=1;
       c=c<<7;
       if(((arr[x][y] & c)==0)&&(arr[x][y]!='.')){
         arr[x][y]='0';
       return 0;
     }
     else
     {
       arr[x][y]='0';
     }

    }
  if (x==0)
  {
    if ((arr[x+1][y-1]!='.')&&(arr[x+1][y-1]!='0'))
    {
      arr[x][y]='0';
      near[2]=1;
      /*findpath(x+1, y-1,arr);*/
    }
    else if ((arr[x+1][y]!='.')&&(arr[x+1][y]!='0'))
    {
      arr[x][y]='0';
      near[4]=1;

    }

    else if ((arr[x+1][y+1]!='.')&&(arr[x+1][y+1]!='0'))
    {
      arr[x][y]='0';
      near[7]=1;
    }
    for(i=0;i<8;i++)
    {
      if(near[i]==1)
      {
        if(i==2)
        {
          findpath(x+1, y-1,arr,step,terminal_x,terminal_y);
        }
        if(i==4)
        {
          findpath(x+1, y,arr,step,terminal_x,terminal_y);
        }
        if(i==7)
        {
          findpath(x+1, y+1,arr,step,terminal_x,terminal_y);
        }
      }
    }
  }
  if (x!=0)
  {
    if ((arr[x-1][y-1]!='.')&&(arr[x-1][y-1]!='0'))
    {

      arr[x][y]='0';
      near[0]=1;


    }
    if ((arr[x][y-1]!='.')&&(arr[x][y-1]!='0'))
    {

      arr[x][y]='0';
      near[1]=1;


    }
    if ((arr[x+1][y-1]!='.')&&(arr[x+1][y-1]!='0'))
    {

      arr[x][y]='0';
      near[2]=1;


    }
    if ((arr[x-1][y]!='.')&&(arr[x-1][y]!='0'))
    {

      arr[x][y]='0';
      near[3]=1;


    }
    if ((arr[x+1][y]!='.')&&(arr[x+1][y]!='0'))
    {

      arr[x][y]='0';
      near[4]=1;


    }
    if ((arr[x-1][y+1]!='.')&&(arr[x-1][y+1]!='0'))
    {

      arr[x][y]='0';
      near[5]=1;


    }
    if ((arr[x][y+1]!='.')&&(arr[x][y+1]!='0'))
    {

      arr[x][y]='0';
      near[6]=1;


    }
    if ((arr[x+1][y+1]!='.')&&(arr[x+1][y+1]!='0'))
    {

      arr[x][y]='0';
      near[7]=1;
    }

    ways=0;
    for(i=0;i<8;i++)
    {
        if(((near[0]==1)&&(near[1]==1))||((near[1]==1)&&(near[2]==1))||
      ((near[2]==1)&&(near[4]==1))||((near[4]==1)&&(near[7]==1))||
      ((near[7]==1)&&(near[6]==1))||((near[6]==1)&&(near[5]==1))||
    ((near[5]==1)&&(near[3]==1))||((near[0]==1)&&(near[3]==1)))
    {
      arr[x][y]='.';
      return 0;
    }
      else if(near[i]==1)
      {
        ways++;
        if(ways>=2)
        {
          terminal_x=x;
          terminal_y=y;
        }
      }
    }

    for(i=0;i<8;i++)
    {

      if(near[i]==1)
      {
        if(i==0)
        {
          findpath(x-1, y-1,arr,step,terminal_x,terminal_y);
        }
        if(i==1)
        {
          findpath(x, y-1,arr,step,terminal_x,terminal_y);
        }
        if(i==2)
        {
          findpath(x+1, y-1,arr,step,terminal_x,terminal_y);
        }
        if(i==3)
        {
          findpath(x-1, y,arr,step,terminal_x,terminal_y);
        }
        if(i==4)
        {
          findpath(x+1, y,arr,step,terminal_x,terminal_y);
        }
        if(i==5)
        {
          findpath(x-1, y+1,arr,step,terminal_x,terminal_y);

        }
        if(i==6)
        {
          findpath(x, y+1,arr,step,terminal_x,terminal_y);
        }
        if(i==7)
        {
          findpath(x+1, y+1,arr,step,terminal_x,terminal_y);
        }
      }

    }

    if (ways==0)
    {
      if((x==terminal_x)&&(y==terminal_y))
        {
          return 0;
        }


        else if (arr[x-1][y-1]=='0')
        {
          arr[x][y]='.';

          findpath(x-1, y-1,arr,step,terminal_x,terminal_y);
        }
        else if (arr[x][y-1]=='0')
        {
          arr[x][y]='.';

          findpath(x, y-1,arr,step,terminal_x,terminal_y);
        }
        else if (arr[x+1][y-1]=='0')
        {
          arr[x][y]='.';

          findpath(x+1, y-1,arr,step,terminal_x,terminal_y);

        }
        else if (arr[x-1][y]=='0')
        {
          arr[x][y]='.';

          findpath(x-1, y,arr,step,terminal_x,terminal_y);


        }
        else if (arr[x+1][y]=='0')
        {
          arr[x][y]='.';

          findpath(x+1, y,arr,step,terminal_x,terminal_y);


        }
        else if (arr[x-1][y+1]=='0')
        {
          arr[x][y]='.';

          findpath(x-1, y+1,arr,step,terminal_x,terminal_y);


        }
        else if (arr[x][y+1]=='0')
        {
          arr[x][y]='.';

          findpath(x, y+1,arr,step,terminal_x,terminal_y);


        }
        else if (arr[x+1][y+1]=='0')
        {
          arr[x][y]='.';

          findpath(x+1, y+1,arr,step,terminal_x,terminal_y);
        }

      }
    }
  }
