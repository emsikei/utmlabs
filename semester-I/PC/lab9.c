#include <stdio.h> 
#include <math.h> 

float getFuncValue(float a, float b, float c, float x); 

int main() {
    float   a, b, c;
    float   startX, endX, dX;
    float   F;
    
    printf("Enter:");
    printf("\ta = "); scanf("%f", &a);
    printf("\tb = "); scanf("%f", &b);
    printf("\tc = "); scanf("%f", &c);
    printf("\tX start = "); scanf("%f", &startX);
    printf("\tX end = "); scanf("%f", &endX);
    printf("\tdX = "); scanf("%f", &dX);

    for (float x = startX; x <= endX; x += dX) { 

        F = getFuncValue(a, b, c, x); 
        printf("x = %.2f\t", x);
        printf("F = %.2f\n", F);
    }
 
    return 0;
}


float getFuncValue(float a, float b, float c, float x) { 
    float res = 0.0; 
    if (x + c < 0 && b == 0) 
    {
        res = (a + b) / log(x - c);
    }
    else if (x + c > 0 && b != 0)
    {
        res = (sin(a) - x + 3) / pow(c, 2); 
    }
    else
    {
        res = (4 * x + 8) / pow(a, 2) + sin(x); 
    }
    return res; 
}


