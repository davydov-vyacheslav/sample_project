/**
 * @file test.cpp
 * @brief Файл з тестами на реалізації функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 30-jul-2022
 * @version 1.0
 */

#include "lib.h"

#include <gtest/gtest.h>

/**
 * Верифікація роботи функції {@link get_animal_type_name} на основі набора масивів вхідних та очікуваних даних
 */
TEST(ProgramingLab00, test_get_animal_by_name)
{
  const size_t DATA_SIZE = 6;

  AnimalType input_data[] = { CAT, DOG, COW, PIG, ANIMAL_TYPE_COUNT, static_cast<AnimalType>(ANIMAL_TYPE_COUNT + 1) };
  string expected_values[] = { "Кіт", "Собака", "Корова", "Свиня", "N/A", "N/A" };

  for (size_t i = 0; i < DATA_SIZE; i++) {
    const string actual_value = getAnimalTypeName(input_data[i]);
    ASSERT_EQ(expected_values[i], actual_value);
  }
}

/**
 * Верифікація роботи функції {@link Animal::generateAnimal()}.
 *
 * У зв'язку з тим, що функція {@link Animal::generateAnimal()} генерує пседвдовипадкові
 * дані, її веріфікація полягає в перевірці меж для певної кільскості "експеріментів".
 */
TEST(ProgramingLab00, test_generate_animal)
{
  const size_t EXPERIMENTS_COUNT = 10;
  for (size_t i = 0; i < EXPERIMENTS_COUNT; i++) {
    Animal* actual_data = Animal::generateAnimal();
    ASSERT_NE(getAnimalTypeName(actual_data->getType()), "N/A");
    ASSERT_LT(actual_data->getWeight(), INT8_MAX);
    ASSERT_LT(actual_data->getHeight(), INT8_MAX);
    delete actual_data;
  }
}
