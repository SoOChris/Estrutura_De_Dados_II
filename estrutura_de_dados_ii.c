#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void swap(int *xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1); 
    int j;
  
    for (j = low; j <= high - 1; j++) 
    { 
       
        if (arr[j] < pivot) 
        { 
            i++;
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
}

//algoritmos de ordenação

void bubbleSort(int arr[], int n)
{
	int i,j;
	for(i = 0; i < n-1; i++){
		for(j=0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				swap(&arr[j], &arr[j+1]);
			}
		}
	}
	
	printf("O algoritmo foi ordenado com o bubble sort!!!\n");
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
  
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    printf("O algoritmo foi ordenado usando Insertion Sort!!!\n");
}

void selectionSort(int arr[], int n)
{
	int i,j,menor;

	for(i = 0; i< n-1; i++)
	{
		menor = i;
		for(j= i+1; j < n; j++)
		{
			if(arr[j] < arr[menor])
			{
				menor = j;
			}
			
			if(	menor != i)
			{
				swap(&arr[menor], &arr[i]);
			}
		}	
	}
	
	printf("O algoritmo foi ordenado usando Selection Sort!!!\n");
}

void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
    
}

void printArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf(" \t%d ", arr[i]);
	}
	printf("\n");
}



//algoritmos de busca

int linearSearch(int arr[], int n,int target)
{
	int i;
	for(i = 0; i < n; i++)
	{
		if(arr[i] == target){
			return i;
		}
	}
	
	printf("O valor: %d nao existe no vetor", target);
	printf("\n");
	return 0;
}

int binarySearch(int arr[], int l, int r, int x)
{
	while(r >= l )
	{
		int mid = l+(r-l)/2;
		if(arr[mid] == x)
		{
			return mid;
		}
		
	
		if(arr[mid]  > x){
			return binarySearch(arr, l, mid-1,x);
		}
		
		return binarySearch(arr, mid+1, r,x);
	}
	
	return -1;
}

int main()
{
	int opt,optS,i;
	int sort = 0;
	
	int arr[100] = {};
	
	for(i = 0; i < 100; i++)
	{
		arr[i] = rand()%500;
	}
	

	
	int n = sizeof(arr)/sizeof(arr[0]);
	
	while(opt != 4)
	{
		printf("Digite 1 para exibir o array\n");
		printf("Digite 2 para ordenar\n");
		printf("Digite 3 para buscar\n");
		printf("Digite 4 para encerrar o programa\n");
		scanf("%d", &opt);
		if(opt == 1){
			printArray(arr, n);
		}
		
		if(opt == 2)
		{
			
			while(opt != 0)
			{
				printf("Digite 0 para voltar\n");
				printf("Digite 1 para ordenar com bubbleSort\n");
				printf("Digite 2 para ordenar com insertionSort\n");
				printf("Digite 3 para ordenar com selectionSort\n");
				printf("Digite 4 para ordenar com quickSort\n");
				
				scanf("%d", &opt);
				if(opt == 1)
				{
					bubbleSort(arr,n);
					sort = 1;
				}
				if(opt == 2)
				{
					insertionSort(arr,n);
					sort = 1;
				}
				
				if(opt == 3)
				{
					selectionSort(arr,n);
					sort = 1;
				}
				if(opt == 4)
				{
					quickSort(arr,0,n-1);
					sort = 1;
					printf("O algoritmo foi ordenado usando Quick Sort!!!\n");
				}
			}
		}
		
		if(opt == 3)
		{
			while(opt != 0)
			{
				
				printf("Digite 0 para voltar\n");
				printf("Digite 1 para buscar com linear Search\n");
				printf("Digite 2 para buscar com Binary Search\n");
				scanf("%d", &opt);
				
				if(opt == 1){
					
					printf("Digite um valor a ser procurado: \n");
					scanf("%d", &optS);
					
					
					int result = linearSearch(arr, n, optS);
					printf("O elemento esta presente no indice: %d\n", result);
				}
				if(opt == 2)
				{
					if(sort == 0)
					{
						printf("Para realizar buscas com o binary sort, o vetor deve estar ordenado.\n");
					}else{
						
					printf("Digite um valor a ser procurado: \n");
					scanf("%d", &optS);
					
					
					int result = binarySearch(arr, 0, n-1, optS);
						(result == -1)
				        ? printf("Elemento nao existe\n")
				        : printf("Indice %d\n", result);
				    }
				}
			}
		}
	}
	
	return 0;
}
