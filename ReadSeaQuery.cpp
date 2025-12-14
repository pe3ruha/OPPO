#include "ReadSeaQuery.h"
#include <string>
#include <iostream>



std::string ReadSeaQuery() {
    std::string query;
    std::cout << "Введите море о котором нужна информация: ";
    std::cin >> query;
    return "\"" + query + "\"";
}