// all pins
int fl_dir = 46; // 7
int fr_dir = 40; // 4
int bl_dir = 4;
int br_dir = 7;
int fr_pwm = 12;
int fl_pwm = 10;  // pwm 12 10 for ek cytron and 8 5 pwm for dusra cytron
int bl_pwm = 5; 
int br_pwm = 8;


// rack 
//int rack_dir = 15;
//int rack_pwm = 3;
//int rackSpeed=80;


void setup() {
  // put your setup code here, to run once:
 
pinMode(fl_dir,OUTPUT);
pinMode(fr_dir,OUTPUT);
pinMode(bl_dir,OUTPUT);
pinMode(br_dir,OUTPUT);
pinMode(fl_pwm,OUTPUT);
pinMode(fr_pwm,OUTPUT);
pinMode(bl_pwm,OUTPUT);
pinMode(br_pwm,OUTPUT);
Serial.begin(115200);


// rack 
pinMode(rack_dir,OUTPUT);
pinMode(rack_pwm,OUTPUT);

}

void Speed(int val1,int val2,int val3,int val4){
  analogWrite(fl_pwm,val1);
  analogWrite(fr_pwm,val2);
  analogWrite(bl_pwm,val3);
  analogWrite(br_pwm,val4);
}


void Stop(){
  analogWrite(fl_pwm,0);
  analogWrite(fr_pwm,0);
  analogWrite(bl_pwm,0);
  analogWrite(br_pwm,0);
}

// all the fucking variables 
int hat_up,hat_down,hat_left,hat_right,up,down,left,right,start,back,front_left,front_right,left_x,left_y,right_x,right_y,lt1,rt1,left_x_dir,left_y_dir,right_x_dir,right_y_dir;

void Digitest(){
  if(hat_up == 1){
  // digitalWrite(fl_pwm,HIGH);
  Forward();
Speed(100, 100,100,100);
  }
  else if(hat_up == 0){
  Stop();}
  //digitalWrite(fl_pwm,LOW);
   if(hat_down == 1){
   //digitalWrite(fr_pwm,HIGH);
   Backward();
   Speed(100,100,100,100);
   }
  if(hat_down == 0){
  Stop();}
  //digitalWrite(fr_pwm,LOW);

    if(hat_left == 1){
   //digitalWrite(bl_pwm,HIGH);
   SideWayLeft();
   Speed(100,100,100,100);
    }
  if(hat_left == 0){
  Stop();}
  //digitalWrite(bl_pwm,LOW);

  if(hat_right == 1){
   //digitalWrite(br_pwm,HIGH);
   SideWayRight();
   Speed(100,100,100,100);}
 if(hat_right == 0){
  Stop();}
  //digitalWrite(br_pwm,LOW);
}

int range_map(int s){
   int val = s - '0';
   if(0<=val && val<= 6 ){
    return map(val,0,6,0,200);
   }
   else{
    return map(val,7,9,205,255);
   }
}

  void North_West(int val_north, int val_west){
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,HIGH);
    analogWrite(fl_pwm,0);
    analogWrite(br_pwm,0);
    analogWrite(fr_pwm,val_north);
    analogWrite(bl_pwm,val_west);
  }

    void North_East(int val_north, int val_east){
    digitalWrite(fl_dir,HIGH);
    digitalWrite(br_dir,HIGH);
    analogWrite(fr_pwm,0);
    analogWrite(fr_pwm,0);
    analogWrite(bl_pwm,0);
    analogWrite(fl_pwm,val_north);
    analogWrite(br_pwm,val_east);
  }

    void South_West(int val_north, int val_west){
    digitalWrite(fl_dir,LOW);
    digitalWrite(br_dir,LOW);
    analogWrite(fr_pwm,0);
    analogWrite(bl_pwm,0);
    analogWrite(fl_pwm,val_north);
    analogWrite(br_pwm,val_west);
  }

    void South_East(int val_north, int val_west){
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,LOW);
    analogWrite(fl_pwm,0);
    analogWrite(br_pwm,0);
    analogWrite(fr_pwm,val_north);
    analogWrite(bl_pwm,val_west);
  }

  void Forward(){
    digitalWrite(fl_dir,LOW);
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,LOW);
    digitalWrite(br_dir,LOW);    
  }
void Backward(){
    digitalWrite(fl_dir,HIGH);
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,HIGH);
    digitalWrite(br_dir,HIGH);
}

 void SideWayRight(){
    digitalWrite(fl_dir,HIGH);
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,LOW);
    digitalWrite(br_dir,HIGH);
 }

 void SideWayLeft(){
    digitalWrite(fl_dir,LOW);
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,HIGH);
    digitalWrite(br_dir,LOW);
 }

void ClockWise(){
    digitalWrite(fl_dir,LOW);
    digitalWrite(fr_dir,HIGH);
    digitalWrite(bl_dir,LOW);
    digitalWrite(br_dir,HIGH);
    Speed(180,180,180,180);
}

