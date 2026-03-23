#include <stdio.h>
#include <string.h>

char grid[50][50];

int verify(char a[50][50], int n, int m, int i, int j)
{
	int lights = 0;
	if (i > 0 && a[i - 1][j] == 'L') {
		lights++;
	}
	if (i < n - 1 && a[i + 1][j] == 'L') {
		lights++;
	}
	if (j > 0 && a[i][j - 1] == 'L') {
		lights++;
	}
	if (j < m - 1 && a[i][j + 1] == 'L') {
		lights++;
	}
	return lights;
}

void  complete(char grid[50][50], int n, int m, int i, int j)
{
	int a, b;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (grid[i][j] == 'L') {
				for (a = i - 1; a >= 0; a--) {
					if (grid[a][j] == '-') {
						grid[a][j] = 'x';
					} else if (strchr("L01234#", grid[a][j]) != 0) {
						break;
					}
				}
				for (a = i + 1; a < n; a++) {
					if (grid[a][j] == '-') {
						grid[a][j] = 'x';
					} else if (strchr("L01234#", grid[a][j]) != 0) {
						break;
					}
				}
				for (b = j - 1; b >= 0; b--) {
					if (grid[i][b] == '-') {
						grid[i][b] = 'x';
					} else if (strchr("L01234#", grid[i][b]) != 0) {
						break;
					}
				}
				for (b = j + 1; b < m; b++) {
					if (grid[i][b] == '-') {
						grid[i][b] = 'x';
					} else if (strchr("L01234#", grid[i][b]) != 0) {
						break;
					}
				}
			}
		}
	}
}

void complete_missing(char grid[50][50], int n, int m, int i, int j)
{
	if (i > 0 && strchr("L01234#", grid[i - 1][j]) == 0) {
		grid[i - 1][j] = 'x';
	}
	if (i < n - 1 && strchr("L01234#", grid[i + 1][j]) == 0) {
		grid[i + 1][j] = 'x';
	}
	if (j > 0 && strchr("L01234#", grid[i][j - 1]) == 0) {
		grid[i][j - 1] = 'x';
	}
	if (j < m - 1 && strchr("L01234#", grid[i][j + 1]) == 0) {
		grid[i][j + 1] = 'x';
	}
}

int free_cells(char grid[50][50], int n, int m, int i, int j)
{
	int number = 0;
	if (i > 0 && grid[i - 1][j] == '-') {
		number++;
	}
	if (i < n - 1 && grid[i + 1][j] == '-') {
		number++;
	}
	if (j > 0 && grid[i][j - 1] == '-') {
		number++;
	}
	if (j < m - 1 && grid[i][j + 1] == '-') {
		number++;
	}
	return number;
}

int check_lights(char grid[50][50], int n, int m)
{
	int ok = 1;
	for (int i = 0; i < n; i++) {
		int count = 0;
		for (int j = 0; j < m; j++) {
			if (strchr("#01234", grid[i][j]) != 0) {
				count = 0;
			}
			if (grid[i][j] == 'L') {
				count++;
				if (count > 1) {
					ok = 0;
				}
			}
		}
	}
	for (int j = 0; j < m; j++) {
		int count = 0;
		for (int i = 0; i < n; i++) {
			if (strchr("#01234", grid[i][j]) != 0) {
				count = 0;
			}
			if (grid[i][j] == 'L') {
				count++;
				if (count > 1) {
					ok = 0;
				}
			}
		}
	}
	return ok;
}

int main(void)
{
	int o, n, m, i, j, ok = 1;
	scanf("%d", &o);
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			scanf(" %c", &grid[i][j]);
		}
	}
	complete(grid, n, m, i, j);
	if (o == 1) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (strchr("01234", grid[i][j]) != 0) {
					if (verify(grid, n, m, i, j) == grid[i][j] - '0') {
						complete_missing(grid, n, m, i, j);
					}
				}
			}
		}
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				printf("%c ", grid[i][j]);
			}
			printf("\n");
		}
	} else if (o == 2) {
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (strchr("01234", grid[i][j]) != 0) {
					int num = grid[i][j] - '0';
					if (verify(grid, n, m, i, j) > num) {
						ok = 0;
					}
				}
			}
		}
		ok = check_lights(grid, n, m);
		for (i = 0; i < n; i++) {
			for (j = 0; j < m; j++) {
				if (strchr("01234", grid[i][j]) != 0) {
					int needed = grid[i][j] - '0';
					int already = verify(grid, n, m, i, j);
					int free = free_cells(grid, n, m, i, j);
					if (already + free < needed) {
						ok = 0;
					}
				}
			}
		}
			if (ok == 0) {
				printf("zero\n");
			} else {
				printf("ichi\n");
			}
		}

	return 0;

}
