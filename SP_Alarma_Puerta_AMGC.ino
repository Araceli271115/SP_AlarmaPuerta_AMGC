#include "LowPower.h"
const int PinBocina =13; //Pin de bocina
const int PinLedBlanco =12; //Pin de LED
const int PinSwitchReed = 2; // Pin Switch Reed
int frecMin = 100; //frecuencia más baja que se va a emitir
int frecMax = 200; //frecuencia más alta que se va a emitir 

void setup(){
    pinMode(PinSwitchReed, INPUT);
    pinMode(PinBocina, OUTPUT);
    pinMode(PinLedBlanco,OUTPUT);
    digitalWrite(PinLedBlanco, LOW);
    digitalWrite(PinBocina, LOW);
    
    attachInterrupt(digitalPinToInterrupt(2),interrupcionAlarma,LOW);

   }
/*leemos el valor del Switch Reed y lo asignamos a la variable estadoSwitch,
  si lee un 0 la bocina emite un sonido y prende el led ya que la puerta se encuentra abierta.
  Ambos for hacen que la bocina emita un sonido en diferentes frecuencias

  El arduino siempre estará en bajo consumo de energia hasta que la puerta se abra este realizara una interrupcion
 */
void loop(){
 /* miestras no se abra la puerta entonces que el arduino se encuentra en un modo de consumo de energia minimo 
    mediante la funcion powerDown en donde le indicamos que duerma indefinidamente mientras no se presente una interrupcion 
    de hardware*/
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); 
    
}
/*definición de interrupcion de hardwareque se genera cuando la puerta esta habierta emite una alarma mediante la bocina 
 * y prende y apaga el led
 */
void interrupcionAlarma(){

 for(int i=frecMax; i<=frecMin; i++)
         tone(PinBocina,i);
         digitalWrite(PinLedBlanco, HIGH);
         delay(10000);
         digitalWrite(PinLedBlanco, LOW); 
         noTone(PinBocina);
  
}
