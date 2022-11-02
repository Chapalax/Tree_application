//
// Created by USER on 22.05.2022.
//

#ifndef INC_3_2_DERIVED3_H
#define INC_3_2_DERIVED3_H
#include <utility>

#include "Based.h"
class Derived3 : public Based{
public:
    Derived3(string name, Based* parent) : Based(std::move(name), parent){};
};


#endif //INC_3_2_DERIVED3_H
