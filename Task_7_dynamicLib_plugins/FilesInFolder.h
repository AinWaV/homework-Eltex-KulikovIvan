#ifndef FILESINFOLDER //header guard
#define FILESINFOLDER //header guard


#define MAX_COUNT_PLUGINS 64

struct namesfilesInDir{
    char *pathDir;
    unsigned int countFiles;
    char *filesNamesPtrs[MAX_COUNT_PLUGINS];
};
 
int getNamesFilesInFolder (struct namesfilesInDir *namesfilesInDir);

#endif //header guard