#include "sensor.h"

DECLARE_SM(sensor, 0x1234);

static sensor_data SM_DATA(sensor) data;

sensor_data read_sensor_data(void)
{
    return data;
}
