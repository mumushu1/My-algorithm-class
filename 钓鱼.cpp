#include<stdio.h>
#include<string.h>
//��������������±�ĺ�����
int find_max_i(int a[], int n) {
	int i;
	int j = 1;
	int max = a[1];
	for (i = 2; i <= n; i++) {
		if (max < a[i]) {
			max = a[i];
			j = i;
		}
	}
	return j;
}

int main() {
	int n, i;
	int h, f[30], d[30];
	int t[30] = { 0 };
	int k;//ö�ٴ���
	int fish[30], tf[30], laketime[30][30];//fish:��k�β���������tf��������f�ĸ��ƣ�laketime����k���ڵ�i�����������ʱ��
	int roadtime;//·��ʱ��
	int fishtime;//������ʱ��

	while (scanf_s("%d", &n) && n) {
		scanf_s("%d", &h);
		h = h * 60;//ת��Ϊ����

		for (i = 1; i <= n; i++) {
			scanf_s("%d", &f[i]);
		}
		for (i = 1; i <= n; i++) {
			scanf_s("%d", &d[i]);
		}
		for (i = 1; i <= n - 1; i++) {
			scanf_s("%d", &t[i]);
		}

	    //ÿһ�ο�ʼʱ����Ҫ��ʼ��
		memset(fish, 0, sizeof(fish));
		memset(laketime, 0, sizeof(laketime));

		//ö�ٿ�ʼ
		for (k = 1; k <= n; k++) {
			roadtime = 0;
			for (i = 1; i <= k; i++) {
				tf[i] = f[i];//���Ʋ���
				roadtime = roadtime + 5 * t[i - 1];//·�Ϻ�ʱ
			}
			fishtime = h - roadtime;//������ʱ��

	       //̰�Ŀ�ʼ
			while (fishtime > 0) {
				i = find_max_i(tf, k);//i�ǵ�ǰ�������ĳ���
				fish[k] = fish[k] + tf[i];//����
				tf[i] = tf[i] - d[i];//�ó����������ݼ�
				laketime[k][i] = laketime[k][i] + 5;//�ڸó�������ʱ��
				fishtime = fishtime - 5;//�ܵ���ʱ�����
				if (tf[i] < 0) {
					tf[i] = 0;//���ѵ���
				}
			}

		}
		//ö�ٽ�������ʼ�Ƚϣ�������
		k = find_max_i(fish, k);//��������һ��
		for (i = 1; i <= n; i++) {
			printf("%d ", laketime[k][i]);

		}
		printf("%d\n,Ԥ��������%d\n\n", laketime[k][n], fish[k]);

	}
	return 0;
}