#include <RAK811.h>
#define JOIN_MODE ABP
#define WORK_MODE LoRaWAN
//parametros de coneccion
String NwkSKey = "13f2b06760260961fe16146c113cee8e";
String AppSKey = "0db9665b3a84f04cf8b3c2d9fe3e467d";
String DevAddr = "0169d837";
bool resp =false;//cambiar a true cuando se pruebe en conjunto al server
int tipo = 1; //paquetes confirmados=1
int port = 1;//puertos 1-233
char* buffer = "202030";
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
  if(RAKLoRa.rk_setWorkingMode(WORK_MODE)==0){//0 para lorawan
    delay(4000);
    DebugSerial.println("forma de trabajao LoRaWAN dude");
      if (RAKLoRa.rk_initABP(DevAddr, NwkSKey, AppSKey)==resp){
          delay(4000);
          DebugSerial.println("iniciado en abp we");
          DebugSerial.println(RAKLoRa.rk_joinLoRaNetwork(JOIN_MODE));
          DebugSerial.println("congratulation le entraste");

        }
    }
  
}

void loop() {
DebugSerial.println(RAKLoRa.sendRawCommand("at+reset=0\r\n"));
DebugSerial.println(RAKLoRa.sendRawCommand("at+version\r\n"));
DebugSerial.println(RAKLoRa.sendRawCommand("at+join=abp\r\n"));
DebugSerial.println(RAKLoRa.sendRawCommand("at+abp_info\r\n"));
DebugSerial.println(RAKLoRa.sendRawCommand("at+send=1,2,202020\r\n"));

delay(60000);
}
