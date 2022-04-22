#include "Program.h"

#include <sstream>
#include <string.h>

void help()
{
    std::cout << 
    "Usage: \n"
    " IsoperimetricRectangles [options]\n\n"
    "Options:\n"
    " -a                        rectangle side lenght (default = 200)\n"
    " -p, --perimeter           rectangle perimeter lenght (default = 600)\n"
    " -h, --help                display this help\n";
}

void checkArgument(std::istringstream & stream, float & argument)
{
    if (!(stream >> argument) || !stream.eof())
    {
        std::cerr << "ERROR: Invalid argument" << std::endl;
        help();
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    float a = 200, P = 600;

    for (int i = 1; i < argc; i += 2)
    {
        if (!strcmp(argv[i], "-h") || !strcmp(argv[i], "--help"))
        {
            help();
            return EXIT_SUCCESS;
        }
        else if (argv[i+1])
        {
            std::istringstream stream(argv[i+1]);

            if (!strcmp(argv[i], "-a"))
            {
                checkArgument(stream, a);
            }
            else if (!strcmp(argv[i], "-p") || !strcmp(argv[i], "--perimeter"))
            {
                checkArgument(stream, P);
            }
            else
            {
                std::cerr << "ERROR: '" << argv[i] << "' invalid argument\n";
                return EXIT_FAILURE;
            }
        }
        else
        {
            std::cerr << "ERROR: " << argv[i] << " requires an argument!\nUse --help for more information\n";
            return EXIT_FAILURE;
        }
    }

    Program program(a, P);

    program.run();

    return EXIT_SUCCESS;
}