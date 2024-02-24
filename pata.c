#include <stdio.h>

int main() {
    int r, c, i, j, k = 1, count = 0, a[100][100], s[100][100], t[100][3];

    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r, &c);
    printf("Enter the array elements: ");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Array elements are:\n");

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }

    s[0][0] = r;
    s[0][1] = c;

    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            if (a[i][j] != 0) {
                count++;
                s[count][0] = i;
                s[count][1] = j;
                s[count][2] = a[i][j];
            }
        }
    }

    s[0][2] = count;

    printf("Sparse matrix: \n");

    for (i = 0; i <= count; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    t[0][0] = c; // Number of rows in transpose equals number of columns in original
    t[0][1] = r; // Number of columns in transpose equals number of rows in original
    t[0][2] = count;

    for (i = 0; i < c; i++) {
        for (j = 1; j <= count; j++) {
            if (s[j][1] == i) {
                t[k][0] = s[j][1];
                t[k][1] = s[j][0];
                t[k][2] = s[j][2];
                k++;
            }
        }
    }

    printf("Transpose of the given matrix: \n");

    for (i = 0; i <= t[0][2]; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", t[i][j]);
        }
        printf("\n");
    }

    return 0;
}
