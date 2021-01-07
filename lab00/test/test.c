/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.3
 */

#include "lib.h"
#include <string.h>

/**
 * Верифікація роботи функції {@link get_animal_type_name}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
unsigned short test_get_animal_by_name()
{
	printf("Running test %s ... \n", __FUNCTION__);
#define DATA_SIZE 6

	unsigned short is_success = 1;
	enum animal_type input_data[] = { CAT, DOG, COW, PIG, ANIMAL_TYPE_COUNT, ANIMAL_TYPE_COUNT + 1 };
	char *expected_values[] = { "Кіт",   "Собака", "Корова",
				    "Свиня", "N/A",    "N/A" };

	for (int i = 0; i < DATA_SIZE; i++) {
		char *actual_value = get_animal_type_name(input_data[i]);
		if (strcmp(expected_values[i], actual_value) != 0) {
			printf("Test %s failed: expected: '%s', actual: '%s'\n",
			       __FUNCTION__, expected_values[i], actual_value);
			is_success = 0;
			break;
		}
	}
	return is_success;
}

/**
 * Верифікація роботи функції {@link generate_animal}.
 *
 * У зв'язку з тим, що функція {@link generate_animal} генерує пседвдовипадкові
 * дані, її веріфікація полягає в перевірці меж для певної кільскості
 * "експеріментів".
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
unsigned short test_generate_animal()
{
#define EXPERIMENTS_COUNT 10
	printf("Running test %s ... \n", __FUNCTION__);
	unsigned short is_success = 1;
	for (int i = 0; i < EXPERIMENTS_COUNT; i++) {
		struct animal actual_data;
		generate_animal(&actual_data);
		if (strcmp(get_animal_type_name(actual_data.type), "N/A") ==
		    0) {
			printf("Test %s failed: in one of experiments method generate_animal() "
			       "returned bad animal type\n",
			       __FUNCTION__);
			is_success = 0;
			break;
		}
		if (actual_data.weight > INT8_MAX) {
			printf("Test %s failed: animal's weight '%d' exceed maximum allowed: '%d'\n",
			       __FUNCTION__, actual_data.weight, INT8_MAX);
			is_success = 0;
			break;
		}
		if (actual_data.height > INT8_MAX) {
			printf("Test %s failed: animal's height '%d' exceed maximum allowed: '%d'\n",
			       __FUNCTION__, actual_data.height, INT8_MAX);
			is_success = 0;
			break;
		}
	}

	return is_success;
}

/**
 * Точка входу модуля тестування.
 *
 * Запускає розроблені функції верифікації функцій роботи з структурой
 * {@link animal}.
 *
 * По завершенню тестів виводиться на екран резуміюча інформація про стан
 * проходження тестів.
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
int main()
{
	srand((unsigned int)time(0));
	unsigned short is_success = 1;
	is_success &= test_get_animal_by_name();
	is_success &= test_generate_animal();

	if (is_success) {
		printf("Congratulations! All tests succeed!\n");
	} else {
		printf("Some tests failed. Check logs, fix errors and try again\n");
	}
	return !is_success;
}
