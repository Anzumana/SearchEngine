// gcc -Wall -o invertedindex page.c pagelist.c invertedindex.c searchengine.c

#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H

#include "invertedindex.h"

struct ResultListElement {
	struct Page *page;
	struct ResultListElement *next;
};

struct ResultList {
	struct ResultListElement *element;
};

void computeWeights(struct InvertedIndex *idx);

void computeWeightsForQuery(struct InvertedIndex *idx, struct Page *query);

struct ResultList *computeScores(struct InvertedIndex *idx, struct Page *query);

struct Page *oneResult (struct InvertedIndex *idx);

int createHtmlResult(struct ResultList *resultList, const char *fileName, int n);

#endif
