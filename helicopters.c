#include <stdio.h>
#include <stdlib.h>

int wrong_pos[801], aterizare_gresita[801];
int cnt, cnt2, hel_valide;

int pozitie_gresita(int r1, int c1, int r2, int c2)
{
	if (r1 == r2 || c1 == c2) {
		return 0;
	}
	return 1;
}

int valid(int a[1001][1001], int r1, int c1, int r2, int c2, int s)
{
	int i, j, count_1 = 0, count_0 = 0;
	if (r2 < r1) {
		int aux = r1;
		r1 = r2;
		r2 = aux;
		aux = c1;
		c1 = c2;
		c2 = aux;
	}
	if (s == 1) {
		if (c1 < c2) {
			for (i = r1; i <= r2; i++) {
				for (j = c1; j <= c2; j++) {
					if (a[i][j] == 0) {
						count_0++;
					} else {
						count_1++;
					}
				}
				c1++;
			}
		} else if (c1 > c2) {
			for (i = r1; i <= r2; i++) {
				for (j = c1; j >= c2; j--) {
					if (a[i][j] == 0) {
						count_0++;
					} else {
						count_1++;
					}
				}
				c1--;
			}
		}
	} else if (s == -1) {
		if (c1 < c2) {
			for (i = r2; i >= r1; i--) {
				for (j = c2; j >= c1; j--) {
					if (a[i][j] == 0) {
						count_0++;
					} else {
						count_1++;
					}
				}
				c2--;
			}
		} else if (c1 > c2) {
			for (i = r2; i >= r1; i--) {
				for (j = c1; j >= c2; j--) {
					if (a[i][j] == 0) {
						count_0++;
					} else {
						count_1++;
					}
				}
				c2++;
			}
		}
	}

	if (count_0 > count_1) {
		return 0;
	}
	if (count_0 == 0) {
		return 1;
	}
	return 2;
}

int main(void)
{
	int n, m, a[1001][1001], i, j, r1, c1, r2, c2, s, k;
		scanf("%d%d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	scanf("%d", &k);
	int nr_hel = 1;
	while (k) {
		scanf("%d%d%d%d%d", &r1, &c1, &r2, &c2, &s);
		if (pozitie_gresita(r1, c1, r2, c2) == 0) {
			wrong_pos[cnt] = nr_hel;
			cnt++;
		} else {
			int v = valid(a, r1, c1, r2, c2, s);
			if (v == 1) {
				hel_valide++;
			} else if (v == 0) {
				aterizare_gresita[cnt2] = nr_hel;
				cnt2++;
			}
		}
			k--;
			nr_hel++;
	}
	for (i = 0; i < cnt; i++) {
		printf("Elicopterul %d ", wrong_pos[i]);
		printf("este pozitionat necorespunzator!\n");
	}
	printf("%d\n", hel_valide);
	printf("%d\n", cnt2);
	for (i = 0; i < cnt2; i++) {
		printf("%d ", aterizare_gresita[i]);
	}
	printf("\n");
	return 0;

}
