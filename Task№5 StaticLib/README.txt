Данную работу я выполнял по ОС windows 10. 
Компилятор gcc из набора MinGW

Создаем объектные файлы: 			gcc func*.c -c
Создаем статич библиотек из объектных файлов: 	ar -crs libArithmetic.a *.o
Можем просмотреть модули внутри созданной либы: ar -t  libArithmetic.a
Компилируем:					gcc arithmetic_operations.h main.c -o calc.exe -L. -lArithmetic
Запускаем: 					calc.exe