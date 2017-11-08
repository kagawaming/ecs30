/*Ming Qiu*/
/*define the gcd function*/
int
gcd(int n1, int n2)
{
	int ans;
	if (n1 % n2 == 0)
	ans = n2;
	else
	ans = gcd(n2, n1 % n2);
	return (ans);
}
/*the calculator program*/
main(int argc, char **argv) {
	int n1, n2, result;

	/* Show how to use the program */
	if (4 != argc) {
		printf("Usage: calculate <number> <op> <number>\n");
		exit(1);
	}

	/* Get the numbers */
	n1 = atoi(argv[1]);
	n2 = atoi(argv[3]);

	/* Do the right calculation */
	switch(argv[2][0]) {
	case '+': 	result = n1 + n2; break;
	case '-':	result = n1 - n2; break;
	case 'x':	result = n1 * n2; break;
	case '/':	result = n1 / n2; break;
	case 'g': result = gcd(n1, n2); break;/*add the gcd function to the calculator program*/
	default:	printf("Invalid operator %s\n", argv[2]);
			exit(1);
	}

	/* Show the result */
	printf("Result is %d\n", result);
}
