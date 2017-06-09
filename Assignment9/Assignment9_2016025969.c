#include <stdio.h>

void MakeNode(int dot, int line);
void Dijkstra(int start, int end, int dot_size);

int** node;
int* dist;

int main() 
{
	int start, end, dot, line;

	scanf("%d %d", &dot, &line);
	MakeNode(dot, line);
	scanf("%d %d", &start, &end);

	Dijkstra(start, end, dot);
}

void MakeNode(int dot, int line) {

	node = (int**)malloc(sizeof(int*) * dot);
	dist = (int*)malloc(sizeof(int) * dot);

	for (int i = 0; i < dot; i++) {
		node[i] = (int*)malloc(sizeof(int) * dot);
		dist[i] = 1e9;
	}

	for (int i = 0; i < dot; i++) {
		for (int j = 0; j < dot; j++) {
			node[i][j] = 1e9;
		}
	}

	for (int i = 0; i < line; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		node[a - 1][b - 1] = c;
	}
}

void Dijkstra(int start, int end, int dot_size) {
	int* visit = (int*)malloc(sizeof(int) * dot_size);

	for (int i = 0; i < dot_size; i++) {
		visit[i] = 0;
	}

	dist[start - 1] = 0;

	for (int i = 0; i < dot_size; i++) {
		int min = 1e9;
		int min_v;

		for (int j = 0; j < dot_size; j++) {
			if (visit[j] == 0 && min > dist[j]) {
				min = dist[j];
				min_v = j;
			}
		}

		visit[min_v] = 1;

		for (int k = 0; k < dot_size; k++) {
			if (dist[k] > dist[min_v] + node[min_v][k]) {
				dist[k] = dist[min_v] + node[min_v][k];
			}
		}
	}

	printf("%d\n", dist[end - 1]);
}