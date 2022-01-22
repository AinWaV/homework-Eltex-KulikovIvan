#include <stdio.h>
#include <fcntl.h>
#include <string.h>
//http://www.c-cpp.ru/content/open-rtlopen

int main(void){
    int fd;
    const char filename[]= "outputText.txt";
    char inputStr[256] = {0};
                                                                                    //O_TRUNC - очищает фаил при открытии на запись
    if((fd=open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1) { //O_CREAT создать фаил, если его не существует
    printf("Cannot open file.\n");                                         //S_IRUSR | S_IWUSR права на чтение и запись
    exit (1);                                                           
    }
    
    printf("Введите строку для записи в фаил: %s\n", filename);
    if(!fgets(inputStr, sizeof(inputStr), stdin)){
        printf("Ошибка! fgets()");
        return -1;
    }
    if(write(fd, inputStr, strlen(inputStr)) !=strlen(inputStr)) printf("Write Error");
    else printf("Текст успешно записан в фаил\n"); 
    close(fd);
    return 0;
}