// gcc -Wall -o searchengine searchengine.c
// wget -r -l 1 -k -p -e robots=off -nc -w 1 --random-wait -Q100m -D en.m.wikipedia.org http://en.m.wikipedia.org/wiki/C_%28programming_language%29

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "invertedindex.h"
#define Debug 1

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
//	printf("current documentFrequency:%d\n",head->documentFrequency);
	struct InvertedIndexEntry *e = calloc(1,sizeof(struct InvertedIndexEntry));
	struct InvertedIndexHead *h = calloc(1,sizeof(struct InvertedIndexHead));
	//printf("code 333");
// ganz wichtig da wir sonst nicht auf frequency und terms zugreifen koennen . Das hier ist die zuweisung fuer unser Entry auf welcher page und terms wir arbeiten in diesem 
	e->page = page;
	e->term = term;
	//char meinarray[strlen(term->term)+1];
	char *tmp = strdup(page->url);
	//printf("code 33433");
	//printf("%s\n",tmp);
	e->term->frequency = term->frequency;
	//printf("code 555");
	e->page->url = tmp;
	//printf("code 444");
	
	//neues a.txt mit zahl erzeugt
	h->entries = head->entries;
	head->entries = e;	
	e->next = h->entries;
//	printf("For page:%s,the Term:%s is %d times there\n",page->url,e->url,e->frequency);
//	printf("code 222");

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
//	printf("test 1.1.1");
	if (idx == NULL || page == NULL) return;

	struct InvertedIndexHead *h;
//	printf("test 1.1.2");
	struct Term *t;
//	printf("test 1.1.3");

	// go through terms of page
	for (t = page->terms; t != NULL; t = t->next) {
		//printf("test 1.1.1.1");
		//printf("Code 111\n");
//		printf("%s\n",t->term);
		// check if term is already in the index
		if ((h = findTermInIndex(idx, t->term)) != NULL) {
			//printf("test 1.1.1.1");
			// term already in index, add page

				addInvertedIndexEntry(idx, h, page, t);

		} else { // term not yet in index
			//printf("test 2.1.1.1");
			// add new term to index
//			printf("here we go");
			h = addInvertedIndexHead(idx, t->term);
			//printf("test 2.2.1.1");
			// add entry for the new term
			addInvertedIndexEntry(idx, h, page, t);
//			printf("test 2.3.1.1");
		}
	}
}



// Inserts the whole page list into the empty index.
// precondition: idx is empty, idx != NULL, pl != NULL
void setPageList(struct InvertedIndex *idx, struct PageList *pl)
{
//	printf("test 1.1");
	if (idx == NULL || pl == NULL){
		printf("Error Code:123");
		return;
	}

	idx->pageList = pl;
//	printf("test 1.2");

	struct PageListNode *p = NULL;
//	printf("test 1.3");

	// go through list of pages
	for (p = pl->nodes; p != NULL; p = p->next) {
		if (p->page != NULL) {
//			printf("inverted index set page: %s\n", p->page->url);
			insertTermsOfPageInIndex(idx, p->page);
		}
	}
//	printf("test 1.4");

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
			printf("\t\tpage = %s\n", e->page->url);
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
					e, e->term->frequency, e->next ? "" : "= NULL");
			if (e->page->url) {
				printf("	string%p [label = \"%s\"];\n", e->page->url, e->page->url);
				printf("	entry%p:url:e -> string%p:w;\n", e, e->page->url);
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
			printf("	entry%p [label=\"%s\"];\n", e, e->page->url);
			if (e->next) {
				printf("	entry%p -> entry%p;\n", e, e->next);
			}
		}

	}
	printf(	"}\n");

}


// B 08 Aufgabe 1 d)
int saveInvertedIndex(const struct InvertedIndex *idx, const char* fileName)
{
	if (idx == NULL || path == NULL) return 0;

	/*
	 * Format:
	 *
	 * <page url>
	 * <page url>
	 * ...
	 *
	 * <empty line>
	 * <term>
	 * <page url>
	 * <term frequency>
	 * <page url>
	 * <term frequency>
	 * ...
 	 */

	if (strlen(BASE_PATH) + strlen(fileName) > PATH_SIZE) {
		return 0;
	}
	strcpy(path, BASE_PATH);
	strcat(path, fileName);

	FILE* file = fopen(path, "w"); // open file for writing
	if (file == NULL) {
		printf("COULD NOT SAVE INDEX TO: %s\n", path);
		return 0;
	}

	// save page URLs
	struct PageListNode *p;
	for (p = idx->pageList->nodes; p != NULL; p = p->next) {
		fprintf(file, "%s\n", p->page->url);
	}

	struct InvertedIndexHead *h;
	struct InvertedIndexEntry *e;

	// save each term in index
	for (h = idx->head; h != NULL; h = h->next) {
		fprintf(file, "\n%s\n", h->term);
		for (e = h->entries; e != NULL; e = e->next) {
			fprintf(file, "%s\n%d\n", e->page->url, e->term->frequency);
		}
	}

	fclose(file);

	return 1;
}

