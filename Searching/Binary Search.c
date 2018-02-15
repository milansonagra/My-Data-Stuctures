#include<stdio.h>
void BinarySearch(int aa[],int key,int start,int end)
{
     int mid=(start+end)/2;
     if(start<=end)
     {
          if(key==aa[mid])
               printf("\nREASULT:-\tKey element %d is found at index - %d",aa[mid],mid);
          else if(key<aa[mid])
               return BinarySearch(aa,key,0,mid-1);
          else
               return BinarySearch(aa,key,mid+1,end);
     }
     else
     {
          printf("\nREASULT:-\tEntered number is not found !");
     }
}
void ShortArray(int *a,int length)
{
     int i,j;
     for(i=0;i<length;i++)
     {
          for(j=i;j<length;j++)
          {
               if(*(a+i)>*(a+j))
               {
                    *(a+i) = *(a+i) + *(a+j);
                    *(a+j) = *(a+i) - *(a+j);
                    *(a+i) = *(a+i) - *(a+j);
               }
          }
     }
}
int main()
{
     int l;
     int key;
     printf("Enter the length of array:");
     scanf("%d",&l);
     int a[l],i;
     for(i=0;i<l;i++)
     {
          printf("\t-> ");
          scanf("%d",&a[i]);
     }
     printf("Enter the element you want to search from array:");
     scanf("%d",&key);

     ShortArray(a,l);
     BinarySearch(a,key,0,l-1);
}
