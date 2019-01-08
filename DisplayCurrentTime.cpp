#include "FastLED.h"
#include "DisplayCurrentTime.h"

      int zero[18] = {1,2,3,4,25,28,49,52,73,76,97,100,121,124,145,146,147,148};                          // Lattice of Number 0
      int one[10] = {3,26,27,51,75,99,123,146,147,148};                                                   // Lattice of Number 1
      int two[16] = {1,2,3,4,28,52,73,74,75,76,97,121,145,146,147,148};                                   // Lattice of Number 2
      int three[16] = {1,2,3,4,28,52,73,74,75,76,100,124,145,146,147,148};                                // Lattice of Number 3
      int four[13] = {1,3,25,27,49,51,73,74,75,76,99,123,147};                                            // Lattice of Number 4
      int five[16] = {1,2,3,4,25,49,73,74,75,76,100,124,145,146,147,148};                                 // Lattice of Number 5
      int six[18] = {1,2,3,4,25,49,73,74,75,76,97,100,121,124,145,146,147,148};                           // Lattice of Number 6
      int seven[10] = {1,2,3,4,28,51,75,99,123,147};                                                      // Lattice of Number 7
      int eight[20] = {1,2,3,4,25,28,49,52,73,74,75,76,97,100,121,124,145,146,147,148};                   // Lattice of Number 8
      int nine[18] = {1,2,3,4,25,28,49,52,73,74,75,76,100,124,145,146,147,148};                           // Lattice of Number 9
      int point[2] = {84,132};                                                                            // Lattice of character :
            
      int lenth[11] = {18,10,16,16,13,16,18,10,20,18,2};
      int *num[10]={zero,one,two,three,four,five,six,seven,eight,nine};

      void displayCurrentTime(uint16_t time4Day)
      {
        int offset = 0;
        int i = 0;
        int number  = 10000;
        if(time4Day==0)
        {
              
        }
        while(number)
        {
            int n = time4Day/number;
            if(n!=0)
            {
                time4Day = time4Day%number;
            }
            for(i=0;i<lenth[n];i++)
            {
                int a=*(*(num+n)+i) + offset;
                leds[a] = CRGB::White;
            }
            if(offset==6)
                offset += 7;
            else
                offset += 6;
            
            number = number/10;
            if(number==100)
            {
                number = number/10;
            }
        }

        for(i=0;i<2;i++)
        {
            int b=point[i];
            leds[b] = CRGB::White;
        }

      }
