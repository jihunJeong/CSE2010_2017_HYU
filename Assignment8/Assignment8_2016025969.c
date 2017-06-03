#include <stdio.h>

#define MAX_QUEUE_SIZE 10000

typedef struct queue* Queue;
typedef struct queue {
	int* array;
	int rear;
	int front;
}queue;

Queue CreateQueue();
void Enqueue(int num, Queue q);
int Dequeue(Queue q);

void MakeAdjacency(int dot, int line);
void MakeVisit(int dot_num);
void Dfs (int now, int dot_num);
void Bfs (int start, int dot_num, Queue q);

int** adjacency;
int* visit;
/*
	void dfs 에서 now : 기준점
				 인접행렬을 통해 [now][1] ---- [now][5]를 본다.
				 방문 했던 곳은 다시는 가지 않는다.
				 visit 배열 : 방문한 곳을 체크하는 배열
				 그 다음 재귀함수

	void bfs 에서 queue 이용 이전에 짠거 참고하기wh
*/
int main() {
	int dot, line, f_dot;
	scanf("%d %d %d", &dot, &line, &f_dot);

	MakeAdjacency(dot, line);
	MakeVisit(dot);

	Dfs(f_dot, dot);
	printf("\n");

	MakeVisit(dot);

	Queue q = CreateQueue();
	Bfs(f_dot, dot, q);
	printf("\n");

	return 0;
}

Queue CreateQueue() {
	Queue q = (Queue)malloc(sizeof(queue));
	
	q->array = (int*)malloc(sizeof(int) * MAX_QUEUE_SIZE);
	q->rear = -1;
	q->front = -1;

	return q;
}

void Enqueue(int num, Queue q) {
	if (q->rear != MAX_QUEUE_SIZE - 1) {
		q->rear += 1;
		q->array[q->rear] = num;
	} else {
		printf("Q is full\n");
	}
}

int Dequeue(Queue q) {
	int num = NULL;

	if (q->front < q->rear) {
		q->front += 1;
		num = q->array[q->front];
		q->array[q->front] = NULL;
	}

	return num;
}

void MakeAdjacency(int dot, int line) {
	adjacency = (int**)malloc(sizeof(int*) * dot);
	for (int i = 0; i < dot; i++) {
		adjacency[i] = (int*)malloc(sizeof(int) * dot);
	}

	for (int i = 0; i < dot; i++) {
		for (int j = 0; j < dot; j++) {
			adjacency[i][j] = 0;
		}
	}

	for (int i = 0; i < line; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adjacency[a - 1][b - 1] = 1;
		adjacency[b - 1][a - 1] = 1;
	}
}

void MakeVisit(int dot_num) {
	visit = (int*)malloc(sizeof(int) * dot_num);
	for (int i = 1; i <= dot_num; i++) {
		visit[i - 1] = 0;
	}
}

void Dfs(int now, int dot_num) {
	visit[now - 1] = 1;
	printf("%d ", now);

	for (int i = 1; i <= dot_num; i++) {
		int next = i;

		if (adjacency[now - 1][next - 1] == 1) {
			if (visit[next - 1] == 0) {
				visit[next - 1] = 1;
				Dfs(next, dot_num);
			}
		}
	}

}

void Bfs(int start, int dot_num, Queue q) {
	Enqueue(start, q);
	visit[start - 1] = 1;

	while (q->front < q->rear) {
		int now = Dequeue(q);
		printf("%d ", now);

		for (int i = 1; i <= dot_num; i++) {
			int next = i;

			if (adjacency[now - 1][next - 1] == 1) {
				if (visit[next - 1] == 0) {
					visit[next - 1] = 1;
					Enqueue(next, q);
				}
			}
		}
	}
}