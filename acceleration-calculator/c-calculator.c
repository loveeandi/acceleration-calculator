#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // Needed for malloc() and free()

    // Declare external assembly function
    extern long long int calculate(float i, float f, float t);

int main() {
    int n;
    long long int acceleration;

    // Get how many cars, store in n
    printf("How many cars: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of cars\n");
        return 1;
    }

    // Create 2D array n x 3
    float (*matrix)[3] = malloc(n * sizeof(*matrix));
    if (matrix == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    // Populate matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            if (j == 0) {
                printf("Enter initial velocity for car %d: ", i + 1);
                scanf("%f", &matrix[i][j]);
            }
            else if (j == 1) {
                printf("Enter final velocity for car %d: ", i + 1);
                scanf("%f", &matrix[i][j]);
            }
            else if (j == 2) {
                printf("Enter time for car %d: ", i + 1);
                scanf("%f", &matrix[i][j]);
            }
        }
    }

    // Call ASM function calculate(i, f, t) and print the returned acceleration
    for (int i = 0; i < n; i++) {
        acceleration = calculate(matrix[i][0], matrix[i][1], matrix[i][2]);
        printf("Acceleration for car %d: %lld\n", i + 1, acceleration);
    }

    // Free allocated memory
    free(matrix);
    return 0;
}

On Thu, Nov 26, 2026 at 4:20 PM Naomi Isabelle Reyes <naomi_reyes@dlsu.edu.ph> wrote :

    One attachment
    •  Scanned by Gmail
    ccalulator.c
    100 %
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // Needed for malloc() and free()

    // Declare external assembly function
    extern long long int calculate(float i, float f, float t);

int main() {
    int n;
    long long int acceleration;

    // Get how many cars, store in n
    printf("How many cars: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of cars\n");
        return 1;
    }

    // Create 2D array n x 3
    float (*matrix)[3] = malloc(n * sizeof(*matrix));
    if (matrix == NULL) {
        printf("malloc failed\n");
        return 1;
    }

    // Populate matrix row by row (initial velocity, final velocity, time)
    for (int i = 0; i < n; i++) {
        printf("Enter initial velocity, final velocity, and time for car %d (i, f, t): ", i + 1);
        if (scanf("%f, %f, %f", &matrix[i][0], &matrix[i][1], &matrix[i][2]) != 3) {
            printf("Invalid input format. Expected: float, float, float\n");
            free(matrix);
            return 1;
        }
    }

    // Call ASM function calculate(i, f, t) and print the returned acceleration
    for (int i = 0; i < n; i++) {
        acceleration = calculate(matrix[i][0], matrix[i][1], matrix[i][2]);
        printf("Acceleration for car %d: %lld\n", i + 1, acceleration);
    }

    // Free allocated memory
    free(matrix);
    return 0;
}
Displaying ccalulator.c.