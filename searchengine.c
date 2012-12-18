#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "searchengine.h"


// †B 08 Aufgabe 2 b)
void computeWeights(struct InvertedIndex *idx)
{

}


// †B 08 Aufgabe 2 d)
void computeWeightsForQuery(struct InvertedIndex *idx, struct Page *query)
{

}


// †B 08 Aufgabe 2 e)
struct ResultList *computeScores(struct InvertedIndex *idx, struct Page *query)
{

	return NULL;
}


// †B 08 Aufgabe 2 f)
struct Page *oneResult(struct InvertedIndex *idx){

	return NULL;
}


// †B 08 Aufgabe 2 a)
int main08(int argc, char *argv[])
{

	// †B 08 Aufgabe 2 a)
	#define MINI 0
	#if MINI
		setBasePath(".../searchengineproject/minicorpus/"); // Need to be changed
	#else
		setBasePath(".../searchengineproject/en.m.wikipedia.org/wiki/");

	#endif

	// †B 08 Aufgabe 2  c)

	return 0;
}
