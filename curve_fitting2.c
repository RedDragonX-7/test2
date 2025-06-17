#include<stdio.h>
#include<math.h>
#define size 20
int main()
{
    float x[size], y[size], log_x, log_y, sumx, sumy, sumxy, sumxx, a,b;
    int n,i;
    printf("Enter number of data points: ");
    scanf("%d",&n);
    printf("Enter data points [X,Y]: ");
    for(i=0;i<n;i++)
    {
        scanf("%f%f",&x[i],&y[i]);
    }
    for(i=0;i<n;i++)
    {
        log_x=log(x[i]);
        log_y=log(y[i]);
        sumx += log_x;
        sumy += log_y;
        sumxy += log_x*log_y;
        sumxx += log_x*log_x;
    }
    float A,B;
    B=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
    A=(sumy-b*sumx)/n;
    a=exp(A);
    
    printf("\nA: %f\nB: %f\n",a,B);
    printf("\nA + BX = %f + (%f)B", a,B);
    return 0;
}