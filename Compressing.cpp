#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "Compress_commands.h"
using std::cin;
using std::cout;
using std::endl;

NODE* create_node(int id, int val)
{
	NODE* node = (NODE*)calloc(1, sizeof(NODE));
	node->symb = id;
	node->isSymb = 1;
	node->freq = val;
	node->next = node;
	return node;
}
LIST* init_list()
{
	LIST* list = (LIST*)malloc(sizeof(LIST));
	list->head = create_node(0, 0);
	list->tail = create_node(0, 0);
	list->head->next = list->tail;
	list->size = 0;
	return list;
}
void add_node(LIST* list, int id, int val)
{
	NODE* node = create_node(id, val);
	node->next = list->head->next;
	list->head->next = node;
	list->size++;
}
void print_list(LIST* list)
{
	NODE* node = list->head->next;
	while (node != list->tail) {
		if (node->freq != 0) cout << node->symb << ' ' << node->freq << endl;
		node = node->next;
	}
}
void megaswap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void fill_list(LIST* list, int* arr) {
	int max = arr[0], id = 0, size = SIMB;
	for (int a = 0; a < SIMB; ++a) {
		for (int i = 0; i < size; ++i) {
			if (arr[i] > max) {
				max = arr[i];
				id = i;
			}
		}
		add_node(list, id, max);
		megaswap(arr[id], arr[size - 1]);
		--size;
		max = arr[0];
	}
}