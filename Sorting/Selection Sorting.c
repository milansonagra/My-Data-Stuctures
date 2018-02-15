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

     int min;
     for(i=0;i<length;i++)
     {
          min=Array[i];
          for(j=i;j<length;j++)
          {
               if(min>Array[j])
               {
                    min = min + Array[j];
                    Array[j] = min - Array[j];
                    min = min - Array[j];
               }
          }
          Array[i]=min;
     }

     printf("ARRAY:-\n");
     for(i=0;i<length;i++)
     {
          printf("\t %d\n",Array[i]);
     }
}
