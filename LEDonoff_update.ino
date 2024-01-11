/*bien do am thanh*/
int min=0;
int max=80; 
int tapam=20;
void setup() {

}
void loop() {
int doc=analogRead(0);
int doc1=map(doc,min,max,0,255);
if(doc<tapam) 
{
  for(int i=1;i<=13;i++)
digitalWrite(i,HIGH);}
else {
for(int i=0;i<=13;i++)
analogWrite(i,255-doc1);
delay(200);
}



  
  
  
}
