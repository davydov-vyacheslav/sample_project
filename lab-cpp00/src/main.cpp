/**
 * @mainpage
 * # Загальне завдання
 * 1. **Сформувати** функцию, що генерирує обʼєкт із залученням механізму
 * випадкової генерації даних (прикладная галузь вказана в індивідуальному завданні);
 *
 * 2. **Сформувати** функцію, яка буде виводити масив (колекцію) структур на екран
 *
 * @author Davydov V.
 * @date 30-jul-2022
 * @version 1.0
 */

/**
 * @file main.c
 * @brief Файл з демонстрацією роботи класу {@link Animal} та методів оперування ним.
 *
 * @author Davydov V.
 * @date 30-jul-2022
 * @version 1.0
 */

#include "lib.h"

#include <ctime>
#include <iostream>
#include <list>

using std::list;
using std::cout;
using std::endl;

/**
 * Кількість тварин у колекції
 */
const size_t ANIMAL_COUNT = 10;

/**
 * Головна функція.
 *
 * Послідовність дій:
 * - створення колекції із {@link ANIMAL_COUNT} тварин
 * - генерація даних для кожної тварини шляхом виклика статичної функції {@link Animal.generateAnimal()}
 * - вивід даних про всіх тварин на екран за допомогою функції {@link Animal.getInfo()}
 * @return успішний код повернення з програми (0)
 */
int main()
{
  srand((unsigned int)time(nullptr));

  list<Animal*> animals;

  for (unsigned int i = 0; i < ANIMAL_COUNT; i++) {
    animals.push_back(Animal::generateAnimal());
  }

  for (const Animal* animal : animals) {
    cout << "Інформація про тварину: " << animal->getInfo() << endl;
  }

  return 0;
}
