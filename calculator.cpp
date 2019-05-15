#include "BigNumberLib.h"
#include "calculator.h"

#include "ui_calculator.h"
#include <iostream>
#include <vector>

double calcValue = 0.0;
bool divTrigger = false;
bool multTrigger = false;
bool addTrigger = false;
bool subTrigger = false;
bool modTrigger = false;

Calculator::Calculator(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Calculator)
{
    ui->setupUi(this);

    ui->Display->setText(QString::number(calcValue));
    QPushButton *numButtons[10];
    for(int i = 0; i < 10; i++)
    {
        QString buttonName = "Button" + QString::number(i);
        numButtons[i] = Calculator::findChild<QPushButton *>(buttonName);
        connect(numButtons[i], SIGNAL(released()), this, SLOT(NumPressed()));
    }
    connect(ui->Button_Add, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_Sub, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_Mult, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_Div, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_Mod, SIGNAL(released()), this, SLOT(MathButtonPressed()));
    connect(ui->Button_Equals, SIGNAL(released()), this, SLOT(EqualButtonPressed()));
    connect(ui->Button_Change_Sign, SIGNAL(released()), this, SLOT(ChangeNumberSign()));
}

Calculator::~Calculator()
{
    delete ui;
}


void Calculator::NumPressed()
{
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button ->text();
    QString displayValue = ui->Display ->text();
    if((displayValue.toDouble() == 0) || (displayValue.toDouble() == 0))
    {
        ui->Display->setText(buttonValue);
    }
    else
    {
        QString newValue = displayValue + buttonValue;
        double doubleNewValue = newValue.toDouble();
        ui->Display->setText(QString::number(doubleNewValue,'g',1000));

    }
}

void Calculator::MathButtonPressed()
{
    divTrigger = false;
    multTrigger = false;
    addTrigger = false;
    subTrigger = false;
    modTrigger = false;

    QString displayValue = ui->Display->text();
    calcValue = displayValue.toDouble();
    QPushButton *button = (QPushButton *)sender();
    QString buttonValue = button->text();

    if(QString::compare(buttonValue, "/", Qt::CaseInsensitive) ==0)
    {
        divTrigger = true;
    }
    else if(QString::compare(buttonValue, "*", Qt::CaseInsensitive) ==0)
    {
        multTrigger = true;
    }
    else if(QString::compare(buttonValue, "+", Qt::CaseInsensitive) ==0)
    {
        addTrigger = true;
    }
    else if(QString::compare(buttonValue, "-", Qt::CaseInsensitive) ==0)
    {
        subTrigger = true;
    }
    else
    {
        modTrigger = true;
    }
    ui->Display->setText(buttonValue);
}
void Calculator::EqualButtonPressed()
{
    double solution = 0.0;
    QString displayValue = ui->Display->text();
    double doubleDisplayValue = displayValue.toDouble();
    if(addTrigger || subTrigger || multTrigger || divTrigger || modTrigger)
    {
        if(addTrigger)
        {
            solution = calcValue + doubleDisplayValue;
        }
        else if(subTrigger)
        {
            solution = calcValue - doubleDisplayValue;
        }
        else if(multTrigger)
        {
            solution = calcValue * doubleDisplayValue;
        }
        else if(divTrigger)
        {
            solution = calcValue / doubleDisplayValue;
        }
        else if(modTrigger)
        {
            solution = calcValue / doubleDisplayValue;
        }
    }
    ui->Display->setText(QString::number(solution));
}
void Calculator::ChangeNumberSign()
{
    QString displayValue = ui->Display->text();
    QRegExp reg("[-]?[0-9.]*");
    if(reg.exactMatch(displayValue))
    {
            double doubleDisplayValue = displayValue.toDouble();
            double doubleDisplayValueSign = -1*doubleDisplayValue;
            ui->Display->setText(QString::number(doubleDisplayValueSign));
    }
}
