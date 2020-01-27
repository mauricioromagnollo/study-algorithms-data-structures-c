#include "../headers/todolist.h"

task_t newTask(description_t description, date_t dateInit, date_t dateEnd) {
  return(task_t) {
    -1,
    description,
    dateInit,
    dateEnd,
    false
  };
}

void setIsDone(task_t *task, bool itsDone) {
  task->isDone = (itsDone) ? true : false;
}

void setId(id_t lastId, task_t *task) {
  task->id = (lastId + 1);
}
