#include <stdio.h>
#include <stdlib.h>

//Вывести квадратную матрицу по заданному N
int main() {
	int N;
	printf("Enter \"N\": ");
	scanf_s("%d", &N);
	for (int i = 1; i <= N * N; i++) {
		printf("%d\t", i);	// \t-табуляция по горизонт
		if (i % N == 0) printf("\n");
	}
	return 0;
}



//Вывести заданный массив размером N в обр порядке
int main() {
	const int N = 5; //Размер массива
	int *array = calloc(N, sizeof(int)); 
	printf("enter the array elements\n");
	for (int i = 0; i < N; i++) {
		printf("%d. ",i+1);
		scanf_s("%d", &array[i]);
	}
	printf("initial array: ");
	for (int i = 0; i < N; i++) printf("%d ", array[i]);
	for (int i = 0; i < N / 2; i++) {
		int tmp = array[i];
		array[i] = array[N - i - 1];
		array[N - i - 1] = tmp;
	}
	printf("\nreverse array: ");
	for (int i = 0; i < N; i++) printf("%d ", array[i]);

	return 0;
}



//Заполнить верхний треугольник матрицы 1, а нижний 0
//https://math1.ru/images/matrix/matrix/2.png
int main() {
	const int N = 15; //размер матрицы
	for (int i = 0; i < N; i++) {
		for (int c = 0; c < i; c++) printf("0 ");
		for (int j = 0; j < N - i; j++) printf("1 ");
		printf("\n");
	}
	return 0;
}
//Или так:
void main() {
	const int N = 5;
	for (int i = 0; i < N; i++) 
		for (int j = 0; j < N; printf((j++ < i) ? "0" : "1"), printf((j == N) ? "\n" : " "));
}



#define N 5
int main(){
    int array[N][N];
    // Заполняем массив
    for (int i = 0, m=1; i < (N / 2); i++) {
        for (int j = i; j < (N - i); j++) array[i][j] = m++;  
        for (int j = 1; j < (N - i - i); j++) array[(j + i)][(N - i) - 1] = m++;
        for (int j = (N - 2) - i; j >= i; j--) array[(N - i) - 1][(j)] = m++;
        for (int j = ((N - i) - 2); j > i; j--)  array[j][i] = m++;
    }
    if (N % 2 != 0) array[(N / 2)][(N / 2)] = (N * N); //заполняем центр массива, если N нечет
    //Выводим массив
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) printf("%d\t", array[i][j]);
        printf("%d\n", array[i][N - 1]);
    }
    return 0;
}
