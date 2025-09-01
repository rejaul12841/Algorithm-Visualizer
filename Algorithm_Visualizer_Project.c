#include <stdio.h>
#include <stdlib.h>

// Linear Search
void linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        printf("Checking index %d: %d\n", i, arr[i]);
        if (arr[i] == target) {
            printf("Target Found at index %d!\n", i);
            return;
        }
    }
    printf("Target not found.\n");
}

// Binary Search
void binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        printf("Middle element: %d\n", arr[mid]);
        if (arr[mid] == target) {
            printf("Target Found!\n");
            return;
        } else if (arr[mid] < target) {
            printf("Go Right\n");
            left = mid + 1;
        } else {
            printf("Go Left\n");
            right = mid - 1;
        }
    }
    printf("Target not found.\n");
}

// Basic Sorting Algorithms
void insertionSort(int arr[], int n) {
    printf("\n.... Insertion Sort ....\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i], j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void bubbleSort(int arr[], int n) {
    printf("\n... Bubble Sort ....\n");
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j]; arr[j] = arr[j+1]; arr[j+1] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// Divide & Conquer Sorting

void merge(int arr[], int l, int m, int r) {
    int n1 = m-l+1, n2 = r-m;
    int L[n1], R[n2];
    for (int i=0;i<n1;i++) L[i]=arr[l+i];
    for (int j=0;j<n2;j++) R[j]=arr[m+1+j];

    int i=0, j=0, k=l;
    while(i<n1 && j<n2) {
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }
    while(i<n1) arr[k++]=L[i++];
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}


int partitionPivot(int arr[], int low, int high, int pivotIndex) {
    int pivot = arr[pivotIndex];
    int temp = arr[pivotIndex]; arr[pivotIndex] = arr[high]; arr[high] = temp;

    int i = low - 1;
    for(int j=low;j<high;j++){
        if(arr[j]<=pivot){
            i++;
            int t=arr[i]; arr[i]=arr[j]; arr[j]=t;
        }
    }
    temp=arr[i+1]; arr[i+1]=arr[high]; arr[high]=temp;
    return i+1;
}

void quickSort(int arr[], int low, int high, int pivotIndex, int firstCall) {
    if(low<high){
        int pi;
        if(firstCall){
            pi = partitionPivot(arr, low, high, pivotIndex);
        } else {
            pi = partitionPivot(arr, low, high, high);
        }
        quickSort(arr, low, pi-1, pivotIndex, 0);
        quickSort(arr, pi+1, high, pivotIndex, 0);
    }
}

// Greedy Algorithms
void fractionalKnapsack() {
    int n; printf("Number of items: "); scanf("%d",&n);
    float w[n], p[n];
    for(int i=0;i<n;i++) {
        printf("Enter profit and weight of item %d: ", i+1);
        scanf("%f %f",&p[i], &w[i]);
    }
    float W; printf("Enter maximum capacity: "); scanf("%f",&W);
    float ratio[n];
    for(int i=0;i<n;i++) ratio[i]=p[i]/w[i];

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(ratio[i]<ratio[j]){
                float t=ratio[i]; ratio[i]=ratio[j]; ratio[j]=t;
                t=p[i]; p[i]=p[j]; p[j]=t;
                t=w[i]; w[i]=w[j]; w[j]=t;
            }

    float total=0;
    for(int i=0;i<n;i++){
        if(w[i]<=W){ W-=w[i]; total+=p[i]; }
        else { total+=p[i]*(W/w[i]); break; }
    }
    printf("Maximum Profit = %.2f\n", total);
}

void coinChangeGreedy() {
    int n; printf("Number of coin types: "); scanf("%d",&n);
    int coins[n];
    printf("Enter coin values: ");
    for(int i=0;i<n;i++) scanf("%d",&coins[i]);
    int amount; printf("Enter amount: "); scanf("%d",&amount);

    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(coins[i]<coins[j]){
                int t=coins[i]; coins[i]=coins[j]; coins[j]=t;
            }

    printf("Coins used: ");
    for(int i=0;i<n;i++)
        while(amount>=coins[i]){ amount-=coins[i]; printf("%d ", coins[i]); }
    printf("\n");
}

// Sorting Menu
void sortingMenu() {
    int opt,n;
    printf("\n.... Sorting Menu ....\n");
    printf("Select Sorting Type:\n1. Basic Sorting (Insertion / Bubble)\n2. Divide and Conquer Techniques (Quick / Merge)\nEnter option: ");
    scanf("%d",&opt);

    if(opt==1){
        printf("\n.... Basic Sorting Selected ....\n");
        int sopt;
        printf("1. Insertion Sort\n2. Bubble Sort\nEnter option: "); scanf("%d",&sopt);
        printf("Enter number of elements: "); scanf("%d",&n);
        int arr[n];
        printf("Enter elements: ");
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);
        if(sopt==1) insertionSort(arr,n);
        else bubbleSort(arr,n);
    } else {
        printf("\n.... Divide and Conquer Techniques Selected ....\n");
        int sopt;
        printf("1. Quick Sort\n2. Merge Sort\nEnter option: "); scanf("%d",&sopt);
        printf("Enter number of elements: "); scanf("%d",&n);
        int arr[n];
        printf("Enter elements: ");
        for(int i=0;i<n;i++) scanf("%d",&arr[i]);

        if(sopt==1){
            int pivotIndex;
            printf("Enter pivot index for Quick Sort (0 to %d): ", n-1);
            scanf("%d", &pivotIndex);
            quickSort(arr,0,n-1,pivotIndex,1);
        } else mergeSort(arr,0,n-1);

        printf("Sorted array: ");
        for(int i=0;i<n;i++) printf("%d ", arr[i]);
        printf("\n");
    }
}

// Main Menu
int main() {
    int choice;
    while(1){
        printf("\n.... Algorithm Visualizer ....\n");
        printf("1. Search (Linear / Binary)\n");
        printf("2. Sorting ( Basic Sorting / Divide and Conquer Techniques)\n");
        printf("3. Greedy Algorithms (Fractional Knapsack / Coin Change)\n");
        printf("4. Exit\n");
        printf("Enter choice: "); scanf("%d",&choice);

        if(choice==1){
            int n,target,opt;
            printf("1. Linear Search\n2. Binary Search\nEnter option: "); scanf("%d",&opt);
            printf("Enter number of elements: "); scanf("%d",&n);
            int arr[n];
            printf("Enter elements: ");
            for(int i=0;i<n;i++) scanf("%d",&arr[i]);
            printf("Enter target: "); scanf("%d",&target);
            if(opt==1) linearSearch(arr,n,target);
            else binarySearch(arr,n,target);
        }
        else if(choice==2) sortingMenu();
        else if(choice==3){
            int opt; printf("1. Fractional Knapsack\n2. Coin Change\nEnter option: "); scanf("%d",&opt);
            if(opt==1) fractionalKnapsack();
            else coinChangeGreedy();
        }
        else if(choice==4){ printf("Exiting...\n"); break; }
        else printf("Invalid choice.\n");
    }
    return 0;
}
