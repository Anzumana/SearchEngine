// gcc -Wall -o pagelist page.c pagelist.c

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pagelist.h"

struct PageList *createPageList(void)
{
	struct PageList *pl= calloc(1,sizeof(struct PageList));
	return pl;
}


int putPage(struct PageList *pl, struct Page *page)
// return 0 if nothing added
// return 1 if page addet to pagelist
{
	if(pl==NULL||page==NULL){
		return 0;
	}
	struct PageListNode *tmp = calloc(1,sizeof(struct PageListNode));
	for(tmp = pl->nodes; tmp!=NULL ; tmp=tmp->next){
		if(!strcmp(tmp->page->url,page->url)){
	//		printf("Seite bereits vorhanden!");
			return 0;
		}
	}
	
	struct PageListNode *pln = calloc(1,sizeof(struct PageListNode));
	pln->page = page;
	pln->next = pl->nodes;
	pl->nodes = pln;
	return 1;
}

struct Page *getPage(struct PageList *pl, const char *url)
{
	if(pl==NULL||url==NULL){
		return;
	}
	struct PageListNode *tmp = calloc(1,sizeof(struct PageListNode));
	for(tmp = pl->nodes; tmp!=NULL ; tmp=tmp->next){
		if(!strcmp(tmp->page->url,url)){
	//		printf("Seite bereits vorhanden!");
			return tmp->page;
		}
	}
	return NULL;
}


int numberOfPagesR(struct PageListNode *pln)
{
	if(pln==NULL){
		return 0;
	}
	struct PageListNode *tmp = calloc(1,sizeof(struct PageListNode));
	tmp = pln;
	tmp = tmp->next;
	int a = 1 + numberOfPagesR(tmp);
	return a;

}

int numberOfPages(struct PageList *pl)
{
	if(pl==NULL){
		return 0;
	}
	struct PageListNode *tmp = calloc(1,sizeof(struct PageListNode));
	tmp = pl->nodes;
	return numberOfPagesR(tmp);
}


static int strStartsWith(const char *s, const char *prefix)
{
	if(s==NULL||prefix==NULL){
		return;
	}
	// To Do Aufgabe 1 f);
	int length = strlen(prefix);
	//printf("The string to check is %d long\n", length);
	char c[length+1];
	strncpy (c,s,length);
	c[length] ='\0';
	//printf("%s and %s\n",prefix,c);
	if(!strcmp(c,prefix)){
//		printf("yes this works");
		return 0;
	}
	return 1;
}


void loadPages(struct PageList *pl, const char* url)
{
	#if Debug
	printf("Statement\n");
	#endif
	if(pl==NULL||url==NULL){
		return;
	}
	struct Page *page = calloc(1, sizeof(struct Page));
	page = loadPage(url);
	putPage(pl,page);
	#if Debug
	//printLinksOfPage(page);
	#endif
	struct Link *f ;
	for(f = pl->nodes->page->links; f != NULL;f = f->next) {
		int a = strStartsWith(f->url,"https");
		int b =	strStartsWith(f->url,"ftp:");
		int c = strStartsWith(f->url,"..");
		int d =	strStartsWith(f->url,"http");
		int e =	strStartsWith(f->url,"Special:");
		int g =	strStartsWith(f->url,"W._W._Norton_&amp;_Company");
		int h = strStartsWith(f->url,"AT&amp;T_Bell_Labs");
		// habe Special: hinzugenommen da dieses bei der url erstellung nicht gefilter wird
		if((a&&b&&c&&d&&e&&g&&h)){
		#if Debug
			printf("The linklist url is: %s\n",f->url);
			printf("%d,%d,%d,%d\n",a,b,c,d);
		#endif
			page = loadPage(f->url);
			putPage(pl,page);
		}
	}
//idea is that we can check at this point how many pages are in our list and that amount  
//	struct Link *link = calloc(1,sizeof(struct Link));
//	link = pl->nodes->page->links->next;
//	loadPages(pl,link->url);
	
}
	



void printPagesContainingTerm(struct PageList *pl, char *term)
{
	if(pl==NULL||term==NULL){
		return;
	}
	int a=0;
	struct PageListNode *tmp = calloc(1,sizeof(struct PageListNode));
	for(tmp = pl->nodes; tmp!=NULL ; tmp=tmp->next){
		a = frequencyOfTermOnPage(tmp->page,term);
		if(a!=0){
			printf("this page contains the term %s : %s\n", term,tmp->page->url);
		}
	}
	if(a!=0){
		return;
	}
	printf("There is no page containing the term %s",term);
	return;
}

int mainA1(void)
{

//    setBasePath("/Users/Anzumana/Dropbox/uni/Programmieren_I/blaetter/blatt6/searchengineproject/en.m.wikipedia.org/wiki/");

	//struct PageList *pl = createPageList();
	//struct Page *page = calloc(1, sizeof(struct Page));
	//loadPages(pl,"C_(programming_language)");
	//loadPages(pl,"a.txt");
	//int a;
	//printf("%d\n\n\n",a);
	//printf("%s",page->url);
/*
	page = loadPage("C_data_types");
	a = putPage(pl,page);
	printf("%d\n\n\n",a);
	printf("%s\n",page->url);
	struct PageListNode *tmp = calloc(1,sizeof(struct PageListNode));
	printf("The following pages are in our Pagelist currentyl\n");
	for(tmp = pl->nodes; tmp!=NULL ; tmp=tmp->next){
		printf("%s\n",tmp->page->url);
	}
	printf("\n\n");
	page = getPage(pl,"C_(programming_language)");
	printf("%s\n",page->url);
	
	
	int c =strStartsWith("httphello","http");
	c =strStartsWith("slkdfjhello","http");
	printPagesContainingTerm(pl,"byte");
	printf("THe number of pages is %d\n",numberOfPages(pl));

	
	loadPages(pl, "C_(programming_language)");

	int i = numberOfPages(pl);
	printf("numberOfPages = %d\n", i);

	char *t = "geek";
	printf("\nthese pages contain the term %s:\n", t);
	printPagesContainingTerm(pl, t);

	char *s = "leibniz";
	printf("\nthese pages contain the term %s:\n", s);
	printPagesContainingTerm(pl, s);
*/

	return 0;
}
