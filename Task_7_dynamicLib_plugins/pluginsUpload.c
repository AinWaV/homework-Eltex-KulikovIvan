#include "FilesInFolder.h"
#include <string.h>
#include <dlfcn.h>
#include <stdio.h>

char *getFileNamePathDlopen(const char* pathDirUpload, const char* fileName){
    static char strBuf[100];
    strcpy(strBuf, pathDirUpload);
    strcat(strBuf, fileName);
    return strBuf;
}

int pluginsUpload(const char* pathDirUpload, void **uploadedPlugins, int *countUpdoloadedPlugins){ //"./plugins/"
    struct namesfilesInDir namesfilesInDir;
	namesfilesInDir.pathDir = pathDirUpload; //Папка в которой лежит бинарник обозн "."
	namesfilesInDir.countFiles = 0;

    void *plugin_handler;     //указатель на подгружаемую библиотеку
    char *(*plugin_checkFunct_ptr)(void); //Указатель на функцию проверки плагина

	if(getNamesFilesInFolder(&namesfilesInDir) == -1) exit(-1); //Получить кол-во и имена файлов в указанной папке

     for(int i=0; i<namesfilesInDir.countFiles; i++){
        if(strstr (namesfilesInDir.filesNamesPtrs[i],"plugin") == NULL) continue; //Если фаил не содержит в названии слово "plugin"
        plugin_handler = dlopen(getFileNamePathDlopen(pathDirUpload, namesfilesInDir.filesNamesPtrs[i]),RTLD_LAZY); //указатель на подгружаемый плагин
        if (!plugin_handler){	printf("dlopen() error: %s\n", dlerror()); continue; }	//Если плагин не открыли
        plugin_checkFunct_ptr = dlsym(plugin_handler, "checkPlugin");
        if(strcmp(plugin_checkFunct_ptr(),"pluginIsOk")){
            printf("Updload error, file is corrupted!: %s\n", namesfilesInDir.filesNamesPtrs[i]);
            dlclose(plugin_handler);
            continue;
        }
        //Если все что выше прошло успешно, заносим хенд плагина в список и увел счетчик на 1
        uploadedPlugins[(*countUpdoloadedPlugins)++] = plugin_handler;
        printf("Успешно загружен плагин: %s\n", namesfilesInDir.filesNamesPtrs[i]);
    }

	
}