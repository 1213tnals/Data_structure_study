#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10000

void radixSort(int* a, int n) {
	int res[MAX], maxValue = 0;    //res는 결과 배열, bucket은 자릿수배열
	int exp = 1;

	for (int i = 0; i < n; i++) {
		if (a[i] > maxValue) maxValue = a[i];
	}

	while (maxValue / exp > 0) {  // 1의 자리부터 계산
		int bucket[10] = { 0 };  //자릿수 배열은 10개까지만 있음
		for (int i = 0; i < n; i++) bucket[a[i] / exp % 10]++;   //자릿수 배열 처리
		for (int i = 1; i < 10; i++) bucket[i] += bucket[i - 1]; //자릿수 누적 계산
		for (int i = n - 1; i >= 0; i--) { //같은 자릿수 끼리는 순서를 유지
			res[--bucket[a[i] / exp % 10]] = a[i];
		}
		for (int i = 0; i < n; i++) a[i] = res[i]; //기본 배열 갱신
		exp *= 10;
	}
}

int main(void) {
	int a[MAX];
	int i, n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	radixSort(a, n);
	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
}