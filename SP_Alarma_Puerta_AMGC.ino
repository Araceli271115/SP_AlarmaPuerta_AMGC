const int PinSwitchReed = 2; // Pin Switch Reed
const int PinBocina =13; //Pin de bocina
int estadoSwitch = 1;   //guarda el valor del switch reed
int frecuencia=220;

void setup(){
    pinMode(PinSwitchReed, INPUT);
}
/*leemos el valor del Switch Reed y lo asignamos a la variable estadoSwitch,
  si lee un 0 la bocina emite un sonido ya que la puerta se encuentra abierta.
 */
void loop(){
    estadoSwitch = digitalRead(PinSwitchReed); 
    if (estadoSwitch == 0){
     tone(PinBocina, frecuencia);
      }else{
        noTone(PinBocina);
      }
}
