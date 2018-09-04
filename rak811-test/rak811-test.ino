#include <RAK811.h>
#define JOIN_MODE ABP
#define WORK_MODE LoRaWAN
//parametros de coneccion
String NwkSKey = "tu-clave";
String AppSKey = "tu-clave";
String DevAddr = "tu-direccion-de dispositivo";
bool resp =true;//cambiar a true cuando se pruebe en conjunto al server
int tipo = 1; //paquetes confirmados=1
int port = 1;//puertos 1-233
char* buffer = "72616B776972656C657373";
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

Serial.println("vercion");
DebugSerial.println(RAKLoRa.rk_getVersion());
Serial.println("banda ");
DebugSerial.println(RAKLoRa.rk_getBand());
Serial.println("modo de trabajo");
DebugSerial.println(RAKLoRa.rk_setWorkingMode(WORK_MODE));
Serial.println("tipo de red");
DebugSerial.println(RAKLoRa.rk_joinLoRaNetwork(JOIN_MODE));
//envio de datos
DebugSerial.println(RAKLoRa.rk_sendData(tipo,port,buffer));
//envio de datos
DebugSerial.println(RAKLoRa.rk_recvData());
}