// B 08 Aufgabe 1 d)
// get next line, remove trailing newline character
static char *fgetl(char *s, int count, FILE *file)
{
	char *r = fgets(s, count, file);
	if (r != NULL) {
		int n = strlen(s) - 1;
		if (n >= 0 && s[n] == '\n') {
			s[n] = '\0';
		}
	}
	return r;
}

// B 08 Aufgabe 1 d)
struct InvertedIndex *loadInvertedIndex(const char* fileName)
{
	if (path == NULL) return NULL;

	if (strlen(BASE_PATH) + strlen(fileName) > PATH_SIZE) {
		return NULL;
	}
	strcpy(path, BASE_PATH);
	strcat(path, fileName);

	FILE* file = fopen(path, "r"); // open file for reading
	if (file == NULL) {
		printf("COULD NOT LOAD INDEX FROM: %s\n", path);
		return NULL;
	}

	/*
	 * The following code does not check for correctness of the file format.
	 *
	 * Format:
	 *
	 * <page url>
	 * <page url>
	 * ...
	 *
	 * <empty line>
	 * <term>
	 * <documentFrequency>
	 * <page url>
	 * <term frequency>
	 * <page url>
	 * <term frequency>
	 * ...
 	 */

	struct InvertedIndex *idx = createInvertedIndex();
	idx->pageList = createPageList();
	// @todo: if NULL...


	struct Page *p;
	// <page url>
	while ((fgetl(buffer, sizeof(buffer), file) != NULL) && strlen(buffer) > 0) {
		p = calloc(1, sizeof(struct Page));
		// @todo: if NULL...
		p->url = strdup(buffer);
		// @todo: if NULL...
		putPage(idx->pageList, p);
		// @todo: if 0...
	}

	struct InvertedIndexHead *h;
	struct InvertedIndexEntry *e;
	struct Term *t;

	// <term>
	while ((fgetl(buffer, sizeof(buffer), file) != NULL) && strlen(buffer) > 0) {
		h = addInvertedIndexHead(idx, buffer);
		// @todo: if NULL...
		// printf("h->term = %s\n", h->term);
		// <page url>
		while ((fgetl(buffer, sizeof(buffer), file) != NULL) && strlen(buffer) > 0) {
			// assert: page has already been put in page
			p = getPage(idx->pageList, buffer);
			// printf("p->url = %s\n", p->url);

			t = calloc(1, sizeof(struct Term));
			// @todo: if NULL...
			t->term = strdup(h->term);
			// @todo: if NULL...

			// <term frequency>
			fgetl(buffer, sizeof(buffer), file);
			t->frequency = atoi(buffer);
			// printf("t->frequency = %d\n", t->frequency);

			t->next = p->terms;
			p->terms = t;

			e = addInvertedIndexEntry(idx, h, p, t);

		}
	}

	fclose(file);

	return idx;
}
int numberOfTermsInIndex(const struct InvertedIndex *idx){
	if(idx == NULL){
		return 0;
	}
	int i = 0;
	struct InvertedIndexHead *h = calloc(1,sizeof(struct InvertedIndexHead));
	for(h = idx->head;h!=NULL;h = h->next){
	//	printf("%s\n",h->term);
		i++;
	}
	return i;
}
int numberOfTermsOccurencesInIndex(const struct InvertedIndex *idx){
	if(idx == NULL){
		return 0;
	}
	int i = 0;
	struct InvertedIndexHead *h = calloc(1,sizeof(struct InvertedIndexHead));
	struct InvertedIndexEntry *e = calloc(1,sizeof(struct InvertedIndexEntry));
	for(h = idx->head;h!=NULL;h = h->next){
		for(e= h->entries;e!=NULL; e = e->next){
	//			printf("%d\n",e->t->frequency);
				i = i + e->term->frequency;
		}
	//	printf("%s\n",h->term);
	}
	return i;
	

}

int main(int argc, char *argv[])
{
	#if Debug
		printf("Debug statement in main\n");
	#endif
	struct PageList *pl;
	pl =createPageList();

	//loadPages(pl,"C_(programming_language)");
	loadPages(pl, "a.txt");
	#if Debug
		printf("test 1\n");
	#endif

	struct InvertedIndex *idx = createInvertedIndex();
	#if Debug
		printf("test 2\n");
	#endif
	setPageList(idx, pl);
	#if Debug
		printf("test 3\n");
	#endif
	printInvertedIndex(idx);
	#if Debug
		printf("test 4\n");
	#endif
	//printf("%s\n\n",idx->pageList->nodes->page->url);
	#if Debug
	printf("test 5");
	#endif
	//if(idx->head->entries->url == NULL){
	//	printf("its nulss");
	//}
	//printf("%s\n\n",idx->head->entries->url);
//	struct InvertedIndexHead *idxh;
//	idxh = findTermInIndex( idx, "tmp char array to test");

	//printInvertedIndexGV(idx);
	printInvertedIndexGVSimple(idx);
	int b = saveInvertedIndex(idx,"Indexsaved");
	struct InvertedIndex *test = loadInvertedIndex("Indexsaved");
	printInvertedIndex(test);
	int z = numberOfTermsInIndex(idx);
	printf("Number of Terms in our Index are: %d\n",z);
	int y = numberOfTermsOccurencesInIndex(idx);
	printf("Number of Terms Total in our Index are: %d\n",y);
	


	return 0;
}
