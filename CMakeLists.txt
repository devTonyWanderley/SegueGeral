cmake_minimum_required(VERSION 3.19)
project(SegueGeral LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets LinguistTools)

qt_standard_project_setup()

qt_add_executable(SegueGeral
    WIN32 MACOSX_BUNDLE
    main.cpp
    geral.cpp
    geral.h
    geral.ui
    configread.h configread.cpp configread.ui
)

qt_add_translations(
    TARGETS SegueGeral
    TS_FILES SegueGeral_pt_BR.ts
)

target_link_libraries(SegueGeral
    PRIVATE
        Qt::Core
        Qt::Widgets
)

include(GNUInstallDirs)

install(TARGETS SegueGeral
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET SegueGeral
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
