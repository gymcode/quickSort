#include<iostream>
#include<cstdlib>

using namespace std;

int quick_Sort(int a[], int low, int high);

int main()
{
	int a, i;
	cout<<"\nEnter the number of element : "<< endl;
	cin>>a;

	int arr[a];
	for(i = 0; i < a; i++)
	{
		cout<<"Element "<<i+1<<": ";
		cin>>arr[i];
	}

	quick_Sort(arr, 0, a-1);

	cout<<"Sorted Data using the Quick Sort method "<<endl;
	for (i = 0; i < a; i++)
        	cout<<arr[i]<< " ";
	return 0;
}


void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

// Partitioning of the array
int Part(int arr[], int low, int high)
{
	int piv, index, i;
	index = low;
	piv = high;

	// Getting index of pivot.
	for(i=low; i < high; i++)
	{
		if(arr[i] < arr[piv])
		{
			swap(&arr[i], &arr[index]);
			index++;
		}
	}
	swap(&arr[piv], &arr[index]);

	return index;
}

int Rand_Part_piv(int a[], int low, int high)
{
	int pt, n, temp;
	n = rand();
	pt = low + n%(high-low+1);

	swap(&a[high], &a[pt]);

	return Part(a, low, high);
}

// Quick sort function
int quick_Sort(int a[], int low, int high)
{
	int piv_index;
	if(low < high)
	{
		piv_index = Rand_Part_piv(a, low, high);
		// implementing quick sort using Quick Sort
		quick_Sort(a, low, piv_index-1);
		quick_Sort(a, piv_index+1, high);
	}
	return 0;
}
