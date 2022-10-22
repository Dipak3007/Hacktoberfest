#include <stdio.h>
#include <stdlib.h>

int parent[100], i, rank[100], r, s;

int makeset(int x)
{
    parent[x] = x;
    rank[x] = 0;
    return x;
}
int findset(int x)
{
    while (x != parent[x])
    {
        x = parent[x];
    }
    return x;
}
int munion(int x, int y)
{
    r = findset(x);
    s = findset(y);
    if (r == s)
    {
        return r;
    }
    else
    {
            if (rank[r] > rank[s])
              {
                parent[s] = r;
                rank[r]=rank[r]+rank[s];
               return r;
              }
              else
                  {
                    parent[r]=s;
                    rank[s]=rank[r]+rank[s];
                    return s;
                  }
        
    
    }
}

int main()
{
    int i, j, t, n, flag, count=0;
    printf("How many disjoint set you want to create?   ");
    scanf("%d", &n);
    makeset(n);
    printf("%d number of makeset operations are executed \n ", n);
    printf("To stop Union operation, press - 1   \n");
    while (t != -1)
    {
        printf("Enter the value of t");
        scanf("%d", &t);
        if (t != -1)
        {
            printf("Enter i and j to perform Union(i, j) operation\n");
            printf("I = ");
            scanf("%d", &i);
            printf("J = ");
            scanf("%d", &j);
            munion(i, j);
            printf("UNION(%d, %d) is finished", i, j);
        }
    }
    printf("Do you want to find the connected components");
    printf("Press '1' for YES or, '0' for NO");
    scanf("%d", &flag);
    if (flag == 1)
    {
       for (i = 1; i <= n; i++)
        {
            if (findset(i) == i)
                count = count + 1;
        }
        
        printf("The number of connected component is %d", count);
    }
    else
    {
        printf("We do not want to find the connected components");
    }
    return 0;
}
