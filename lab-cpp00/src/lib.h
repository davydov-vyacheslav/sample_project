#ifndef SAMPLE_PROJECT_LIB_H
#define SAMPLE_PROJECT_LIB_H

/**
 * @file lib.h
 * @brief Файл з описом тварини, перерахуванням типу тварин та функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 30-jul-2022
 * @version 1.0
 */

#include <string>

using std::string;

/**
 * Тип тварини
 */
enum AnimalType
{
  PIG,              /**< Свиня */
  COW,              /**< Корова */
  DOG,              /**< Собака */
  CAT,              /**< Кіт */
  ANIMAL_TYPE_COUNT /**< Кількість тварин */
};

/**
 * Отримання текстового представлення значення типу тварини
 * @param type значення перерахування типу тварини
 * @return текстове репрезентування типу
 */
string getAnimalTypeName(const AnimalType& type);

/**
 * Обʼєкт «Тварина»
 */
class Animal
{
  AnimalType type; /**< тип тварини */
  size_t height;   /**< ріст тварини, см */
  size_t weight;   /**< маса тварини, грам */

public:
  Animal() = default;
  Animal(AnimalType type, size_t height, size_t weight);
  Animal(const Animal& copy) = default;
  ~Animal() = default;

  /**
   * Вивід до екрану даних про тварину.
   *
   * Функція виводить дані на екран про тварину у наступному форматі:
   * "Тип_тварини: зріст = ріст_тварини см, маса = маса_тварини гр."
   */
  string getInfo() const;

  /**
   * Створення даних про тварину.
   *
   * Функція генерує та повертає тварину з випадковими значеннями її полів
   * @return заповнений обʼєкт {@link Animal}
   */
  static Animal* generateAnimal();

  AnimalType getType() const;
  size_t getHeight() const;
  size_t getWeight() const;
};

#endif
