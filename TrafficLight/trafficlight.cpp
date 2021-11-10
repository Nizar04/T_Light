#include "trafficlight.h"
#include <QWidget>
#include <QLayout>
#include <QRadioButton>
#include<QApplication>


TrafficLight::TrafficLight(QWidget * parent): QWidget(parent){

    //Creatign the widgets
    createWidgets();

    //place Widgets
    placeWidgets();
   // makeconnexionx();
   startTimer(1000);
//    lights.append(redlight);
//     lights.append(redlight);
//      lights.append(redlight);
//        lights.append(redlight);
//    lights.append(yellowlight);
//    lights.append(greenlight);
//    lights.append(greenlight);
//    index=0;
}


void TrafficLight::createWidgets()
{

  redlight = new QRadioButton;
  redlight->setEnabled(false);
  redlight->toggle();
  redlight->setStyleSheet("QRadioButton::indicator:checked { background-color: red;}");

  yellowlight = new QRadioButton;
  yellowlight->setEnabled(false);

  yellowlight->setStyleSheet("QRadioButton::indicator:checked { background-color: yellow;}");


  greenlight = new QRadioButton;
  greenlight->setEnabled(false);

  greenlight->setStyleSheet("QRadioButton::indicator:checked { background-color: green;}");
}


void TrafficLight::placeWidgets()
{

  // Placing the widgets
  auto layout = new QVBoxLayout;
  layout->addWidget(redlight);
  layout->addWidget(yellowlight);
  layout->addWidget(greenlight);
  setLayout(layout);
}


void TrafficLight::timerEvent(QTimerEvent *e){
//   if(redlight->isChecked())
//        yellowlight->toggle();
//   else if (yellowlight->isChecked())
//       greenlight->toggle();
//   else
//       redlight->toggle();
//    index = (index+1)%7;
//    lights[index]->toggle();
    lifeTime++;
    if(redlight->isChecked() && lifeTime == 4)
    {
        yellowlight->toggle();
        lifeTime=0;
    }
    else if(yellowlight->isChecked() && lifeTime == 1)
    {
        greenlight->toggle();
        lifeTime=0;
    }
    if(greenlight->isChecked() && lifeTime == 2)
    {
        redlight->toggle();
        lifeTime=0;
    }
}
void TrafficLight::keyPressEvent(QKeyEvent *e){
//    if(e->key() == Qt::Key_Escape)
//        qApp->exit();
//    else if (e->key() == Qt::Key_R)
//        lights[0]->toggle();
//    else if(e->key() == Qt::Key_Y)
//        lights[1]->toggle();
//    else if(e->key() == Qt::Key_G)
//        lights[2]->toggle();
    if(e->key() == Qt::Key_Escape)
        qApp->exit();
    else if (e->key() == Qt::Key_R)
        redlight->toggle();
    else if(e->key() == Qt::Key_Y)
        yellowlight->toggle();
    else if(e->key() == Qt::Key_G)
        greenlight->toggle();



}
