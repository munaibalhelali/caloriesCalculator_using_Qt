#ifndef PERSON_H
#define PERSON_H

#include <QObject>

class Person : public QObject
{
    Q_OBJECT
public:
    explicit Person(QObject *parent = nullptr);
    double weight() const{return mWeight;}
    void setWeight(double weight);

signals:
    void weightChanged();

private:
    double mWeight = 0.0;

};

#endif // PERSON_H
