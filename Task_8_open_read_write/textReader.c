#include <stdio.h>
#include <fcntl.h>
#include <string.h>
//http://www.c-cpp.ru/content/open-rtlopen

// int64_t getFileSize(const char* file_name){
// 	int64_t _file_size = 0;
// 	struct stat _fileStatbuff;
// 	int fd = open(file_name, O_RDONLY);
// 	if(fd == -1){
// 		_file_size = -1;
// 	}
// 	else{
// 		if ((fstat(fd, &_fileStatbuff) != 0) || (!S_ISREG(_fileStatbuff.st_mode))) {
// 			_file_size = -1;
// 		}
// 		else{
// 			_file_size = _fileStatbuff.st_size;
// 		}
// 		close(fd);
// 	}
// 	return _file_size;
// }

int main(void){
    int fd;
    const char filename[]= "outputText.txt";
    char readStrBuf[10]; //Можем устанавливать любой размер

    if((fd=open(filename, O_RDONLY)) == -1) { 
    printf("Cannot open file.\n");                                       
    exit (1);                                                           
    }
    
    int readBytes = 0;
    printf("Считанный текст из файла: %s\n", filename);
    while(1){
        readBytes = read(fd, readStrBuf, sizeof(readStrBuf));
        if(readBytes <= 0) break;
        readStrBuf[readBytes] = '\n';
        printf("%.*s",readBytes,readStrBuf); //.* - ограничение ширины поля = readBytes
    }

    close(fd);
    return 0;
}