//Curve fitting using regression analysis
#include<stdio.h>
#include<math.h>
#define size 20
int main()
{
    float x[size], y[size], sumx, sumy, sumxy, sumxx, a,b;
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
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i]*y[i];
        sumxx += x[i]*x[i];
    }
    float A,B;
    B=(n*sumxy-sumx*sumy)/(n*sumxx-sumx*sumx);
    A = (sumy-sumx*B)/n;
    printf("\nA: %f\nB: %f\n",A,B);
    printf("\nA + BX = %f + (%f)B", A,B);
    return 0;
}
