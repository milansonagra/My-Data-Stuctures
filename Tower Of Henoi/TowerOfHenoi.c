#include<stdio.h>
int moves=0;
void move(char Src,char Use,char Dest,int r)
{
    moves++;
    if(r==1)
    {
        printf("move disk Tower-%c to Tower-%c\n",Src,Dest);
        return;
    }
    move(Src,Dest,Use,r-1);
    printf("move disk Tower-%c to Tower-%c\n",Src,Dest);
    move(Use,Dest,Src,r-1);
}
int main()
{
    int no_ring;
    printf("Enter the number of Rings:");
    scanf("%d",&no_ring);

    move('A','B','C',no_ring);
    printf("\nTotal %d number of moves are performed.",moves);
}
