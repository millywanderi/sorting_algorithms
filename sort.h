#ifndef SORT_H
#define SORT_H

/* Libraries */
#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;

/* prototypes */
void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swapping(int **array, size_t one, size_t two);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void quick_sort_help(int *array, size_t size, int one, int two);
int qs_partition(int *array, int low, int up, size_t size);
void shell_sort(int *array, size_t size);
size_t find_seq(size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node(listint_t **list, listint_t *one, listint_t *two);
void counting_sort(int *array, size_t size);
void init_zero(int *array, int size);
int find_max_val(int *array, size_t size);
void merge_sort(int *array, size_t size);
void printer(int *array, const char *cont, size_t lb, size_t ub);
void join_print(int *array, size_t lb, size_t ub, size_t mb, int *cpy);
void pars(int *array, size_t lb, size_t ub, int *cpy);
void heap_sort(int *array, size_t size);
void build_down(int *array, size_t sta, size_t size, size_t end);
void heapy(int *array, size_t size);
void elem_swap(int *array, size_t size, int *m, int *n);
void radix_sort(int *array, size_t size);
void zero_init(int *array, int size);
int max_dig(int *array, size_t size);
void count_sort(int *array, size_t size, int loc);
void bitonic_sort(int *array, size_t size);
void quick_sort_hoare(int *array, size_t size);

#endif
