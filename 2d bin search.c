#include <stdio.h>
#include <stdlib.h>

int binarySearch1D(int arr[], int K, int N) {
    int low = 0;
    int high = N - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == K)
            return mid;
        if (arr[mid] < K)
            low = mid + 1;
        else
            high = mid - 1;
    }

    // if not found, return -1
    return -1;
}

int main() {
    // INPUT
    int m, n;
    printf("Enter the number of rows-\n");
    scanf("%d", &m);
    printf("Enter the number of columns-\n");
    scanf("%d", &n);

    int a[m][n];
    int i, j, row = -1, col = -1;  // Initialize row and col to -1
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter element at index-(%d,%d)\n", i, j);
            scanf("%d", &a[i][j]);
            printf("\n");
        }
    }  // for i

    // array display
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d  ", a[i][j]);
        }
        printf("\n");
    }  // for i

    int K;
    printf("Enter the element to be searched-\n");
    scanf("%d", &K);
    int low = 0;
    int high = m - 1;

    // binary search on first column
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (K >= a[mid][0] && K <= a[mid][n - 1]) {
            row = mid;
            // binary search on that column
            col = binarySearch1D(a[mid], K, n);
            break;  // Add break here to exit the loop once a match is found
        } else if (K < a[mid][0]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (col != -1)
        printf("Element found at-(%d,%d)\n", row, col);
    else
        printf("Not found\n");

    return 0;
}
