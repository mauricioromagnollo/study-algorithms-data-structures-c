
#include <stdio.h>
#include <stdlib.h>
#include "binaryfile.h"

int main() {

  User_t user;
  id_t id;
  FILE *file;
  bool runLoopExec = true;

  setLocaleLang();
  clearConsoleScreen();
  
  makeNewDir(PATH_NEW_DIR);
  
  if(!isExist(file, FILENAME)) {
    file = newFile(FILENAME);
  }

  while(runLoopExec) {
    clearConsoleScreen();

    switch(getMainOptions()) {
      
      case 0: // Exit
        printf("\n[!] Exiting...\n");
        pauseRuntime(2);
        runLoopExec = false;
        break;

      case 1: // New User - C
        inputNewUser(&user);
        insertInFile(user, DATASIZE, file, FILENAME);
        break;

      case 2: // Search User - R
        break;
      
      case 3: // Edit User - U
        break;
      
      case 4: // Delete User - D
        break;
      
      case 5: // Read All Data File
        readAndPrintAllFile(file, FILENAME, DATASIZE);
        break;
      
      default: 
        printf("\n[!] Invalid keyboard input option... try again!\n");
        pauseRuntime(2);
        break;
    }
  }

  printf("\n");
  return 0;
}