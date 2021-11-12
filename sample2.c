#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    BYTE buffer[512];
    
    if (argc != 1)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    
    char *inptfile = argv[1];
    //open memory card
    FILE *inptptr = fopen(inptfile, "r");
    if(inptptr == NULL)
    {
        printf("Could not open %s.\n", inptfile);
        return 1;
    }
    
    while(fread(&buffer, 512, 1, inptfile) == 1)
    {
        if(buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2]== 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            char *filename[8];
            sprintf(filename, "%03i.jpg", counter);
            //FILE *outfile = fopen(filename, "w");
            int counter = 0;
            
            if(counter == 0)
            {
                filename = 000.jpg;
                FILE *outfile = fopen(filename, "w");
                if(outfile == NULL)
                {
                    printf("Could not write to %s.\n", outfile);
                    return 1;
                }
                fwrite(&buffer, 512, 1, outfile);
            }
            
            else
            {
                fclose(outfile);
                FILE *outfile = fopen(filename, "w");
                fwrite(&buffer, 512, 1, outfile);
            }
            counter++;
        }
        
        else
        {
            fwrite(&buffer, 512, 1, outfile);
        }
    }
    
    fclose(outfile);
    fclose(inptfile);
    free(buffer);
    free(filename);
    return 0;
}