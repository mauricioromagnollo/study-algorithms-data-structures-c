#ifndef TODOLIST_H_INCLUDED
#define TODOLIST_H_INCLUDED


#endif // TODOLIST_H_INCLUDED
#include "todolist_types.h"

task_t newTask(description_t, date_t, date_t);
void setIsDone(task_t *, bool);
void setId(id_t, task_t *);
