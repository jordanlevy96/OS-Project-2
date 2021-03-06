//Jordan Levy and Chris Moranda

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <util/delay.h>

void blinkOn(){

   //DDRB |= 0x80;
   //PORTB |= 0x80;
   asm volatile("ldi r24, 0x24");
   asm volatile("ldi r25, 0x00");
   asm volatile("movw r30, r24");
   asm volatile("ld r18, Z");
   asm volatile("ldi r24, 0x24");
   asm volatile("ldi r25, 0x00");
   asm volatile("ori r18, 0x80");
   asm volatile("movw r30, r24");
   asm volatile("st Z, r18");
   asm volatile("ldi r24, 0x25");
   asm volatile("ldi r25, 0x00");
   asm volatile("movw r30, r24");
   asm volatile("ld r18, Z");
   asm volatile("ldi r24, 0x25");
   asm volatile("ldi r25, 0x00");
   asm volatile("ori r18, 0x80");
   asm volatile("movw r30, r24");
   asm volatile("st Z, r18");

}

void blinkOff(){

   /*DDRB |= 0x80;
   PORTB &= 0x4F;*/
   asm volatile("ldi r24, 0x24");
   asm volatile("ldi r25, 0x00");
   asm volatile("movw r30, r24");
   asm volatile("ld r18, Z");
   asm volatile("ldi r24, 0x24");
   asm volatile("ldi r25, 0x00");
   asm volatile("ori r18, 0x80");
   asm volatile("movw r30, r24");
   asm volatile("st Z, r18");
   asm volatile("ldi r24, 0x25");
   asm volatile("ldi r25, 0x00");
   asm volatile("movw r30, r24");
   asm volatile("ld r18, Z");
   asm volatile("ldi r24, 0x25");
   asm volatile("ldi r25, 0x00");
   asm volatile("andi r18, 0x4F");
   asm volatile("movw r30, r24");
   asm volatile("st Z, r18");


}

void delay_time(int time) {
   for (int i = 0; i < time; i++) {
      _delay_ms(1);
   }
}

void blink(int *delay){
   //TODO: make delay time an argument
   while(1){
      blinkOn();
      delay_time(20);
      blinkOff();
      delay_time(20);
   }
}

