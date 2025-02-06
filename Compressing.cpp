#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "Compressing.h"
using std::cin;
using std::cout;
using std::endl;

NODE* create_node(int id, int val)
{
	/*NODE* node;
	node = new NODE;*/
	NODE* node = (NODE*)calloc(1, sizeof(NODE));
	node->symb = (unsigned char)id;
	node->isSymb = 1;
	node->freq = val;
	node->next = NULL;
	node->left = NULL;
	node->right = NULL;
	return node;
}
LIST* init_list()
{
	/*LIST* list;
	list = new LIST;*/
	LIST* list = (LIST*)calloc(1, sizeof(LIST));
	list->head = NULL;
	list->tail = NULL;
	//list->head->next = list->tail;
	list->size = 0;
	return list;
}
NODE* Add2LIST(NODE* head, NODE* node) {
	if (!head) return node;
	if (node->freq < head->freq) {
		node->next = head;
		return node;
	}
	NODE* current = head;
	while (current->next && current->next->freq <= node->freq) current = current->next;
	node->next = current->next;
	current->next = node;
	return head;
}

//void add_node(LIST* list, int id, int val)
//{
//	NODE* node = create_node(id, val);
//	node->next = list->head->next;
//	/*if (list->size == 0) list->head = node;
//	if (list->size == 1) list->tail = node;*/
//	list->head->next = node;
//	list->size++;

void megaswap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
void fill_list(LIST* list, int* arr) {
	/*int max = arr[0], id = 0, size = code_size;
	for (int a = 0; a < code_size; ++a) {
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
	}*/
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > 0) {
			NODE* node = create_node(i, arr[i]);
			list->head = Add2LIST(list->head, node);
			list->size++;
		}
	}
	printf("Filling list completed!\n");
}
void print_list(LIST* list)
{
	NODE* node = list->head;
	while (node) {
		if (node->freq != 0) cout << node->symb << " - " << node->freq << endl;
		node = node->next;
	}
}

NODE* MakeNodeFromNode(NODE* left, NODE* right)
{
	NODE* node;
	node = new NODE;
	node->freq = left->freq + right->freq;
	node->isSymb = 0;
	node->symb = 0;
	node->left = left;
	node->right = right;
	node->next = NULL;
	return node;
}
NODE* MakeTreeFromList(NODE* head)
{
	while (head && head->next) {
		NODE* left = head;
		NODE* right = head->next;
		head = right->next;
		left->next = NULL;
		right->next = NULL;
		NODE* node = MakeNodeFromNode(left, right);
		head = Add2LIST(head, node);
	}
	printf("Creating tree completed!\n");
	return head;
}