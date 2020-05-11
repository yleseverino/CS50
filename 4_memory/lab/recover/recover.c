#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // Check usage
    if (argc != 2)
    {
        return 1;
    }

    // Open file
    FILE *raw = fopen(argv[1], "r");
    if (!raw)
    {
        return 1;
    }

    // Creating a Buffer to read 512 bytes
    unsigned char buffer[512];

    // Inicializing the file
    FILE *img = fopen("000.jpg", "w");

    // Creating a variable to save the futures names of files
    char image[3];

    int i = 0;
    int size;
    while ((size = (fread(buffer, 1, 512, raw)) == 512)) //read the file until the end
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {
            if (i == 0)
            {
                fwrite(buffer, 1, 512, img);
                i++;
            }

            else
            {
                fclose(img);
                sprintf(image, "%03i.jpg", i);
                img = fopen(image, "w");
                fwrite(buffer, 1, 512, img);
                i++;

            }


        }
        else if (i > 0)
        {
            fwrite(buffer, 1, 512, img);
        }

    }

    fwrite(buffer, 1, size, img);
    fclose(img);
    fclose(raw);


}
