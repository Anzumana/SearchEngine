// †B 08 Aufgabe 1 d)
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

// †B 08 Aufgabe 1 d)
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

// †B 08 Aufgabe 1 d)
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
