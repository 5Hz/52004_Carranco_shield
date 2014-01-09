#include <TSL2561.h>
#include <Wire.h>
/*
Generado en Electronica 5Hz :D
codigo de prueba para el carranco shield
*/

//-----------------------------------------------------------definiciones

#define ST 6
#define temp 25.0
#define I2C_ADDRESS 0x77
TSL2561 tsl(TSL2561_ADDR_FLOAT);

//--------------------------------------------------definiciones de pines
const int analogInPin = A3;  // Analog input pin that the humidity sensor is attached to

//-------------------------------------definiciones de variables globales
const unsigned char oversampling_setting = 3; //oversamplig for measurement
  const unsigned char pressure_waittime[4] = { 5, 8, 14, 26 };
  int ac1;
  int ac2;
  int ac3;
  unsigned int ac4;
  unsigned int ac5;
  unsigned int ac6;
  int b1;
  int b2;
  int mb;
  int mc;
  int md;

//------------------------------------------------prototipos de funciones


//----------------------------------------------------------configuracion
void setup()
{
  Serial.begin(9600);
  if (tsl.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No sensor?");
    while (1);
  }
  // You can change the gain on the fly, to adapt to brighter/dimmer light situations
  //tsl.setGain(TSL2561_GAIN_0X);         // set no gain (for bright situtations)
  tsl.setGain(TSL2561_GAIN_16X);      // set 16x gain (for dim situations)
  // Changing the integration time gives you a longer time over which to sense light
  // longer timelines are slower, but are good in very low light situtations!
  tsl.setTiming(TSL2561_INTEGRATIONTIME_13MS);  // shortest integration time (bright light)
  //tsl.setTiming(TSL2561_INTEGRATIONTIME_101MS);  // medium integration time (medium light)
  //tsl.setTiming(TSL2561_INTEGRATIONTIME_402MS);  // longest integration time (dim light)
  // Now we're ready to get readings!
  
  Serial.println("***********************************************");
  Serial.println("***************Electronica 5 Hz****************");
  Serial.println("**Programa de prueba para el Carranco Shield***");
  Serial.println("***********************************************");
}

//#########################################################ciclo principal
void loop()
{
  menu();
  do{}while(Serial.available() == 0);
  switch (Serial.read())
  {
    case '1':
      Serial.println("Setting up BMP085");
      bmp085_get_cal_data();
      do{presion();}while(Serial.read() != '*');
    break;
    case '2':
      do{humedad();}while(Serial.read() != '*');
    break;
    case '3':
     // do{temperatura();}while(Serial.read() != '*');
    break;
    case '4':
      do{luminosidad();}while(Serial.read() != '*');
    break;
    default:
      Serial.println("intenta otra vez :)");
    break;
  }
}
//##################################################fin del ciclo principal


//-----------------------------------------------------------------funciones
void menu()
{
  Serial.println("Que sensor quieres probar?");
  Serial.println("1.- Presión");
  Serial.println("2.- humedad");
  Serial.println("3.- temperatura");
  Serial.println("4.- Luminosidad");
}


