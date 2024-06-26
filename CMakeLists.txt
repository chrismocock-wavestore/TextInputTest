cmake_minimum_required(VERSION 3.5)

cmake_policy(SET CMP0071 NEW)
cmake_policy(SET CMP0087 NEW)

project(TextInputTest VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2 QuickWidgets Widgets)

qt_standard_project_setup(REQUIRES 6.5)

set(PROJECT_SOURCES
        main.cpp
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        model.h model.cpp
	MainWindow.qml
)

qt_add_executable(appTextInputTest WIN32 MACOSX_BUNDLE
    ${PROJECT_SOURCES}
)

target_link_libraries(appTextInputTest
    PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Qml
    Qt6::Quick
    Qt6::QuickControls2
    Qt6::QuickWidgets
    Qt6::Widgets
)

qt_add_qml_module(appTextInputTest
    URI TextInputTest
    QML_FILES
      "MainWindow.qml"
    RESOURCE_PREFIX /TextInputTest
    NO_RESOURCE_TARGET_PATH    
)

set_target_properties(appTextInputTest PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS appTextInputTest
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

qt_generate_deploy_qml_app_script(
    TARGET appTextInputTest
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})
