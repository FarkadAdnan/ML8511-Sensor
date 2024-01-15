/*
   Klaus Lenssen - library for ML8511 sensor

   Copyright (C) January 2016 by Klaus Lenssen

   Licensed under "get you a coffee license"

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

//#define DEBUG_ML8511 1

#ifndef _ML8511_SENSOR_H
#define _ML8511_SENSOR_H


#if ARDUINO >= 100
#include "Arduino.h"
//#include "Print.h"
#else
#include "WProgram.h"
#endif

#define ML8511_REF_VOLTAGE_FAULT    1
#define ML8511_UV_VOLTAGE_FAULT     2

class ML8511 
{
  public: 
    ML8511( void );
    ML8511( uint8_t sensorPin, uint8_t voltageRefPin );

    bool begin( void );
    float readSensor( void );
    float refVoltage( void );
    float uvVoltage( void );
    uint8_t  error( void );
    
#ifdef DEBUG_ML8511
#warning ML8511 debug code active
    void debugSensor( void );
#endif
    
  private:
    int averageAnalogRead(int pinToRead);
    float mapfloat(float x, float in_min, float in_max, float out_min, float out_max);
    
    // ML8511 UV sensor pin definitions
    uint8_t _sensorPin = 0;       //Output from the sensor --> default A0
    uint8_t _voltageRefPin = 1;   //3.3V power reference on the Arduino board --> A1

    uint16_t  _uvLevel;
    uint16_t  _refLevel;
    uint8_t   _error;
    float     _uvIntensity;
    float   _outputVoltage;

    // ADC Voltage constants
    // reference Voltage of my DCcduino UNO is 3.44V = 676 reading on Pin A1
    #define ML8511_REFERENCE_VOLTAGE (3.44)
    #define ML8511_VOLTAGE_TICKS 676

    float     _voltageStep  = ML8511_REFERENCE_VOLTAGE / ML8511_VOLTAGE_TICKS;
    uint16_t    _voltageLow = ML8511_VOLTAGE_TICKS * 0.95;
    uint16_t    _voltageHigh = ML8511_VOLTAGE_TICKS * 1.05;
};


#endif    // _ML8511_SENSOR_H
