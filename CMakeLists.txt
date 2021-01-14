cmake_minimum_required(VERSION 3.10.2)

if (APPLE)
    include(${CMAKE_CURRENT_LIST_DIR}/SFML-2.5.1/CMakeLists.txt)
else()
    find_package(SFML COMPONENTS system window graphics network audio)
    include_directories(${SFML_INCLUDE_DIR})
endif()

include_directories(${CMAKE_CURRENT_LIST_DIR}/)
project(TurboHiker)

set(CMAKE_CXX_STANDARD 14)

set(GUI
        src/Utils/SFML_Extras/Object.cpp src/Utils/SFML_Extras/Object.h
        src/Utils/SFML_Extras/Button.cpp src/Utils/SFML_Extras/Button.h
        src/Utils/SFML_Extras/Textbox.cpp src/Utils/SFML_Extras/Textbox.h
        src/Utils/SFML_Extras/Slider.cpp src/Utils/SFML_Extras/Slider.h
        )

add_library(Logic STATIC
        src/Logic/Entities/Entity.cpp src/Logic/Entities/Entity.h

        src/Logic/Entities/Dynamic/DynamicEntity.cpp src/Logic/Entities/Dynamic/DynamicEntity.h
        src/Logic/Entities/Dynamic/Player.cpp src/Logic/Entities/Dynamic/Player.h
        src/Logic/Entities/Dynamic/Enemy.cpp src/Logic/Entities/Dynamic/Enemy.h

        src/Logic/Entities/Static/Score.cpp src/Logic/Entities/Static/Score.h
        src/Logic/Entities/Static/Camera.cpp src/Logic/Entities/Static/Camera.h
        src/Logic/Entities/Static/Finish.cpp src/Logic/Entities/Static/Finish.h
        src/Logic/Entities/Static/World.cpp src/Logic/Entities/Static/World.h
        src/Logic/Entities/Static/Lane.cpp src/Logic/Entities/Static/Lane.h

        src/Logic/Factories/AbstractFactory.h
        )

set(Exceptions
        src/Exceptions/MyException.cpp src/Exceptions/MyException.h
        src/Exceptions/MissingFile.cpp src/Exceptions/MissingFile.h
        src/Exceptions/NullptrException.cpp src/Exceptions/NullptrException.h
        )

set(Singletons
        src/Singletons/Transformation.cpp src/Singletons/Transformation.h
        src/Singletons/RandomNumberGenerator.cpp src/Singletons/RandomNumberGenerator.h
        src/Singletons/StopWatch.cpp src/Singletons/StopWatch.cpp
        )

set(Observer
        src/Observer/Observable.cpp src/Observer/Observable.h
        src/Observer/Observer.cpp src/Observer/Observer.h
        )

set(Representation
        src/Representation/Factories/AbstractFactory.cpp src/Representation/Factories/AbstractFactory.h

        src/Representation/Entities/Entity.cpp src/Representation/Entities/Entity.h
        src/Representation/Entities/Dynamic/Player.cpp src/Representation/Entities/Dynamic/Player.h
        src/Representation/Entities/Dynamic/Enemy.cpp src/Representation/Entities/Dynamic/Enemy.h

        src/Representation/Entities/Static/Camera.cpp src/Representation/Entities/Static/Camera.h
        src/Representation/Entities/Static/Finish.cpp src/Representation/Entities/Static/Finish.h
        src/Representation/Entities/Static/Lane.cpp src/Representation/Entities/Static/Lane.h
        )

add_executable(TurboHiker
        ${Exceptions} ${Singletons} ${Observer} ${Representation} ${GUI}
        src/main.cpp
        src/Game.cpp src/Game.h
        src/Utils/CONST.h
        src/Utils/Enum.h
        )


target_link_libraries(TurboHiker Logic)
target_link_libraries(TurboHiker sfml-audio sfml-graphics sfml-window sfml-system)
