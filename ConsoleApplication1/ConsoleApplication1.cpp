#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>

void array_output(int mass[]);
void random_filling_array(int mass[]);
void func_search(int mass[], int mass2[]);
int main() {
    int mass[900];
    int mass2[900] = { 0 };
    srand(time(NULL));
    // filling the array
    random_filling_array(mass);
    // array output
    array_output(mass);
    func_search(mass, mass2);
   // array_output(mass2);

    for (int i = 0; i < 900; i++) {
        if (mass2[i] == 0)
            break;
        printf("%d %d \n", i + 1, mass2[i]);
    }
    return 0;
}

void func_search(int mass[], int mass2[]) {
    int o = 0;
    for (int j = 100; j < 1000; j++) { // проверка чисел от 100 до 999
        for (int i = 0; i <= 900; i++) { // проверка элементов в массиве
            if (mass[i] == j) { // прерывание цикла, в случае если значение элемента массива совпадает с числом
                break;
            }
            if (i == 900) { // в случае если i = 900, это означает что числа нет в массиве 
                mass2[o] = j; // записи этого числа во второй массив
                o++; // переход к следующему элементу второго массива
            }
        }
    }

}

void random_filling_array(int mass[]) {
    for (int i = 0; i < 900; i++) {
        mass[i] = rand() % 899 + 100;
    }
}
void array_output(int mass[]) {
    for (int i = 0; i < 900; i++) {
        printf("%d.  %d \n", i + 1, mass[i]);
    }
}