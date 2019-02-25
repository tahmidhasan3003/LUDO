#include<stdio.h>
int main()
{
    int n,i,j,y,x=1;
    scanf("%d",&n);
    n=(n+1)/2;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=(n-i)*2;j++)
            printf(" ");
        for(j=i;j<=x;j++)
            printf("%d ",j);
        for(j=x-1;j>=i;j--)
            printf("%d ",j);
        printf("\n");
        x+=2;
    }
    return 0;
}
