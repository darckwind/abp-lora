//importando la libreria
#include <RAK811.h>
//parametros de coneccion
String NwkSKey = "13f2b06760260961fe16146c113cee8e";
String AppSKey = "0db9665b3a84f04cf8b3c2d9fe3e467d";
String DevAddr = "0169d837";

//tipo de coneccion 
#define JOIN_MODE ABP

//modo de trabajo
#define WORK_MODE LoRaWAN

//definiendo puertos a usar
#define ATSerial Serial;
#define DebugSerial Serial;

//dato de resteo
char* buffer ="223022";

//definiedo si confirmamamos paquetes 1 si, 0 no
int tipo = 1;

//definir puertpo de coneccion 1 a 233
int port = 1;

//comando at
String Command = ""at+version\r\n""

//diciendo los puertos a streamear en el RAK811
RAK811 RAKLoRa(DebugSerial,ATSerial);


void setup() {
  //inicio de los puertos serial
  DebugSerial.begin(115200);
  ATSerial.begin(115200);

  //obteniendo la vercion/firmware del rak811 en  un string 
  DebugSerial.println(RAKLoRa.rk_getVersion());
  delay(600);

  //obtenemos la banda en la que esta trabajando el rak811 en un string 
  DebugSerial.println(RAKLoRa.rk_getBand());
  delay(600);
  
  //Definiendo modo de trabajo del RAK811
  if(RAKLoRa.rk_setWorkingMode(WORK_MODE)){
    //Definiendo modo de transmicion ABP y setiendo los parametros pertinentes, debuelve un boleano
    if(RAKLoRa.rk.initABP(DevAddr, NwkSKey, AppSKey)){
      //ingresando a la red lora con el modo seleccionado devolviendo un boleano
      DebugSerial.println(RAKLoRa.rk_joinLoRaNetwork(JOIN_MODE));
      Serial.println("la coneccion mediante el modo seleccionado y la red definida a sido exitosa");
      }else{
        Serila.println("conexion mediant modo seleccionado fallida");
        }
    }else{
      Serial.println("Fallo en seteo modo de trabajo");
      }
}

void loop() {
  //envio de datos con los parametros tipo, puerto y dato en hex. devuelve un boleano
  DebugSerial.println(tipo,port,buffer);
  delay(600);
  //recepcion de respuesta del modulo devuelve un string con la respesta del modulo
  DebugSerial.println(RAKLoRa.rk_recvData());
  delay(600);
  
  //en caso de que se quiera enviar un comando at, solo retorna un string de la prmera linea esperada de retorno
  DebugSerial.println(RAKLoRa.sendRawCommand(Command));
  delay(600);
  
  //estadisticas de la señal de radio
  DebugSerial.println(RAKLoRa.rk_checkStatusStatistics());
  delay(600);

  //obtener info de la configuracion
  DebugSerial.println(RAKLoRa.rk_getConfig("dev_addr"));
  DebugSerial.println(RAKLoRa.rk_getConfig("apps_key"));
  DebugSerial.println(RAKLoRa.rk_getConfig("nwks_key"));
  delay(600);
}
