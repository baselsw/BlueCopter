
void leds_init(){
 pinMode(LED13,OUTPUT);
 digitalWrite(LED13,LOW); 
}

void leds_status(byte stat){
 digitalWrite(LED13,stat);  
}
