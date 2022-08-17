#include "Application.h"
#include <iostream>

extern Application* CreateApplication(Arguments);

int main(int argc, char** argv)
{
    Arguments args{argc, argv};
    auto app = CreateApp(args);

    std::cout << "Current loaded level: " << app->currentLevel->name << std::endl;

    app->run();
    app->end();
    return 0;
}