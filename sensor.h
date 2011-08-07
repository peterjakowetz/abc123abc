#ifndef SENSOR_INCLUDED
#define SENSOR_INCLUDED

enum SensorValue {WHITE, GREY, BLACK};
typedef enum SensorValue SensorValue;

enum SensorPosition {SENSOR_LEFT, SENSOR_CENTRE, SENSOR_RIGHT};
typedef enum SensorPosition SensorPosition;

SensorValue readSensor(SensorPosition sensor, void* bot);




#endif
