#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //-5% grade
    std::vector<double> temp{0.0251, 0.2157, 0.7888, 1.2957};
    mFunctionParam.push_back(temp);
    temp.clear();
    //-4% grade
    temp = {0.0244, 0.2079, 0.8053, 1.3281};
    mFunctionParam.push_back(temp);
    temp.clear();
    //-3% grade
    temp = {0.0237, 0.2000, 0.8217, 1.3605};
    mFunctionParam.push_back(temp);
    temp.clear();
    //-2% grade
    temp = {0.0230, 0.1922, 0.8382, 1.3929};
    mFunctionParam.push_back(temp);
    temp.clear();
    //-1% grade
    temp = {0.0222, 0.1844, 0.8546, 1.4253};
    mFunctionParam.push_back(temp);
    temp.clear();
    //0% grade
    temp = {0.0215, 0.1765, 0.8710, 1.4577};
    mFunctionParam.push_back(temp);
    temp.clear();
    //+1% grade
    temp = {0.0171, 0.1062, 0.6080, 1.8600};
    mFunctionParam.push_back(temp);
    temp.clear();
    //+2% grade
    temp = {0.0184, 0.1134, 0.6566, 1.9200};
    mFunctionParam.push_back(temp);
    temp.clear();
    //+3% grade
    temp = {0.0196, 0.1205, 0.7053, 1.9800};
    mFunctionParam.push_back(temp);
    temp.clear();
    //+4% grade
    temp = {0.0208, 0.1277, 0.7539, 2.0400};
    mFunctionParam.push_back(temp);
    temp.clear();
    //+5% grade
    temp = {0.0221, 0.1349, 0.8025, 2.1000};
    mFunctionParam.push_back(temp);



    //initialize
    mPerson.setWeight(ui->weightSpinBox->value());
    mTime = ui->timeSpinBox->value();
    mSpeed = ui->speedSpinBox->value();
    mSlopIndex = ui->slopComboBox->currentIndex();

    //connect butttons
    connect(ui->weightSpinBox, SIGNAL(valueChanged(double)), this, SLOT(weightChanged(double)));
    connect(ui->timeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(timeChanged(int)));
    connect(ui->speedSpinBox, SIGNAL(valueChanged(double)), this, SLOT(speedChanged(double)));
    connect(ui->slopComboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(slopChanged(int)));

    //display calory count
    connect(this, SIGNAL(caloryCountChanged()), SLOT(displayCalories()));

    calculateCalories();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::calculateCalories()
{
    std::vector<double> coefficients = mFunctionParam[mSlopIndex];
    mCaloryCount = (coefficients[0]* (mSpeed * mSpeed * mSpeed) - coefficients[1]*(mSpeed * mSpeed) + coefficients[2]*mSpeed + coefficients[3])* mPerson.weight() * mTime/60;
    emit caloryCountChanged();

}

void Widget::weightChanged(double weight)
{
    mPerson.setWeight(weight);
    calculateCalories();
}

void Widget::timeChanged(int time)
{
    mTime = time;
    calculateCalories();
}

void Widget::speedChanged(double speed)
{
    mSpeed = speed;
    calculateCalories();

}

void Widget::slopChanged(int index)
{
    mSlopIndex = index;
    calculateCalories();
}

void Widget::displayCalories()
{
        ui->totalCaloriesValueLabel->setText(QString::number(mCaloryCount));
}

