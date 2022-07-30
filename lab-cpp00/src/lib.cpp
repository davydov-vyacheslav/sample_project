/**
 * @file lib.cpp
 * @brief Файл з реалізацією функцій оперування тваринами
 *
 * @author Davydov V.
 * @date 30-jul-2022
 * @version 1.0
 */

#include "lib.h"

#include <sstream>

using std::stringstream;

string getAnimalTypeName(const AnimalType& type)
{
  string result;
  switch (type) {
    case CAT:
      result = "Кіт";
      break;
    case DOG:
      result = "Собака";
      break;
    case COW:
      result = "Корова";
      break;
    case PIG:
      result = "Свиня";
      break;
    default:
      result = "N/A";
  }
  return result;
}

Animal::Animal(AnimalType type, size_t height, size_t weight)
  : type(type)
  , height(height)
  , weight(weight)
{
}

string Animal::getInfo() const
{
  stringstream strs;
  strs << getAnimalTypeName(this->type) << ", ";
  strs << "зріст = " << this->height << " см"
       << ", ";
  strs << "маса = " << this->weight << " гр";
  return strs.str();
}

Animal* Animal::generateAnimal()
{
  return new Animal(static_cast<AnimalType>(random() % ANIMAL_TYPE_COUNT), static_cast<size_t>(random() % INT8_MAX),
           static_cast<size_t>(random() % INT8_MAX));
}
AnimalType Animal::getType() const
{
  return type;
}
size_t Animal::getHeight() const
{
  return height;
}
size_t Animal::getWeight() const
{
  return weight;
}
