#include <stdio.h>

#define ARRAY_SIZE 15

int linear_search(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

void bubble_sort_descending(int arr[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (arr[j] < arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int binary_search_descending(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return -1;
}

void print_array(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    int X[ARRAY_SIZE];
    int A;
    int index;

    printf("Введіть %d цілих чисел для масиву X:\n", ARRAY_SIZE);
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Елемент %d: ", i + 1);
        scanf("%d", &X[i]);
    }

    printf("\nВведіть цільове значення A для пошуку: ");
    scanf("%d", &A);

    printf("\nПочатковий масив X: ");
    print_array(X, ARRAY_SIZE);

    printf("\n--- Лінійний пошук ---\n");
    index = linear_search(X, ARRAY_SIZE, A);
    if (index != -1) {
        printf("Елемент %d знайдено лінійним пошуком на позиції (індексі): %d\n", A, index);
    } else {
        printf("Елемент %d не знайдено лінійним пошуком.\n", A);
    }

    printf("\n--- Сортування масиву за спаданням ---\n");
    bubble_sort_descending(X, ARRAY_SIZE);
    printf("Масив X після сортування за спаданням: ");
    print_array(X, ARRAY_SIZE);

    printf("\n--- Бінарний пошук (у відсортованому масиві) ---\n");
    index = binary_search_descending(X, ARRAY_SIZE, A);
    if (index != -1) {
        printf("Елемент %d знайдено бінарним пошуком на позиції (індексі): %d\n", A, index);
    } else {
        printf("Елемент %d не знайдено бінарним пошуком.\n", A);
    }

    return 0;
}