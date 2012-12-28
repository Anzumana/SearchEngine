#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>
#include "searchengine.h"
#define Debug 1


// †B 08 Aufgabe 2 b)
void computeWeights(struct InvertedIndex *idx)
{
//(1+log_10 tf(t,d)) * log_10 (N/ df(t)) = tf.idf(t,d)
/* df = documentFrequency

*/
	#if Debug
	printf("N numberOfPages :%d\n",numberOfPages(idx->pageList));
	int N = numberOfPages(idx->pageList);
	printf("test printf for fucntion compute Weigts\n");
	struct InvertedIndexHead *h;
	struct InvertedIndexEntry *e;
	for (h = idx->head; h != NULL; h = h->next) {
		//printf("term = %s\n", h->term);
		//printf("df= %d\n",h->documentFrequency);
		int df = h->documentFrequency;
		for (e = h->entries; e != NULL; e = e->next) {
			//printf("term frequency (tf)= %d\n",e->term->frequency);
			int tf = e->term->frequency;
			printf("Values for calculation\n");
			printf("=======================\nn");	
			printf("term = %s\n", h->term);
			printf("page = %s\n", e->page->url);
			printf("df=%d, tf =%d, N=%d\n",df,tf,N);
			printf("tfidf:%f\n",e->term->tfidf);
			e->term->tfidf = (1 + log10(tf)) * log10(((double)N/(double)df));
			printf("====================\n");	

		}
	}
	#endif

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
int main(int argc, char *argv[])
{
	// †B 08 Aufgabe 2 a)
	struct InvertedIndex *InvIndex= loadInvertedIndex("Indexsaved");
	int z = numberOfTermsInIndex(InvIndex);
	printf("Number of Terms in our Index are: %d\n",z);
	int y = numberOfTermsOccurencesInIndex(InvIndex);
	printf("Number of Terms Total in our Index are: %d\n",y);
	computeWeights(InvIndex);
	// †B 08 Aufgabe 2  c)

	return 0;
}
