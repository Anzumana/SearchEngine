// gcc -Wall -o pagelist page.c pagelist.c

#ifndef PAGELIST_H
#define PAGELIST_H

//#include "pageUe06.h"
#include "page.h"

struct PageList {
	struct PageListNode *nodes;
};

struct PageListNode {
	struct Page *page;
	struct PageListNode *next;
};

struct PageList *createPageList(void);

int putPage(struct PageList *pl, struct Page *page);

struct Page *getPage(struct PageList *pl, const char *url);

int numberOfPages(struct PageList *pl);

void loadPages(struct PageList *pl, const char* url);

void printPagesContainingTerm(struct PageList *pl, char *term);

#endif
