#include <iostream>
#include <clocale>

using namespace std;

/*
* Лабораторная работа 7. Поливцев Михаил, ИВТ-31. Задание 2. Индивидуальный вариант 16.
* Дан массив размера N. Обнулить элементы массива, расположенные между его
* минимальным и максимальным элементами (не включая минимальный и максимальный элементы).
* Реализовать ввод, обработку и вывод массивов с применением функций.
*/ 

void input_mas(int* mas, int n);
void change_mas(int* mas, int n);
void output_mas(int* mas, int n);

int main() {
	setlocale(LC_ALL, "ru");

	int n;
	cout << "Введите размер массива >> ";
	cin >> n;
	if (n < 1) {
		cout << "неверный ввод";
		return 1;
	}
	int* lst;
	lst = new int[n];

	input_mas(lst, n);
	change_mas(lst, n);
	output_mas(lst, n);

	delete[] lst;
}

void input_mas(int* mas, int n) {
	for (int i = 0; i < n; i++) {
		cout << "Введите элемент массива >> ";
		cin >> mas[i];
	}
}

void change_mas(int* mas, int n) {
	int max_i = 0, min_i = 0, m1, m2;

	for (int i = 0; i < n; i++) {
		if (mas[i] < mas[min_i]) {
			min_i = i;
		}
		if (mas[i] > mas[max_i]) {
			max_i = i;
		}
	}

	if (max_i > min_i) {
		m1 = min_i + 1;
		m2 = max_i;
	}
	else {
		m1 = max_i + 1;
		m2 = min_i;
	}

	for (int i = m1; i < m2; i++) {
		mas[i] = 0;
	}
}

void output_mas(int* mas, int n) {
	for (int i = 0; i < n; i++) {
		cout << mas[i] << " ";
	}
}