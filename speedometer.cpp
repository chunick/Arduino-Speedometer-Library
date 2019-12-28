#include "speedometer.h"

void Speedometer::init(double tireDiameter, Speedometer::measurementSystem ms)
{
   measurement = ms;
   this->tireDiameter = tireDiameter;
   circumference = Pi * tireDiameter;
   currentMilliseconds = 0;
   previousMilliseconds = 0;
   elapsedMilliseconds = 0;
   mph = 0;
   kph = 0;
   miles = 0;
   kilometers = 0;
   revolutions = 0;
}

int Speedometer::getSpeed() 
{
   if (measurement == Imperial)
   {
      return mph;
   } else {
      return kph;
   }
}

double Speedometer::getDistance() 
{
   if (measurement == Imperial)
   {
      return miles;
   } else {
      return kilometers;
   }
}

void Speedometer::setSpeed(int speed)
{
   if  (measurement == Imperial)
   {
      mph = speed;
   } else {
      kph = speed;
   }
}

void Speedometer::setDistance(double distance)
{
   if  (measurement == Imperial)
   {
      miles = distance;
   } else {
      kilometers = distance;
   }
}

void Speedometer::update()
{
   // update revolutions counter
   revolutions += 1;
   // find out how much time elapsed since last full rotation and update previousMilliseconds
   elapsedMilliseconds = currentMilliseconds - previousMilliseconds;
   previousMilliseconds = currentMilliseconds;
   // calculate Imperial speed and distance or Metric speed and distance
   if (measurement == Imperial)
   {
      setSpeed((long)(((((circumference * 1000) / (double)elapsedMilliseconds) / 12) * 3600) / 5280));
      setDistance((revolutions * circumference) / 12.0 / 5280.0);
   } else {
      setSpeed((long)((circumference / elapsedMilliseconds) * 36));
      setDistance(kilometers = (revolutions * circumference) / 100000);
   }
}

void Speedometer::nextTick(long currentMilliseconds)
{
   this->currentMilliseconds = currentMilliseconds;
   // if a rotation has not occurred in the last five seconds, it is safe to assume that the
   // vehicle is traveling less than 1mph/kph, so set the speed to 0
   if (currentMilliseconds - previousMilliseconds >= 5000) 
   {
      setSpeed(0);
   }
}