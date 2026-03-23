#include <stdio.h>

unsigned long long cmmdc(unsigned long long x, unsigned long long y)
{
	unsigned long long r;
	while (y) {
		r = x % y;
		x = y;
		y = r;
	}
	return x;
}

unsigned long long cmmmc(unsigned long long x, unsigned long long y)
{
	unsigned long long cmmmc = x / cmmdc(x, y) * y;
	return cmmmc;
}

int main(void)
{
	unsigned long long window, time[10001], value[10001];
	int i = 0;
	scanf("%llu", &window);
	while (1) {
		scanf("%llu%llu", &time[i], &value[i]);
		if (time[i] == 0 && value[i] == 0) {
			break;
		}
		i++;
	}
	for (int j = 0; j < i - 1; j++) {
		for (int k = j + 1; k < i; k++) {
			if (time[k] - time[j] <= window) {
				if (value[j] == 0 || value[k] == 0) {
					break;
				}
				printf("%llu ", cmmmc(value[j], value[k]));
				printf("%llu\n", cmmdc(value[j], value[k]));
			} else {
				break;
			}
		}
	}
	return 0;

}
