#pragma once
#ifndef __LIBRARY_H
#define __LIBRARY_H

#include <iostream>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

#define YES 1
#define NO 0
typedef enum { cmd_exit, cmd_add, cmd_remove, cmd_find, cmd_showlist, cmd_recruit }comand;

#define PHONE_SET { "090", "098", "091", "031", "035", "038" }
#define PHONE_SIZE 8
#define MIN_RECRUIT 3           //so luong sinh vien toi thieu can tuyen dung
#define MAX_RECRUIT 10          //so luong sinh vien toi da can tuyen dung

typedef enum {
    nam,
    nu
}gender;

typedef enum {
    good,
    normal
}level;

typedef enum {
    EXIT_T,
    GOOD_T,
    NORMAL_T
}Student_t;

#endif