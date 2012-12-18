// gcc -Wall -o page page.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "page.h"
#include "stem.h"

/*
 * To Do Aufgabe 1 c)
Header Datein sind dafuer da damit wir unsere Source Code Dateien auf denen wir arbeiten klein halten. Man koennte theoretisch auch das ganze programm mit saemtlichen funktionen
und co in eine einzige Datei schreiben dies wuerde das bearbeiten jedoch sehr kompliziert machen da man in der datei nicht wirklich den ueberblick behalten kann. 
um dies zu vermeiden sollte man immer versuchen die einzelnen funktionen unseres Programms die sehr aehnlich sind bzw. die zusammengehoeren in eine externe datei auslagern und diese dann ueber ein include anweisung eingbinden. wenn man spaeter dann an eine bestimmten funktion arbeitet sind alle funktionen die mit dieser zu tun haben in der datei mit drin und nicht vieles was wir fuer die arbeiten in dem moment nicht brauchen.
 *
 */
char buffer[BUFFER_SIZE+1];
char path[PATH_SIZE+1];

const char BASE_PATH[] = "/Users/Anzumana/Dropbox/uni/Programmieren_I/blaetter/blatt6/searchengineproject/minicorpus/";
//const char BASE_PATH[] = "/Users/Anzumana/Dropbox/uni/Programmieren_I/blaetter/blatt6/searchengineproject/en.m.wikipedia.org/wiki/";


#define TYPE_TERM 1
#define TYPE_LINK 2
#define TYPE_EOF 3


static void insertTermInPage(struct Page *page, const char *term)
// the const makes sure that we are not able to chang the string that we give our function only the pointer
{
if(page == NULL|term== NULL){
	return;
}
	char *tmp = strdup(term);
	struct Term *f ;
	
// this for loops makes sure that if we have the term already in our page the term frequency gets increased by 1 and terminated the function
	for(f = page->terms; f != NULL;f = f->next) {
	   if(!strcmp(f->term,tmp)){
			f->frequency++;
		   return;
	   }
	}
	
// this only gets executed if the term is not already in our page so we add a new item to the terms list
	struct Term *e = calloc(1,sizeof(struct Term));
	e->term = tmp;
	e->frequency = 1;
//	printf("A new Term struct with value:%12s created.\n",e->term);
	e->next = page->terms;
	page->terms = e;
		//printf("%s\n",(page->terms)->term);

}


void printTermsOfPage(struct Page *page)
{
	if(page == NULL) return;
	struct Term *e ;
		//printf("%s\n",(page->terms)->term);
	for(e = page->terms; e != NULL;e = e->next) {
		printf("The Term:%12s has a frequency of %d\n",e->term, e->frequency);
	}

}

static void insertLinkInPage(struct Page *page, const char *url)
{
	int a = strlen(url);
	if(a==0){
		return;
	}
	//printf("%u\n",(unsigned)strlen(url));
	
	if(page == NULL || url == NULL){
		printf("never the case");
		return;
	}
	// To Do Aufgabe 1 f)
	char *tmp = strdup(url);
	//printf("LINK STRUCT WITH value:%16s created.\n",tmp);
	struct Link *f ;
// this for loops makes sure that if we have the term already in our page the term frequency gets increased by 1 and terminated the function
	for(f = page->links; f != NULL;f = f->next) {
	   if(!strcmp(f->url,tmp)){
		   return;
	   }
	}
	
// this only gets executed if the term is not already in our page so we add a new item to the terms list
	struct Link *e = calloc(1,sizeof(struct Term));
	e->url = tmp;
	printf("A new Link struct with value:%16s created.\n",e->url);
	e->next = page->links;
	page->links= e;
		//printf("%s\n",(page->terms)->term);



}


void printLinksOfPage(struct Page *page)
{
	if(page == NULL) return;
	struct Link *e ;
		//printf("%s\n",(page->terms)->term);
	for(e = page->links; e != NULL;e = e->next) {
		printf("The url is:%12s  \n",e->url);
	}


}


