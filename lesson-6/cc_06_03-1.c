static int nbump = 0;
int bump() {
	return nbump++;
}

void start(n)
int n;
{
	nbump = n;
}
