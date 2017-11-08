#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int
test_trolls(int x, int y, char arr[30][30],int step[200], int terminal_x, int terminal_y)
{
  int i,near[8],ways, routex[200],routey[200],c,k;
  for(i=0;i<8;i++)
  {
    near[i]=0;
  }
    if (x==29){

     arr[x][y]='*';

     return 0;

    }

  if (x==0)
  {
    if ((arr[x+1][y-1]!='.')&&(arr[x+1][y-1]!='*'))
    {
      arr[x][y]='*';
      near[2]=1;
    }
    else if ((arr[x+1][y]!='.')&&(arr[x+1][y]!='*'))
    {
      arr[x][y]='*';
      near[4]=1;

    }

    else if ((arr[x+1][y+1]!='.')&&(arr[x+1][y+1]!='*'))
    {
      arr[x][y]='*';
      near[7]=1;
    }
    for(i=0;i<8;i++)
    {
      if(near[i]==1)
      {
        if(i==2)
        {
          test_trolls(x+1, y-1,arr,step,terminal_x,terminal_y);
        }
        if(i==4)
        {
          test_trolls(x+1, y,arr,step,terminal_x,terminal_y);
        }
        if(i==7)
        {
          test_trolls(x+1, y+1,arr,step,terminal_x,terminal_y);
        }
      }
    }
  }
  if (x!=0)
  {

    if ((arr[x][y-1]!='.')&&(arr[x][y-1]!='*'))
    {

      arr[x][y]='*';
      near[1]=1;
      test_trolls(x, y-1,arr,step,terminal_x,terminal_y);


    }
    else if ((arr[x+1][y-1]!='.')&&(arr[x+1][y-1]!='*'))
    {

      arr[x][y]='*';
      near[2]=1;
      test_trolls(x+1, y-1,arr,step,terminal_x,terminal_y);


    }
    else if ((arr[x-1][y]!='.')&&(arr[x-1][y]!='*'))
    {

      arr[x][y]='*';
      near[3]=1;
      test_trolls(x-1, y,arr,step,terminal_x,terminal_y);


    }
    else if ((arr[x+1][y]!='.')&&(arr[x+1][y]!='*'))
    {

      arr[x][y]='*';
      near[4]=1;
      test_trolls(x+1, y,arr,step,terminal_x,terminal_y);


    }
    else if ((arr[x-1][y+1]!='.')&&(arr[x-1][y+1]!='*'))
    {

      arr[x][y]='*';
      near[5]=1;
      test_trolls(x-1, y+1,arr,step,terminal_x,terminal_y);


    }
    else if ((arr[x][y+1]!='.')&&(arr[x][y+1]!='*'))
    {

      arr[x][y]='*';
      near[6]=1;
      test_trolls(x, y+1,arr,step,terminal_x,terminal_y);


    }
    else if ((arr[x+1][y+1]!='.')&&(arr[x+1][y+1]!='*'))
    {

      arr[x][y]='*';
      near[7]=1;
      test_trolls(x+1, y+1,arr,step,terminal_x,terminal_y);
    }
    else if ((arr[x-1][y-1]!='.')&&(arr[x-1][y-1]!='*'))
    {

      arr[x][y]='*';
      near[0]=1;
      test_trolls(x-1, y-1,arr,step,terminal_x,terminal_y);


    }
    else{
      if (arr[x+1][y+1]=='*')
      {
        arr[x][y]='.';

        test_trolls(x+1, y+1,arr,step,terminal_x,terminal_y);
      }

     else if (arr[x-1][y-1]=='*')
      {
        arr[x][y]='.';

        test_trolls(x-1, y-1,arr,step,terminal_x,terminal_y);
      }
      else if (arr[x][y-1]=='*')
      {
        arr[x][y]='.';

        test_trolls(x, y-1,arr,step,terminal_x,terminal_y);
      }
      else if (arr[x+1][y-1]=='*')
      {
        arr[x][y]='.';

        test_trolls(x+1, y-1,arr,step,terminal_x,terminal_y);

      }
      else if (arr[x-1][y]=='*')
      {
        arr[x][y]='.';

        test_trolls(x-1, y,arr,step,terminal_x,terminal_y);


      }
      else if (arr[x+1][y]=='*')
      {
        arr[x][y]='.';

        test_trolls(x+1, y,arr,step,terminal_x,terminal_y);


      }
      else if (arr[x-1][y+1]=='*')
      {
        arr[x][y]='.';

        test_trolls(x-1, y+1,arr,step,terminal_x,terminal_y);


      }
      else if (arr[x][y+1]=='*')
      {
        arr[x][y]='.';

        test_trolls(x, y+1,arr,step,terminal_x,terminal_y);


      }
    }



    }
  }
