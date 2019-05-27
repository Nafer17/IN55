#ifndef STRUCT_H
#define STRUCT_H

#include <QVector3D>
#include <QOpenGLFunctions>

struct VertexData
{
    QVector3D position;
    QVector3D color;
    QVector3D normal;
};

struct VerticesStruct
{
    VertexData* vertices;
    int nbrVertices;
};


struct IndicesStruct
{
    GLushort* indices;
    int nbrIndices;
};


struct Parameters
{
    //Global Size
    double globalSizeFactor; //Will multiply the whole morel by that factor
    double globalSizeVariance;


    //Height parameters
    double height; //Height of the morel if it is 100% vertical
    double stemHeightPart; //Part of the stem in the morel's height, in percentage (0 to 100)
    double heightVariance;


    //Radius parameters
    double junctionRadius; //Radius at the junction between the cap and the stem
    double junctionRadiusVariance;

    double capMaxRadiusFactor;
    double capMaxRadiusVariance;

    double capMaxRadiusFactor2;
    float capBaseMaxRadiusLocationFactor; //if d=1/3, the morel will be at it's max at 1/3 of its height
    float capTipMaxRadiusLocationFactor; //same but for the tip

    double radiusAtBaseFactor;
    double radiusAtBaseVariance;


    //Meshing parameters
    GLushort stemNumberOfHorizontalDivisions;
    GLushort stemNumberOfVerticalDivisions;
    GLushort capNumberOfHorizontalDivisions;
    GLushort capNumberOfVerticalDivisions;

    //Morel curvature parameters (Bezier)
    double curvatureVariance;
    double anglePosVariance;


    //Colors
    QVector3D capColor;
    QVector3D stemColor;
    QVector3D holesEdgesColor;


    //Perlin parameters
    double capGlobalPerlinPower;
    double capDetailsPerlinPower;


    //Voronoi tesselation factor
    double holesDensityFactor;
    double holesEdgesWidthFactor;
};

#endif // STRUCT_H
