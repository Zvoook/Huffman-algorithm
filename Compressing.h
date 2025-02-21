#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#define BYTE 8
#define SIZE 256
typedef struct NODE {
	unsigned char symb;
	int isSymb;
	unsigned int freq;
	unsigned char code[SIZE];
	int level;
	struct NODE* left, * right, * next;
}NODE;
typedef struct LIST {
	struct NODE* head;
	struct NODE* tail;
	int size;
}LIST;

int File_Size(FILE* name);
NODE* create_node(int id, int val);
LIST* init_list();
void add_node(LIST* list, int id, int val);
void print_list(LIST* list);
void fill_list(LIST* list, int* arr);
NODE* Add2LIST(NODE* head, NODE* node);
NODE* MakeNodeFromNode(NODE* left, NODE* right);
NODE* MakeTreeFromList(NODE* head);
void coding(NODE* node, int len, char* code, char* codes[]);
void compressing(const char* input, const char* output, char* codes[]);
void decompressing(const char* input, const char* output, int lenght, NODE* node, char* codes[]);
