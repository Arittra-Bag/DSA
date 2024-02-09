#include<stdio.h>

// INTERPOLATION SEARCH ALGORITHM
int interpolation_search(int arr[], int n, int key)
{
    int low = 0, high = n-1, mid;
    while(low <= high){
        mid = low + (((key - arr[low]) * (high - low)) / (arr[high] - arr[low]));
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            low = mid + 1;
        }
        else if(arr[mid] > key)
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n, i, key, pos;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element to be searched: ");
    scanf("%d", &key);
    pos = interpolation_search(arr, n, key);
    if(pos == -1){
        printf("Element not found\n");
    }
    else{
        printf("Element found at position %d\n", pos+1);
    }  
    return 0;
}