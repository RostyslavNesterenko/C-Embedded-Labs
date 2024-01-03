#include <stdio.h>
#include <math.h>

int main() {
    double m, numerator, denominator, z1, z2;

    // Prompt the user to enter the value of m
    printf("Enter the value of m: ");
    scanf("%lf", &m);

    // Check for possible mathematical errors for z1
    if (m <= 0) {
        printf("The value of m must be positive to compute the square roots for z1.\n");
        return 1;
    }

    // Calculate the numerator for z1
    numerator = sqrt(pow(3 * m + 2, 2) - 24 * m);

    // Calculate the denominator for z1
    double sqrt_m = sqrt(m);
    denominator = 3 * sqrt_m - 2 / sqrt_m;

    // Check for division by zero for z1
    if (denominator == 0) {
        printf("The expression for z1 cannot be computed because of division by zero.\n");
        return 1;
    }

    // Compute z1
    z1 = numerator / denominator;

    // Check for possible mathematical errors for z2
    if (m < 0) {
        printf("The value of m must be non-negative to compute the square root for z2.\n");
        return 1;
    }

    // Compute z2
    z2 = -sqrt(m);

    // Output the result
    printf("The value of z1 is: %lf\n", z1);
    printf("The value of z2 is: %lf\n", z2);

    return 0;
}
