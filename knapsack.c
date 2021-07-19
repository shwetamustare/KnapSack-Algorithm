#include <stdio.h>
#include <stdlib.h>
 
int w[10], p[10], v[10][10], n, i, j, capacity, x[10] = {0};
 
int max(int i, int j) {
    return ((i > j) ? i : j);
}
 
int KnapSack(int i, int j) {
    int value;
    if (v[i][j] < 0) {
        if (j < w[i])
            value = KnapSack(i - 1, j);
        else
            value = max(KnapSack(i - 1, j), p[i] + KnapSack(i - 1, j - w[i]));
        v[i][j] = value;
    }
    return (v[i][j]);
}
 
int main(int argc, char** argv) {
    int profit, count = 0;
    printf("\nEnter the number of elements : ");
    scanf("%d", &n);
    printf("\nEnter the profit and weights of the elements\n");
    for (i = 1; i <= n; i++) {
        printf("Item no : %d\n", i);
        scanf("%d %d", &p[i], &w[i]);
    }
    printf("\nEnter the capacity \n");
    scanf("%d", &capacity);
    for (i = 0; i <= n; i++)
        for (j = 0; j <= capacity; j++)
            if ((i == 0) || (j == 0))
                v[i][j] = 0;
            else
                v[i][j] = -1;
    profit = KnapSack(n, capacity);
    i = n;
    j = capacity;
    while (j != 0 && i != 0) {
        if (v[i][j] != v[i - 1][j]) {
            x[i] = 1;
            j = j - w[i];
            i--;
        } else
            i--;
    }
    printf("Items in the KnapSack are : \n\n");
    printf("Sl.no \t weight \t profit\n");
    printf("\n----------------------------------------\n");
    for (i = 1; i <= n; i++)
        if (x[i])
            printf("%d \t %d \t\t  %d\n", ++count, w[i], p[i]);
    printf("Total profit = %d\n", profit);
    return (EXIT_SUCCESS);
}
 
 
/*
 
Output:-
 
Enter the number of elements : 3
 
Enter the profit and weights of the elements
Item no : 1
4 6
Item no : 2
1 2
Item no : 3
7 3
 
Enter the capacity
7
Items in the KnapSack are :
 
Sl.no    weight          profit
 
----------------------------------------
1        2                1
2        3                7
Total profit = 8
 
 

    */
