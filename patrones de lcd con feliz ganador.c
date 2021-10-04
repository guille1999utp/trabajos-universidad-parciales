#INCLUDE <16F887.H>
#FUSES NOWDT, NOPUT, INTRC_IO, NOMCLR, NOPROTECT, NOBROWNOUT,NOWRT,XT,NOMCLR
#USE DELAY(internal = 8MHZ)
#INCLUDE<lcd.C>

INT16  CONT=0, tiempo=1, mostrar=0;

#INT_TIMER0
void  temp()
{
   
   tiempo=tiempo+1;
     cont=cont+1;
   if (tiempo%500 == 0)
      {
         output_toggle(pin_c0);
      }
       if (tiempo%700==0)
      {
         output_toggle(pin_c2);
      }
       if (tiempo%1000==0)
      {
         output_toggle(pin_c1);
      }
       if (tiempo%2000==0)
      {
         output_toggle(pin_c3);
      }
          if (cont%1000==0)
      {
           lcd_gotoxy(1,1);
   printf(lcd_putc,"personas: %lu", mostrar);
      }
        
      if(mostrar > 500){
      lcd_gotoxy(1,1);
   printf(lcd_putc,"feliz ganador");
      set_timer0(231);
      lcd_gotoxy(1,1);
   printf(lcd_putc,"              ");
   set_timer0(231);
      }
      
      
    mostrar = cont/1000;
      set_timer0(231);
}
VOID  MAIN()
{
lcd_init();
port_b_pullups(255);
lcd_gotoxy(1,1);
lcd_cursor_on(false);

setup_timer_0(RTCC_INTERNAL|RTCC_DIV_8);
SET_TIMER0(231);
enable_interrupts(int_timer0);
 enable_interrupts(global);



   while (TRUE)
   {
    
   }
}
