#include <stdio.h>
#include<stdlib.h>
//Count Sort
void countingSort(int arr[], int n, int exp)
{
    
    int output[n],i;
    int dig_freq[10] = {0};
    // Count occurrences of each digit in the current place value
    for (i = 0; i < n; i++) {
        dig_freq[(arr[i] / exp) % 10]++;
    }
    // store cumulative count
    for (i = 1; i < 10; i++)
	{
        dig_freq[i] += dig_freq[i - 1];
    }
    // Build the output array using count array
    for (i = n - 1; i >= 0; i--)
	{
        output[dig_freq[(arr[i] / exp) % 10] - 1] = arr[i];
        dig_freq[(arr[i] / exp) % 10]--;
    }
    // Copy the output array to the original array
    for (i = 0; i < n; i++)
	{
        arr[i] = output[i];
    }
}
//Radix Sort
void RadixSort(int *a,int n)
{   
    //finding max
    int max=a[0];
	int i,exp;
	for(i=0;i<n;i++)
	 max=a[i]>max?a[i]:max;
	 
    for(exp=1;max/exp>0;exp *=10)
        countingSort(a,n,exp);
}

int main() {
    int n1;
    printf("Enter the size of the array: ");
    scanf("%d", &n1);

    int *a = (int *)malloc(n1 * sizeof(int));
    int i;

    printf("Enter the array:\n");
    for (i = 0; i < n1; i++)
        scanf("%d", &a[i]);

    RadixSort(a, n1);

    printf("\nSorted array:\n");
    for (i = 0; i < n1; i++)
        printf("%d ", a[i]);

    free(a);

    return 0;
}
