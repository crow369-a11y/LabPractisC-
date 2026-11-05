#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <windows.h>

int sumLastNums(int x);
bool isPositive(int x);
bool isUpperCase(char x);
bool isDivisor(int a, int b);
int lastNumSum(int a, int b);
double safeDiv(int x, int y);
std::string makeDecision(int x, int y);
bool sum3(int x, int y, int z);
std::string age(int x);
void printDays(int x);
std::string reverseListNums(int x);
int power(int x, int y);
bool equalNum(int x);
void leftTriangle(int x);
void guessGame(void);
int findLast(const int* arr, int size, int x);
int* add(const int* arr, int size, int x, int pos, int& new_size);
void reverse(int* arr, int size);
int* concat(const int* arr1, int size1, const int* arr2, int size2, int& new_size);
int* deleteNegative(const int* arr, int size, int& new_size);

int main(void) {
  SetConsoleOutputCP(CP_UTF8);
  int choice = 0;

  while (true) {
    std::cout << "1. Сумма двух последних цифр\n";
    std::cout << "2. Проверка на положительность\n";
    std::cout << "3. Проверка на верхний регистр\n";
    std::cout << "4. Проверка делителя\n";
    std::cout << "5. Сумма последних цифр двух чисел\n";
    std::cout << "6. Безопасное деление\n";
    std::cout << "7. Сравнение чисел\n";
    std::cout << "8. Сумма двух равна третьему?\n";
    std::cout << "9. Склонение слова 'год'\n";
    std::cout << "10. Дни недели\n";
    std::cout << "11. Обратный отсчет\n";
    std::cout << "12. Возведение в степень\n";
    std::cout << "13. Одинаковые цифры?\n";
    std::cout << "14. Треугольник\n";
    std::cout << "15. Угадай число\n";
    std::cout << "16. Поиск последнего в массиве\n";
    std::cout << "17. Вставка в массив\n";
    std::cout << "18. Реверс массива\n";
    std::cout << "19. Склеивание массивов\n";
    std::cout << "20. Удаление отрицательных\n";
    std::cout << "0. Выход\n";
    std::cout << "Выбор: ";
    
    if (!(std::cin >> choice)) {
      break;
    }
    if (choice == 0) {
      break;
    }

    if (choice == 1) {
      int x = 0;
      std::cout << "Введите число: ";
      std::cin >> x;
      sumLastNums(x);
    } else if (choice == 2) {
      int x = 0;
      std::cout << "Введите число: ";
      std::cin >> x;
      bool res = isPositive(x);
      if (res) {
        std::cout << "Число положительное\n";
      } else {
        std::cout << "Число не положительное\n";
      }
    } else if (choice == 3) {
      char c = ' ';
      std::cout << "Введите символ: ";
      std::cin >> c;
      bool res = isUpperCase(c);
      if (res) {
        std::cout << "Символ в верхнем регистре\n";
      } else {
        std::cout << "Символ не в верхнем регистре\n";
      }
    } else if (choice == 4) {
      int a = 0;
      int b = 0;
      std::cout << "Введите два числа: ";
      std::cin >> a >> b;
      bool res = isDivisor(a, b);
      if (res) {
        std::cout << "Одно число является делителем другого\n";
      } else {
        std::cout << "Нет\n";
      }
    } else if (choice == 5) {
      int a = 0;
      int b = 0;
      std::cout << "Введите два числа: ";
      std::cin >> a >> b;
      int res = lastNumSum(a, b);
      std::cout << "Сумма последних цифр: " << res << "\n";
    } else if (choice == 6) {
      int x = 0;
      int y = 0;
      std::cout << "Введите делимое и делитель: ";
      std::cin >> x >> y;
      double res = safeDiv(x, y);
      std::cout << "Результат: " << res << "\n";
    } else if (choice == 7) {
      int x = 0;
      int y = 0;
      std::cout << "Введите два числа: ";
      std::cin >> x >> y;
      std::string res = makeDecision(x, y);
      std::cout << res << "\n";
    } else if (choice == 8) {
      int x = 0;
      int y = 0;
      int z = 0;
      std::cout << "Введите три числа: ";
      std::cin >> x >> y >> z;
      bool res = sum3(x, y, z);
      if (res) {
        std::cout << "Да, сумма двух равна третьему\n";
      } else {
        std::cout << "Нет\n";
      }
    } else if (choice == 9) {
      int x = 0;
      std::cout << "Введите возраст: ";
      std::cin >> x;
      std::string res = age(x);
      std::cout << res << "\n";
    } else if (choice == 10) {
      int x = 0;
      std::cout << "Введите номер дня (1-7): ";
      std::cin >> x;
      printDays(x);
    } else if (choice == 11) {
      int x = 0;
      std::cout << "Введите число: ";
      std::cin >> x;
      std::string res = reverseListNums(x);
      std::cout << res << "\n";
    } else if (choice == 12) {
      int x = 0;
      int y = 0;
      std::cout << "Введите основание и степень: ";
      std::cin >> x >> y;
      int res = power(x, y);
      std::cout << "Результат: " << res << "\n";
    } else if (choice == 13) {
      int x = 0;
      std::cout << "Введите число: ";
      std::cin >> x;
      bool res = equalNum(x);
      if (res) {
        std::cout << "Все цифры одинаковые\n";
      } else {
        std::cout << "Не все цифры одинаковые\n";
      }
    } else if (choice == 14) {
      int x = 0;
      std::cout << "Введите размер треугольника: ";
      std::cin >> x;
      leftTriangle(x);
    } else if (choice == 15) {
      guessGame();
    } else if (choice == 16) {
      int size = 0;
      std::cout << "Введите размер массива: ";
      std::cin >> size;
      int* arr = new int[size];
      for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
      }
      int x = 0;
      std::cout << "Введите искомое число: ";
      std::cin >> x;
      int res = findLast(arr, size, x);
      if (res == -1) {
        std::cout << "Число не найдено\n";
      } else {
        std::cout << "Последний индекс: " << res << "\n";
      }
      delete[] arr;
    } else if (choice == 17) {
      int size = 0;
      std::cout << "Введите размер массива: ";
      std::cin >> size;
      int* arr = new int[size];
      for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
      }
      int x = 0;
      int pos = 0;
      std::cout << "Введите число для вставки: ";
      std::cin >> x;
      std::cout << "Введите позицию: ";
      std::cin >> pos;
      int new_size = 0;
      int* res = add(arr, size, x, pos, new_size);
      std::cout << "Новый массив: ";
      for (int i = 0; i < new_size; ++i) {
        std::cout << res[i] << " ";
      }
      std::cout << "\n";
      delete[] arr;
      delete[] res;
    } else if (choice == 18) {
      int size = 0;
      std::cout << "Введите размер массива: ";
      std::cin >> size;
      int* arr = new int[size];
      for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
      }
      reverse(arr, size);
      std::cout << "Перевернутый массив: ";
      for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
      }
      std::cout << "\n";
      delete[] arr;
    } else if (choice == 19) {
      int size1 = 0;
      std::cout << "Введите размер первого массива: ";
      std::cin >> size1;
      int* arr1 = new int[size1];
      for (int i = 0; i < size1; ++i) {
        std::cout << "arr1[" << i << "] = ";
        std::cin >> arr1[i];
      }
      int size2 = 0;
      std::cout << "Введите размер второго массива: ";
      std::cin >> size2;
      int* arr2 = new int[size2];
      for (int i = 0; i < size2; ++i) {
        std::cout << "arr2[" << i << "] = ";
        std::cin >> arr2[i];
      }
      int new_size = 0;
      int* res = concat(arr1, size1, arr2, size2, new_size);
      std::cout << "Склеенный массив: ";
      for (int i = 0; i < new_size; ++i) {
        std::cout << res[i] << " ";
      }
      std::cout << "\n";
      delete[] arr1;
      delete[] arr2;
      delete[] res;
    } else if (choice == 20) {
      int size = 0;
      std::cout << "Введите размер массива: ";
      std::cin >> size;
      int* arr = new int[size];
      for (int i = 0; i < size; ++i) {
        std::cout << "arr[" << i << "] = ";
        std::cin >> arr[i];
      }
      int new_size = 0;
      int* res = deleteNegative(arr, size, new_size);
      std::cout << "Массив без отрицательных: ";
      for (int i = 0; i < new_size; ++i) {
        std::cout << res[i] << " ";
      }
      std::cout << "\n";
      delete[] arr;
      delete[] res;
    } else {
      std::cout << "Нет такого пункта\n";
    }
  }
  return 0;
}

