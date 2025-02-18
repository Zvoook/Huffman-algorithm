#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "Compressing.h"
using std::cin;
using std::cout;
using std::endl;
#define Huffman
#ifdef Huffman
int main() {
	//Frequency counting
	FILE* file = fopen("Video.mov", "rb");
	if (!file) {
        cout << "Can't open source file!" << endl;
        return -1;
    	}
	long lenght = File_Size(file);
	int* amount = (int*)calloc(SIZE, sizeof(int));
	for (int i = 0; i < lenght; ++i) amount[(unsigned char)fgetc(file)]++;
	fclose(file);

	//Creating List
	LIST* list = init_list();
	fill_list(list, amount);

	//Creating Tree from List
	NODE* root=MakeTreeFromList(list->head);

	//Simbols' codes writing
	char* code = (char*)calloc(SIZE, sizeof(char));
	char** codes = (char**)calloc(SIZE, sizeof(char*));
	for (int i = 0; i < SIZE; ++i) codes[i] = (char*)calloc(SIZE, sizeof(char));
	coding(root, 0, code, codes);
	for (int i = 0; i < SIZE; i++) {
		if (amount[i] > 0)
			printf("'%c' : %s\n", i, codes[i]);
	}
	//Compressing and decompressing
  	compressing("Video.mov", "Compress Video.bin", codes);
  	decompressing("Compress Video.bin", "Decomp Video.mov", lenght, root, codes);
    	for (int i = 0; i < SIZE; i++) free(codes[i]);
    	free(codes);
 	free(code);
	}
#endif
