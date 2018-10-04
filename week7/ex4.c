#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int min(int a, int b)
{
    if (a < b)
        return a;
    else
        return b;
}

void *new_realloc(void *ptr, size_t size2, size_t size1) //size_t in bytes
{

    void *ptr2;
    
    if(ptr == NULL){
		ptr2 = malloc(size2);
	}
	else if(size2 == 0){
		free(ptr);
		return;
	}
	else{
        int minsize;
        minsize = min(size1, size2);

        ptr2 = malloc(size2);
        ptr2 = memcpy(ptr2, ptr, minsize);
        free(ptr);
    }

    return ptr2;

}

int main(){


	printf("Введите размер массива: ");
	int size1;
	
	scanf("%d", &size1);

	int* arr = malloc(size1 * sizeof(int));

	for(int i = 0; i < size1; i++){
		arr[i] = i;
		printf("%d ", arr[i]);
	}

	printf("Введите новый размер массива: ");
	int size2;
	scanf("%d", &size2);

	arr = new_realloc(arr, size2 * sizeof(int), size1 * sizeof(int));

	if(size2 > size1){
		for(int i = size1; i < size2; i++){
			arr[i] = i;
		}	
	}

	for(int i = 0; i < size2; i++){
		printf("%d ", arr[i]);
	}
	
	free(arr);

	return 0;
}