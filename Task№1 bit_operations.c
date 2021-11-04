#include <stdio.h>

int main() {
	int array = 0x00DDAABB;
	unsigned char out;
	printf("initial array=%x\n", array); 
	//Выводим байты числа array
	for (int i = 0; i < 4; i++) {
		out = ((array >> 8 * i) & 0x000000FF);
		printf("%d byte array=%hhx\n", i+1, out);//%hhx - вывод 1 байтного числа, если исп %x, char неявно приводится к int
	}
	array ^= 0x00110000;// XOR-им 
	printf("modified array=%x\n",array);
	return 0;
}
