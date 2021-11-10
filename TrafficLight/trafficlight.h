#ifndef TRAFFIC_LIGHT_H
#define TRAFFIC_LIGHT_H

#include <QWidget>
#include<QVector>
#include<QKeyEvent>
#include<QTimer>
class QRadioButton;

class TrafficLight: public QWidget{
  Q_OBJECT

public:

  TrafficLight(QWidget * parent = nullptr);

protected:
     void createWidgets();
     void placeWidgets();
   //  void makeconnexionx();
     void timerEvent(QTimerEvent *e)override;
     void keyPressEvent(QKeyEvent *e)override;


private:

  QRadioButton * redlight;
  QRadioButton * yellowlight;
  QRadioButton * greenlight;
//  QVector<QRadioButton*> lights;
//  int index;
  int lifeTime;



};


#endif
