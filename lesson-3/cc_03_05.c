#include <stdio.h>
#include <string.h>

int main() {
	char t[1000];
	char *copy();
	void reverse();

	copy("Hello world", t);
	printf("%s\n", t);
	reverse(t);
	printf("%s\n", t);
}

/* copy s1 to s2; assume s2 big enough */
char *copy(s1, s2) 
char s1[], s2[]; 
{
	int i;
	for(i = 0; s2[i] = s1[i]; i++);
	return s2;
}

void reverse(t) 
char t[];
{
	char tmp[1000];
	int i;
	for(i = 0; tmp[i] = t[i]; i++) ;

	int j, k, len;
	len = strlen(tmp);
	for(j = 0, k = len - 1; j <= len; j++, k--){
		if(tmp[k] == '\0') continue;
		t[j] = tmp[k];
	}
}
