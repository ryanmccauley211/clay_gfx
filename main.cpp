#include <GLFW/glfw3.h>
#include <vector>
#include <yaml-cpp/yaml.h>
#include "geometry/vector.h"
#include "drawable/primitive/polyline.h"
#include "drawable/simple/triangle.h"
#include "scene.h"
#include "drawable/simple/circle.h"
#include "drawable/primitive/line.h"
#include "drawable/plotting/axis.h"
#include "drawable/plotting/axes.h"
#include "drawable/simple/point.h"

int main() {
    YAML::Node config = YAML::LoadFile("../config.yaml");
    YAML::Node windowConfig = config["window"];

    const std::string title = windowConfig["title"].as<std::string>();
    const int width = windowConfig["width"].as<int>();
    const int height = windowConfig["height"].as<int>();

    Scene scene = Scene(title.c_str(), width, height);
    scene.init();
    unsigned int rectVertId = scene.generateVBO();

//    Point2D p1 = {-0.15, -0.15};
//    Point2D p2 = {-0.15, 0.15};
//    Point2D p3 = {0.15, 0.15};
//    Point2D p4 = {0.15, -0.15};
//
//    Rect polyline = Rect::make(p1, p2, p3, p4)
//            .withThickness(0.03)
//            .withJoint(JointType::MITER)
//            .filled()
//            .withFillColor({0, 0, 0, 1})
//            .withStrokeColor({1, 0, 0, 1});

//    Circle circle = Circle::make({0, 0}, 0.8)
//            .filled()
//            .withFillColor({0, 1, 0, 1})
//            .withStrokeColor({1, 0, 1, 1});

//    Line line = Line::make({0.1, 0.1}, {-0.2, -0.2});
//
//    std::vector<float> vertices = line.asVertices();

//    Axis axis = Axis::make(AxisType::VERTICAL, {
//            {-0.8, 0.8},
//            {0.8, 0.8},
//            {-0.8, -0.8},
//            {0.8, -0.8}
//    }).withThickness(0.01)
//            .withTicks();
//
//    Axis axis2 = Axis::make(AxisType::HORIZONTAL, {
//            {-0.8, 0.8},
//            {0.8, 0.8},
//            {-0.8, -0.8},
//            {0.8, -0.8}
//    }).withThickness(0.01);
//
//    Axes2D axes2D = Axes2D::make({
//                                         {-0.8, 0.8},
//                                         {0.8,  0.8},
//                                         {-0.8, -0.8},
//                                         {0.8,  -0.8}
//                                 })
//                                         .withThickness(0.01)
//                                         .withNbTicks(50)
//                                         .withTicks();

//    axis2.asVertices();
//    std::vector<float> vertices = axes2D.asVertices();

//    Point point = Point::make({0.2, 0.2});
//
    Line line = Line::make({0.3, 0.4}, {-0.3, 0})
            .withThickness(0.05)
            .withCapType(CapType::ROUND);


//    scene.bindVBO(scene.generateVBO(), vertices);

//    scene.bindVBO(rectVertId, axis.asVertices());
//    scene.bindVBO(rectVertId, vertices);
//    scene.bindVBO(rectVertId, point.asVertices());
    scene.bindVBO(rectVertId, line.asVertices());
//    scene.bindVAO(rectVertId, vertices);
//    scene.enableWireFrameMode();
    scene.render();

    return 0;
}