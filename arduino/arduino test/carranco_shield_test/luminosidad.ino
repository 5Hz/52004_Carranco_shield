//TSL2560

void luminosidad()
{
    // Simple data read example. Just read the infrared, fullspecrtrum diode 
    // or 'visible' (difference between the two) channels.
    // This can take 13-402 milliseconds! Uncomment whichever of the following you want to read
    //uint16_t x = tsl.getLuminosity(TSL2561_VISIBLE);     
    //uint16_t x = tsl.getLuminosity(TSL2561_FULLSPECTRUM);
    //uint16_t x = tsl.getLuminosity(TSL2561_INFRARED);
    
    //Serial.println(x, DEC);
  
    // More advanced data read example. Read 32 bits with top 16 bits IR, bottom 16 bits full spectrum
    // That way you can do whatever math and comparions you want!
    uint32_t lum = tsl.getFullLuminosity();
    uint16_t ir, full;
    ir = lum >> 16;
    full = lum & 0xFFFF;
    Serial.print("IR: "); Serial.print(ir);   Serial.print("\t\t");
    Serial.print("Full: "); Serial.print(full);   Serial.print("\t");
    Serial.print("Visible: "); Serial.print(full - ir);   Serial.print("\t");
    
    Serial.print("Lux: "); Serial.println(tsl.calculateLux(full, ir));
    
    delay(250); 
}

