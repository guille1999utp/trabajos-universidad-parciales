#INCLUDE <16F887.H>
#FUSES NOWDT, NOPUT, INTRC_IO, NOMCLR, NOPROTECT, NOBROWNOUT, NOWRT
#USE DELAY(internal =8MHZ)
#USE fast_io(b)
#USE fast_io(a)

#define a input(pin_b0)
#define b input(pin_b1)
#define c input(pin_b2)
#define d input(pin_b3)

#define e input(pin_a0)
#define f input(pin_a1)
#define g input(pin_a2)
#define h input(pin_a3)



int1 f1;
int1 f2;


void main()
{
   set_tris_b(0x0F); 
   output_b(0);
   set_tris_a(0x0F);
   output_a(0);
   while(true)
   {
      f1=(~a&c)|(b&c)|(~a&b&~d)|(~b&a&~d)|(a&~b&~d);
      output_bit(pin_b7,f1);

      f2=(~e&~f&~g)|(g&~f&~h)|(~e&f&g)|(e&~g&f);
      output_bit(pin_a7,f2);

   }
}
