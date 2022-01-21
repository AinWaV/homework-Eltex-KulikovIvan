#Ход действий для сборки плагинов (можно использовать как скрипт)

gcc -fPIC -c plugin_*.c
gcc -shared -o plugin_add.so plugin_add.o
gcc -shared -o plugin_subtract.so plugin_subtract.o
gcc -shared -o plugin_multiply.so plugin_multiply.o
gcc -shared -o plugin_divide.so plugin_divide.o
rm *.o

