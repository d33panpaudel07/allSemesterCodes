#include <stdio.h>
int main()
{
    int num_processes, num_resources;
    printf("Enter number of processes: ");
    scanf("%d", &num_processes);

    printf("Enter number of resources: ");
    scanf("%d", &num_resources);

    int available[num_resources];
    printf("Enter the available resources:\n");
    for (int i = 0; i < num_resources; i++)
    {
        scanf("%d", &available[i]);
    }

    int max[num_processes][num_resources];
    int allocation[num_processes][num_resources];
    int need[num_processes][num_resources];

    printf("Enter the maximum resources for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i);
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    printf("Enter the allocated resources for each process:\n");
    for (int i = 0; i < num_processes; i++)
    {
        printf("Process %d:\n", i);
        for (int j = 0; j < num_resources; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int work[num_resources];
    for (int i = 0; i < num_resources; i++)
    {
        work[i] = available[i];
    }

    int finish[num_processes];
    for (int i = 0; i < num_processes; i++)
    {
        finish[i] = 0;
    }

    int safe_sequence[num_processes];
    int num_safe = 0;

    while (num_safe < num_processes)
    {
        int found = 0;
        for (int i = 0; i < num_processes; i++)
        {
            if (!finish[i])
            {
                int j;
                for (j = 0; j < num_resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        break;
                    }
                }
                if (j == num_resources)
                {
                    found = 1;
                    for (int k = 0; k < num_resources; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safe_sequence[num_safe++] = i;
                    finish[i] = 1;
                }
            }
        }
        if (!found)
        {
            printf("Unsafe state!\n");
            return 1;
        }
    }

    printf("Safe sequence:");
    for (int i = 0; i < num_processes; i++)
    {
        printf(" %d", safe_sequence[i]);
    }
    printf("\n");
    return 0;
}
