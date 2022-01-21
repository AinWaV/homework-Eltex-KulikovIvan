#include "../pluginFunctions.h"

int subtract(const int value1, const int value2) {
	return value1 - value2;
}

char *getPluginInfo(){
    return "Этот плагин предназнчен для того чтобы вы могли вычитать одно число из другое\n";
}

char *getPluginMenuDescription(){
    return "Вычитание чисел";
}
char *checkPlugin(){
    return "pluginIsOk";
}

void pluginStart(){
    int value1, value2;
    printf("Вычиталка чисел запущена!\n");
    printf("Введите первое число: ");
	scanf("%d", &value1);
	printf("Введите второе число: ");
	scanf("%d", &value2);

    printf("Результат: %d\n", subtract(value1, value2));
}
