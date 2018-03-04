#include<stdio.h>

long int Array[20];

void addInArray(long int x)
{
    int Hash;
    short int flag=0;
    Hash = (x % 18)+2;

    while(Array[Hash]!=0 || flag>=20)
    {
        Hash=(Hash<20)?Hash+1:0;
        flag++;
    }

    Array[Hash] = x;

    printf("Element %ld is endered success-fully at index of - %d.\n",x,Hash);
}
int main()
{
    int i;
    long int x;
    for(i=0;i<20;i++)
        Array[i]=0;

    for(i=0;i<15;i++)
    {
        ReEnter:
            printf("\nEnter any number between 1,00,000 and 9,99,999:");
            scanf("%ld",&x);

            if(x < 100000 || x > 999999)
            {
                goto ReEnter;
            }

            addInArray(x);
    }

    printf("Last array:-\n");
    for(i=0;i<20;i++)
    {
        printf("%\t| %d\t| %ld \n",i,Array[i]);
    }
}
