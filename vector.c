#include "vector.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void vector_create(vector *v)
{
	v->size = 0;
	v->vals = NULL;
}

void vector_destroy(vector *v)
{
	free(v->vals);
	v->vals = 0;
	v->size = 0;
}

void vector_push_back(vector *v,elem e)
{
	v->size++;
	v->vals = realloc(v->vals, sizeof(elem) * v->size);
	v->vals[v->size-1] = e;
}

void vector_print(vector *v)
{
	printf("------------------------------------------------------\n");
	printf("|              key|                             value|\n");
	printf("------------------------------------------------------\n");
	for(int i=0;i<v->size;i++)
		printf("|%16d%c|%34s|\n",v->vals[i].keypart1,v->vals[i].keypart2,v->vals[i].strval);
	printf("------------------------------------------------------\n");
	printf("| Total elements: %34d |\n",v->size);
	printf("------------------------------------------------------\n");
}

int elem_bigger(elem a,elem b)
{
	return a.keypart1>b.keypart1 || (a.keypart1==b.keypart1 && a.keypart2>b.keypart2);
}

void vector_swap(vector *v, int a, int b)
{
	elem t = v->vals[a];
	v->vals[a] = v->vals[b];
	v->vals[b] = t;
}

void shaker_sort(vector* v)
{
	int left = 0;
	int right = v->size - 1;
	int flag = 1;
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i<right; i++)
		{
			if (elem_bigger(v->vals[i],v->vals[i + 1]))
			{
				vector_swap(v, i, i + 1);
				flag = 1;
			}
		}
		right--;
		for (int i = right; i>left; i--)
		{
			if (elem_bigger(v->vals[i - 1],v->vals[i]))
			{
				vector_swap(v, i, i - 1);
				flag = 1;
			}
		}
		left++;
	}
}

int binary_search(vector *v, elem e)
{
	int left = 0;
	int right = v->size;
	while(left < right)
	{
		int mid = (left + right) / 2;
		if(elem_bigger(v->vals[mid],e))
			right = mid;
		else if(elem_bigger(e,v->vals[mid]))
			left = mid + 1;
		else
			return mid;
	}
	return -1;
}

