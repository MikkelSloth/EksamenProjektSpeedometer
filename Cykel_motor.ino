void setup() {
  // put your setup code here, to run once:
pinMode(3, INPUT);
pinMode(9,OUTPUT); 
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
Serial.begin(9600);
}
float pi  = 3.1415; // Konstanten pi
float delta_d = 2 * pi / 20; // distancen mellem to pinde i enheden radianer
float hjul_radius = 0.26; //meter
float hast_thresh = 6.5; //Kilometer i timen

float v = 0; // Initiel Hastighed

int before = 0; // Initalisering af Første stadie!
long t_prev = millis(); // Initialisering af første forrige tid.
long t, delta_t;
int result;

void loop() {
  // put your main code here, to run repeatedly:

int sensorValue = analogRead(A0);
//Serial.println(sensorValue); //test slidermonitor

int sensorValue2 = digitalRead(3);
Serial.println(sensorValue2); //test sensoren
int now = sensorValue2;
if(now != before){ // Hvis der er en ændring i SensorValue2 (Både op og ned)!
  if(now > 0){ // Hvis der er en positiv ændring
    //Tidsregning
    t = millis(); // Mål aktuel tid ved den positive ændring
    delta_t = t - t_prev; // Udregning af forskellen mellem den aktuelle tid og den forrige tid for positiv ændring
    t_prev = t; // Aktuel tid bliver til forrige tid!

    //Hastighedsudregning
    v = delta_d / delta_t; //  radian/ms
    v = v * hjul_radius * 1000; // m/s
    v = v * 3.6; // km/t
  }
}
before = now; // Nuværende stadie bliver gamle stadie

int val = map(sensorValue, 0, 1023, 0, 255);

digitalWrite(9,HIGH);
digitalWrite(10,LOW); //retning motor
analogWrite(11,val); //speed motor

if(v > hast_thresh) // Hvis hastighed er for høj
{
  analogWrite(11,0); // Slukker for motoren
}
else
{
   analogWrite(11,val); //speed motor
}
}
