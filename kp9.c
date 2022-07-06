#include <stdio.h>
#include "vector.h"

int main()
{
	vector v;
	char name_of_keys_file[50];
	char name_of_vals_file[50];
	printf("Input name of file with keys: ");
	scanf(" %s", name_of_keys_file);
	printf("Input name of file with values: ");
	scanf(" %s", name_of_vals_file);
	FILE *fk;
	fk = fopen(name_of_keys_file, "r");
	FILE *fv;
	fv = fopen(name_of_vals_file, "r");
	vector_create(&v);
	elem el;
	while(fscanf(fk,"%d%c\n",&(el.keypart1),&(el.keypart2))==2 && fscanf(fv,"%s\n",el.strval)==1)
		vector_push_back(&v,el);
	printf("\nTable before sorting:\n");
	vector_print(&v);
	printf("\nTable after sorting:\n");
	shaker_sort(&v);
	vector_print(&v);
	int w;
	printf("\nInput number of binary searches: ");
	scanf("%d", &w);
	for(int i = 0; i < w; i++)
	{
		printf("Enter table key: ");
		elem se;
		scanf("%d%c",&(se.keypart1),&(se.keypart2));
		int idx = binary_search(&v,se);
		if(idx == -1)
			printf("element with given key not found\n");
		else
			printf("element found: %s\n",v.vals[idx].strval);
	}
	vector_destroy(&v);
	return 0;
}

