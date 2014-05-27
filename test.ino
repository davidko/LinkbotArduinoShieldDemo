#include <Linkbot.h>
#include <math.h>

Linkbot l;
void setup()
{
  pinMode(8, OUTPUT);
  l.setJointStates(1, 1, 1, 45, 45, 45);
  l.stop();
}

void loop()
{
    double time = (double)millis()/1000.0;
    double omega = 1;
    double r = 0.5 + 0.5*sin(omega * (time));
    double g = 0.5 + 0.5*sin(omega * (time + 2*M_PI/3));
    double b = 0.5 + 0.5*sin(omega * (time + 4*M_PI/3));
    double multiplier;
    multiplier = analogRead(0) / 2.0;

    if (multiplier < 20) {
        l.stop();
        return;
    }

    float speed = (multiplier * -1);
    speed = speed + 128;
    speed = speed * (M_PI/180.0) * 100;
    if(speed > 180) speed = 180;
    if(speed < -180) speed = -180;
    l.setLEDColor(r*multiplier, g*multiplier, b*multiplier);
    l.setJointSpeeds(speed, speed, -speed);
    //l.setMotorPowers(speed, speed, -speed);
    delay(100);
    /*
    digitalWrite(8, HIGH);
    l.driveTo(0, 0, 0);
    digitalWrite(8, LOW);
    l.driveTo(90, 90, 90);
    */
}
