int LS1 = 6; 
int LS2 = 5; 
int CS = 4; 
int RS1 = 3; 
int RS2 = 2; 
int ENA = 10; //speed motor a

int M_A1 = 7; //motor a = +

int M_A2 = 8; //motor a = -

int M_B1 = 9; //motor b = -

int M_B2 = 12; //motor b = +

int ENB = 11; //speed motor b
int speedCar = 160;         // 400 - 1023.
  int speed_Coeff = 2.2 ;
int speed_Coeff1=1.2 ;

void setup()
{
  Serial.begin(9600);
  pinMode(LS1,INPUT);
   pinMode(LS2,INPUT);
    pinMode(CS,INPUT);
     pinMode(RS1,INPUT);
      pinMode(RS2,INPUT);
}
void loop()
{
pinMode(M_B1, OUTPUT);
pinMode(M_B2, OUTPUT);
pinMode(M_A1, OUTPUT);
pinMode(M_A2, OUTPUT);

pinMode(ENB, OUTPUT);
pinMode(ENA, OUTPUT);

//analogWrite(ENA, 110);
//analogWrite(ENB, 110);

int  ls1=digitalRead(LS1);
  int ls2=digitalRead(LS2);
   int cs=digitalRead(CS);
    int rs1=digitalRead(RS1);
     int   rs2=digitalRead(RS2);
      Serial.print(ls1);
      Serial.print("  ");
      Serial.print(ls2);
      Serial.print("  ");
      Serial.print(cs);
      Serial.print("  ");
      Serial.print(rs1);
      Serial.print("  ");
      Serial.print(rs2);
      Serial.println("  ");
      //delay(200);
      if(ls1==1&&ls2==1&&cs==0&&rs1==1&&rs1==1){forword();}
       if(ls2==0&&cs==0&&rs1==1){SturnLeft();}
        if(ls1==1&&ls2==1&&cs==1&&rs1==1&&rs2==0){turnRight();}
        if(ls2==0&&cs==1&&rs1==1){turnLeft();}
         if(ls2==1&&cs==0&&rs1==0){SturnRight();}
         if(ls1==0&&ls2==1&&cs==1&&rs1==1&&rs2==1){turnLeft();}
          if(ls2==1&&cs==1&&rs1==0){turnRight();}
           if(ls1==1&&ls2==1&&cs==1&&rs1==1&&rs2==1){backword();}
            if(ls2==0&&cs==0&&rs1==0||ls1==0&&ls2==0&&cs==0&&rs1==0&&rs2==0){forword();}
}
void forword(){
analogWrite(ENA, speedCar);
analogWrite(ENB, speedCar);
digitalWrite(M_A1, HIGH);

digitalWrite(M_A2, LOW);

digitalWrite(M_B1, HIGH);

digitalWrite(M_B2, LOW);
}
void SturnRight(){
  analogWrite(ENA, speedCar/speed_Coeff1);
analogWrite(ENB, speedCar/speed_Coeff1);

digitalWrite(M_A1, LOW);

digitalWrite(M_A2, HIGH);

digitalWrite(M_B1, HIGH);

digitalWrite(M_B2, LOW);

}

void turnRight(){
  analogWrite(ENA, speedCar/speed_Coeff1);
analogWrite(ENB, speedCar/speed_Coeff1);

digitalWrite(M_A1, LOW);

digitalWrite(M_A2, LOW);

digitalWrite(M_B1, HIGH);

digitalWrite(M_B2, LOW);

}

void SturnLeft(){
analogWrite(ENA, speedCar/speed_Coeff1);
analogWrite(ENB, speedCar/speed_Coeff1);
digitalWrite(M_A1, HIGH);

digitalWrite(M_A2, LOW);

digitalWrite(M_B1, LOW);

digitalWrite(M_B2, HIGH);

}

void turnLeft(){
analogWrite(ENA, speedCar/speed_Coeff1);
analogWrite(ENB, speedCar/speed_Coeff1);
digitalWrite(M_A1, HIGH);

digitalWrite(M_A2, LOW);

digitalWrite(M_B1, LOW);

digitalWrite(M_B2, LOW);

}

void backword(){
analogWrite(ENA, speedCar/speed_Coeff);
analogWrite(ENB, speedCar/speed_Coeff);
digitalWrite(M_A1, LOW);

digitalWrite(M_A2, HIGH);

digitalWrite(M_B1, LOW);

digitalWrite(M_B2, HIGH);
}
