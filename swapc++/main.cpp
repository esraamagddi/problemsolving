#include <iostream>

void swapByValue(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void swapByAddress(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swapByReference(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 5, y = 10;

    // Call by Value
    int a = x, b = y;
    std::cout << "Before Swap (Call by Value): a = " << a << ", b = " << b << std::endl;
    swapByValue(a, b);
    std::cout << "After Swap (Call by Value): a = " << a << ", b = " << b << std::endl;

    // Call by Address
    a = x, b = y;
    std::cout << "Before Swap (Call by Address): a = " << a << ", b = " << b << std::endl;
    swapByAddress(&a, &b);
    std::cout << "After Swap (Call by Address): a = " << a << ", b = " << b << std::endl;

    // Call by Reference
    a = x, b = y;
    std::cout << "Before Swap (Call by Reference): a = " << a << ", b = " << b << std::endl;
    swapByReference(a, b);
    std::cout << "After Swap (Call by Reference): a = " << a << ", b = " << b << std::endl;

    return 0;
}
