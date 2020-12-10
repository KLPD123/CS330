#include "Cylinder.h"

//------------------------------------------------------------------------------
Cylinder::Cylinder()
    :Cylinder(1, 1)
{
}

//------------------------------------------------------------------------------
Cylinder::Cylinder(double r, double h)
    :Polyhedron("Cylinder"),
     height(h),
     radius(r)
{
    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}

//------------------------------------------------------------------------------
void Cylinder::read(std::istream& ins)
{
    ins >> height;
    ins >> radius;

    double d = this->getDiameter();
    boundingBox.setUpperRightVertex(d, d, height);
}

//------------------------------------------------------------------------------
void Cylinder::display(std::ostream& outs) const
{
     Polyhedron::display(outs);

    outs << "Radius: " << radius
         << " "
         << "Height: " << getHeight();
}

//------------------------------------------------------------------------------
void Cylinder::scale(double scalingFactor)
{
    // Implement this function
    radius *= scalingFactor;
    height *= scalingFactor;

    boundingBox.scale(scalingFactor);
}

//------------------------------------------------------------------------------
