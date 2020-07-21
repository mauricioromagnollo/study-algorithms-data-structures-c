#ifndef BINARY_FILE_H_INCLUDED
#define BINARY_FILE_H_INCLUDED

#include <stdio.h>

typedef enum { false, true } bool;

#define PATH_DATA "./data"
#define PATH_FILE "./data/data.bin"
#define MAX_USERS_SIZE 100

typedef unsigned int userid_t;
typedef unsigned int age_t;
typedef char name_t[20];
typedef char mail_t[20];
typedef char phone_t[10];

typedef struct {
  mail_t email;
  phone_t number;
} contact_t;

typedef struct {
  userid_t id;
  name_t firstName;
  name_t lastName;
  age_t age;
  contact_t contact;
} user_t;

#define DATA_SIZE sizeof(user_t)
#define FILE_DATA_SIZE_MAX (MAX_USERS_SIZE * DATA_SIZE)

#endif