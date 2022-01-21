#include "../pluginFunctions.h"


int add(const int value1, const int value2) {
	return value1 + value2;
}

char *getPluginInfo(){
    return "Этот плагин предназнчен для того чтобы вы могли складывать два числа\n";
}

char *getPluginMenuDescription(){
    return "Сложение чисел";
}
char *checkPlugin(){
    return "pluginIsOk";
}

void pluginStart(){
    int value1, value2;
    printf("Складывалка чисел запущена!\n");
    printf("Введите первое число: ");
	scanf("%d", &value1);
	printf("Введите второе число: ");
	scanf("%d", &value2);

    printf("Результат: %d\n", add(value1, value2));
}