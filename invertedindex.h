// gcc -Wall -o invertedindex page.c pagelist.c invertedindex.c

#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include "pagelist.h"

struct InvertedIndexEntry {
	char *url; // document URL
	int frequency; // number of times the term appears in document
	//struct Page *p;
	//struct Term *t;
	struct InvertedIndexEntry *next;
};

struct InvertedIndexHead {
	char *term;
	int documentFrequency;
	struct InvertedIndexEntry *entries;
	struct InvertedIndexHead *next;
};

struct InvertedIndex {
	struct PageList *pageList; // the list of pages from which this index was generated
	struct InvertedIndexHead *head;
};

struct InvertedIndex *createInvertedIndex(void);

struct InvertedIndexHead *addInvertedIndexHead(
	struct InvertedIndex *idx,
	const char *term);

struct InvertedIndexEntry *addInvertedIndexEntry(
	struct InvertedIndex *idx,
	struct InvertedIndexHead *head,
	struct Page *page,
	struct Term *term
);

struct InvertedIndexHead *findTermInIndex(
	const struct InvertedIndex *idx,
	const char *term);

void insertTermsOfPageInIndex(struct InvertedIndex *idx, struct Page *page);

// precondition: idx is empty, idx != NULL, pl != NULL
void setPageList(struct InvertedIndex *idx, struct PageList *pl);

void printInvertedIndex(struct InvertedIndex *idx);

#endif
