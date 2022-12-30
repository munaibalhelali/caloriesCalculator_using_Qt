#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "person.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void calculateCalories();
    void weightChanged(double weight);
    void timeChanged(int time);
    void speedChanged(double speed);
    void slopChanged(int index);
    void displayCalories();


signals:
    void caloryCountChanged();

private:
    Ui::Widget *ui;
    Person mPerson;
    int mTime;
    double mSpeed;
    double mCaloryCount;
    int mSlopIndex;
    std::vector<std::vector<double>> mFunctionParam;
};
#endif // WIDGET_H
