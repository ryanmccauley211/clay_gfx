cmake_minimum_required(VERSION 3.15)
project(opengl_tutorial)

set(CMAKE_CXX_STANDARD 14)

add_executable(
        opengl_tutorial
        main.cpp
        ext/glad/src/glad.c
        shader/shader.h shader/shader.cpp geometry/point-geo.cpp geometry/point-geo.h geometry/vector.h geometry/line-metrics.h geometry/vector.cpp geometry/anchor.h geometry/anchor.cpp geometry/line-metrics.cpp drawable/primitive/polyline.h drawable/primitive/polyline.cpp common/float_approximator.h common/float_approximator.cpp drawable/drawable.h drawable/simple/triangle.h drawable/simple/triangle.cpp geometry/tri-metrics.h geometry/tri-metrics.cpp drawable/simple/rect.h drawable/simple/rect.cpp drawable/primitive/color.h drawable/primitive/color.cpp scene.h scene.cpp drawable/simple/circle.h drawable/simple/circle.cpp drawable/plotting/axis.h drawable/plotting/axis.cpp drawable/attribute/range.h drawable/attribute/range.cpp drawable/attribute/boundary.h drawable/attribute/boundary.cpp drawable/primitive/line.h drawable/primitive/line.cpp drawable/plotting/axes.h drawable/plotting/axes.cpp drawable/simple/point.h drawable/simple/point.cpp plot2d/scatter.h plot2d/scatter.cpp plot2d/fn_generator.h parser/math_parser.h parser/math_expr.h)


find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
pkg_search_module(YAML REQUIRED yaml-cpp)

include_directories(/usr/local/include)
include_directories(ext/glad/include)
include_directories(ext/exprtk)
include_directories(ext/catch)

target_link_libraries(opengl_tutorial ${GLFW_LIBRARIES} ${YAML_LIBRARIES})

add_subdirectory(test)

set(CMAKE_CXX_FLAGS "-framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo")