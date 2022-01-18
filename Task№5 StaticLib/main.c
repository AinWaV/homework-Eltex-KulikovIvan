#include "arithmetic_operations.h"

int main() {
	printf("select an action:\n1. Multiplication\n2. Division\n3. Addition\n4. Subtraction\nEnter number: ");
	int choice;
	scanf("%d", &choice);

	int value1, value2, result;

	printf("Enter the first value: ");
	scanf("%d", &value1);

	printf("Enter the second value: ");
	scanf("%d", &value2);

	switch (choice)	{
	case 1:
		result = multiply(value1, value2);	break;
	case 2:
		result = divide(value1, value2); 	break;
	case 3:
		result = add(value1, value2);		break;
	case 4:
		result = subtract(value1, value2);	break;
	default:
		printf("Error! Enter the action number from 1 to 4\n");
		return(-2);
	}

	printf("result is: %d", result);

	return 0;
}