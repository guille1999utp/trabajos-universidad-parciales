//nicolas arrieta
#INCLUDE<16F887.H>
#device adc = 10
#FUSES NOWDT, NOPUT, INTRC_IO, NOMCLR, NOPROTECT, NOBROWNOUT, NOWRT
#USE DELAY(internal = 8MHZ)
#USE fast_io(a)
#USE fast_io(c)
#USE fast_io(d)
#INCLUDE<lcd.C>
#DEFINE a input(PIN_A0)

int16 numero1,resultado, entrada;
int8 incremento = 0;
int vc[4]={0x01,0x02,0x04,0x08};

ciclo(int dato){
if(dato==3){
incremento = 0;
delay_ms(500);
 return output_c(vc[3]);
}else if(dato==2){
incremento++;
delay_ms(500);
return output_c(vc[2]);
}else  if(dato==1){
incremento++;
delay_ms(500);
 return output_c(vc[1]);
}else if(dato==0){
incremento++;
delay_ms(500);
 return output_c(vc[0]);
}
}

void main()
{
lcd_init();
lcd_gotoxy(1,1);
lcd_cursor_on(false);
set_tris_c(0);
setup_adc_ports(san0);
setup_adc(adc_clock_internal);

   while(true)
   {

   set_adc_channel(0);
     delay_us(20);
      numero1 = read_adc();
 
entrada = numero1*0.29325513196480938416422287390029;
 delay_us(20);
   resultado = entrada;
   lcd_gotoxy(1,1);
   printf(lcd_putc,"Angulo: %ld ",resultado);
  
for(int16 angulo = entrada; angulo>0; angulo--){
ciclo(incremento);
}
break;

  }
   }
