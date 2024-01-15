int UV_OUT = A0;    
int REF_3V3 = A1;   
void setup(){
  Serial.begin(9600);
  Serial.println("ML8511 example");
}
void loop(){
  int uv_Level = analogRead_average(UV_OUT);
  int ref_Level = analogRead_average(REF_3V3);
  float output_Voltage = 3.3 / ref_Level * uv_Level;
  float uvIntensity = mapfloat(output_Voltage, 0.99, 2.8, 0.0, 15.0); 
 
  Serial.print("ML8511 output: ");
  Serial.print(uv_Level);
  Serial.print(" / ML8511 voltage: ");
  Serial.print(output_Voltage);
  Serial.print(" / UV Intensity (mW/cm^2): ");
  Serial.print(uvIntensity);
  Serial.println();
  delay(500);
}

int analogRead_average(int pinToRead){
  int NumberOfSamples = 8;
  int runningValue = 0; 

  for(int x = 0; x < NumberOfSamples; x++)
    runningValue += analogRead(pinToRead);
  runningValue /= NumberOfSamples;
  return(runningValue);
}
float mapfloat(float x, float in_min, float in_max, float out_min, float out_max){
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
