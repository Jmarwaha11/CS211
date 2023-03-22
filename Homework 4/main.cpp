#include <iostream>
#include "Date.h"
using namespace std;
int sumDigit(int temp) {
    int sum = 0;
    while (temp != 0) {
        int remain = temp % 10;
        sum = sum + remain;
        temp = temp / 10;
    }
    return sum;
}
int sum(int mo, int da, int ye) {
    int sum = mo + da + ye;
    while (sum >= 10) {
        sum = sumDigit(sum);
    }
    return sum;
}

int main() {
    int size;
    cout << "please enter a Size of the date array";
    cin >> size;
    Date* date_list = new Date[size];
    int* num_list = new int[size];
    for (int i = 0; i < size; i++)
        date_list[i].input();
    for (int i = 0; i < size; i++)
        num_list[i] = sum(date_list[i].getMonthNum(), date_list[i].getDay(), date_list[i].getYear());
    cout << "Date" << "\t" << "Integer" << endl;
    for (int i = 0; i < size; i++) {
        date_list[i].output();
        cout << "\t" << num_list[i] << endl;
    }
    delete[] date_list;
    delete[] num_list;
    return 0;
}
