# abp-lora RAK811 v1.1
### Previous steps
1. Include the library from this repo.
2. Note that the main function has a 10 sec delay embedded in the library's code (because the RAK811 has to communicate with the lora server or any kind of service you use).
3. Restart the RAK811 once the code has been uploaded to the arduino.
4. Feel you free to use this code as you want.
 ### RAK811 configuration</br> 
Set the jumpers between the pins
 * CRX => TXD and CTX => RXD
 * 5_3R => TDX and 5_3T => RDX
 <img src="https://i.pinimg.com/originals/12/7e/47/127e4726e179b56442707227bc176cf2.jpg" alt="IMAGE ALT TEXT HERE" width="240" height="180" border="10" />
