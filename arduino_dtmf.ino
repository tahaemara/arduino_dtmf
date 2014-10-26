///////////////////
/// Taha Emara
/// Youtube Channel : http://www.youtube.com/user/omar0103637
/// Facebook Page : https://www.facebook.com/IcPublishes
///////////////////
const int StD=0;  //int 0 on digital pin 2   
//Delayed Steering (Output).Presents a logic high when a received tone-pair has been 
//registered and the output latch updated
int key;      //key represents the pressed key 
int numberToCheck=9;   
int led = 13;  //this pin goes to high if arduino receives code of 9 "1001" on pins
const int pins[4]={8,9,10,11};  // inputs to arduino from dtmf -MT8870- Q1,Q2,Q2 and Q4
///////////////////
void setup()
{
  Serial.begin(9600);
  attachInterrupt(StD,dtmf_decode,RISING);
  for(int i=0;i<4;i++)
  pinMode(pins[i],INPUT);            
}
///////////////////
void loop()
{
  if(key==numberToCheck)//assign the value on pressing which you want the led to blink
  {
    digitalWrite(led, HIGH);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
///////////////////
void dtmf_decode()
{
  key=0;
  for(int i=0;i<4;i++)
  key+=digitalRead(pins[i])<<i;      
  Serial.println(key);
}
