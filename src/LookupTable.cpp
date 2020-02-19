#include <stdio.h>
#include <inttypes.h>
#include "../gcem/include/gcem.hpp"
#include <array>
#include <string>


#define M_PI       3.14159265358979323846   // pi

template <uint8_t peakValue, uint16_t size>
struct SinLUT {
  constexpr SinLUT() : lut() {
      for (auto i = 0; i < lut.size(); ++i)
        {
            lut[i] =  static_cast<int16_t>(gcem::sin(2* M_PI * i / size)*peakValue);
        }
  }
  std::array<int16_t, size> lut;
};

int main() {

 constexpr static auto sinlut = SinLUT<250, 256>();
 
 for(auto i : sinlut.lut){
     printf("%d \n", i);
 }

 
}