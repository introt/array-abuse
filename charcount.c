#include <stdio.h> // fopen, printf
#include <ctype.h> // tolower
int main() { // with thanks to https://stackoverflow.com/a/15713419
	FILE *file = fopen("/tmp/input.txt", "r"); // try to open file for reading
	if (file == NULL) return 1; // file not found!
	char c; // ASCII only; used as index
	unsigned long int chars[127] = {0}; // room for all printable characters (32-126)
	unsigned long int total = 0, count; // long ints need initialization
	while ((c = fgetc(file)) != EOF) { // while the next char is not end of file
		chars[tolower(c)]++; // count A-Z as a-z
	}
	for (char i = 32; i < 127; i++) { // start from spaces; could be unrolled (would skip A-Z as well!)
		count = chars[i]; // count isn't used before getting a value
		if (count != 0) { // skip chars with a count of 0
			printf("%c: %ld\n", i, count); // printf handles representing i as an ASCII char
			total += count; // total gets added to and thus needs initialization
		}
	}
	printf("Total: %ld\n", total); // see http://bot.fi/5ot for explanation
	return 0; // success!
}
