//
// Created by ori on 12/01/2020.
//

#ifndef EX4_SEARCHABLE_H
#define EX4_SEARCHABLE_H

#include <vector>
#include "State.h"

using namespace std;

template <typename T>
class Searchable {
     virtual State<T> getInitialState() = 0;
     virtual bool isGoalState(State<T> state) = 0;
     virtual vector<State<T>> getAllPossibleStates(State<T>) = 0;

};




template <typename T>
class Matrix : public Searchable<T> {
private:
    vector<vector<State<T>*>> matrix;
    State<T>* initialState;
    State<T>* goalState;

public:

    Matrix(vector<vector<State<T>*>> m, State<T>* ini, State<T>* goal) {
        this->matrix = m;
        this->initialState = ini;
        this->goalState = goal;
    }


    State<T> getInitialState() {

    }
    bool isGoalState(State<T> state) {


    }
    vector<State<T>> getAllPossibleStates(State<T>) {

    }
};


#endif //EX4_SEARCHABLE_H