int sumLastNums(int x) {
  if (x < 10) {
    std::cout << "Число X должно быть больше или равно 10\n";
    return -1;
  }
  int last_two_digits = x % 100;
  int first_digit = last_two_digits / 10;
  int second_digit = last_two_digits % 10;
  int result = first_digit + second_digit;
  std::cout << "Сумма последних 2-х цифр: " << result << "\n";
  return result;
}

bool isPositive(int x) {
  if (x > 0) {
    return true;
  } else {
    return false;
  }
}

bool isUpperCase(char x) {
  if (x >= 'A' && x <= 'Z') {
    return true;
  } else {
    return false;
  }
}

bool isDivisor(int a, int b) {
  if (a == 0 || b == 0) {
    return false;
  }
  if (a % b == 0 || b % a == 0) {
    return true;
  } else {
    return false;
  }
}

int lastNumSum(int a, int b) {
  int abs_a = std::abs(a);
  int abs_b = std::abs(b);
  int last_a = abs_a % 10;
  int last_b = abs_b % 10;
  int result = last_a + last_b;
  return result;
}

double safeDiv(int x, int y) {
  if (y == 0) {
    std::cout << "Делитель не может быть равен 0\n";
    return 0.0;
  } else {
    double result = static_cast<double>(x) / y;
    return result;
  }
}

