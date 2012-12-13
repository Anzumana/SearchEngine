// Assignment 6

// gcc -Wall -o page page.c

// interface of module page.c

#ifndef PAGE_H
#define PAGE_H

#define BUFFER_SIZE 4095
extern char buffer[BUFFER_SIZE+1];

#define PATH_SIZE 511
extern char path[];
extern const char BASE_PATH[];

/* To Do Aufgabe b)
(i) Beschreibung der Struktur der Daten.
Wir arbeiten mit Listen da man mit diesen den speicher felxibel an die jeweiligen beduerfnisse anpasst und nicht fest vorgegeben ist, koennen wir auf einer seite so viele woerter und 
und verlinkungen speichern wie wir wollen.
Im grunde besteht eine Seite bei uns aus der URL der Seite selbst und dann 2 Listen Koepfen einer von diesen ist der Listenkopf fuer alle zu speichernden verlinkungen und eine
fuer die gespeicherten begriffe. ( termns/ links)
(ii) Die wohl einfachste Moeglichkeit weiter Links und Woerter hinzuzufuegen waere es diese einfach in unsere Liste mit woertern und bzw. links hinzuzufuegen. wenn die Reihenfolge keine Rolle spielt koennen wir so einfach immer jedes neue Wort an den anfang unserer Liste hinzufuegen .
 *
 */

struct Link {
	char *url; // URL of target page
	struct Link *next; // next link of page
};

struct InvertedIndexEntry;

struct Term {
	char *term;
	int frequency; // the number of times the term appears in the document
	struct Term *next; // next term of page
};

struct Page {
	char *url;
	struct Term *terms;
	struct Link *links;
};

// fileName ist der Name der Datei ohne Pfad
// geladen wird die Datei mit dem Namen concat(BASE_PATH, url)
struct Page *loadPage(const char* fileName);
void deletePage(struct Page *page);

void printTermsOfPage(struct Page *page);
void printLinksOfPage(struct Page *page);

int numberOfTermsOnPage(struct Page *page);
int numberOfLinksOnPage(struct Page *page);

int frequencyOfTermOnPage(struct Page *page, char *term);
double meanLengthOfTermsOnPage(struct Page *page);
int maxLengthOfTermsOnPage(struct Page *page);

#endif
