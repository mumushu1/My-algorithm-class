#include<stdio.h>
#include<string.h>
//用来找数组最大下标的函数：
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
	int k;//枚举次数
	int fish[30], tf[30], laketime[30][30];//fish:第k次捕鱼总数，tf：是数组f的复制，laketime：第k次在第i个池塘钓鱼的时间
	int roadtime;//路上时间
	int fishtime;//纯钓鱼时间

	while (scanf_s("%d", &n) && n) {
		scanf_s("%d", &h);
		h = h * 60;//转换为分钟

		for (i = 1; i <= n; i++) {
			scanf_s("%d", &f[i]);
		}
		for (i = 1; i <= n; i++) {
			scanf_s("%d", &d[i]);
		}
		for (i = 1; i <= n - 1; i++) {
			scanf_s("%d", &t[i]);
		}

	    //每一次开始时，都要初始化
		memset(fish, 0, sizeof(fish));
		memset(laketime, 0, sizeof(laketime));

		//枚举开始
		for (k = 1; k <= n; k++) {
			roadtime = 0;
			for (i = 1; i <= k; i++) {
				tf[i] = f[i];//复制操作
				roadtime = roadtime + 5 * t[i - 1];//路上耗时
			}
			fishtime = h - roadtime;//纯钓鱼时间

	       //贪心开始
			while (fishtime > 0) {
				i = find_max_i(tf, k);//i是当前有最多鱼的池塘
				fish[k] = fish[k] + tf[i];//钓鱼
				tf[i] = tf[i] - d[i];//该池塘的鱼数递减
				laketime[k][i] = laketime[k][i] + 5;//在该池塘钓鱼时间
				fishtime = fishtime - 5;//总钓鱼时间减少
				if (tf[i] < 0) {
					tf[i] = 0;//鱼已钓完
				}
			}

		}
		//枚举结束，开始比较，找最优
		k = find_max_i(fish, k);//鱼最多的那一次
		for (i = 1; i <= n; i++) {
			printf("%d ", laketime[k][i]);

		}
		printf("%d\n,预期鱼数：%d\n\n", laketime[k][n], fish[k]);

	}
	return 0;
}
