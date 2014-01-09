//HIH-5030

void humedad() {
    //reemplazar por temperatura dada por el otro sensor
    //sensors.requestTemperatures(); // Send the command to get temperatures
    //temp = sensors.getTempCByIndex(0); // Why "byIndex"? You can have more than one IC on the same bus. 0 refers to the first IC on the wire
    // read the analog in value:
    float sensorValue = analogRead(analogInPin);            
    // map it to the range of the analog out:
    //  outputValue = map(sensorValue, 0, 1023, 0, 255);  
    // change the analog out value:
  
    float RH=((sensorValue/1024.0)-0.1515)/0.00636;
    float TrueRH = (RH)/(1.0546-0.00216*temp);
   // for (int i=0; i <= barras; i++)
   // Serial.print("-");
    Serial.print(" ");
    Serial.print("RH = " );                       
    Serial.print(RH);
    Serial.print("%     Temp = " );                       
    Serial.print(temp); 
    Serial.print("C     True RH = " );                       
    Serial.print(TrueRH);   
    Serial.print("%    output = ");      
    Serial.println(sensorValue);   
    delay(1000);
}
