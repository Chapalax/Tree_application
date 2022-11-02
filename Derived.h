//
// Created by USER on 22.05.2022.
//

#ifndef INC_3_2_DERIVED_H
#define INC_3_2_DERIVED_H
#include <utility>

#include "Based.h"
class Derived : public Based{
public:
    Derived(string name, Based* parent) : Based(std::move(name), parent){};
};

#endif //INC_3_2_DERIVED_H