// assumptions on parameter:
// require: file != NULL, file is open for reading
static void skipGarbage(FILE* file)
{
	int c;
	while ((c = getc(file)) != EOF && !isalnum(c) && c != '<' && c != '>');
	// assert: c is EOF, alnum, '<', or '>'
	ungetc(c, file);
	// assert: next c = getc(file) will return EOF, alnum, '<', or '>'
}

// assumptions on parameters:
// require: file != NULL, file is open for reading
//          number of bytes in token array == tokenArraySize, tokenArraySize > 1
// token is an output parameter
// --> design by contract
static int nextTermOrLink(FILE* file, char token[], unsigned int tokenArraySize)
{
	int i, c, n;
	char *s, *t, *t2;
	tokenArraySize--; // space for '\0' character
	token[0] = '\0';

	skipGarbage(file);
	// assert: next c = getc(file) will return EOF, alnum, '<', or '>'
	c = getc(file);
	if (c == EOF) return TYPE_EOF;
	// assert: c is alnum, '<', or '>'

	while (c == '<') { // start of an HTML element
		c = tolower(getc(file));
		if (c == EOF) return TYPE_EOF;
		if (c == 'a') { // start of an HTML anchor element
			i = 0;
			do { // read rest of HTML anchor element
				token[i++] = c;
			} while ((c = getc(file)) != EOF && c != '>' && i < tokenArraySize);
			if (i >= tokenArraySize) {
				printf("Buffer overflow: i >= tokenArraySize\n");
				exit(1);
			}
			// assert: c == EOF || c == '>' || i >= tokenArraySize
			token[i++] = '\0';

			// find the contents of the href attribute (the URL)
			s = strstr(token, "href=\""); // search for string in string
			if (s != NULL) {
				s += 6; // skip href="
				t = strchr(s, '"'); // find end of URL (closing quote)
				t2 = strchr(s, '#'); // trim local references within URLs
				if (t2 != NULL) {
					if (t == NULL || t2 < t) {
						t = t2;
					}
				}
				if (t != NULL) {
					n = t - s;
					for (i = 0; i < n; i++) {
						token[i] = s[i];
					}
					token[i] = '\0';
					return TYPE_LINK;
				}
			}
			// ignore anchor elements without href attribute
		} else { // not an anchor element, skip rest of HTML element
			while ((c = getc(file)) != EOF && c != '>');
			// assert: c == EOF or c == '>'
			if (c == EOF) return TYPE_EOF;
			// assert: c == '>'
		}
		skipGarbage(file);
		c = getc(file);
		// assert: c is EOF, alnum, '<', or '>'
		if (c == EOF) return TYPE_EOF;
		// assert: c is alnum or '<' or '>'
	}

	// it must be a term (a word)
	// assert: c is alnum or '>' ('>' only if not well-formed HTML)
	if (!isalnum(c)) {
		printf("HTML is not well-formed: c = '%c'\n", c);
		exit(1);
	}
	i = 0;
	do {
		token[i++] = tolower(c);
	} while (isalnum(c = getc(file)) && i < tokenArraySize);
	if (i >= tokenArraySize) {
		printf("Buffer overflow: i >= tokenArraySize\n");
		exit(1);
	}
	// assert: c is not alnum or i >= tokenArraySize
	ungetc(c, file); // consider this character next time
	token[i++] = '\0'; // terminate the string
	return TYPE_TERM;
}


struct Page *loadPage(const char* fileName)
{
	if(fileName == NULL){
		return NULL ;
	}
	//printf("yes this function gets calles\n");
	struct Page *page = calloc(1, sizeof(struct Page));
	char *tmp = strdup(fileName);
	page->url = tmp;
	//printf("%s is url given to function\n",page->url);
	strcpy(path,BASE_PATH);
	strcat(path,tmp);
	printf("%s is our path\n",path);
	FILE * file;
  	file = fopen (path,"r");
	
