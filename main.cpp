#include <igl/opengl/glfw/Viewer.h>
#include <igl/copyleft/cgal/mesh_boolean.h>
#include <igl/MeshBooleanType.h>
#include "cube.h"
#include <iostream>
using namespace std;
using namespace igl;

int main(int argc, char *argv[])
{
    Cube cube;
    Eigen::Vector3f origin(0.0, 0.0, 0.0);
    Eigen::Vector3f dimensions(1.0, 1.0, 1.0);

    Cube cube2;
    Eigen::Vector3f origin2(1.0, 0.0, 0.0);
    Eigen::Vector3f dimensions2(1.0, 1.0, 1.0);

    cube.make_cube(origin, dimensions);
    cube2.make_cube(origin2, dimensions2);

    Eigen::MatrixXd VC;
    Eigen::MatrixXi FC;

    igl::copyleft::cgal::mesh_boolean(cube.V,cube.F,cube2.V,cube2.F,MeshBooleanType::MESH_BOOLEAN_TYPE_UNION,VC,FC);

    // Plot the mesh
    igl::opengl::glfw::Viewer viewer;
    viewer.data().set_mesh(VC, FC);
    viewer.data().set_face_based(true);
    viewer.launch();
}