#include <stdio.h>
#include <stdlib.h>

// Counting sort algorithms for specefic values in dataset
void Count_sorting(int array[], int sz, int expo) {
    int out_array[sz];
    int count_freq[10] = {0};
    int i;

    //to count number of times a value has appeared
    for (i = 0; i < sz; i++) {
        count_freq[(array[i] / expo) % 10]++;
    }

    // Calculate the running sum of the counts
    for (i = 1; i < 10; i++) {
        count_freq[i] += count_freq[i - 1];
    }

    // creating an array that contains the values sorted into order
    for (i = sz - 1; i >= 0; i--) {
        out_array[count_freq[(array[i] / expo) % 10] - 1] = array[i];
        count_freq[(array[i] / expo) % 10]--;
    }

    // Copy the sorted array back to the original array
    for (i = 0; i < sz; i++) {
        array[i] = out_array[i];
    }
}

// Radix sort the array
void Radix_Sorting_algo(int arr1[], int n) {
    // Find the maximum value in the array to determine the maximum number of digits
    int valMaximum = arr1[0];
    int i;
    for (i = 1; i < n; i++) {
        if (arr1[i] > valMaximum) {
            valMaximum = arr1[i];
        }
    }

    // Sort the array for each digit, starting from the least significant digit
    for (int expo = 1; valMaximum / expo > 0; expo *= 10) {
        Count_sorting(arr1, n, expo);
    }
}

// Binary search the sorted array for a specific value
int Binary_Searching_Algo(int arr1[], int n, int p) {
    int begin = 0;
    int finish = n - 1;
    while (begin <= finish) {
        int middle = (begin + finish) / 2;
        if (arr1[middle] == p) {
            return middle;
        } else if (arr1[middle] < p) {
            begin = middle + 1;
        } else {
            finish = middle - 1;
        }
    }
    return -1;
}

// Insert a new record into the dataset
void Insert_new_Record(int arr[], int* n, int x) {
    arr[*n] = x;
    (*n)++;
    Radix_Sorting_algo(arr, *n);
}

// Delete a record from the dataset
void Delete_old_rec(int arr[], int* n, int x) {
    int i = Binary_Searching_Algo(arr, *n, x);
    if (i != -1) {
        for (; i < *n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        (*n)--;
        printf("Dataset after deleting %d:\n", x);
        for (int i = 0; i < *n; i++) {
            printf("%d ", arr[i]);
        }
        
    }
    else if(i==-1)
    {
        printf("-1\n");
    }
    
}

int main() {
    int size=rand()%100;
    int dataset[size];
    for(int i=0;i<size;i++){
     dataset[i]=rand()%1000;
    }
    int n = sizeof(dataset) / sizeof(dataset[0]);
    Radix_Sorting_algo(dataset, n);
    printf("Initial dataset:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", dataset[i]);
    }
    printf("\n\n");
    
    char ch;
    while(1){
        printf("Enter operation you want to perform on the dataset.\n|S:search | I:insert | D:delete | E:exit | ");
        scanf(" %c", &ch);
        if(ch =='S' ||ch=='s'){
            int targ;
            printf("Enter an element to be checked:  ");
            scanf("%d",&targ);
            int result = Binary_Searching_Algo(dataset, n, targ);
        
            // Print the result
            if (result != -1) {
                printf("Found %d at index %d\n", targ, result);
            } else {
                printf("%d not found in the dataset\n", targ);
            }
                printf("\n");
        }
        else if(ch=='I' || ch=='i'){
            int new_record;
            printf("Insert a new element:  ");
            scanf("%d",&new_record);
            Insert_new_Record(dataset, &n, new_record);
            printf("Dataset after inserting %d:\n", new_record);
            for (int i = 0; i < n; i++) {
                printf("%d ", dataset[i]);
            }
            printf("\n\n");
        }
        else if(ch=='D' ||ch== 'd'){
            int record_to_delete;
            printf("Delete an element:  ");
            scanf("%d",&record_to_delete);
            Delete_old_rec(dataset, &n, record_to_delete);
            printf("\n");
            
        }
        else if(ch=='E' ||ch== 'e'){
            printf("Thank You!");
            break;
        }
    }
    return 0;
}
