#ifndef speedometer_h
#define speedometer_h

class Speedometer {

public:

enum measurementSystem {Imperial, Metric};
static const measurementSystem imperial = Imperial;
static const measurementSystem metric = Metric;
void init(double tireDiameter, measurementSystem measurement);
int getSpeed();
double getDistance();
void update();
void nextTick(long currentMilliseconds);

private:

measurementSystem measurement;
long currentMilliseconds, previousMilliseconds, elapsedMilliseconds;
int mph, kph;
double miles, kilometers, tireDiameter, circumference, revolutions;
static constexpr double Pi = 3.14159265359;

void setSpeed(int speed);
void setDistance(double distance);
};
#endif