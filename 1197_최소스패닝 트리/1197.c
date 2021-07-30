#include <stdio.h>

typedef struct{
    int u, v, cost;
}edge;


int V, E;
edge EdgeArr[100000];
int EdgeCnt;
int Parent[10000];


int findSet(int v) {
	if (v == Parent[v]) return v;

	return findSet(Parent[v]);
}

void quickSort(edge arr[], int left, int right) {
	if (left < right) {
		int p = left, i = left + 1, j = right;
		while (i <= j) {
			while (arr[i].cost <= arr[p].cost) i++;
			while (arr[j].cost > arr[p].cost) j--;

			if (i < j) {
				edge tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}

		edge tmp = arr[p];
		arr[p] = arr[j];
		arr[j] = tmp;
		quickSort(arr, left, j - 1);
		quickSort(arr, j + 1, right);
	}
}

int kruskal() {
	quickSort(EdgeArr, 0, EdgeCnt - 1);
	for (int i = 0; i < V; ++i)
		Parent[i] = i;

	int sumCost = 0, selectCnt = 0;
	for (int i = 0; i < EdgeCnt; ++i) {
		int u = EdgeArr[i].u, v = EdgeArr[i].v;
		if (findSet(u) == findSet(v)) continue;

		Parent[findSet(u)] = findSet(v);

		sumCost += EdgeArr[i].cost;
		if (++selectCnt >= V - 1) break;
	}

	return sumCost;
}

int main() {
	scanf("%d %d", &V, &E);	

	EdgeCnt = 0;
	for (int i = 0; i < E; ++i) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);

		EdgeArr[EdgeCnt].u = u - 1;
		EdgeArr[EdgeCnt].v = v - 1;
		EdgeArr[EdgeCnt++].cost = w;
	}

	printf("%d", kruskal());
	return 0;
}