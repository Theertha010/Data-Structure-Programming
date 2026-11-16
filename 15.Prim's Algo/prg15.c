#include <stdio.h> 
#define MAX 10
int main() { int vertex_array[MAX], counter; int vertex_count = 0; int row, column; int cost_matrix[MAX][MAX]; int visited[MAX] = {0}; int edge_count = 0, count = 1; int sum_cost = 0, min_cost; int vertex1, vertex2;

printf("Total no of vertex: ");
scanf("%d", &vertex_count);

if (vertex_count < 1 || vertex_count >= MAX)
{
    printf("Invalid number of vertices!");
    return 0;
}

printf("\n-- Enter vertex --\n\n");

for (counter = 1; counter <= vertex_count; counter++)
{
    printf("vertex[%d]: ", counter);
    scanf("%d", &vertex_array[counter]);
}

printf("\n--- Enter Cost matrix of size %d x %d ---\n\n",
       vertex_count, vertex_count);

for (row = 1; row <= vertex_count; row++)
{
    for (column = 1; column <= vertex_count; column++)
    {
        scanf("%d", &cost_matrix[row][column]);

        if (cost_matrix[row][column] == 0)
            cost_matrix[row][column] = 999;
    }
}

visited[1] = 1;
edge_count = vertex_count - 1;

while (count <= edge_count)
{
    min_cost = 999;
    vertex1 = -1;
    vertex2 = -1;

    for (row = 1; row <= vertex_count; row++)
    {
        for (column = 1; column <= vertex_count; column++)
        {
            if (visited[row] != 0 &&
                visited[column] == 0 &&
                cost_matrix[row][column] < min_cost)
            {
                min_cost = cost_matrix[row][column];
                vertex1 = row;
                vertex2 = column;
            }
        }
    }

    if (vertex1 == -1)
    {
        printf("\nGraph is disconnected!");
        return 0;
    }

    printf("\nEdge %d is (%d -> %d) with cost: %d",
           count++, vertex_array[vertex1],
           vertex_array[vertex2], min_cost);

    sum_cost += min_cost;
    visited[vertex2] = 1;

    cost_matrix[vertex1][vertex2] = 999;
    cost_matrix[vertex2][vertex1] = 999;
}

printf("\n\nMinimum cost = %d", sum_cost);

return 0;


}
