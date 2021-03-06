//
// Created by ori on 12/01/2020.
//

#ifndef EX4_OBJECTADAPTER_H
#define EX4_OBJECTADAPTER_H


#include "Solver.h"
#include "Searchable.h"
#include <string>
#include "Searcher.h"
#include "SearchableCreator.h"
#include "MatrixProblemCreator.h"
#include "AStarsearch.h"

using namespace std;


template<typename T, typename S>
class ObjectAdapter : public Solver<Searchable<T> *, S> {
private:
    Searcher<T, S> *searcher;

public:
    ObjectAdapter(Searcher<T, S> *s) {
        this->searcher = s;
    }


    virtual S solve(Searchable<T> *p) override {

        S s = searcher->search(p);

        return s;

    }

    Searchable<T> *createProblem(vector<string> input) override {

        SearchableCreator<square *> *sc = new MatrixProblemCreator();

        Searchable<T> *mySearchable = sc->create(input);

        return mySearchable;


    }

    /*
     * we need to clone the object adapter in order to avoid duplications of the objects
     * that solve the problem in the parallel server
     */
    ObjectAdapter *clone() override {
        Searcher<T, S> *se = searcher->clone();
        ObjectAdapter *newObj = new ObjectAdapter<square *, string>(se);
        return newObj;

    }


};


#endif //EX4_OBJECTADAPTER_H
