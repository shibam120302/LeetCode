//{ Driver Code Starts
// Initial Template for C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10005

////////////////////   Queue data structure   ////////////////////

struct Queue {
    int front, rear, size;
    int capacity;
    int* array;
};

struct Queue* createQueue(int capacity) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;

    queue->rear = capacity - 1;
    queue->array = (int*)malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    return queue->array[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue)) return -1;
    return queue->array[queue->rear];
}

///////////////       Graph data structure       ////////////////////

struct ListNode {
    int data;
    struct ListNode* next;
};

struct graph {
    struct ListNode* head[N];
    // number of components connected with zero
    int connected_with_zero;
};

struct edges {
    int src, dest;
};

void show_graph(struct graph* g, int n, int m) {
    for (int i = 0; i < n; i++) {
        struct ListNode* graph_ptr = g->head[i];
        if (graph_ptr != NULL) {
            printf("%d-->", i);
        }
        while (graph_ptr != NULL) {
            printf("%d ", graph_ptr->data);
            graph_ptr = graph_ptr->next;
        }
        printf("\n");
    }
}

struct graph* create_graph(struct edges arr_edges[], int n, int m) {
    struct graph* g = (struct graph*)malloc(sizeof(struct graph));

    g->connected_with_zero = 0;

    for (int i = 0; i < n; i++) {
        g->head[i] = NULL;
    }

    for (int i = m - 1; i >= 0; i--) {
        int u = arr_edges[i].src, v = arr_edges[i].dest;

        // edge from u->v
        struct ListNode* newNode =
            (struct ListNode*)malloc(sizeof(struct ListNode));

        newNode->data = v;
        newNode->next = g->head[u];
        g->head[u] = newNode;
    }

    return g;
}


// } Driver Code Ends
// User function Template for C
void bfs_utils(struct graph *g, int n, int m, int ans[]) {
    struct Queue *q = createQueue(n);

    int visit[n];
    memset(visit, 0, sizeof(visit));
    visit[0] = 1;

    enqueue(q, 0);

    int itr = 0;

    while (!isEmpty(q)) {
        int u = front(q);
        dequeue(q);
        ans[itr++] = u;
        g->connected_with_zero++;

        struct ListNode *curr = g->head[u];

        while (curr != NULL) {
            if (visit[curr->data] == 0) {
                visit[curr->data] = 1;
                enqueue(q, curr->data);
            }
            curr = curr->next;
        }
    }
}

int *bfs(struct graph *g, int n, int m) {
    int *ans = (int *)malloc(n * sizeof(int));
    bfs_utils(g, n, m, ans);

    return ans;
}


//{ Driver Code Starts.

int main() {
    int t = 1;

    while (t--) {
        int queries;
        scanf("%d", &queries);

        while (queries--) {
            int n, m;
            scanf("%d %d", &n, &m);
            struct edges arr_edges[m];
            for (int i = 0; i < m; i++) {
                int u, v;
                scanf("%d %d", &u, &v);
                arr_edges[i].src = u;
                arr_edges[i].dest = v;
            }
            struct graph* g = create_graph(arr_edges, n, m);

            // show_graph(g, n, m);

            int* ans = bfs(g, n, m);

            for (int i = 0; i < g->connected_with_zero; i++) {
                printf("%d ", ans[i]);
            }
            printf("\n");
        }
    }
    return 0;
}
// } Driver Code Ends