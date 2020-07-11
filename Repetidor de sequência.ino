
  int bPlayPause = 12;
  int bRecord = 11;
  int bTap = 10;

  int sRele = 9;
  int sBlue = 7;
  int sGreen = 6;
  int sRed = 5;
  int sRec = 4;

  int onOff = 0;

  int block = 0;

  int playLoop = 0;
  
  int recOn = 0;

  int cont = 0;

  int arrayTamanho = 0;

  int gravacao[910];

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  
  Serial.begin(9600);
  
  pinMode(bPlayPause, INPUT);
  pinMode(bRecord, INPUT);
  pinMode(bTap, INPUT);

  pinMode(sRele, OUTPUT);
  pinMode(sBlue, OUTPUT);
  pinMode(sGreen, OUTPUT);
  pinMode(sRed, OUTPUT);

  digitalWrite(sRele, LOW);
}

// the loop function runs over and over again forever
void loop() {

     Serial.println(digitalRead(bTap));

if (block <= 0){
  if(onOff == 0 and playLoop == 0){
      digitalWrite(sBlue, HIGH);
      digitalWrite(sGreen, LOW);
       digitalWrite(sRele, HIGH);
      
      if(digitalRead(bPlayPause) == 0){
      onOff = 1;
      block = 10;
      }
    }
    else if(playLoop == 0){
      digitalWrite(sGreen, HIGH);
      digitalWrite(sBlue, LOW);
      
      if(digitalRead(bPlayPause) == 0){
      onOff = 0;
      block = 10;
      }

      if (cont <= arrayTamanho){
        cont = cont + 1;

         if (gravacao[cont] == 0){
          digitalWrite(sRele, LOW);
          }
          else{
           digitalWrite(sRele, HIGH);
          }
        }
      else{
        cont = 0;
        }
   }
      

  if(recOn == 0){
    digitalWrite(sRed, LOW);
    if(digitalRead(bRecord) == 0){
      recOn = 1;
      playLoop = 1;
      block = 10;
      cont = 0;
    }
  }
  else{
    digitalWrite(sBlue, LOW);
    digitalWrite(sGreen, LOW);
    digitalWrite(sRed, HIGH);

    digitalWrite(sRele, HIGH);
    if(digitalRead(bRecord) == 0){
      recOn = 0;
      playLoop = 0;
      block = 10;

      arrayTamanho = cont;
      cont = 0;
    }
      cont = cont + 1;
      
      gravacao[cont] = digitalRead(bTap);
    }
}

  block = block - 1;
  delay(25);                       // wait for a second
}
