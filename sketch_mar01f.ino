  #define echo 16
  #define trigger 15
  float cm = 0;

  int ports[3] = {32, 33, 26} //Puertos del MCU
 
  void setup() 
  {
    for (int i = 0; i < 3; i++)
    {
      pinMode(ports[i], OUTPUT);
    }
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);
    digitalWrite(trigger, LOW);//Inicializamos el pin con 0
    Serial.begin(115200);
  }

  long readUltrasonicDistance(int triggerPin, int echoPin)
  {
    digitalWrite(triggerPin, LOW);
    delayMicroseconds(2);
    digitalWrite(triggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(triggerPin, LOW);
    pinMode(echoPin, INPUT);
    return pulseIn(echoPin, HIGH); //Se devolvera el tiempo entre el envio y la recepcion
  }

  void measureDistance(float cm)
  {
    if (cm > 0 && cm <= 30)
    {
        digitalWrite(ports[0], HIGH);
        delay(200); 
        digitalWrite(ports[0], LOW);
    }
    else if (cm > 30 && cm <= 60)
    {
        digitalWrite(ports[1], HIGH);
        delay(200); 
        digitalWrite(ports[1], LOW);
    }
  
    else if  (cm > 60 && cm <= 100)
    {
        digitalWrite(ports[2], HIGH);
        delay(200); 
        digitalWrite(ports[2], LOW);
    }
  }

  void loop() 
  {
    cm = 0.01723 * readUltrasonicDistance(trigger,echo); //se calculara la distancia multiplicando la velocidad en la que el sonido recorre un centimetro por el tiempo de rebote obtenido.
    Serial.print("Distancia: ");
    measureDistance(cm);
    Serial.print(cm);
    Serial.println("cm");
  }
  

  
