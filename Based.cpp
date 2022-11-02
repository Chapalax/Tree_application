//
// Created by USER on 21.05.2022.
//

#include "Based.h"
#include <iostream>
#include <utility>

using namespace std;

Based::Based(string name, Based *parent) {
    this->name = move(name);
    this->parent = parent;
    if(parent != nullptr) parent->children.push_back(this);
}

void Based::SetName(string str) {
    this->name = move(str);
}

string Based::GetName() {
    return this->name;
}

void Based::SetParent(Based *parnt) {
    if(this->parent != nullptr)
        for(int i = 0; i < this->parent->children.size(); i++)
            if(this->parent->children[i] == this)
                this->parent->children.erase(this->parent->children.begin() + i);
    if(parnt != nullptr) parnt->children.push_back(this);
    this->parent = parnt;
}

Based *Based::GetParent() {
    return this->parent;
}

void Based::Print(int stage) {
    if(children.empty()) return;
    stage++;
    for(auto & i : children){
        cout << endl << string(4 * stage, ' ') << i->GetName();
        i->Print(stage);
        stage--;
        if(children.size() > 1) stage++;
    }

}

Based *Based::Find(const string& your_name) {
    Based* next = this;
    if(next->GetName() == your_name) return next;
    else return Search(next, your_name);
}

Based *Based::Search(Based *prnt, const string& moniker) {
    Based* parent_object;
    for(auto & i : prnt->children) {
        if (i->GetName() == moniker)
            return i;
        else {
            parent_object = Search(i, moniker);
            if(parent_object != nullptr) return parent_object;
        }
    }
    return nullptr;
}

void Based::SetState(int readiness) {
    if(readiness > 0){
        Based* parent_object = this;
        while (parent_object != nullptr && parent_object->GetParent() != nullptr && parent_object->GetParent()->GetState() > 0)
            parent_object = parent_object->GetParent();
        if(parent_object->GetParent() == nullptr && parent_object->GetState() > 0 || this->GetParent() == nullptr)
            this->state = readiness;
    } else{
        this->state = readiness;
        for(auto & i : children) i->SetState(0);
    }
}

int Based::GetState() const {
    return this->state;
}

void Based::State(int lvl) {
    if(children.empty()) return;
    lvl++;
    for(auto & i : children) {
        cout << endl << string(4 * lvl, ' ') << i->GetName() << " ";
        if (i->state <= 0) cout << "is not ready";
        else cout << "is ready";
        i->State(lvl);
        lvl--;
        if (children.size() > 1) lvl++;
    }
}

Based *Based::FindByPath(string path) {
    if(path[0] == '.') return this;
    else if(path[0] == '/'){
        Based* object = this;
        while (object->GetParent() != nullptr) object = object->GetParent();
        if(path[1] == '/') return object->Find(path.substr(2));
        else if(path.length() == 1) return object;
        else{
            path = path.substr(path.find('/') + 1);
            for(auto & i : object->children)
                if(i->GetName() == path || i->GetName() == path.substr(0, path.find('/')))
                    return i->FindByPath(path.substr(path.find('/') + 1));
            return nullptr;
        }
    } else{
        if (this->GetName() == path) return this;
        else{
            for(auto & i : this->children)
                if(i->GetName() == path.substr(0, path.find('/')))
                    return i->FindByPath(path.substr(path.find('/') + 1));
            return nullptr;
        }
    }
}
