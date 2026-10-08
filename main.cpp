#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

int sumLastNums(int x) {
    x = std::abs(x);
    return (x % 10) + ((x / 10) % 10);
}

bool isPositive(int x) {
    return x > 0;
}

bool isUpperCase(char x) {
    return x >= 'A' && x <= 'Z';
}

bool isDivisor(int a, int b) {
    if (a == 0 || b == 0) return false;
    return (a % b == 0) || (b % a == 0);
}

int lastNumSum(int a, int b) {
    return (std::abs(a) % 10) + (std::abs(b) % 10);
}

double safeDiv(int x, int y) {
    if (y == 0) return 0.0;
    return static_cast<double>(x) / y;
}

std::string makeDecision(int x, int y) {
    if (x < y) return std::to_string(x) + " < " + std::to_string(y);
    if (x > y) return std::to_string(x) + " > " + std::to_string(y);
    return std::to_string(x) + " == " + std::to_string(y);
}

bool sum3(int x, int y, int z) {
    return (x + y == z) || (x + z == y) || (y + z == x);
}

std::string age(int x) {
    int abs_x = std::abs(x);
    int last_digit = abs_x % 10;
    int last_two_digits = abs_x % 100;
    std::string result = std::to_string(x) + " ";
    if (last_two_digits >= 11 && last_two_digits <= 14) {
        result += "лет";
    } else if (last_digit == 1) {
        result += "год";
    } else if (last_digit >= 2 && last_digit <= 4) {
        result += "года";
    } else {
        result += "лет";
    }
    return result;
}

void printDays(int x) {
    if (x < 1 || x > 7) {
        std::cout << "это не день недели\n";
        return;
    }
    for (int i = x; i <= 7; ++i) {
        switch (i) {
            case 1: std::cout << "понедельник "; break;
            case 2: std::cout << "вторник "; break;
            case 3: std::cout << "среда "; break;
            case 4: std::cout << "четверг "; break;
            case 5: std::cout << "пятница "; break;
            case 6: std::cout << "суббота "; break;
            case 7: std::cout << "воскресенье "; break;
        }
    }
    std::cout << "\n";
}

std::string reverseListNums(int x) {
    std::string result;
    for (int i = x; i >= 0; --i) {
        result += std::to_string(i) + " ";
    }
    if (!result.empty()) {
        result.pop_back();
    }
    return result;
}

int power(int x, int y) {
    int result = 1;
    for (int i = 0; i < y; ++i) {
        result *= x;
    }
    return result;
}

bool equalNum(int x) {
    x = std::abs(x);
    int last_digit = x % 10;
    while (x > 0) {
        if (x % 10 != last_digit) {
            return false;
        }
        x /= 10;
    }
    return true;
}

void leftTriangle(int x) {
    for (int i = 1; i <= x; ++i) {
        for (int j = 0; j < i; ++j) {
            std::cout << "*";
        }
        std::cout << "\n";
    }
}

void guessGame() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int target = std::rand() % 10;
    int attempts = 0;
    int guess = -1;
    while (guess != target) {
        std::cout << "Введите число от 0 до 9: ";
        if (std::cin >> guess) {
            attempts++;
            if (guess == target) {
                std::cout << "Вы угадали!\n";
            } else {
                std::cout << "Вы не угадали, ";
            }
        } else {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Неверный ввод. ";
        }
    }
    std::cout << "Вы отгадали число за " << attempts << " попытки\n";
}

