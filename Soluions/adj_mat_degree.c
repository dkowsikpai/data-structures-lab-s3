#include <stdio.h>

int main(){
    int n, u, v, m;
    int indegree=0, outdegree = 0;
    printf("Enter the number of vertex in graph: ");
    scanf("%d", &n);
    n++;
    int A[n][n];
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            A[i][j] = 0;
        }
    }

    for (int j=1; j < n; j++){
            A[0][j] = j;
    }
    for (int j=1; j < n; j++){
            A[j][0] = j;
    }
    // printf("Enter 0 0 to exit");
    printf("\nEnter the vertices: \n");
    for (int i=0; i<n - 1; i++){
        printf("Enter the vertices %d :", i+1);
        scanf("%d %d", &u, &v);
        A[u][v] = 1;
        // printf("%d-%d -- %d", u, v, A[u][v]);

    }
    // printf(" ");
    // for (int i=0; i<n; i++)
    //     printf("%d ", i+1);
    // printf("\n");
    printf("\nAdjacency Matrix\n");
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    
    for (int i=1; i<n; i++){
        outdegree = 0;
        for (int j=1; j<n; j++){
            if(A[i][j] == 1)
                outdegree++;
        }
        printf("Outdegree of %d is %d\n", i, outdegree);
    }
    for (int i=1; i<n; i++){
        indegree = 0;
        for (int j=1; j<n; j++){
            if(A[j][i] == 1)
                indegree++;
        }
        printf("Indegree of %d is %d\n", i, indegree);
    }

}