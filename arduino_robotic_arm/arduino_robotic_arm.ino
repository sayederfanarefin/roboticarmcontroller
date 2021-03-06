#include <Servo.h>


Servo base1,base2,arm,shoulder,wrist,claw;

int base1_deg=55;
int base2_deg=130;
int arm_deg=0;
int shoulder_deg=0;
int wrist_deg=0;
int claw_deg = 0;

int base1_deg_new=0;
int base2_deg_new=180;
int arm_deg_new=0;
int shoulder_deg_new=0;
int wrist_deg_new=0;
int claw_deg_new = 0;



void setup() {
  base1.attach(8);
  base2.attach(11);
  arm.attach(9);
  shoulder.attach(10);
  //wrist.attach(7);
  claw.attach(6);

    base1.write(base1_deg);
    base2.write(base2_deg);
    arm.write(arm_deg);
    shoulder.write(shoulder_deg);
   //wrist.write(wrist_deg);
   claw.write(claw_deg);
   
  Serial.begin(9600);
}

void loop() {
  
  if(Serial.available()>0){

      String base1_str  = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this
    
    String base2_str = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this

    String shoulder_str = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this

    String arm_str = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this

    String wrist_str = Serial.readStringUntil(',');
    Serial.read(); //next character is comma, so skip it using this
    
    String claw_str = Serial.readStringUntil(',');
    Serial.read();
    
    
    String token = Serial.readStringUntil('\0');

    base1_deg_new = base1_str.toInt();
    base2_deg_new = base2_str.toInt();
    arm_deg_new = arm_str.toInt();
    wrist_deg_new = wrist_str.toInt();
    shoulder_deg_new = shoulder_str.toInt();
    claw_deg_new = claw_str.toInt();

    /*
    //1,45,678,3,09,67
    Serial.println(base1_deg);
    Serial.println(base2_deg);
    Serial.println(shoulder_deg);
    Serial.println(arm_deg);
    Serial.println(wrist_deg);
    Serial.println(claw_deg);
    */

    if(base1_deg != base1_deg_new && base2_deg != base2_deg_new ){

      base1_deg = base1_deg_new;
      base2_deg = base2_deg_new;
      
       base1.write(base1_deg);
       base2.write(base2_deg);
       delay(10);
    }

   
    if(arm_deg != arm_deg_new ){

      if(arm_deg < arm_deg_new){
        while(arm_deg <= arm_deg_new){
          arm_deg++;
          arm.write(arm_deg);
          delay(10);
        }
      }else if(arm_deg > arm_deg_new){
        while(arm_deg >= arm_deg_new){
          arm_deg--;
          arm.write(arm_deg);
          delay(10);
        }
      }
      arm_deg = arm_deg_new;

    }

   if(shoulder_deg != shoulder_deg_new ){

      if(shoulder_deg < shoulder_deg_new){
        while(shoulder_deg <= shoulder_deg_new){
          shoulder_deg++;
          shoulder.write(shoulder_deg);
          delay(10);
        }
      }else if(shoulder_deg > shoulder_deg_new){
        while(shoulder_deg >= shoulder_deg_new){
          shoulder_deg--;
          shoulder.write(shoulder_deg);
          delay(10);
        }
      }
      shoulder_deg = shoulder_deg_new;
    }
    
    wrist.write(wrist_deg);

    if(claw_deg != claw_deg_new ){

      if(claw_deg < claw_deg_new){
        while(claw_deg <= claw_deg_new){
          claw_deg++;
          claw.write(claw_deg);
          delay(10);
        }
      }else if(claw_deg > claw_deg_new){
        while(claw_deg >= claw_deg_new){
          claw_deg--;
          claw.write(claw_deg);
          delay(10);
        }
      }
      claw_deg = claw_deg_new;
    }
    
    //send the token 
    Serial.println(token);
  }
   
}
