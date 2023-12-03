#include "globalIncludes.h"
#include "errorHandling.h"

uint8_t getNumber(const char* string) {
	uint8_t number = 0;
	size_t size = strlen(string);

	for (size_t i = 0; i < size; i++) {
		if (string[i] >= '0' && string[i] <= '9') {
			number = (string[i] - '0') * 10;
			break;
		}
	}

	for (size_t i = size; i >= 0; i--) {
		if (string[i] >= '0' && string[i] <= '9') {
			number += string[i] - '0';
			break;
		}
	}

	return number;
}

int main(int argc, char* argv[]) {
	FILE* file;

	assert_neq_0(fopen_s(&file, "entries.txt", "r"), "Could not open file");

	uint64_t result = 0;
	while (true) {
		char* buffer = malloc(75);
		assert_eq_0(buffer, "could not malloc");
		if (fgets(buffer, 75, file) == NULL) //eof
			break;
		result += getNumber(buffer);
		free(buffer);
	}

	fclose(file);

	printf("%llu", result);

	return 0;
}