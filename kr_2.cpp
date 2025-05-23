#include <iostream>
#include <cstring>
#include <algorithm>

void createArrayStrings(char**, int);
void inputArrayStrings(char**, int);
void outputArray(char**, int);
bool isDigit(char*);
int extractNumber(char*);
void sortArrayByNumbers(char**, int*, int);

int main() {
    int size{};
    std::cout << "Enter size array for strings: ";
    std::cin >> size;
    std::cin.ignore(); 

    char** arrayString = new char*[size];
    createArrayStrings(arrayString, size);


    std::cout << "Enter " << size << " strings" << '\n';
    inputArrayStrings(arrayString, size);

    std::cout << "Input arrayString:" << '\n';
    outputArray(arrayString, size);


    int* numbers = new int[size];
    for (int i = 0; i < size; i++) {
        numbers[i] = extractNumber(arrayString[i]);
    }

    sortArrayByNumbers(arrayString, numbers, size);

    std::cout << "Sorted string" << '\n';
    outputArray(arrayString, size);

    return 0;
}


void createArrayStrings(char** array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] = new char[100];
    }
}

void inputArrayStrings(char** array, int size) {
    for (int i = 0; i < size; i++) {
        std::cin.getline(array[i], 100);
    }
}


void outputArray(char** array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << "\n";
    }
}

bool isDigit(char* str) {
    if (*str == '\0') return false;
    char* p = str;
    if (*p == '-') {
        p++;
        if (*p == '\0') return false;
    }
    while (*p != '\0') {
        if (*p < '0' || *p > '9') return false;
        p++;
    }
    return true;
}


int extractNumber(char* str) {
    char* pch = strtok(str, " ");
    while (pch != NULL) {
        if (isDigit(pch)) {
            return atoi(pch);
        }
        pch = strtok(NULL, " ");
    }
    return 0; 
}

void sortArrayByNumbers(char** array, int* numbers, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (numbers[j] > numbers[j + 1]) {
                std::swap(numbers[j], numbers[j + 1]);
                std::swap(array[j], array[j + 1]);
            }
        }
    }
}


