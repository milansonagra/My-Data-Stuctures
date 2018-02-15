#include<stdio.h>
int main()
{
     int i,j,length;
     printf("Enter the length of the array:");
     scanf("%d",&length);

     int Array[length];
     printf("Enter the array:-\n");
     for(i=0;i<length;i++)
     {
          printf("\t-> ");
          scanf("%d",&Array[i]);
     }

     for(i=0;i<length;i++)
     {
          int flag=0;
          for(j=0;j<length-i-1;j++)
          {
               int temp;
               if(Array[j]>Array[j+1])
               {
                    Array[j] = Array[j] + Array[j+1];
                    Array[j+1] = Array[j] - Array[j+1];
                    Array[j] = Array[j] - Array[j+1];
                    flag++;
               }
          }
          if(flag==0)
          {
               break;
          }
          printf("\n%d\n",i);
     }

     printf("ARRAY:-\n");
     for(i=0;i<length;i++)
     {
          printf("\t %d\n",Array[i]);
     }

}