	// still to impleent fopen returns poiter to open file
	//for ( until return wert ist 3)
	int a = 0;
	while(a!=3){
		a = nextTermOrLink(file, buffer,BUFFER_SIZE );
		if(a==1){
			insertTermInPage(page,buffer);
		}
		else{
			insertLinkInPage(page,buffer );
		}
	}
//	printf("%s\n",buffer);
//	printf("%d\n",a);
   fclose (file);

	return page;
}



void deletePage(struct Page *page)
{
   if (page == NULL) return;
   struct Term *w, *wnext;
   for (w = page->terms; w != NULL; w = wnext) {
	  wnext = w->next;
	  free(w->term);
	  free(w);
   }
   struct Link *r, *rnext;
   for (r = page->links; r != NULL; r = rnext) {
	  rnext = r->next;
	  free(r->url);
	  free(r);
   }
	free(page->url);
	free(page); 
	printf("If we see this statement then the page delete function was executed correctly");


}



// Other helpful functions
int numberOfTermsOnPage(struct Page *page)
{
	if (page == NULL) return 0;
	int i = 0;
	struct Term *t;
	for (t = page->terms; t != NULL; t = t->next) {
		i++;
	}
	return i;
}

int numberOfLinksOnPage(struct Page *page)
{
	if (page == NULL) return 0;
	int i = 0;
	struct Link *l;
	for (l = page->links; l != NULL; l = l->next) {
		i++;
	}
	return i;
}

int frequencyOfTermOnPage(struct Page *page, char *term)
{
	if (page == NULL) return 0;
	struct Term *t;
	for (t = page->terms; t != NULL; t = t->next) {
		if (t->term != NULL && strcmp(t->term, term) == 0) {
			return t->frequency;
		}
	}
	return 0;
}
/*
int main(void)
{

	struct Page *page = calloc(1, sizeof(struct Page));
	// Test für Aufgabe 1 d)
	char *term ="programming";
	insertTermInPage(page, term);
	term ="shell";
	insertTermInPage(page, term);
	term ="c-shell";
	insertTermInPage(page, term);
	insertTermInPage(page, "programming");
	insertTermInPage(page, "programming");
	insertTermInPage(page, "programming");
	insertTermInPage(page, "programming");
	insertTermInPage(page, "c-shell");

	// Test für Aufgabe 1 e)
	printTermsOfPage(page);

	// Test für Aufgabe 1 f)
	char *link = "http://en.wikipedia.org/wiki/Unix";
	insertLinkInPage(page, link);
	link ="http://en.wikipedia.org/wiki/C_shell";
	insertLinkInPage(page, link);
	link ="http://en.wikipedia.org/wiki/Internationalization_and_localization";
	insertLinkInPage(page, link);
	link ="http://en.wikipedia.org/wiki/C_shell";
	insertLinkInPage(page, link);
	insertLinkInPage(page, link);
	insertLinkInPage(page, link);
	insertLinkInPage(page, link);
	// Test für Aufgabe 1 g)
	printLinksOfPage(page);
	page=NULL;

	// Test für Aufgabe 1 h)
#if 1
	 page = loadPage("C_(programming_language)");

#else

	page = loadPage("a.txt");
#endif
	if (page == NULL) {
		printf("could not load page\n");
		return 1;
	}
	printTermsOfPage(page);
	printLinksOfPage(page);


	// Weitere Funktionen
	printf("%d terms on page %s\n", numberOfTermsOnPage(page), page->url);
	printf("%d links on page %s\n", numberOfLinksOnPage(page), page->url);

	char t1[64] = "programming";
	// stemTerm(t1);
	printf("term %s occurs %d times on page %s\n", t1, frequencyOfTermOnPage(page, t1), page->url);

	char *t2 = "geek";
	printf("term %s occurs %d times on page %s\n", t2, frequencyOfTermOnPage(page, t2), page->url);

	char *t3 = "university";
	printf("term %s occurs %d times on page %s\n", t3, frequencyOfTermOnPage(page, t3), page->url);

	// Test für Aufgabe 1 j)
	deletePage(page);
	page = NULL;
	return 0;
}
*/


