#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include "Compressing.h"
using std::cin;
using std::cout;
using std::endl;

int File_Size(FILE* f) {
	fseek(f, 0L, SEEK_END);
	long len = ftell(f);
	fseek(f, 0, SEEK_SET);
	return len;
}

NODE* create_node(int id, int val)
{
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
	LIST* list = (LIST*)calloc(1, sizeof(LIST));
	list->head = NULL;
	list->tail = NULL;
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

void fill_list(LIST* list, int* arr) {
	for (int i = 0; i < SIZE; i++) {
		if (arr[i] > 0) {
			NODE* node = create_node(i, arr[i]);
			list->head = Add2LIST(list->head, node);
			list->size++;
		}
	}
	//cout << "Filling list completed!" << endl;
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
	//cout << "Creating tree completed!" << endl;
	return head;
}

void coding(NODE* node, int len, char* code, char* codes[]) {
	if (!node) return;
	if (node->isSymb==1) {
		code[len]='\0';
		strcpy(codes[node->symb], code);
		return;
	}
	if (node->left) {
		code[len] = '0';
		coding(node->left, len+1, code, codes);
	}
	if (node->right) {
		code[len] = '1';
		coding(node->right, len+1, code, codes);
	}
}
