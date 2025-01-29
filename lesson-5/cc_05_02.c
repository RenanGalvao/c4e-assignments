#include <stdio.h>
#include <string.h>
#include <math.h>

main(){
	char s[1000];
	void itob(), itoh(); 
	
	itob(1024, s);
	printf("1024 in base-2 is %s\n", s);

	itoh(1024, s);
	printf("1024 in base-2 is %s\n", s);

}

void itob(n, s)
int n; char s[];
{
	void reverse();
	double pow();

	int power, base, tmp;
	power = tmp = 0;
	base = 2;

	while(pow(base, power) < n)
		power++;

	if(pow(base, power) > n)
		power--;

	s[power+1] = '\0';
	while(power >= 0){
		if(tmp + (int) pow(base, power) <= n) {
			s[power] = '1';
			tmp += (int) pow(base, power);
		} else{
			s[power] = '0';
		}

		power--;
	}
	reverse(s);
}

void itoh(n, s)
int n; char s[];
{
	void reverse();
	double pow();

	int power, base, tmp, comp;
	power = tmp = 0;
	base = 16;
	comp = 10; 

	while(pow(base, power) < n)
		power++;

	if(pow(base, power) > n)
		power--;

	s[power+1] = '\0';
	while(power >= 0){
		if(n % base == 0) {
			tmp = n / base;
			n -= tmp * base;

			/* fix me */
			if(n == 0 && power == 1){
				s[power] = '0';
				s[power-1] = '1';
				return;
			}

		} else {
			tmp = n % base;
			n -= tmp;
		}

		if (tmp <= 9){
			s[power] = '0' + tmp;
		} else {
			s[power] = 'a' + tmp - comp;
		}

		power--;
	}
}

void itoh2(n, s)
int n; char s[];
{
	void reverse();
	int base, comp, tmp, i;
	base = 16;
	comp = 9; /* a = 1 through f */
	tmp = i = 0;

	while(n > 0) {
		if(n % base == 0)
			tmp = (n / base) * base;
		else 
			tmp = n % base;
	
		n -= tmp;
		if (tmp <= 9){
			s[i++] = '0' + tmp;
		} else {
			s[i++] = 'a' + tmp - comp;
		}
	}
	s[i] = '\0';
	reverse(s);
}

void reverse(t)
char t[];
{
	int i, j, c, len;
	len = strlen(t);
	for(i = 0, j = len-1; i < (len / 2); i++, j--){
		c = t[i];
		t[i] = t[j];
		t[j] = c;
	}
}

