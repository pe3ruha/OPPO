#pragma once
#include <string>
#include <vector>
#include <regex>
#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;
/**
 * @class Sea
 * @brief Класс, описывающий море и его основные характеристики.
 */
class Sea {
public:
    string name;          ///< Название моря
    int depth;            ///< Максимальная глубина
    int salinity;         ///< Солёность


    Sea() : depth(0), salinity(0) {}
    /**
     * @brief Выводит информацию о море в табличном виде.
     */
    void Print() const;

    /**
     * @brief Находит самое солёное море.
     * @param seas Вектор морей
     * @param length Количество элементов
     * @return Индекс самого солёного моря
     */
    static int FindMostSalty(const std::vector<Sea>& seas);
};