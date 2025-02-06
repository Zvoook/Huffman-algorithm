#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "Compressing.h"
#define Haffman
#ifdef Haffman
using std::cin;
using std::cout;
using std::endl;
int main() {
	FILE* file = fopen("WAR_AND_PEACE.txt", "rb");
	if (!file) return -1;
	long length = filesize(file);
	/*int* amount;
	amount = new int[code_size];
	for (int i = 0; i < code_size; ++i) amount[i]=0;*/
	int* amount = (int*)calloc(SIZE, sizeof(int));
	for (int i = 0; i < length; ++i) amount[(unsigned char)fgetc(file)]++;
	fclose(file);

	LIST* list = init_list();
	fill_list(list, amount);
	//print_list(list);
	/*char** codes;
	char* code;
	codes = new char*[SIZE];
	code = new char[SIZE];*/
	list->head=MakeTreeFromList(list->head);
}
#endif