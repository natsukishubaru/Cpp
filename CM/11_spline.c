#include <stdio.h>
int main()
{
    int n;
    printf("First degree spline function\n");
    printf("Name: Shubham Dahiya\nClass: 3C1\nRoll No. : 004 1480 2724");
    printf("\nEnter the no. of data points : ");
    scanf("%d",&n);
    float x[n],y[n];
    
    printf("Enter the data points (x and y) : \n");
    for(int i=0;i<n;i++)
    {
        printf("x[%d] = ",i);
        scanf("%f",&x[i]);
        printf("y[%d] = ",i);
        scanf("%f",&y[i]);
        
    }
    
    float m[n-1];
    for(int i=0;i<n-1;i++){
        m[i]=(y[i+1]-y[i])/(x[i+1]-x[i]);
        
    }
    printf("\nFirst degree spline functions : \n");
    for(int i=0;i<n-1;i++){
        printf("For internal [%.2f, %.2f : \n",x[i],x[i+1]);
        printf("s(x) = %.2f(x-%.2f) + %.2f\n",m[i],x[i],y[i]);
    }
    float x_val;
    printf("\nEnter the value of x for interpolation : ");
    scanf("%f",&x_val);
    
    for(int i=0;i<n-1;i++){
        if(x_val>=x[i]&&x_val<=x[i+1])
        {
            float y_val=m[i]*(x_val-x[i])+y[i];
            printf("The interpolated value at x = %.2f is y = %.2f\n",x_val,y_val);
            break;
        }
    }
    return 0;
}