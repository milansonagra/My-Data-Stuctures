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
     int key,flag=1;
     printf("Enter the number you want to search from Array: ");
     scanf("%d",&key);

     for(i=0;i<length;i++)
     {
          if(key==Array[i])
          {
               printf("\nREASULT:-\tEntered element %d is found at index - %d",Array[i],i);
               flag--;
               break;
          }
     }
     if(flag)
     {
          printf("\nREASULT:-\tEntered number is not found !");
     }
}
