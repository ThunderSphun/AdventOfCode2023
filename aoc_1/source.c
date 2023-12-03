#include "globalIncludes.h"
#include "errorHandling.h"

uint64_t stringToLong(const char* string, size_t index, size_t size) {
	uint64_t value = *(uint64_t*) (string + index);

	if(size - index <= 0)
		return 0;

	if (size - index < 8)
		value &= (1ULL << (8 * (size - index))) - 1;

	return value;
}

uint8_t parseNumber(const char* string, size_t index, size_t size) {
	if (string[index] >= '0' && string[index] <= '9')
		return string[index] - '0';

	uint64_t stringValue = stringToLong(string, index, size);

	uint64_t one = stringToLong("one", 0, strlen("one"));
	uint64_t two = stringToLong("two", 0, strlen("two"));
	uint64_t three = stringToLong("three", 0, strlen("three"));
	uint64_t four = stringToLong("four", 0, strlen("four"));
	uint64_t five = stringToLong("five", 0, strlen("five"));
	uint64_t six = stringToLong("six", 0, strlen("six"));
	uint64_t seven = stringToLong("seven", 0, strlen("seven"));
	uint64_t eight = stringToLong("eight", 0, strlen("eight"));
	uint64_t nine = stringToLong("nine", 0, strlen("nine"));

	if ((stringValue & (1ULL << (8 * strlen("one"))) - 1) == one) return 1;
	if ((stringValue & (1ULL << (8 * strlen("two"))) - 1) == two) return 2;
	if ((stringValue & (1ULL << (8 * strlen("three"))) - 1) == three) return 3;
	if ((stringValue & (1ULL << (8 * strlen("four"))) - 1) == four) return 4;
	if ((stringValue & (1ULL << (8 * strlen("five"))) - 1) == five) return 5;
	if ((stringValue & (1ULL << (8 * strlen("six"))) - 1) == six) return 6;
	if ((stringValue & (1ULL << (8 * strlen("seven"))) - 1) == seven) return 7;
	if ((stringValue & (1ULL << (8 * strlen("eight"))) - 1) == eight) return 8;
	if ((stringValue & (1ULL << (8 * strlen("nine"))) - 1) == nine) return 9;

	return 0xff;
}

uint8_t getFirstNumber(const char* string, size_t size) {
	for (size_t i = 0; i < size; i++) {
		uint8_t value = parseNumber(string, i, size);
		if (value != 0xff)
			return value;
	}
}

uint8_t getLastNumber(const char* string, size_t size) {
	for (size_t i = size; i >= 0; i--) {
		uint8_t value = parseNumber(string, i, size);
		if (value != 0xff)
			return value;
	}
}

uint8_t getNumber(const char* string) {
	size_t size = strlen(string);

	return getFirstNumber(string, size) * 10 + getLastNumber(string, size);
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
		uint8_t number = getNumber(buffer);
		printf("%i\n", number);
		result += number;
		free(buffer);
	}

	fclose(file);

	printf("\n%llu", result);

	return 0;
}