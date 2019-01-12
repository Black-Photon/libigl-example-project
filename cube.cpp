#include <igl/opengl/glfw/Viewer.h>
#include "cube.h"

void Cube::make_cube(Eigen::Vector3f origin, Eigen::Vector3f dimensions)
{
    float x = origin.x();
    float y = origin.y();
    float z = origin.z();

    float dx = dimensions.x();
    float dy = dimensions.y();
    float dz = dimensions.z();

    // Inline mesh of a cube
    V = (Eigen::MatrixXd(8,3)<<
        x,      y,      z,
        x,      y,      z+dz,
        x,      y+dy,   z,
        x,      y+dy,   z+dz,
        x+dx,   y,      z,
        x+dx,   y,      z+dz,
        x+dx,   y+dy,   z,
        x+dx,   y+dy,   z+dz).finished();
    F = (Eigen::MatrixXi(12,3)<<
        1,7,5,
        1,3,7,
        1,4,3,
        1,2,4,
        3,8,7,
        3,4,8,
        5,7,8,
        5,8,6,
        1,5,6,
        1,6,2,
        2,6,8,
        2,8,4).finished().array()-1;
}