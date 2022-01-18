#include "arithmetic_operations.h"
#include <stdlib.h>
#include <stdio.h>
#include <dlfcn.h> // для дин библиотек
#include <string.h>

char *getChoiceFuncName(const int choice){
		switch (choice)	{
		case 1: return "multiply";	break;
		case 2: return "divide";	break;
		case 3: return "add";		break;
		case 4: return "subtract";	break;
		default: 
			printf("Error! Enter the action number from 1 to 4\n");
			exit(-2);
	}
}

void printActionsAndGetValues(int *choice, int *value1, int *value2){
	printf("select an action:\n1. Multiplication\n2. Division\n3. Addition\n4. Subtraction\nEnter number: ");
	scanf("%d", choice);
	printf("Enter the first value: ");
	scanf("%d", value1);
	printf("Enter the second value: ");
	scanf("%d", value2);
}

int main(){
	void *library_handler = dlopen("./libArithmeticDyn.so",RTLD_LAZY);; //указатель на подгружаемую библиотеку
	int (*func_ptr)(const int value1, const int value2) = NULL; //Указатель на ф-цию из дин библ

	if (!library_handler){	printf("dlopen() error: %s\n", dlerror()); exit(1); }	//Если либу не открыли, заверш вып

	int choice, value1, value2;
	printActionsAndGetValues(&choice, &value1, &value2); //Печатаем менюшку и получаем ввод исх значений

	func_ptr = dlsym(library_handler, getChoiceFuncName(choice)); //Получаем адрес функции
	if(func_ptr == NULL){printf("dlsym(), func not found!\n");	exit(1);} //Если адрес не получен, заверш выполнение

	printf("result is: %d\n", func_ptr(value1,value2)); //Вызываем полученную функцию

	dlclose(library_handler); //закрыть объект dlopen()
	return 0;
}