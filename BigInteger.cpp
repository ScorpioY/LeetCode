#include<stdio.h>
#include<string.h>
int main() {
	int a[201], b[201], j = 0;
	char a_nums[201], b_nums[201];
	int a_len, b_len, max_len;
	scanf("%s%s", &a_nums, &b_nums);
	a_len = strlen(a_nums);
	b_len = strlen(b_nums);
	for (int i = a_len - 1; i >= 0; i--) {
		a_nums[i] -= '0';
		a[j] = a_nums[i];
		j++;
	}
	j = 0;
	for (i = b_len - 1; i >= 0; i--) {
		b_nums[i] -= '0';
		b[j] = b_nums[i];
		j++;
	}
	if (a_len == b_len) {
		a[a_len] = 0;
		b[b_len] = 0;
	}
	if (a_len>b_len) {
		for (i = b_len; i <= a_len; i++)
			b[i] = 0;
		a[a_len] = 0;
	}
	if (a_len<b_len) {
		for (i = a_len; i <= b_len; i++)
			a[i] = 0;
		b[b_len] = 0;
	}
	max_len = (a_len >= b_len) ? a_len : b_len;
	for (i = 0; i<max_len; i++) {
		a[i] += b[i];
		if (a[i] >= 10) {
			a[i] -= 10;
			a[i + 1] += 1;
		}
	}
	if (a[max_len] != 0)
		printf("%d", a[max_len]);
	for (i = max_len - 1; i >= 0; i--) {
		printf("%d", a[i]);
	}
	return 0;
}