#include <asm.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>




/*Nelson Cole.
 *
 *
 *  Simples E/S
 *
 *  putchar, puts, printf
 *
 *  getchar, gets, scanf
 */


int8_t putchar(int8_t ch){

    return int70(3,0,0,ch);

}

void puts(char *string){


    int70(4,0,0,string);


}


void printf(const char *format,...){


	char* ap;
	va_start (ap,format);
	int index = 0;
	uint8_t u;	
	int d;
	char c, *s;
	char buffer[256];

	while (format[index])
	{
		switch (format[index])
		{
		case '%':
			++index;
			switch (format[index])
			{
			
     case 'C':
			case 'c':
				c = (int8_t) va_arg (ap, int32_t);
				putchar(c);
				break;
     
     case 'S':
			case 's':
				s = va_arg (ap, int8_t*);
				puts(s);
				break;

			case 'd':
			case 'i':
				d = va_arg (ap, int32_t);
				atoi(d, buffer);
				puts(buffer);
				break;

			case 'U':
			case 'u':
				u = va_arg (ap, uint32_t);
				atoi(u, buffer);
				puts(buffer);
				break;

			case 'X':
			case 'x':
				d = va_arg (ap, int32_t);
				i2hex(d, buffer,8);
				puts(buffer);
				break;
			
			default:
				putchar('%');
				putchar('%');
				break;
				
			}
			break;

		default:
			putchar(format[index]);
			break;
		}
		++index;
    }
}



int8_t getchar(){


	int32_t value =0;
          uint8_t ch;
          
          while(TRUE){
				value = int70(8,0,0,0);
				if(value !=0){
				ch = value;
				value = 0;
				if(ch != '\n')putchar(ch);
            return ch;
        }
    }

	
}


void gets(int8_t *buffer){

    int32_t i=0;
    int8_t ch=0;
    int32_t size = sizeof(buffer);

	 while(TRUE){
		 ch = getchar();
		 if(ch == '\n')break;
		 else if(ch == '\b' && i > 0)buffer[--i] = 0;
		 else if(ch != '\b')buffer[i++] =ch; 
		 }
	  


}



void scanf(const char *format,...){


    

}














