/******************************
* Функции                     *
* Вариант 10                  *
* Карпов Кирилл               *
******************************/

#include <iostream>
#include <cmath>

using namespace std;

double averagePositiveNumber(double arrayUser[], int count) {
  double sumPositiveElement = 0.0;
  int countPositiveElement = 0;

  for (int rowIndex = 0; rowIndex < count; ++rowIndex) {
    if (arrayUser[rowIndex] > 0) {
      sumPositiveElement += arrayUser[rowIndex];
      ++countPositiveElement;
    }
  }

  if (countPositiveElement == 0) {
    return 0.0;
  }

  return sumPositiveElement / countPositiveElement;
}

void cinArray(double arrayUser[], int count) {
  for (int rowIndex = 0; rowIndex < count; ++rowIndex) {
    cout << "Element: " << rowIndex + 1 << " = ";
    cin >> arrayUser[rowIndex];
  }
}

int main() {
  const int maxArraySize = 100;
  const double maxElementMagnitude = 1000.0;

  int countElementArrayR, countElementArrayL;
  double arrayR[maxArraySize], arrayL[maxArraySize];

  cout << "Enter the number of array elements R: ";

  if (!(cin >> countElementArrayR) || countElementArrayR < 1 || countElementArrayR > maxArraySize) {
    cout << "INVALID";
    return 0;
  }

  cout << "Enter the number of array elements L: ";

  if (!(cin >> countElementArrayL) || countElementArrayL < 1 || countElementArrayL > maxArraySize) {
    cout << "INVALID";
    return 0;
  }

  cout << "Array R:\n";
  cinArray(arrayR, countElementArrayR);

  cout << "Array L:\n";
  cinArray(arrayL, countElementArrayL);

  for (int rowIndex = 0; rowIndex < countElementArrayR; ++rowIndex) {
    if (!cin || abs(arrayR[rowIndex]) > maxElementMagnitude) {
      cout << "INVALID";
      return 0;
    }
  }

  for (int rowIndex = 0; rowIndex < countElementArrayL; ++rowIndex) {
    if (!cin || abs(arrayL[rowIndex]) > maxElementMagnitude) {
      cout << "INVALID";
      return 0;
    }
  }

  cout << "\nAverage positive elements R: ";
  if (averagePositiveNumber(arrayR, countElementArrayR) == 0.0) {
    cout << "NO POSITIVE ELEMENTS";
  } else {
    cout << averagePositiveNumber(arrayR, countElementArrayR);
  }

  cout << "\nAverage positive elements L: ";
  if (averagePositiveNumber(arrayL, countElementArrayL) == 0.0) {
    cout << "NO POSITIVE ELEMENTS";
  } else {
    cout << averagePositiveNumber(arrayL, countElementArrayL);
  }

  return 0;
}