int findLast(const int* arr, int size, int x) {
    for (int i = size - 1; i >= 0; --i) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

int* add(const int* arr, int size, int x, int pos, int& new_size) {
    new_size = size + 1;
    int* new_arr = new int[new_size];
    for (int i = 0; i < pos && i < size; ++i) {
        new_arr[i] = arr[i];
    }
    new_arr[pos] = x;
    for (int i = pos; i < size; ++i) {
        new_arr[i + 1] = arr[i];
    }
    return new_arr;
}

void reverse(int* arr, int size) {
    for (int i = 0; i < size / 2; ++i) {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int* concat(const int* arr1, int size1, const int* arr2, int size2, int& new_size) {
    new_size = size1 + size2;
    int* new_arr = new int[new_size];
    for (int i = 0; i < size1; ++i) {
        new_arr[i] = arr1[i];
    }
    for (int i = 0; i < size2; ++i) {
        new_arr[size1 + i] = arr2[i];
    }
    return new_arr;
}

int* deleteNegative(const int* arr, int size, int& new_size) {
    int count = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            count++;
        }
    }
    new_size = count;
    int* new_arr = new int[new_size];
    int j = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i] >= 0) {
            new_arr[j++] = arr[i];
        }
    }
    return new_arr;
}

int main(void) {
    int val;
    std::cout << "Task 1.2 SumLastNums: ";
    while (!(std::cin >> val)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << sumLastNums(val) << "\n";
    
    std::cout << "Task 1.4 IsPositive: ";
    while (!(std::cin >> val)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << (isPositive(val) ? "true" : "false") << "\n";
    
    char cval;
    std::cout << "Task 1.6 IsUpperCase: ";
    while (!(std::cin >> cval)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << (isUpperCase(cval) ? "true" : "false") << "\n";
    
    int a18, b18;
    std::cout << "Task 1.8 IsDivisor (a): ";
    while (!(std::cin >> a18)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Task 1.8 IsDivisor (b): ";
    while (!(std::cin >> b18)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << (isDivisor(a18, b18) ? "true" : "false") << "\n";
    
    int sum5 = 0;
    for (int i = 0; i < 5; ++i) {
        std::cout << "Task 1.10 LastNumSum (val " << (i + 1) << "): ";
        while (!(std::cin >> val)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
        sum5 = lastNumSum(sum5, val);
    }
    std::cout << "Task 1.10 Result: " << sum5 << "\n";

    int x22, y22;
    std::cout << "Task 2.2 SafeDiv (x): ";
    while (!(std::cin >> x22)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Task 2.2 SafeDiv (y): ";
    while (!(std::cin >> y22)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << safeDiv(x22, y22) << "\n";

    int x24, y24;
    std::cout << "Task 2.4 MakeDecision (x): ";
    while (!(std::cin >> x24)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Task 2.4 MakeDecision (y): ";
    while (!(std::cin >> y24)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << makeDecision(x24, y24) << "\n";

    int x26, y26, z26;
    std::cout << "Task 2.6 Sum3 (x): ";
    while (!(std::cin >> x26)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Task 2.6 Sum3 (y): ";
    while (!(std::cin >> y26)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Task 2.6 Sum3 (z): ";
    while (!(std::cin >> z26)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << (sum3(x26, y26, z26) ? "true" : "false") << "\n";

    std::cout << "Task 2.8 Age: ";
    while (!(std::cin >> val)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << age(val) << "\n";

    std::cout << "Task 2.10 PrintDays (1-7): ";
    while (!(std::cin >> val) || val < 1 || val > 7) { 
        std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry (1-7): "; 
    }
    printDays(val);

    std::cout << "Task 3.2 ReverseListNums: ";
    while (!(std::cin >> val) || val < 0) { 
        std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry (>=0): "; 
    }
    std::cout << reverseListNums(val) << "\n";

    int x34, y34;
    std::cout << "Task 3.4 Power (x): ";
    while (!(std::cin >> x34)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Task 3.4 Power (y): ";
    while (!(std::cin >> y34) || y34 < 0) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry (>=0): "; }
    std::cout << power(x34, y34) << "\n";

    std::cout << "Task 3.6 EqualNum: ";
    while (!(std::cin >> val)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << (equalNum(val) ? "true" : "false") << "\n";

    std::cout << "Task 3.8 LeftTriangle size: ";
    while (!(std::cin >> val) || val < 1) { 
        std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry (>=1): "; 
    }
    leftTriangle(val);

    std::cout << "Task 3.10 GuessGame:\n";
    guessGame();

    int size42;
    std::cout << "Task 4.2 FindLast array size: ";
    while (!(std::cin >> size42) || size42 < 1) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    int* arr42 = new int[size42];
    for (int i = 0; i < size42; ++i) {
        std::cout << "arr[" << i << "]: ";
        while (!(std::cin >> arr42[i])) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    }
    int x42;
    std::cout << "Task 4.2 FindLast x: ";
    while (!(std::cin >> x42)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Result: " << findLast(arr42, size42, x42) << "\n";
    delete[] arr42;

    int size44;
    std::cout << "Task 4.4 Add array size: ";
    while (!(std::cin >> size44) || size44 < 1) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    int* arr44 = new int[size44];
    for (int i = 0; i < size44; ++i) {
        std::cout << "arr[" << i << "]: ";
        while (!(std::cin >> arr44[i])) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    }
    int x44, pos44;
    std::cout << "Task 4.4 Add x: ";
    while (!(std::cin >> x44)) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    std::cout << "Task 4.4 Add pos: ";
    while (!(std::cin >> pos44) || pos44 < 0 || pos44 > size44) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    int new_size44;
    int* res44 = add(arr44, size44, x44, pos44, new_size44);
    std::cout << "Result: ";
    for (int i = 0; i < new_size44; ++i) std::cout << res44[i] << " ";
    std::cout << "\n";
    delete[] arr44;
    delete[] res44;

    int size46;
    std::cout << "Task 4.6 Reverse array size: ";
    while (!(std::cin >> size46) || size46 < 1) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    int* arr46 = new int[size46];
    for (int i = 0; i < size46; ++i) {
        std::cout << "arr[" << i << "]: ";
        while (!(std::cin >> arr46[i])) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    }
    reverse(arr46, size46);
    std::cout << "Result: ";
    for (int i = 0; i < size46; ++i) std::cout << arr46[i] << " ";
    std::cout << "\n";
    delete[] arr46;

    int size48_1, size48_2;
    std::cout << "Task 4.8 Concat array 1 size: ";
    while (!(std::cin >> size48_1) || size48_1 < 1) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    int* arr48_1 = new int[size48_1];
    for (int i = 0; i < size48_1; ++i) {
        std::cout << "arr1[" << i << "]: ";
        while (!(std::cin >> arr48_1[i])) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    }
    std::cout << "Task 4.8 Concat array 2 size: ";
    while (!(std::cin >> size48_2) || size48_2 < 1) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    int* arr48_2 = new int[size48_2];
    for (int i = 0; i < size48_2; ++i) {
        std::cout << "arr2[" << i << "]: ";
        while (!(std::cin >> arr48_2[i])) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    }
    int new_size48;
    int* res48 = concat(arr48_1, size48_1, arr48_2, size48_2, new_size48);
    std::cout << "Result: ";
    for (int i = 0; i < new_size48; ++i) std::cout << res48[i] << " ";
    std::cout << "\n";
    delete[] arr48_1;
    delete[] arr48_2;
    delete[] res48;

    int size410;
    std::cout << "Task 4.10 DeleteNegative array size: ";
    while (!(std::cin >> size410) || size410 < 1) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    int* arr410 = new int[size410];
    for (int i = 0; i < size410; ++i) {
        std::cout << "arr[" << i << "]: ";
        while (!(std::cin >> arr410[i])) { std::cin.clear(); std::cin.ignore(10000, '\n'); std::cout << "Invalid. Retry: "; }
    }
    int new_size410;
    int* res410 = deleteNegative(arr410, size410, new_size410);
    std::cout << "Result: ";
    for (int i = 0; i < new_size410; ++i) std::cout << res410[i] << " ";
    std::cout << "\n";
    delete[] arr410;
    delete[] res410;

    return 0;
}
