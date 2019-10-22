/* ::::::::::::::::::::::::::::::::::::
   			    Interface
   ::::::::::::::::::::::::::::::::::::  */

/* ::::::::::::::::::::::::::::::::::::
   			    Auxiliary Functions
   ::::::::::::::::::::::::::::::::::::  */

FILE * newFile(char *fileName);
bool isExist(FILE *file, char *fileName);
void printUser(User_t user);
void inputNewUser(User_t *user);
void insertInFile(User_t user, size_t sizeOfData, FILE *file, char *fileName);
// void removeUser(id_t id, FILE *file, char *fileName);
unsigned int getNextCursorAcessPosition(FILE *file, char *fileName, size_t sizeCursorMove);
User_t getUser(id_t id, FILE *file, char *fileName, size_t sizeDataBytes);
void readAndPrintAllFile(FILE *file, char *fileName, size_t sizeDataBytes);
main_t getMainOptions();

/* ::::::::::::::::::::::::::::::::::::
   			    System Functions
   ::::::::::::::::::::::::::::::::::::  */

void setLocaleLang();
void clearBuffer();
void clearConsoleScreen();
void makeNewDir(char *pathDir);
char * getDate();
char * getTime();
void pauseRuntime(int tSeconds);
short int deleteFile(char *fileName);

#endif // BINARYFILE_H_INCLUDED