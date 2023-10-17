#include <stdio.h>

void tower_function(int n, char beg, char aux, char end)
{
    if (n <= 0)
        printf("\n invalid entry");

    else if (n == 1)
        printf("\n Move disk 1 from %c to %c", beg, end);
    else
    {
        tower_function(n - 1, beg, end, aux);
        printf("\n Move disk %d from %c to %c", n, beg, end);
        tower_function(n - 1, aux, beg, end);
    }
}

int main()
{
    int n;
    char a, b, c;

    printf("Enter the number of discs: ");
    scanf("%d", &n);
    printf("Tower of Hanoi for %d discs:\n", n);
    tower_function(n, 'A', 'B', 'C');

    return 0;
}
