#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10000 

typedef struct {
    int *arr;
    int left;
    int right;
} ThreadArgs;

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0; 
    j = 0; 
    k = left; 

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void *merge_sort_threaded(void *args) {
    ThreadArgs *data = (ThreadArgs *)args;
    int left = data->left;
    int right = data->right;
    int *arr = data->arr;

    if (left < right) {
        int mid = (left + right) / 2;

        ThreadArgs leftArgs = {arr, left, mid};
        ThreadArgs rightArgs = {arr, mid + 1, right};

        pthread_t leftThread, rightThread;

        pthread_create(&leftThread, NULL, merge_sort_threaded, &leftArgs);
        pthread_create(&rightThread, NULL, merge_sort_threaded, &rightArgs);

        pthread_join(leftThread, NULL);
        pthread_join(rightThread, NULL);

        merge(arr, left, mid, right);
    }
    return NULL;
}

int main() {
    FILE* file = fopen("input", "r");
    if (!file) {
        printf("Error opening file.\n");
        return 1;
    }

    int n;
    fscanf(file, "%d", &n);
    int arr[MAX];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);

    ThreadArgs args = {arr, 0, n - 1};
    pthread_t intialThread;
    pthread_create(&intialThread, NULL, merge_sort_threaded, &args);
    pthread_join(intialThread, NULL);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

