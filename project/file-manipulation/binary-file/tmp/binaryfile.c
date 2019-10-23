
FILE * newFile(char *fileName) {
  FILE *file = fopen(fileName, "wb");
  if(file) return file;
  return NULL;
}

bool isExist(FILE *file, char *fileName) {
  bool isFileExist = false;
  file = fopen(fileName, "rb");
  if(file) {
    isFileExist = true;
    fclose(file);
  }
  return isFileExist;
}

void printUser(User_t user) {
  printf("\n=========================================\n");
  printf("Id:......%d\n", user.id);
  printf("Name:....%s %s\n", user.firstName, user.lastName);
  printf("Age:.....%d\n", user.age);
  printf("E-mail:..%s\n", user.contact.email);
  printf("Number: %d\n", user.contact.phone);
  printf("=========================================");
}

void inputNewUser(User_t *user) {
  printf("\n----------------------------------\n");
  printf("[*] Entering data for a new user:\n");
  printf("----------------------------------\n");
  // setId(user->id) == lineNumber;
  clearBuffer();
  user->id = 2;
  printf("[#] First Name: ");
  gets(user->firstName);  clearBuffer();
  printf("[#] Last Name: ");
  gets(user->lastName);  clearBuffer();
  printf("[#] Age: ");
  scanf("%d", &user->age);  clearBuffer();
  printf("[#] E-mail: ");
  gets(user->contact.email); clearBuffer();
  printf("[#] Number: ");
  scanf("%d", &user->contact.phone); clearBuffer();
}

void makeNewDir(char *pathDir) {
  struct stat st = {0};
  if(stat(pathDir, &st) == -1) {
    if(mkdir(pathDir, 0700) == 0) {
      printf("\n[*] New directory %s created successfully.\n", pathDir);
      pauseRuntime(2);
    } else {
      printf("\n[!] New directory %s creation failed.\n", pathDir);
      pauseRuntime(2);
      exit(1);
    }
  }
}

void setLocaleLang() {
	setlocale(LC_ALL,"");
}

void clearBuffer() {
  #ifdef __unix__
    __fpurge(stdin);
  #elif defined(_WIN32) || defined(WIN32)
    fflush(stdin);
  #endif
}

void clearConsoleScreen() {
  #ifdef __unix__
    system("clear");
  #elif defined(_WIN32) || defined(WIN32)
    system("cls");
  #endif
}

char * getDate() {
	return &*__DATE__;
}

char * getTime() {
	return &*__TIME__;
}

void pauseRuntime(int tSeconds) {
  #ifdef __unix__
    sleep(tSeconds);
  #elif defined(_WIN32) || defined(WIN32)
    Sleep(t_seg * 1000);
  #endif
}

short int deleteFile(char *fileName) {
	return(!remove(fileName));
}

void insertInFile(User_t user, size_t sizeOfData, FILE *file, char *fileName) {
  file = fopen(fileName, "ab");
  if(file)
    fwrite(&user, sizeOfData, 1, file);
  fclose(file);
}

unsigned int getNextCursorAcessPosition(FILE *file, char *fileName, size_t sizeCursorMove) {
  file = fopen(fileName, "rb");
  fseek(file, sizeCursorMove, SEEK_CUR);
  unsigned int linePosition = ((int) ftell(file));
  fclose(file);
  return (linePosition);
}

User_t getUser(id_t id, FILE *file, char *fileName, size_t sizeDataBytes) {
  unsigned int lineNumber = id;
  User_t catchUser;
  file = fopen(fileName, "rb");
  if(file) {
    fseek(file, ((lineNumber - 1) * sizeDataBytes), SEEK_SET);
    fread(&catchUser, sizeDataBytes, 1, file);
  }
  fclose(file);
  return catchUser;
}

void readAndPrintAllFile(FILE *file, char *fileName, size_t sizeDataBytes) {
  User_t user;
  int lineNumber = 0;
  file = fopen(fileName, "rb");

  if(file) {
    printf("\n========================\nPRINTING ALL USERS\n========================\n");
    while(!feof(file)) {
      fseek(file, lineNumber * sizeDataBytes, SEEK_SET);
      fread(&user, sizeDataBytes, 1, file);
      printUser(user);
      lineNumber++;
    }
    printf("========================\n");
    fclose(file);
  }
}

main_t getMainOptions() {
  main_t option;
  printf("\n============================================\n");
  printf("[*] MAIN OPTIONS:\n");
  printf("============================================\n");
  printf("1 - New User\n");
  printf("2 - Search User\n");
  printf("3 - Edit User\n");
  printf("4 - Delete User\n");
  printf("5 - All Users\n");
  printf("> ");
  scanf("%ui",&option);
  clearBuffer();
  return option;
}