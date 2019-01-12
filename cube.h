#ifndef CUBE_H
#define CUBE_H

class Cube
{
    public:
        void make_cube(Eigen::Vector3f origin, Eigen::Vector3f dimensions);
        Eigen::MatrixXd V;
        Eigen::MatrixXi F;
};

#endif