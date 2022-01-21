#ifndef PLUGINFUCNT //header guard
#define PLUGINFUCNT //header guard

char *getPluginInfo(); //Вернет строку-описание данного плагина
char *getPluginMenuDescription(); //Получить короткое описание действий плагина (как будет отобр в меню)
char *checkPlugin(); //Для проверки плагина (простейшая проверка "левый фаил или рабочий плагин")
void pluginStart(); //запустить исполнение кода плагина


#endif //header guard