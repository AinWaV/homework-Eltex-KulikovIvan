#include "../pluginFunctions.h"

int divide(const int value1, const int value2) {
	return value1 / value2;
}

char *getPluginInfo(){
    return "Этот плагин предназнчен для того чтобы вы могли делить одно число на другое\n";
}

char *getPluginMenuDescription(){
    return "Деление чисел";
}
char *checkPlugin(){
    return "pluginIsOk";
}

void pluginStart(){
    int value1, value2;
    printf("Делилка чисел запущена!\n");
    printf("Введите первое число: ");
	scanf("%d", &value1);
	printf("Введите второе число: ");
	scanf("%d", &value2);

    printf("Результат: %d\n", divide(value1, value2));
}