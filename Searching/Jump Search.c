#include<stdio.h>
#include<math.h>
#include<stdlib.h>
void JumpSearch(int arr[],int jump,int key)
{
     static int i=0;i++;
     if(key==arr[jump])
     {
          printf("\n\n\tThe searched number is found after %d jump.",i);
     }
     else if(key>arr[jump])
     {
          JumpSearch(arr,jump*i,key);
     }
     else
     {
          jump/=i;
          int cnt,flag=0;
          for(cnt=jump;cnt<jump*i;cnt++)
          {
               if(arr[cnt]==key)
               {
                    printf("\n\n\tThe searched number is found after %d jump.\n\tAnd %d linear search.",i,cnt-jump);
                    flag++;
                    break;
               }
          }
          if(flag==0)
          {
               printf("\n\n\tEntered number is not found in the list.");
          }
     }
}
int main()
{
     int i,length;
     printf("Enter the length of array: ");
     scanf("%d",&length);
     int array[length];
     printf("Enter the array:-\n");
     for(i=0;i<length;i++)
     {
          printf("\t->  ");
          scanf("%d",&array[i]);
     }

     int key,jump;
     printf("Enter the number you want to find : ");
     scanf("%d",&key);
     if(key>array[length])
     {
          printf("\n\tThe number you entered is not in range !");
          exit(0);
     }
     jump=sqrt(length);

     JumpSearch(array,jump,key);
}
