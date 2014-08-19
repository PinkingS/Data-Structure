int** my2DAlloc(int row, int col) {
	int** rowptr;
	rowptr = (int**)malloc(row * sizeof(int*));
	for(int i = 0; i < row; ++i)
		rowptr[i] = (int*)malloc(col * sizeof(int));
	return rowptr;
}

void my2DDelloc(int** rowptr, int row) {
	for(int i = 0; i < row; ++i)
		free(rowptr[i]);
	free(rowptr);
}

int** my2DAlloc_2(int row, int col) {
	int header = row * sizeof(int*);
	int data = row * col * sizeof(int);
	int** rowptr = (int**)malloc(header + data);
	if(rowptr == NULL)
		return NULL;

	int* buf = (int*)(rowptr+row);
	for(int i = 0; i < row; ++i) {
		rowptr[i] = buf + i + col;
	}
	return rowptr;
}
