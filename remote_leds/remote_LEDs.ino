#include <IRremote.h>
#include <stdlib.h>

const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
const int redLED1 = 8;
const int yellowLED1 = 9;
const int greenLED = 10;
const int yellowLED2 = 11;
const int redLED2 = 12;

void setup(){
  irrecv.enableIRIn();
  // irrecv.blink13(true); deprecated(apparently -_-)
  pinMode(redLED1, OUTPUT);
  pinMode(yellowLED1, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(redLED2, OUTPUT);

}

void loop(){
  if (irrecv.decode(&results)){
    switch(results.value){
      case 0xFF30CF: //key 1
        blinkByColour();
        break;
      case 0xFF629D: //key MODE
        testPin();
        break;
      case 0xFF18E7: //key 2
        oddAndEven();
        break;
      case 0xFF7A85: //key 3
        scrolling();
        break;
      case 0xFF10EF: //key 4
        randomPins();
        break;   
    }

    irrecv.resume();
  }
}

void testPin(){
  while (true){
    digitalWrite(greenLED, HIGH);
    delay(2000);
    digitalWrite(greenLED, LOW);
    delay(1000);
    
    if (results.value != 0xFF629D)
      break;
  }
  
  
}

void blinkByColour(){
  // Red LEDs
  digitalWrite(redLED1, HIGH);
  digitalWrite(redLED2, HIGH);

  delay(1000);
  
  digitalWrite(redLED1, LOW);
  digitalWrite(redLED2, LOW);

  // Yellow LEDs
  digitalWrite(yellowLED1, HIGH);
  digitalWrite(yellowLED2, HIGH);

  delay(1000);

  digitalWrite(yellowLED1, LOW);
  digitalWrite(yellowLED2, LOW);

  // Green LEDs
  digitalWrite(greenLED, HIGH);
  
  delay(1000);
  
  digitalWrite(greenLED, LOW);

  // Yellow LEDs
  digitalWrite(yellowLED1, HIGH);
  digitalWrite(yellowLED2, HIGH);

  delay(1000);

  digitalWrite(yellowLED1, LOW);
  digitalWrite(yellowLED2, LOW);
}

void oddAndEven(){
  // Odd positions
  digitalWrite(redLED1, HIGH);
  digitalWrite(greenLED, HIGH);
  digitalWrite(redLED2, HIGH);

  delay(1000);

  digitalWrite(redLED1, LOW);
  digitalWrite(greenLED, LOW);
  digitalWrite(redLED2, LOW);

  // Even positions
  digitalWrite(yellowLED1, HIGH);
  digitalWrite(yellowLED2, HIGH);

  delay(1000);

  digitalWrite(yellowLED1, LOW);
  digitalWrite(yellowLED2, LOW);
}

void scrolling(){

  // loop from the lowest pin to the highest
  for (int pin = 8; pin < 13; pin++){
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
  }

  // loop from the highest pin to the lowest
  for (int pin = 12; pin >= 8; pin--){
    digitalWrite(pin, HIGH);
    delay(500);
    digitalWrite(pin, LOW);
  }
}

void randomPins(){
  for (int num = 0; num < 10; num++){
    int randomPin = rand() % 5 + 8;
    digitalWrite(randomPin, HIGH);
    delay(900);
    digitalWrite(randomPin, LOW);
  }
    
}
