// gcc -Wall -o searchengine searchengine.c
// wget -r -l 1 -k -p -e robots=off -nc -w 1 --random-wait -Q100m -D en.m.wikipedia.org http://en.m.wikipedia.org/wiki/C_%28programming_language%29

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "invertedindex.h"

struct InvertedIndex *createInvertedIndex(void)
{
	return calloc(1, sizeof(struct InvertedIndex));
}

// Add new head (struct InvertedIndexHead) to list of index heads. Return new head.
// Duplicate term and store in new head.
struct InvertedIndexHead *addInvertedIndexHead(
	struct InvertedIndex *idx,
	const char *term)
{
	// To Do Aufgabe 2 d)
	return NULL;
}

// Add new entry (struct InvertedIndexEntry) in the list of this index head. Return the new entry.
// Duplicate page URL. Store term frequency.
struct InvertedIndexEntry *addInvertedIndexEntry(		// <-- IMPL
	struct InvertedIndex *idx,
	struct InvertedIndexHead *head,
	struct Page *page,
	struct Term *term
)
{
	// To Do Aufgabe 2 c)
	return NULL;
}


// Return index head for the term if in index, return NULL otherwise.
struct InvertedIndexHead *findTermInIndex(
	const struct InvertedIndex *idx,
	const char *term)
{
	// To Do Aufgabe 2 b)
	return NULL;
}


// Inserts a single page into the index.
void insertTermsOfPageInIndex(struct InvertedIndex *idx, struct Page *page)
{
	if (idx == NULL || page == NULL) return;

	struct InvertedIndexHead *h;
	struct Term *t;

	// go through terms of page
	for (t = page->terms; t != NULL; t = t->next) {
		// check if term is already in the index
		if ((h = findTermInIndex(idx, t->term)) != NULL) {
			// term already in index, add page

				addInvertedIndexEntry(idx, h, page, t);

		} else { // term not yet in index
			// add new term to index
			h = addInvertedIndexHead(idx, t->term);
			// add entry for the new term
			addInvertedIndexEntry(idx, h, page, t);
		}
	}
}



// Inserts the whole page list into the empty index.
// precondition: idx is empty, idx != NULL, pl != NULL
void setPageList(struct InvertedIndex *idx, struct PageList *pl)
{
	if (idx == NULL || pl == NULL) return;

	idx->pageList = pl;

	struct PageListNode *p = NULL;

	// go through list of pages
	for (p = pl->nodes; p != NULL; p = p->next) {
		if (p->page != NULL) {
///			printf("inverted index set page: %s\n", p->page->url);
			insertTermsOfPageInIndex(idx, p->page);
		}
	}

}



void printInvertedIndex(struct InvertedIndex *idx)
{
	if (idx == NULL) return;

	struct InvertedIndexHead *h;
	struct InvertedIndexEntry *e;

	for (h = idx->head; h != NULL; h = h->next) {
		printf("term = %s\n", h->term);
		for (e = h->entries; e != NULL; e = e->next) {
			printf("\t\tpage = %s\n", e->url);
		}
	}

}

// produces GraphViz code (detailed)
// use this if you want
void printInvertedIndexGV(struct InvertedIndex *idx)
{
	if (idx == NULL) return;

	struct InvertedIndexHead *h;
	struct InvertedIndexEntry *e;

	printf(	"digraph structs {\n"
			"	rankdir=LR;\n"
			"	node [shape=record];\n");

	if (idx->head) {
		printf("	index [label=\"<pageList> pageList | <head> head \"];\n");
		printf("	index:head -> head%p;\n", idx->head);
	}

	for (h = idx->head; h != NULL; h = h->next) {
		printf("	head%p [label=\"<term> term | <entries> entries %s | <next> next %s\"];\n",
				h, h->entries ? "" : "= NULL", h->next ? "" : "= NULL");
		if (h->term) {
			printf("	string%p [label = \"%s\"];\n", h->term, h->term);
			printf("	head%p:term:e -> string%p:w;\n", h, h->term);
		}
		if (h->entries) {
			printf("	head%p:entries:e -> entry%p:w;\n", h, h->entries);
		}
		if (h->next) {
			printf("	head%p:next:e -> head%p:w;\n", h, h->next);
		}

		for (e = h->entries; e != NULL; e = e->next) {
			printf("	entry%p [label=\"<url> url | <frequency> frequency = %d | <next> next %s\"];\n",
					e, e->frequency, e->next ? "" : "= NULL");
			if (e->url) {
				printf("	string%p [label = \"%s\"];\n", e->url, e->url);
				printf("	entry%p:url:e -> string%p:w;\n", e, e->url);
			}
			if (e->next) {
				printf("	entry%p:next:e -> entry%p:w;\n", e, e->next);
			}
		}


	}

	printf(	"}\n");

}


// produces GraphViz code (simplified)
// use this if you want
void printInvertedIndexGVSimple(struct InvertedIndex *idx)
{
	if (idx == NULL) return;

	struct InvertedIndexHead *h;
	struct InvertedIndexEntry *e;

	printf(	"digraph structs {\n"
			"	rankdir=LR;\n");

	for (h = idx->head; h != NULL; h = h->next) {
		printf("	head%p [label=\"%s\"];\n", h, h->term);
		if (h->entries) {
			printf("	head%p -> entry%p;\n", h, h->entries);
		}
		if (h->next) {
			printf("	head%p -> head%p;\n", h, h->next);
		}

		for (e = h->entries; e != NULL; e = e->next) {
			printf("	entry%p [label=\"%s\"];\n", e, e->url);
			if (e->next) {
				printf("	entry%p -> entry%p;\n", e, e->next);
			}
		}

	}
	printf(	"}\n");

}



int mainA2(int argc, char *argv[])
{
	struct PageList *pl;
	pl = createPageList();
	setBasePath(".../searchengineproject/minicorpus/"); // Need to be changed

	loadPages(pl, "a.txt");

	struct InvertedIndex *idx = createInvertedIndex();
	setPageList(idx, pl);

	printInvertedIndexGV(idx);
//	printInvertedIndexGVSimple(idx);

	return 0;
}
