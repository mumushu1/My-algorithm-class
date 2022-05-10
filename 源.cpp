#include<stdio.h>
#include<stdlib.h>
int dp[100][100];
int  max(int a, int b) {
	if (a > b)
		return a;
	else
		return b;

}void Dynamic(int* w, int* v, int n, int c) {
	for (int i = 1; i <= n; i++)//��������
		dp[i][0] = 0;
	for (int i = 1; i <= c; i++)//��Ʒ����
		dp[0][i] = 0;
	int i, j;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= c; j++) {
			if (w[i] > j)
				dp[i][j] = dp[i - 1][j];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
		}
	}
}

int main() {
	int c, n, w[105], v[105];
	printf("��������Ʒ�����ͱ�������\n");
	scanf_s("%d %d", &n, &c);
	//c:��������     n:��Ʒ���� 
	w[0] = 0;
	printf("�����������Ʒ������\n");
	for (int i = 1; i < n + 1; i++)
		scanf_s("%d", &w[i]);
	printf("�����������Ʒ�ļ�ֵ\n");
	v[0] = 0;
	for (int i = 1; i < n + 1; i++)
		scanf_s("%d", &v[i]);

	int i, j;
	Dynamic(w, v, n, c);
	for (i = 0; i <= n; i++)
	{
		for (j = 0; j <= c; j++)
			printf("%d ", dp[i][j]);
		printf("\n");
	}
	return 0;

}