#include<stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void sort(int job[], int cost[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (cost[j] > cost[j + 1])
            {
                swap(&cost[j], &cost[j + 1]);
                swap(&job[j], &job[j + 1]);
            }
        }
    }
}

void print(int job[], int cost[], int size)
{
    int i;
    printf("Job      Cost      \n");
    for (i = 0; i < size; i++)
    {

        printf("%d  %10d ", job[i], cost[i]);
        printf("\n");
    }
}

int Sum(int arr[],int length){
    int sum = 0;

     for (int i = 0; i < length; i++) {     
       sum = sum + arr[i];    
    } 

    return sum; 

}

void print_list(int list[],int size,int n){
    int i;
   
    printf("\n List%d elements are : \n",n);
    for(i=0;i<size;i++){
        printf("%3d",list[i]);
    }
}

int main(int argc, char const *argv[])
{
    int n, i, j = 0, k;
    int f = 1;             // print listt count 
    printf("Enter the number of index :\n");
    scanf("%d", &n);
    printf("Enter the index job and their cost in order\n");
    int job[10], cost[10];

    //int list1[10] = {0,0,0,0,0,0,0,0,0,0};  //process 1
    //int list2[10] = {0,0,0,0,0,0,0,0,0,0};  // process 2

    int list1[n],list2[n];

    for (i = 0; i < 10; i++)
    {
        list1[i] = 0;
    }

    for (i = 0; i < 10; i++)
    {
        list2[i] = 0;
    }

    for (i = 0; i < n; i++)
    {
        printf("job No: ");
        scanf("%d",&job[i]);
        printf("Cost: ");
        scanf("%d",&cost[i]);        
    }

    printf("Table before sortig\n");
    print(job,cost,n);


    sort(job, cost,n);

    printf("Table after sortig\n");
    print(job,cost,n);

    int l1 = 0;  // for list1
    int l2 = 0;  // for list2
    int z = 0;  // for job array

    printf("List one before iterartion");
    print_list(list1,n,f);
    while(l1<n && l2<n){
            if(list1[l1] == 0 && list2[l2] == 0){
                list1[l1] = job[z];
                z++;
                l1++;
                list2[l2] = job[z];
                z++;
                l2++;
            }

            else{
                if (Sum(list1,n) < Sum(list2,n)){
                    list1[l1] = job[z];
                    l1++;
                    z++;
                }
                else{
                     list2[l2] = job[z];
                     l2++;
                     z++; 
                }
        
            }
        }
    //int L1 = sizeof(list1)/sizeof(list1[0]);
    print_list(list1,n,f);
    f++;
    //int L2 = sizeof(list1)/sizeof(list1[0]);
    print_list(list2,n,f);
    printf("\nHello");
    return 0;
}
