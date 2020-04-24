/**
 * @mainpage
 * # Загальне завдання
 * 1. **Сформувати** функцию, що генерирує структуру із залученням механізму
 * випадкової генерації даних (прикладная галузь вказана в індивідуальному
 * завданні);
 *
 * 2. **Сформувати** функцію, яка буде виводити масив структур на екран
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.3
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи структури {@link animal} та методів
 * оперування ним.
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.3
 */

#include "lib.h"

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення масиву із {@link ANIMAL_COUNT} тварин
 * - генерація даних для кожної тварини шляхом виклика функції
 * {@link generate_animal}
 * - вивід даних про всіх тварин на екран за допомогою функції
 * {@link show_animals}
 * @return успішний код повернення з програми (0)
 */
int main()
{
	srand((unsigned int)time(0));
	struct animal animals[ANIMAL_COUNT];

	for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {
		generate_animal(&animals[i]);
	}
	show_animals(animals, ANIMAL_COUNT);

	return 0;
}
