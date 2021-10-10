/**
 * @file test.c
 * @brief Файл з тестами на реалізації функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.4
 */

#include "lib.h"
#include <string.h>
#include <check.h>

/**
 * Верифікація роботи функції {@link get_animal_type_name}
 * на основі набора масивів вхідних та очікуваних даних
 *
 * @return стан проходження тестів: 1 - тести пройшли успішно, 0 - частина
 * тестів не пройшла
 */
START_TEST(test_get_animal_by_name)
{
#define DATA_SIZE 6

	enum animal_type input_data[] = { CAT, DOG, COW, PIG, ANIMAL_TYPE_COUNT, ANIMAL_TYPE_COUNT + 1 };
	char *expected_values[] = { "Кіт", "Собака", "Корова", "Свиня", "N/A", "N/A" };

	for (int i = 0; i < DATA_SIZE; i++) {
		const char *actual_value = get_animal_type_name(input_data[i]);
		ck_assert_str_eq(expected_values[i], actual_value);
	}
}
END_TEST

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
START_TEST(test_generate_animal)
{
#define EXPERIMENTS_COUNT 10
	for (int i = 0; i < EXPERIMENTS_COUNT; i++) {
		struct animal actual_data;
		generate_animal(&actual_data);
		ck_assert_str_ne(get_animal_type_name(actual_data.type), "N/A");
		ck_assert_int_lt(actual_data.weight, INT8_MAX);
		ck_assert_int_lt(actual_data.height, INT8_MAX);
	}
}
END_TEST

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
int main(void)
{
	Suite *s = suite_create("Programing");
	TCase *tc_core = tcase_create("Lab00");

	tcase_add_test(tc_core, test_get_animal_by_name);
	tcase_add_test(tc_core, test_generate_animal);
	suite_add_tcase(s, tc_core);

	SRunner *sr = srunner_create(s);
	srunner_run_all(sr, CK_VERBOSE);
	int number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);

	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
