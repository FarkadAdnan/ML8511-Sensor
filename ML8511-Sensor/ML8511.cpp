/*
  Farkad Adnan - library for ML8511 sensor

   Copyright (C) January 2024 by author=Farkad Adnan @farkadadnan

   Licensed under "get you a coffee license"

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/


#include <ML8511.h>

ML8511::ML8511( void ) : _sensorPin(0), _voltageRefPin(1) {};

ML8511::ML8511( uint8_t sensorPin, uint8_t voltageRefPin )  : _sensorPin(sensorPin), _voltageRefPin(voltageRefPin) {};

bool ML8511::begin( )
{
  pinMode(_sensorPin, INPUT);
  pinMode(_voltageRefPin, INPUT);
#ifdef DEBUG_ML8511
  char tmp[64];
    
  Serial.print(F("\n--- ML8511 -----------------------------"));
    Serial.print( F("\n\tread 3V3 reference on port: ")); Serial.print(_voltageRefPin);
    Serial.print( F("\n\tread UV sensor value on port: ")); Serial.print(_sensorPin);
  Serial.print(F("\n\tBoard 3V3 reference: "));
  Serial.print(F("\n\tVOLTAGE_TICKS: ") );  Serial.print(ML8511_VOLTAGE_TICKS);
    dtostrf( _voltageStep, 1, 8, tmp);
    Serial.print(F("\t_voltageStep: ") );  Serial.print(tmp);
    Serial.print(F(" --> "));
  Serial.println(ML8511_VOLTAGE_TICKS * _voltageStep);
  Serial.println(F("---------------------------------------"));
#endif
    
    // TODO: add code to detect sensor
    
    return true;
}

uint8_t  ML8511::error( void )
{
    return _error;
}

float  ML8511::refVoltage( void )
{
    return _refLevel; // * _voltageStep;
}

float  ML8511::uvVoltage( void )
{
    return _outputVoltage;
}

#ifdef  DEBUG_ML8511
void ML8511::debugSensor( void )
{
    char tmp[64];
    
    Serial.print( F("\nML8511 debugSensor:") );
        switch (_error) {
            case ML8511_UV_VOLTAGE_FAULT:
                Serial.print(F("Voltage value read from sensor out of bounds!"));
                break;
            case ML8511_REF_VOLTAGE_FAULT:
                Serial.print(F("3V3 Voltage value out of bounds!"));
                break;
            default:
                Serial.print(F("\tok"));
                break;
        }
    Serial.print(F("\n\tReferenz 3V3: "));
    Serial.print(_refLevel);
    Serial.print(F(" --> "));
    Serial.print(_refLevel * _voltageStep);
    Serial.print(F(" V "));
    
    //Serial.print(F(" ML8511 output: "));
    Serial.print(F(" _uvLevel: "));
    Serial.print(_uvLevel);
    Serial.print(F(" ==> _outputVoltage: "));
    Serial.print(_outputVoltage);
    
    Serial.print(F(" --> UV Intensity (mW/cm^2): "));
    Serial.print(_uvIntensity);
}
#endif


float ML8511::readSensor( void ) 
{
    _error = 0;
    _uvLevel = averageAnalogRead(_sensorPin);
  _refLevel = averageAnalogRead(_voltageRefPin);
    if (_refLevel < _voltageLow || _refLevel > _voltageHigh) {
        _error = ML8511_REF_VOLTAGE_FAULT;
        return -1.0;
    }
    
  //Use the REF_3V3 reading as a reference to get a very accurate output value from sensor
  _outputVoltage = _voltageStep * ( ML8511_VOLTAGE_TICKS / _refLevel) * _uvLevel;
    if (_outputVoltage < 0.90 || _outputVoltage > 2.8)
        _error = ML8511_UV_VOLTAGE_FAULT;

  _uvIntensity = mapfloat(_outputVoltage, 1.0, 2.8, 0.0, 15.0); //Convert the voltage to a UV intensity level

  return _uvIntensity;

}



//Takes an average of readings on a given pin
//Returns the average
int ML8511::averageAnalogRead(int pinToRead)
{
  byte numberOfReadings = 8;
  unsigned int runningValue = 0;

  for (int x = 0 ; x < numberOfReadings ; x++)
   runningValue += analogRead(pinToRead);
  runningValue /= numberOfReadings;

  return (runningValue);
}

//The Arduino Map function but for floats
//From: http://forum.arduino.cc/index.php?topic=3922.0
float ML8511::mapfloat(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

