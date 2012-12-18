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
	struct InvertedIndexHead *h = calloc(1,sizeof(struct InvertedIndexHead));
	char *tmp = strdup(term);
	h->term =  tmp;
	h->next = idx->head;
	idx->head = h;
	return h;
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
	if(idx==NULL||head==NULL||page==NULL||term==NULL){
		return NULL;
	}
//	struct InvertedIndexHead *h = calloc(1,sizeof(struct InvertedIndexHead ));
//	struct Page *p=  calloc(1,sizeof(struct Page));
//	struct Term *t = calloc(1,sizeof(struct Term));
	head->documentFrequency++ ;
	printf("current documentFrequency:%d\n",head->documentFrequency);
	struct InvertedIndexEntry *e = calloc(1,sizeof(struct InvertedIndexEntry));
	struct InvertedIndexHead *h = calloc(1,sizeof(struct InvertedIndexHead));
	//char meinarray[strlen(term->term)+1];
	char *tmp = strdup(page->url);
//	printf("%s\n",tmp);
	e->url = tmp;
	e->frequency = term->frequency;
	
	//neues a.txt mit zahl erzeugt
	h->entries = head->entries;
	head->entries = e;	
	e->next = h->entries;
//	printf("For page:%s,the Term:%s is %d times there\n",page->url,e->url,e->frequency);

	return e;
}


// Return index head for the term if in index, return NULL otherwise.
struct InvertedIndexHead *findTermInIndex( const struct InvertedIndex *idx, const char *term)
{
	if(idx ==NULL || term == NULL){
		return;
	}
	
	//printf("|||||%s\n",idx->head->term);
//	printf("function working on gets called\n");	

	struct InvertedIndexHead *h;
	for (h= idx->head; h != NULL; h = h->next) {
//		printf("term = %s\n", h->term);
		if(!strcmp(h->term ,term)){
			return h;
		}
	}
// if term is in our list
	return NULL;
// if term doesn't exist in our list
}


// Inserts a single page into the index.
void insertTermsOfPageInIndex(struct InvertedIndex *idx, struct Page *page)
{
	if (idx == NULL || page == NULL) return;

	struct InvertedIndexHead *h;
	struct Term *t;

	// go through terms of page
	for (t = page->terms; t != NULL; t = t->next) {
		//printf("Code 111\n");
		//printf("%s\n",t->term);
		// check if term is already in the index
		if ((h = findTermInIndex(idx, t->term)) != NULL) {
			// term already in index, add page

				addInvertedIndexEntry(idx, h, page, t);

		} else { // term not yet in index
			// add new term to index
//			printf("here we go");
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
	if (idx == NULL || pl == NULL){
		printf("Error Code:123");
		return;
	}

	idx->pageList = pl;

	struct PageListNode *p = NULL;

	// go through list of pages
	for (p = pl->nodes; p != NULL; p = p->next) {
		if (p->page != NULL) {
//			printf("inverted index set page: %s\n", p->page->url);
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
		printf("documentFrequency = %d\n",h->documentFrequency);
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



int main(int argc, char *argv[])
{
	struct PageList *pl;
	pl =createPageList();

	loadPages(pl, "a.txt");

	struct InvertedIndex *idx = createInvertedIndex();
	setPageList(idx, pl);
	printInvertedIndex(idx);
	printf("%s\n\n",idx->pageList->nodes->page->url);
	//if(idx->head->entries->url == NULL){
	//	printf("its nulss");
	//}
	//printf("%s\n\n",idx->head->entries->url);
//	struct InvertedIndexHead *idxh;
//	idxh = findTermInIndex( idx, "tmp char array to test");

	//printInvertedIndexGV(idx);
	printInvertedIndexGVSimple(idx);


	return 0;
}
