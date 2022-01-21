#include <dlfcn.h> // для дин библиотек
#include <string.h>
#include <stdlib.h>

#include "FilesInFolder.h" //для получения кол-ва и списка имён файлов в папке
#include "pluginFunctions.h" //Функции для работы с плагинами

int mainMenu(void **uploadedPlugins, int countUpdoloadedPlugins){
	char *(*getPluginMenuDescription_ptr)(void) = NULL;
	void (*pluginStart_ptr)(void) = NULL;
	printf("\n*** ГЛАВНОЕ МЕНЮ ***\nДля выхода ctr+c\n");
	printf("Выберите действие: \n");
	for(int i=0; i<countUpdoloadedPlugins; i++){
		getPluginMenuDescription_ptr = dlsym(uploadedPlugins[i], "getPluginMenuDescription");
		printf("%d. %s\n",i+1, getPluginMenuDescription_ptr());
	}
	int choice;
	scanf("%d", &choice);
	if(!(choice > 0 && choice <= countUpdoloadedPlugins)){
		printf("Ошибка! Неверный ввод действия!\n");
		return -1;
	}
	pluginStart_ptr = dlsym(uploadedPlugins[--choice], "pluginStart");
	pluginStart_ptr();
	return 0;
}
int main(){
	void *uploadedPlugins[MAX_COUNT_PLUGINS]; //А вообще можно сделать динамически изменяемый массив
	int countUpdoloadedPlugins = 0;
	pluginsUpload("./plugins/",uploadedPlugins ,&countUpdoloadedPlugins);

	printf("Всего успешно загруженных плагинов: %d\n", countUpdoloadedPlugins);

	if(countUpdoloadedPlugins == 0){
		printf("Наш калькулятор без плагинов ничего не умеет.\nЗавершение работы\n");
		return 0;
	}
	while(1) {mainMenu(uploadedPlugins, countUpdoloadedPlugins);}

	return 0;
}