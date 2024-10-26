#include <stdio.h>
#include <stdlib.h>

// FACTORIAL
// Iterative function
int factorial_iterative(int n) {
    // to do: complete
}

// Recursive function
int factorial_recursive(int n) {
    // to do: complete
}

// SUM ARRAY
// Iterative function
int sumArray_iterative(int arr[], int n) {
    // to do: complete
}

// Recursive function
int sumArray_recursive(int arr[], int n) {
    // to do: complete
}

// MERGE TWO LINKED LISTS
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* mergeLists_iterative(Node* head1, Node* head2) {
    // to do: complete
}

Node* mergeLists_recursive(Node* head1, Node* head2) {
    // to do: complete
}

// helper function to free a linked list
void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// TASK SCHEDULER
typedef struct Task {
    int id;
    int priority;
    struct Task* next;
} Task;

typedef struct Schedule {
    Task* head;
} Schedule;

// Helper function to create a new task
Task* createTask(int id, int priority) {
    Task* newTask = (Task*)malloc(sizeof(Task));
    newTask->id = id;
    newTask->priority = priority;
    newTask->next = NULL;
    return newTask;
}

void newTask(Schedule* queue, int task_id, int task_priority) {
    // to do: complete
}

Task* execute(Schedule* queue) {
    // to do: complete
}

void printQueue(Task* task) {
    if (task == NULL) {
        printf("\n");
        return;
    }
    printf("Task %d with Priority %d -> ", task->id, task->priority);
    printQueue(task->next);
    return;
}


int main() {
    ///////////////////////////////////////////////
    printf("Testing Factorial\n");
    int number = 5;
    printf("Iterative: %d! = %d\n", number, factorial_iterative(number));
    printf("Recursive: %d! = %d\n", number, factorial_recursive(number));

    ///////////////////////////////////////////////
    printf("\nTesting Sum Array\n");
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Iterative: sum = %d\n", sumArray_iterative(arr, n));
    printf("Recursive: sum = %d\n", sumArray_recursive(arr, n));

    ///////////////////////////////////////////////
    printf("\nTesting Merge Lists\n");
    Node* head1 = createNode(1);
    head1->next = createNode(3);
    // head1->next->next = createNode(5);

    Node* head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    Node* mergedList_iter = mergeLists_iterative(head1, head2);
    printf("Merged List (Iterative): ");
    for (Node* temp = mergedList_iter; temp; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");

    // Free the merged list
    freeList(mergedList_iter);
    
    // Reset the original lists (for demonstration purposes)
    head1 = createNode(1);
    head1->next = createNode(3);
    // head1->next->next = createNode(5);

    head2 = createNode(2);
    head2->next = createNode(4);
    head2->next->next = createNode(6);

    Node* mergedList_recur = mergeLists_recursive(head1, head2);
    printf("Merged List (Recursive): ");
    for (Node* temp = mergedList_recur; temp; temp = temp->next) {
        printf("%d ", temp->data);
    }
    printf("\n");

    // Free the merged list
    freeList(mergedList_iter);

    ///////////////////////////////////////////
    Schedule queue = {NULL};

    newTask(&queue, 1, 3);
    newTask(&queue, 2, 4);
    newTask(&queue, 3, 2);
    newTask(&queue, 4, 3);
    newTask(&queue, 5, 5);
    newTask(&queue, 6, 2);
    printQueue(queue.head);
    
    Task* executed_task;
    while ((executed_task = execute(&queue)) != NULL) {
        printf("Executed Task: ID = %d, Priority = %d\n", executed_task->id, executed_task->priority);
        free(executed_task);
    }

    return 0;
}

