const int PinSwitchReed = 2; // Pin Switch Reed
const int PinBocina =13; //Pin de bocina
const int PinLedBlanco =12; //Pin de LED
int estadoSwitch = 1;   //guarda el valor del switch reed
int frecMin = 2000; //frecuencia más baja que se va a emitir
int frecMax = 4000; //frecuencia más alta que se va a emitir 

void setup(){
    pinMode(PinSwitchReed, INPUT);
    pinMode(PinBocina, OUTPUT);
    pinMode(PinLedBlanco,OUTPUT);
    digitalWrite(PinLedBlanco, LOW);
}
/*leemos el valor del Switch Reed y lo asignamos a la variable estadoSwitch,
  si lee un 0 la bocina emite un sonido ya que la puerta se encuentra abierta.
 */
void loop(){
    estadoSwitch = digitalRead(PinSwitchReed); 
    if (estadoSwitch == 0){
      for(int i=frecMin; i<=frecMax; i++)
         tone(PinBocina,i);
      for(int i=frecMax; i<=frecMin; i++)
         tone(PinBocina,i);
         digitalWrite(PinLedBlanco, HIGH);
        delay(1000);
         digitalWrite(PinLedBlanco, LOW);
      }else{
        noTone(PinBocina);
      }
}
