#include <RAK811.h>
#include <LiquidCrystal.h>  

#define JOIN_MODE ABP
#define WORK_MODE LoRaWAN
//parametros de coneccion
String NwkSKey = "13f2b06760260961fe16146c113cee8e";
String AppSKey = "0db9665b3a84f04cf8b3c2d9fe3e467d";
String DevAddr = "0169d837";
#define ATSerial Serial
#define DebugSerial Serial

RAK811 RAKLoRa(ATSerial,DebugSerial);
void setup() {
  DebugSerial.begin(115200);
  DebugSerial.print("inicio");
  ATSerial.begin(115200);
  DebugSerial.println(RAKLoRa.rk_getVersion());
  delay(600);
  DebugSerial.println(RAKLoRa.rk_getBand());
  delay(600);
  if(RAKLoRa.rk_setWorkingMode(WORK_MODE)==0){
    delay(4000);
    DebugSerial.println("forma de trabajao LoRaWAN dude");
      if (RAKLoRa.rk_initABP(DevAddr, NwkSKey, AppSKey)){
          delay(4000);
          DebugSerial.println("ABP network");
          DebugSerial.println(RAKLoRa.rk_joinLoRaNetwork(JOIN_MODE));
          DebugSerial.println("ya entraste dude");

        }
    }
  
}

void loop() {
DebugSerial.println(RAKLoRa.rk_getVersion());
DebugSerial.println(RAKLoRa.rk_getBand());
DebugSerial.println(RAKLoRa.rk_setWorkingMode(WORK_MODE));
DebugSerial.println(RAKLoRa.rk_joinLoRaNetwork(JOIN_MODE));
DebugSerial.println(RAKLoRa.rk_sendData(1,2,"2323"));
DebugSerial.println(RAKLoRa.rk_recvData());
}
