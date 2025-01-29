#include <stdio.h>

int main() {
	int empno;
	float rate, hours, pay;
	void calcpay();

	while(1) {
		if(scanf("%d %f %f", &empno, &rate, &hours) < 3)
			break;
		calcpay(&pay, rate, hours);
		printf("Employee=%d Rate=%.2f Hours=%.2f Pay=%.2f\n", empno, rate, hours, pay);
	}
}

void calcpay(p, r, h)
float *p, r, h;
{
	int WEEK_HOURS = 40;

	if(h <= WEEK_HOURS)
		*p = r * h;
	else
		*p = r * WEEK_HOURS + ((r * 1.5) * ((int)h % WEEK_HOURS));
}
