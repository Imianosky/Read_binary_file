#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t read_file_byte(FILE *fp){
  uint8_t data;
  fread(&data, 1, 1, fp);
  return data;
}


int main() {
  FILE *fp = fopen("compressed_image.RAW", "rb");
  unsigned short sample;
  fseek(fp, 0, SEEK_END);
  long tam = ftell(fp);
  rewind(fp);
  long c = 0;
  while(c!=tam){
    sample = read_file_byte(fp);
    printf("%.8u ", sample);
    c++;
  }
  fclose(fp);
}
