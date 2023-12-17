#include <iostream>

void fillArrayRecursive(int arr[], int size, int index) {
    if (index < size) {
        std::cout << "Enter element at index " << index << ": " << std::endl;
        std::cin >> arr[index];
        fillArrayRecursive(arr, size, index + 1);
    }
}

void printArrayRecursive(const int arr[], int size, int index) {
    if (index < size) {
        std::cout << arr[index] << " ";
        printArrayRecursive(arr, size, index + 1);
    }
    else {
        std::cout << std::endl;
    }
}

int sumOddIndexedElementsRecursive(const int arr[], int size, int index) {
    if (index >= size) {
        return 0;
    }

    return arr[index] + sumOddIndexedElementsRecursive(arr, size, index + 2);
}

int findIndexOfLargestEvenRecursive(const int arr[], int size, int index, int maxEvenIndex, int maxEven) {
    if (index < size) {
        if (arr[index] % 2 == 0 && arr[index] > maxEven) {
            maxEven = arr[index];
            maxEvenIndex = index;
        }

        return findIndexOfLargestEvenRecursive(arr, size, index + 1, maxEvenIndex, maxEven);
    }

    return maxEvenIndex;
}

int main() {
    int size;

    std::cout << "Enter the size of the array: " << std::endl;
    std::cin >> size;

    if (size <= 0) {
        std::cerr << "Invalid array size\n" << std::endl;
        return 1;
    }

    int* arr = new int[size];

    fillArrayRecursive(arr, size, 0);
    printArrayRecursive(arr, size, 0);

    int result = sumOddIndexedElementsRecursive(arr, size, 1);
    std::cout << "Sum of elements with odd indices: " << result << std::endl;

    int maxEvenIndex = findIndexOfLargestEvenRecursive(arr, size, 0, -1, 1);

    if (maxEvenIndex != -1) {
        std::cout << "Index of the largest even element: " << maxEvenIndex << std::endl;
    }
    else {
        std::cout << "No even elements in the array\n" << std::endl;
    }

    delete[] arr;

    return 0;
}
