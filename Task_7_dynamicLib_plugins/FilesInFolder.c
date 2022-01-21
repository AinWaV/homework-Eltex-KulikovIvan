/*
Используется для работы с файлами в директории
*/
#include <stdio.h>
#include <dirent.h>
#include <string.h>

#include "FilesInFolder.h"


int getNamesFilesInFolder (struct namesfilesInDir *nfilesInDir){
    DIR *dir;
    struct dirent *ent;
    char *newStrPtr = NULL; 

    if ((dir = opendir (nfilesInDir->pathDir)) != NULL) {
        while ((ent = readdir (dir)) != NULL) {
            if(!strcmp(ent->d_name, ".")  || !strcmp(ent->d_name, "..")) continue; //не хитрый костыль
            newStrPtr = malloc(strlen(ent->d_name));
            strcpy(newStrPtr, ent->d_name);
            nfilesInDir->filesNamesPtrs[nfilesInDir->countFiles++] = newStrPtr;
        }
        closedir (dir);
        } else {
        perror ("");
        return -1;
    }
    return 0;
}