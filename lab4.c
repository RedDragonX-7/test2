/**
 * Numerical INtegration using general quadrature formula (Trapezoida, Simpson't 1/3 and Simpson's 3/8 rule)
 */
#include <stdio.h>
#include <math.h>
float f(float x)
{
    return 1 / x;
}
float TrapezoidalRule(float a, float b, int n)
{
    float h = (b - a) / n;
    float I = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        float x = a + i * h;
        I += 2 * f(x);
    }
    printf("\n I(Trapezoidal Rule) = %.5f",(h / 2) * I);
    return 0;
}

float SimpsonOneThirdRule(float a, float b, int n)
{
    float h = (b - a) / n;
    float I = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        float x = a + i * h;
        if (i % 2 == 0)
            I += 2 * f(x);
        else
            I += 4 * f(x);
    }
    printf("\n I(Simpson One Third Rule) = %.5f",(h / 3) * I);
    return 0;
}

float SimpsonThreeEightRule(float a, float b, int n)
{
    float h = (b - a) / n;
    float I = f(a) + f(b);
    for (int i = 1; i < n; i++)
    {
        float x = a + i * h;
        if (i % 3 == 0)
            I += 2 * f(x);
        else
            I += 3 * f(x);
    }
    printf("\n I(Simpson Three Eight Rule) = %.5f",3 * (h / 8) * I);
    return 0;
}

int main()
{
    float a, b, I_trap, Is13, Is38, h;
    int n;
    printf("\nEnter lower limit and upper limit: ");
    scanf("%f%f", &a, &b);
    printf("\nEnter no. of segments: ");
    scanf("%d", &n);

    printf("\nCaulating integral of 1/x from %.1f to %.1f\n", a, b);

    I_trap = TrapezoidalRule(a, b, n);
    if (n % 2 == 0)
    {
        Is13 = SimpsonOneThirdRule(a, b, n);
    }
    else
    {
        printf("\n not applicable for SimptionOneThirdRule:");
    }
    if (n % 3 == 0)
    {
        Is38 = SimpsonThreeEightRule(a, b, n);
    }    
    else
    {
        printf("\n not applicable for simpson ThreeEightRule:");
    }

           return 0;
}