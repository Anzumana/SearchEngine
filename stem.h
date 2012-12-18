// http://tartarus.org/~martin/PorterStemmer/c.txt

#ifndef STEM_H_
#define STEM_H_

int stemTerm(char term[]);

/* In stem(p,i,j), p is a char pointer, and the string to be stemmed is from
   p[i] to p[j] inclusive. Typically i is zero and j is the offset to the last
   character of a string, (p[j+1] == '\0'). The stemmer adjusts the
   characters p[i] ... p[j] and returns the new end-point of the string, k.
   Stemming never increases word length, so i <= k <= j. To turn the stemmer
   into a module, declare 'stem' as extern, and delete the remainder of this
   file.
*/
int stem(char * p, int i, int j);

#endif /* STEM_H_ */
