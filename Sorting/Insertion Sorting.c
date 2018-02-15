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

     int key;
     for(i=2;i<length;i++)
     {
          key=Array[i];
          j=i-1;
          while(j>=0 && key<Array[j])
          {
              Array[j+1]=Array[j];
              j--;
          }
          Array[j+1]=key;
     }


     printf("ARRAY:-\n");
     for(i=0;i<length;i++)
     {
          printf("\t %d\n",Array[i]);
     }


}