std::string makeDecision(int x, int y) {
  if (x < y) {
    return std::to_string(x) + " < " + std::to_string(y);
  } else if (x > y) {
    return std::to_string(x) + " > " + std::to_string(y);
  } else {
    return std::to_string(x) + " == " + std::to_string(y);
  }
}

bool sum3(int x, int y, int z) {
  if (x + y == z) {
    return true;
  } else if (x + z == y) {
    return true;
  } else if (y + z == x) {
    return true;
  } else {
    return false;
  }
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
    const char* days[] = {"", "понедельник", "вторник", "среда",
                          "четверг", "пятница", "суббота", "воскресенье"};
    if (x < 1 || x > 7) {
        std::cout << "Это не день недели\n";
        return;
    }
    for (int i = x; i <= 7; ++i)
        std::cout << days[i] << " ";
    std::cout << "\n";
}   

std::string reverseListNums(int x) {
  std::string result = "";
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
    result = result * x;
  }
  return result;
}

bool equalNum(int x) {
  x = std::abs(x);
  int last_digit = x % 10;
  while (x > 0) {
    int current_digit = x % 10;
    if (current_digit != last_digit) {
      return false;
    }
    x = x / 10;
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
      attempts = attempts + 1;
      if (guess == target) {
        std::cout << "Вы угадали! Попыток: " << attempts << "\n";
      } else {
        std::cout << "Вы не угадали, попробуйте еще раз.\n";
      }
    } else {
      std::cin.clear();
      std::cin.ignore(10000, '\n');
      std::cout << "Неверный ввод.\n";
    }
  }
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
  int j = 0;
  
  for (int i = 0; i < pos; ++i) {
    new_arr[j] = arr[i];
    j = j + 1;
  }
  
  new_arr[j] = x;
  j = j + 1;
  
  for (int i = pos; i < size; ++i) {
    new_arr[j] = arr[i];
    j = j + 1;
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
      count = count + 1;
    }
  }
  
  new_size = count;
  int* new_arr = new int[new_size];
  int j = 0;
  
  for (int i = 0; i < size; ++i) {
    if (arr[i] >= 0) {
      new_arr[j] = arr[i];
      j = j + 1;
    }
  }
  
  return new_arr;
}