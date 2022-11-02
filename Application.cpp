//
// Created by USER on 21.05.2022.
//

#include "Application.h"
#include "Derived2.h"
#include "Derived3.h"
#include "Derived4.h"
#include "Derived5.h"
#include "Derived6.h"
#include <iostream>

using namespace std;

void Application::Build() {
    int state;
    string path, child_name;
    Based* child;
    cin >> path;
    SetName(path);
    cin >> path;
    while (path != "endtree"){
        if(this->FindByPath(path) == nullptr){
            exception = path;
            break;
        }
        cin >> child_name >> state;
        switch (state) {
            case 2:
                child = new Derived2(child_name, this->FindByPath(path));
                break;
            case 3:
                child = new Derived3(child_name, this->FindByPath(path));
                break;
            case 4:
                child = new Derived4(child_name, this->FindByPath(path));
                break;
            case 5:
                child = new Derived5(child_name, this->FindByPath(path));
                break;
            case 6:
                child = new Derived6(child_name, this->FindByPath(path));
                break;
            }
        cin >> path;
    }
}

int Application::Start() {
    Based* current = this;
    cout << "Object tree" << endl << GetName();
    Print(0);
    if(!exception.empty()){
        cout << endl << "The head object " << exception << " is not found";
        return 0;
    }
    string command, path;
    while (command != "END"){
        cin >> command >> path;
        if(command == "SET") {
            if (current->FindByPath(path) != nullptr) {
                current = current->FindByPath(path);
                cout << endl << "Object is set: " << current->GetName();
            } else cout << endl << "Object is not found: " << current->GetName() << " " << path;
        }
        if(command == "FIND"){
            if (current->FindByPath(path) != nullptr)
                cout << endl << path << string(5, ' ') << "Object name: " << current->FindByPath(path)->GetName();
            else
                cout << endl << path << string(5, ' ') << "Object is not found";
        }
    }
    return 0;
}
