#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#include <pthread.h>
#include <time.h>

#define MAX_LAST_NAME_SIZE 16

#define OPT 1

typedef struct _detail {
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
} detail;

typedef detail *pdetail;

typedef struct __PHONE_BOOK_ENTRY {
    char *lastName;
    struct __PHONE_BOOK_ENTRY *pNext;
    pdetail dtl;
} entry;

entry *findName(char lastname[], entry *pHead);

typedef struct _append_a {
    char *ptr;          // first address of certain pthread on map; map + MAX_LAST_NAME_SIZE * i
    char *eptr;         // last address of map; map + fs
    int tid;            // thread id ( 0, 1, 2, ...)
    int nthread;        // number of threads
    entry *entryStart;  // start address in entry pool
    entry *pHead;
    entry *pLast;
} append_a;

append_a *set_append_a(char *ptr, char *eptr, int tid, int ntd, entry *start);

void append(void *arg);

void show_entry(entry *pHead);

static double diff_in_second(struct timespec t1, struct timespec t2);

#endif
