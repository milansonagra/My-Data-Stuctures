#include<stdio.h>
int *MackingChange(int change)
{
    int coins[]={500,100,50,20,10,5,2,1};
    int i=0,j=0,number_of_coinsGiven=0;
    int change_amount[100];

    while(change>0)
    {
        if(coins[i]<=change)
        {
            change -= coins[i];
            change_amount[j] = coins[i];
            j++;
            number_of_coinsGiven++;
        }
        else
        {
            i++;
        }
    }
    change_amount[99] = number_of_coinsGiven;

    return change_amount;
}
int main()
{
    int N,A_gives,change,i;

    REENTER:
    printf("Enter the amount A wants to give to B:");
    scanf("%d",&N);

    printf("--> Actual amount A gives to B:");
    scanf("%d",&A_gives);

    if(A_gives >= N)
    {
        change = A_gives - N;
    }
    else
    {
        printf("\n---------------ERROR!---------------");
        printf("\nGiven money is not enough!\nPlease enter carefully...\n\n");
        goto REENTER;
    }
    printf("\nTo give the change amount %d B need : ",change);
    int *coins = MackingChange(change);

    int ind = *(coins+99);
    for(i=0;i<ind;i++)
    {
        printf("\t%d,",*(coins+i));
    }
    printf(" coins.\n");
}