void AntiClockWise(){
     digitalWrite(fl_dir,HIGH);
    digitalWrite(fr_dir,LOW);
    digitalWrite(bl_dir,HIGH);
    digitalWrite(br_dir,LOW);
    Speed(180,180,180,180);
}
void loop() {
  // put your main code here, to run repeatedly:

  // MAGIC FUNCTION 
int s[22];
  int i=0;
  while(1){
  if(Serial.available()){
  s[i] = Serial.read(); 
//  Serial.print(s[i]);
  if(s[i]==110){
    i=-1;
  }
  i++;
  if(i==0){
    break;
  }
  if(i>=22){
    i=0;
    break;
  }

  }
  }
  // all the buttons 
  hat_up = s[0] - '0';
  hat_down = s[1] - '0';
  hat_left = s[2] - '0';
  hat_right = s[3] - '0';
  left = s[4] - '0';
  down = s[5] - '0';
  left = s[6] - '0';
  right = s[7] - '0';
  front_right = s[8] - '0';
  front_left = s[9] - '0';
  up = s[10] - '0';
  //front_right = s[11] - '0';
  left_x_dir = s[18] - '0';
  left_y_dir = s[19] - '0';
  right_x_dir = s[20] - '0';
  right_y_dir = s[21] - '0';

  
 // all the axis 

// ALL THY MOVEMENT LOGIC .....
if((left_x_dir==1) && (left_y_dir==1) && (right_x_dir==1) && (right_y_dir==1))
{
  
  analogWrite(fl_pwm,0);
  analogWrite(fr_pwm,0);
  analogWrite(bl_pwm,0);
  analogWrite(br_pwm,0);
  
}
/*
if((left_x_dir == 0) && (left_y_dir==0)),
int val_west = range_map(s[12]);//map((s[12]-'0'),0,9,0,255);
   North_West(val_north,val_west);
}
if((left_x_dir == 2) && (left_y_dir==0)){
   int val_north = range_map(s[13]);//map((s[13]-'0'),0,9,0,255);
   int val_west = range_map(s[12])//map((s[12]-'0'),0,9,0,255);
   North_East(val_north,val_west);
}
if((left_x_dir == 0) && (left_y_dir==2)){
   int val_north = range_map(s[13])//map((s[13]-'0'),0,9,0,255);
   int val_west = range_map(s[12])//map((s[12]-'0'),0,9,0,255);
   South_West(val_north,val_west);
}
if((left_x_dir == 2) && (left_y_dir==2)){
   int val_north = range_map(s[13])//map((s[13]-'0'),0,9,0,255);
   int val_west = range_map(s[12])//map((s[12]-'0'),0,9,0,255);
   South_East(val_north,val_west);
}
*/
if((right_x_dir == 1)&& (right_y_dir ==0)){
  SideWayLeft();
  /*
  int val_fl = range_map(s[16]);//map((s[16]-'0'),0,9,0,217);
  int val_fr = range_map(s[16]);//map((s[16]-'0'),0,9,0,229);
  int val_bl = range_map(s[16]);//map((s[16]-'0'),0,9,0,255);
  int val_br = range_map(s[16]);//map((s[16]-'0'),0,9,0,235);
  Speed(val_fl,val_fr,val_bl,val_br);*/
  Speed(180,180,180,180);
  }
if((left_y_dir == 0)&&(left_x_dir == 1) ){
  //SideWayRight();
  Forward();
    int val_fl = range_map(s[13]);//map((s[13]-'0'),0,9,0,217);
  int val_fr = range_map(s[13]);//map((s[13]-'0'),0,9,0,229);
  int val_bl = range_map(s[13]);//map((s[13]-'0'),0,9,0,255);
  int val_br = range_map(s[13]);//map((s[13]-'0'),0,9,0,235);
  Speed(val_fl,val_fr,val_bl,val_br);
}

if((left_y_dir == 2)&&(left_x_dir == 1) ){
  //Forward();
  Backward();
  int val_fl = range_map(s[13]);//map((s[13]-'0'),0,9,0,217);
  int val_fr = range_map(s[13]);//map((s[13]-'0'),0,9,0,229);
  int val_bl = range_map(s[13]);//map((s[13]-'0'),0,9,0,255);
  int val_br = range_map(s[13]);//map((s[13]-'0'),0,9,0,235);
  Speed(val_fl,val_fr,val_bl,val_br);
}

if((right_x_dir == 1)&&(right_y_dir == 2) ){
  SideWayRight();/*  int val_fl = range_map(s[17]);//map((s[17]-'0'),0,9,0,217);
  int val_fr = range_map(s[17]);//map((s[17]-'0'),0,9,0,229);
  int val_bl = range_map(s[17]);//map((s[17]-'0'),0,9,0,255);
  int val_br = range_map(s[17]);//map((s[17]-'0'),0,9,0,235);
  Speed(val_fl,val_fr,val_bl,val_br);*/
  Speed(180,180,180,180);
}

if(front_right == 1){
  ClockWise();
}

if(front_left == 1){
  AntiClockWise();
}
 
 //Digitest();

// ALL THY OPERATIONAL LOGIC .....

// RACK AND PINION
// 

}
