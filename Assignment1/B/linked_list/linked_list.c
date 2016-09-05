#include <stdlib.h>
#include <stdio.h>
#include "linked_list.h"

list_t list_create()
{
	list_t newlist = (list_t) malloc(sizeof(struct list));
	newlist->head = NULL;
	newlist->tail = NULL;
	newlist->length = 0;
	return newlist;	
}

void list_delete(list_t list)
{
	if(list != NULL){
			node_t temp = list->head;
			node_t next;
			for(int i = 0; i < list->length; i++){
				next = temp->next;
				free(temp);
				temp = next;
			}
			free(list);
		}
}

void list_insert(list_t list, int index, int data)
{
	node_t new_node = (node_t)malloc(sizeof(struct node));
	new_node->data = data;

	node_t temp = list->head;	
	for(int i = 0; i < index - 1; i++){
		temp = temp->next;
	}

	temp->next->prev = new_node;
	new_node->next = temp->next;

	temp->next = new_node;
	new_node->prev = temp;

	list->length++;
}

void list_append(list_t list, int data)
{
	node_t new_node = (node_t)malloc(sizeof(struct node));
	new_node->data = data;

	if(list->length == 0){
		list->head = list->tail = new_node;
		new_node->next = new_node->prev = NULL;
		list->length++;
	}
	else{

		list->tail->next = new_node;
		new_node->prev = list->tail;
		list->tail = new_node;
		list->length++;
	}
}

void list_print(list_t list)
{
	node_t current_node = list->head;
	printf("[");
	for(int i = 0; i < list->length; i++){
		printf("%i", current_node->data);
		current_node = current_node->next;

		if(current_node != NULL){
			printf(", ");
		}
	}
	printf("]\n");
}

long list_sum(list_t list)
{
	node_t current_node = list->head;
	long sum = 0;

	for(int i = 0; i < list->length; i++){
		sum += current_node->data;
		current_node = current_node->next;
	}
	return sum;
}

int list_get(list_t list, int index)
{
	node_t current_node = list->head;
	for(int i = 0; i < index; i++){
		current_node = current_node->next;
	}
	return current_node->data;
}

int list_extract(list_t list, int index)
{
	int data;
	node_t current_node = list->head;


	if(list->length == 0){
		return -1;
	}
	else if(list->length == 1){
		data = current_node->data;
		list->tail = list->head = NULL;
	}
	else if(index == 0){
		data = list->head->data;
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	else if(index >= list->length){
		data = list->tail->data;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
	else{
		for(int i = 0; i < index; i++){
			current_node = current_node->next;
		}
		data = current_node->data;
		current_node->prev->next = current_node->next;
		current_node->next->prev = current_node->prev;
	}

	free(current_node);
	list->length--;
	return data;
}
