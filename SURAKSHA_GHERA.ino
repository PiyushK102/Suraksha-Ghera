// defines pins numbers
const int trigPin = 3;
const int echoPin = 2;
 
const int ledPin1 = 13;
const int ledPin2 = 12;        //////for ultrasonic sensor

// defines variables
long duration;
int distance;
int safetyDistance;


void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(8,OUTPUT);
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}


void loop() {



// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;

safetyDistance = distance;
if (safetyDistance <= 110){
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);

 
    tone(8,2550,1000);
    tone(9,2550,1000);
    tone(10,2550,1000);
    tone(11,2550,1000);
  

  
}
else{
  
  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
}

// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.print(distance);Serial.print("cm ");
Serial.println("");
delay(500);
}
