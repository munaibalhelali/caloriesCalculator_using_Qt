#include "person.h"

Person::Person(QObject *parent) : QObject(parent)
{

}

void Person::setWeight(double weight){
    if(mWeight != weight){
        mWeight = weight;
        emit weightChanged();
    }
}

