//
// Created by USER on 22.05.2022.
//

#ifndef INC_3_2_DERIVED2_H
#define INC_3_2_DERIVED2_H
#include <utility>

#include "Based.h"
class Derived2 : public Based{
public:
    Derived2(string name, Based* parent) : Based(std::move(name), parent){};
};

#endif //INC_3_2_DERIVED2_H
