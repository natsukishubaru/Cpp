#include <stdio.h>
#include <math.h>

int main()
{
    // Define parameters
    double alpha = 0.01;  // Thermal diffusivity
    double L = 1.0;       // Length of the rod
    double T = 0.1;       // Total simulation time
    int nx = 11;          // Number of spatial points
    int nt = 51;          // Number of time points

    double dx = L / (nx - 1);  // Spatial step
    double dt = T / (nt - 1);  // Time step
    double lambda = alpha * dt / (dx * dx);

    if (lambda > 0.5)
    {
        printf("The scheme is unstable. Reduce time step or increase spatial resolution.\n");
        return 0;
    }

    // Create 2D array to store temperature values
    double u[nt][nx];

    // Initial condition: u(x, 0) = sin(pi * x)
    for (int i = 0; i < nx; ++i)
    {
        double x = i * dx;
        u[0][i] = sin(M_PI * x);
    }

    // Time stepping using explicit finite difference method
    for (int n = 0; n < nt - 1; ++n)
    {
        for (int i = 1; i < nx - 1; ++i)
        {
            u[n + 1][i] = u[n][i] + lambda * (u[n][i - 1] - 2 * u[n][i] + u[n][i + 1]);
        }

        // Boundary conditions: u(0, t) = 0, u(L, t) = 0
        u[n + 1][0] = 0.0;
        u[n + 1][nx - 1] = 0.0;
    }

    // Display results
    printf("Temperature distribution at different time steps:\n\n");
    for (int n = 0; n < nt; ++n)
    {
        printf("Time t = %.4f:\t", n * dt);
        for (int i = 0; i < nx; ++i)
        {
            printf("%8.4f ", u[n][i]);
        }
        printf("\n");
    }

    return 0;
}