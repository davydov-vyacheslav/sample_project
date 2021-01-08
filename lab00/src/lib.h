#ifndef SAMPLE_PROJECT_LIB_H
#define SAMPLE_PROJECT_LIB_H

/**
 * @file lib.h
 * @brief Файл з описом структури тварини, перерахуванням типу тварин та функцій
 * оперування тваринами
 *
 * @author Davydov V.
 * @date 14-apr-2020
 * @version 1.3
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Кількість тварин у масиві
 */
#define ANIMAL_COUNT 10

/**
 * Тип тварини
 */
enum animal_type {
	PIG, /**< Свиня */
	COW, /**< Корова */
	DOG, /**< Собака */
	CAT, /**< Кіт */
	ANIMAL_TYPE_COUNT /**< Кількість тварин */
};

/**
 * Структура «Тварина»
 */
struct animal {
	enum animal_type type; /**< тип тварини */
	unsigned int height; /**< ріст тварини, см */
	unsigned int weight; /**< маса тварини, грам */
};

/**
 * Отримання текстового представлення значення типу тварини
 * @param type значення перерахувааня типу тварини
 * @return текстове репрезентування типу
 */
const char *get_animal_type_name(enum animal_type type);

/**
 * Створення даних про тварину.
 *
 * Функція генерує та повертає тварину з випадковими значеннями її полів
 * @param entity структура {@link animal} для заповнення
 */
void generate_animal(struct animal *entity);

/**
 * Вивід до екрану вмісту масиву з даними про тварини.
 *
 * Функція у циклу виводить дані на екран про кожний елемент масиву
 * з даними про тварину у наступному форматі:
 * "Тип_тварини: зріст = ріст_тварини см, маса = маса_тварини гр."
 * @param animals масив з даними о тваринах, які необхідно вивести на екран
 * @param count кількість тварин у переданому масиві
 */
void show_animals(struct animal animals[], unsigned int count);

#endif
