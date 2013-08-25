PROGMEM const byte rxPins[6]={
  RX_PIN_YAW,RX_PIN_ROLL,RX_PIN_PITCH,RX_PIN_AUX1,RX_PIN_AUX2,RX_PIN_THROTTLE};
volatile byte rxState[4]={
  0,0,0,0};
volatile int rxPrev[6]={
  0,0,0,0,0,0};

void rxInit(){
  for(byte i=0;i<6;i++){
    pinMode(pgm_read_byte(&rxPins[i]),INPUT); 
    digitalWrite(pgm_read_byte(&rxPins[i]),HIGH);
  }
  PCICR |= (1 << PCIE0); 
  PCMSK0 |= (1 << PCINT1)|(1 << PCINT2)|(1 << PCINT3)|(1 << PCINT4); 
  sei();
  attachInterrupt(RX_INT_AUX2,rxGoesHigh0,RISING);
  attachInterrupt(RX_INT_THROTTLE,rxGoesHigh1,RISING);
}

void rxGoesHigh0(){
  attachInterrupt(RX_INT_AUX2,rxGoesLow0,FALLING);
  rxPrev[4]=micros();
}
void rxGoesLow0(){
  attachInterrupt(RX_INT_AUX2,rxGoesHigh0,RISING);
  rxVal[4]=micros()-rxPrev[4];  
}

void rxGoesHigh1(){
  attachInterrupt(RX_INT_THROTTLE,rxGoesLow1,FALLING);
  rxPrev[5]=micros();
}
void rxGoesLow1(){
  attachInterrupt(RX_INT_THROTTLE,rxGoesHigh1,RISING);
  rxVal[5]=micros()-rxPrev[5];  
}

ISR(PCINT0_vect) 
{ 
  for(byte i=0;i<4;i++){
    byte rxtemp=digitalRead(pgm_read_byte(&rxPins[i]));
    if((rxState[i] == 0) & (rxtemp==1)){
      rxPrev[i]=micros();
      rxState[i]=1;
    }//if
    else if((rxState[i] == 1) & (rxtemp==0)){
      rxVal[i]=micros()-rxPrev[i];
      rxState[i]=0;
    }//elseif
  }//for
}//ISR


