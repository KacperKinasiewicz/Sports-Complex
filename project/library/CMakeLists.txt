cmake_minimum_required(VERSION 3.4)
project(Library)

set(SOURCE_FILES
        include/typedefs.h

        include/model/BasketballCourt.h
        include/model/Court.h
        include/model/CoveredCourt.h
        include/model/FootballPitch.h
        include/model/GrassPitch.h
        include/model/PingPongTable.h
        include/model/TennisCourt.h
        include/model/VolleyballPitch.h
        src/model/BasketballCourt.cpp
        src/model/Court.cpp
        src/model/CoveredCourt.cpp
        src/model/FootballPitch.cpp
        src/model/GrassPitch.cpp
        src/model/PingPongTable.cpp
        src/model/TennisCourt.cpp
        src/model/VolleyballPitch.cpp

        include/model/Equipment.h
        include/model/Rocket.h
        include/model/Ball.h
        src/model/Equipment.cpp
        src/model/Rocket.cpp
        src/model/Ball.cpp

        include/model/Client.h
        include/model/ClientType.h
        include/model/Address.h
        src/model/Client.cpp
        src/model/ClientType.cpp
        src/model/Address.cpp
        include/model/Rent.h
        src/model/Rent.cpp

        test/master.cpp
        test/CourtTest.cpp
        test/EquipmentTest.cpp
        include/repositories/RentRepository.h
        include/repositories/ClientRepository.h
        include/repositories/CourtRepository.h
        include/repositories/EquipmentRepository.h
        include/StorageContainer.h
        include/managers/ClientManager.h
        include/managers/RentManager.h
        include/managers/CourtManager.h
        include/managers/EquipmentManager.h
        src/managers/EquipmentManager.cpp
        src/managers/CourtManager.cpp
        src/managers/RentManager.cpp
        src/managers/ClientManager.cpp
        src/StorageContainer.cpp
        src/repositories/RentRepository.cpp
        src/repositories/ClientRepository.cpp
        src/repositories/EquipmentRepository.cpp
        src/repositories/CourtRepository.cpp
        test/ClientTest.cpp
        test/RentTest.cpp
        test/AddressTest.cpp
        test/RepositoryTest.cpp
        include/SuperManager.h
        src/SuperManager.cpp
        test/ManagersTest.cpp
)

# Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(Library ${SOURCE_FILES})

target_include_directories(Library PUBLIC include)

# Generowanie testów
enable_testing()

find_package (Boost 1.65.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES
        test/AddressTest.cpp
        test/ClientTest.cpp
        test/CourtTest.cpp
        test/EquipmentTest.cpp
        test/master.cpp
        test/RentTest.cpp
        test/RepositoryTest.cpp
        test/ManagersTest.cpp
) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (LibraryTester ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (LibraryTester
        Library
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

#dodaj test LibraryTest. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(LibraryTest LibraryTester
        --report_level=detailed
        --log_level=all
        --color_output=yes
)

add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})