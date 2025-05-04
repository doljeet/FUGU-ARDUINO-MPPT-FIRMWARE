void setup_wifi() {
  delay(10);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }
}

void Wireless_Telemetry(){
  
  ////////// WIFI TELEMETRY ////////// 
  if(enableWiFi==1){
    int LED1, LED2, LED3, LED4;                      //Declare LED brightness variable 
    if(buckEnable==1)      {LED1=200;}else{LED1=0;}  //BATTERY CHARGING STATUS
    if(batteryPercent>=99 ){LED2=200;}else{LED2=0;}  //FULL CHARGE STATUS
    if(batteryPercent<=10) {LED3=200;}else{LED3=0;}  //LOW BATTERY STATUS
    if(IUV==0)             {LED4=200;}else{LED4=0;}  //PV INPUT PRESENCE STATUS

  if (!client.connected()) {
    client.connect("ESP32_PV", mqtt_user, mqtt_password);
  }
  client.loop();

  char buf[16];

  dtostrf(powerInput, 1, 2, buf);
  client.publish("pv/powerInput", buf);

  dtostrf(batteryPercent, 1, 2, buf);
  client.publish("pv/batteryPercent", buf);

  dtostrf(voltageInput, 1, 2, buf);
  client.publish("pv/voltageInput", buf);

  dtostrf(currentInput, 1, 2, buf);
  client.publish("pv/currentInput", buf);

  dtostrf(voltageOutput, 1, 2, buf);
  client.publish("pv/voltageOutput", buf);

  dtostrf(currentOutput, 1, 2, buf);
  client.publish("pv/currentOutput", buf);

  dtostrf(temperature, 1, 2, buf);
  client.publish("pv/temperature", buf);

  dtostrf(Wh / 1000.0, 1, 2, buf);
  client.publish("pv/energy_kWh", buf);

  dtostrf(energySavings, 1, 2, buf);
  client.publish("pv/energySavings", buf);


  }
} 
