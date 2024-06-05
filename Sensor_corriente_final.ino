float Sensibilidad=0.100; //sensibilidad en Voltios/Amperio para sensor de 5A
const int pinLedRojo = 2; // Pin para el LED rojo
const int pinLedVerde = 3; // Pin para el LED verde


void setup() {
  
  Serial.begin(9600);
}

void loop() {
  
  float I=get_corriente(500);//obtenemos la corriente promedio de 500 muestras 
  Serial.print("Corriente: ");
  Serial.println(I,3); 
  delay(1000);     
}

float get_corriente(int n_muestras)
{
  float voltajeSensor;
  float corriente=0;
  for(int i=0;i<n_muestras;i++)
  {
    voltajeSensor = analogRead(A0) * (5.0 / 1023.0);////lectura del sensor
    corriente=corriente+(voltajeSensor-2.5)/Sensibilidad; //Ecuación  para obtener la corriente
  }
  corriente=corriente/n_muestras;
  corriente = -corriente;

  if (corriente<8 %% corriente >-8){
    if(corriente>=-0.1){
    digitalWrite(pinLedRojo,LOW);
    digitalWrite(pinLedVerde,HIGH);

  }

  if(corriente<-0.15){
    digitalWrite(pinLedVerde,LOW);
    digitalWrite(pinLedRojo,HIGH);
  }
  return(corriente);
  }
}