#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265
#define MAXMATSIZE 4
#define MAXPARAMSIZE 50

// Matrix Inputs
void MatrixInnerInputs(int Size, int ParamSize, int Index,int Matrix[MAXPARAMSIZE][MAXMATSIZE]) { //Non Converted Inputs
    printf("Inputs for %dX%d Matrix %c", Size, Size, 'A'+Index);
    for (int i=0; i<ParamSize; i++) {
        for (int j=0; j<Size; j++) {
            printf("\n\tElement for [%d][%d]: ", i+1, j+1);
            scanf("%d", &Matrix[i][j]);
        }
    }
}

void MatrixInputs(int HigherSize, int ParamSize,int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    //Taking inputs
    static int Index=0;
    int MatrixUnconverted[MAXPARAMSIZE][MAXMATSIZE];
    MatrixInnerInputs(HigherSize-1, ParamSize-1, Index, MatrixUnconverted);
    
    int j;
    for (int i=0; i<ParamSize; i++) {
        for (j=0; j<HigherSize-1; j++) {
            Result[j][i]=MatrixUnconverted[i][j];
        }
        Result[j][i]=1;
    }
    Result[0][ParamSize-1] = Result[0][0];
    Result[1][ParamSize-1] = Result[1][0];
}

// Matrix Output
void MatrixDisplay(int Size, int ParamSize, int Matrix[MAXMATSIZE][MAXPARAMSIZE]) {
    for (int i=0; i<Size; i++) {
        for (int j=0; j<ParamSize; j++) {
            printf(" %d", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void MatrixDisplayFloat(int Size, int ParamSize, float Matrix[MAXMATSIZE][MAXPARAMSIZE]) {
    for (int i=0; i<Size; i++) {
        for (int j=0; j<ParamSize; j++) {
            printf(" %.2f", Matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Fundamental Operation
void MatrixMultiplication(int Size,int ParamSize, int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int MatrixB[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    for(int i=0; i<Size;i++) {
        for(int j=0; j<ParamSize;j++) {
            Result[i][j] = 0;
            for(int k=0; k<Size;k++) {
                Result[i][j] += MatrixA[i][k]*MatrixB[k][j];
            }
        }
    }
}

void MatrixMultiplicationFloat(int Size,int ParamSize, float MatrixA[MAXMATSIZE][MAXPARAMSIZE], int MatrixB[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    for(int i=0; i<Size;i++) {
        for(int j=0; j<ParamSize;j++) {
            Result[i][j] = 0;
            for(int k=0; k<Size;k++) {
                Result[i][j] += MatrixA[i][k]*MatrixB[k][j];
            }
        }
    }
} 

// Derived Transformation Operations
void CompositeMatrixMultiplication(int Size,int ParamSize, int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int MatrixB[MAXMATSIZE][MAXPARAMSIZE],int MatrixC[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int temp1[MAXMATSIZE][MAXPARAMSIZE];
    MatrixMultiplication(Size, ParamSize, MatrixB, MatrixC, temp1);
    printf("\n 1st Order Multiplication In Normal Composite: \n");
    MatrixDisplay(Size,Size, temp1);
    MatrixMultiplication(Size, ParamSize, MatrixA, temp1, Result);
    printf("\n 2nd Order Multiplication In Normal Composite: \n");
    MatrixDisplay(Size,Size, Result);
}

void CompositeMatrixMultiplicationFloat(int Size,int ParamSize, int MatrixA[MAXMATSIZE][MAXPARAMSIZE],float MatrixB[MAXMATSIZE][MAXPARAMSIZE],int MatrixC[MAXMATSIZE][MAXPARAMSIZE],int MatrixD[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int temp1[MAXMATSIZE][MAXPARAMSIZE],temp2[MAXMATSIZE][MAXPARAMSIZE];
    MatrixMultiplication(Size, ParamSize, MatrixC, MatrixD, temp1);
    printf("\n 1st Order Multiplication In FPR Composite: \n");
    MatrixDisplay(3,4, temp1);
    MatrixMultiplicationFloat(Size, ParamSize, MatrixB, temp1, temp2);
    printf("\n 2nd Order Multiplication In FPR Composite: \n");
    MatrixDisplay(3,4, temp2);
    MatrixMultiplication(Size, ParamSize, MatrixA, temp2, Result);
    printf("\n 3rd Order Multiplication In Normal Composite: \n");
    MatrixDisplay(3,4, Result);
}

// Transformation Matrix Conversions
void TranslationMatrixBuild(int Size,int TranslationVector[MAXMATSIZE], int TranslationMatrix[MAXMATSIZE][MAXPARAMSIZE], int Inverse) {
    for (int i=0; i<Size;i++) {
        for (int j=0; j<Size;j++) {
            if (i==j) {
                TranslationMatrix[i][i]=1;
            } else {
                if (j==Size-1){
                    if (Inverse) {
                        TranslationMatrix[i][j] = -TranslationVector[i];
                    } else {
                        TranslationMatrix[i][j] = TranslationVector[i];
                    }
                } else {
                    TranslationMatrix[i][j] = 0;
                }
            }
        }
    }
}

void ScalingMatrixBuild(int Size,int ScalingVector[MAXMATSIZE], int ScalingMatrix[MAXMATSIZE][MAXPARAMSIZE]) {
    for (int i=0; i<Size;i++) {
        for (int j=0; j<Size;j++) {
            if (i==j) {
                if (j==Size-1){
                    ScalingMatrix[i][j] = 1;
                    continue;
                }
                ScalingMatrix[i][i]=ScalingVector[i];
            } else {
                ScalingMatrix[i][j] = 0;
            }
        }
    }
}

void FixedPointScalingMatrixBuild(int Size,int ParamSize,int FixedPoint[MAXMATSIZE],int ScalingVector[MAXMATSIZE], int FixedPointScalingMatrix[MAXMATSIZE][MAXPARAMSIZE]) {
    int TranslationMatrix[MAXMATSIZE][MAXPARAMSIZE], InverseTranslationMatrix[MAXMATSIZE][MAXPARAMSIZE], ScalingMatrix[MAXMATSIZE][MAXPARAMSIZE];
    TranslationMatrixBuild(Size, FixedPoint, TranslationMatrix,0);
    TranslationMatrixBuild(Size, FixedPoint, InverseTranslationMatrix,1);
    ScalingMatrixBuild(Size,ScalingVector, ScalingMatrix);
    printf("\n Built Scaling Matrix: \n");
    MatrixDisplay(Size,Size, ScalingMatrix);
    CompositeMatrixMultiplication(Size, ParamSize,TranslationMatrix, ScalingMatrix, InverseTranslationMatrix, FixedPointScalingMatrix);
}

void ReflectionMatrixBuild(int Size, int Axis, int ReflectionMatrix[MAXMATSIZE][MAXPARAMSIZE]) {
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (i == j) {
                ReflectionMatrix[i][i] = 1;
            } else {
                ReflectionMatrix[i][j] = 0;
            }
        }
    }
    switch (Axis) {
        case 0: // x axis YZ Plane
            if (Size == 3) 
                ReflectionMatrix[1][1] = -1;
            else 
                ReflectionMatrix[0][0] = -1;
            break;
        case 1: // y axis XZ Plane
            if (Size == 3) 
                ReflectionMatrix[0][0] = -1;
            else
                ReflectionMatrix[1][1] = -1;
            break;
        case 2:
            if (Size != 3)
                ReflectionMatrix[2][2] = -1;
            break;
        case 3:
            ReflectionMatrix[0][0] = -1;
            ReflectionMatrix[1][1] = -1;
            if (Size!=3) {
                ReflectionMatrix[2][2] = -1;
            }
            break;
        case 4:
            ReflectionMatrix[0][0] = 0;
            ReflectionMatrix[0][1] = 1; 

            ReflectionMatrix[1][0] = 1;
            ReflectionMatrix[1][1] = 0; 
            break;
        default:
            //inavlid axis
            break;
    }
}

void ShearMatrixBuild(int Size, int Axis, int ShearVector[MAXMATSIZE], int ShearnMatrix[MAXMATSIZE][MAXPARAMSIZE]) {
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (i == j) {
                ShearnMatrix[i][i] = 1;
            } else {
                ShearnMatrix[i][j] = 0;
            }
        }
    }
    switch (Axis) {
        case 0: // x axis YZ Plane
            if (Size == 3) 
                ShearnMatrix[0][1] = ShearVector[0];
            else 
                ShearnMatrix[1][0] = ShearVector[1];
                ShearnMatrix[2][0] = ShearVector[2];
            break;
        case 1: // y axis XZ Plane
            if (Size == 3) 
                ShearnMatrix[1][0] = ShearVector[1];
            else
                ShearnMatrix[0][1] = ShearVector[0];
                ShearnMatrix[2][1] = ShearVector[2];
            break;
        case 2: // Z axis
            if (Size != 3)
                ShearnMatrix[0][2] = ShearVector[0];
                ShearnMatrix[1][2] = ShearVector[1];
            break;
        default:
            //inavlid axiss
            break;
    }
}

void RotationMatrixBuild(int Size, int Axis, int Degrees, float RotationMatrix[MAXMATSIZE][MAXPARAMSIZE]) {
    printf("Degrees: %d\n", Degrees); // Debugging line

    float radians = (Degrees * PI) / 180.0;
    float cosTheta = cos(radians);
    float sinTheta = sin(radians);

    printf("cosTheta: %f, sinTheta: %f\n", cosTheta, sinTheta); // Debugging line
    
    for (int i = 0; i < Size; i++) {
        for (int j = 0; j < Size; j++) {
            if (i == j) {
                RotationMatrix[i][i] = 1;
            } else {
                RotationMatrix[i][j] = 0;
            }
        }
    }

    if (Size==3) {
        RotationMatrix[0][0] = cosTheta;
        RotationMatrix[0][1] = -sinTheta;
        RotationMatrix[1][0] = sinTheta;
        RotationMatrix[1][1] = cosTheta;
    } else {
        switch (Axis) {
            case 0: // 3D rotation around X-axis
                RotationMatrix[1][1] = cosTheta;
                RotationMatrix[1][2] = -sinTheta;
                RotationMatrix[2][1] = sinTheta;
                RotationMatrix[2][2] = cosTheta;
                break;
            case 1: // 3D rotation around Y-axis
                RotationMatrix[0][0] = cosTheta;
                RotationMatrix[0][2] = sinTheta;
                RotationMatrix[2][0] = -sinTheta;
                RotationMatrix[2][2] = cosTheta;
                break;
            case 2: // 2D and 3D rotation around Z-axis
                RotationMatrix[0][0] = cosTheta;
                RotationMatrix[0][1] = -sinTheta;
                RotationMatrix[1][0] = sinTheta;
                RotationMatrix[1][1] = cosTheta;
                break;
            default:
                // Invalid axis
                break;
        }
    }
}

// OPERATIONS
void FixedPointRotation(int Size,int ParamSize,int Axis, int Degree,int FixedPoint[MAXMATSIZE],int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int TranslationMatrix[MAXMATSIZE][MAXPARAMSIZE], InverseTranslationMatrix[MAXMATSIZE][MAXPARAMSIZE];
    float RotationMatrix[MAXMATSIZE][MAXPARAMSIZE];
    TranslationMatrixBuild(Size, FixedPoint, TranslationMatrix,0);
    TranslationMatrixBuild(Size, FixedPoint, InverseTranslationMatrix,1);
    RotationMatrixBuild(Size,Axis, Degree, RotationMatrix);
    CompositeMatrixMultiplicationFloat(Size, ParamSize, TranslationMatrix,RotationMatrix, InverseTranslationMatrix, MatrixA, Result);
}

void Rotation(int Size, int ParamSize, int Axis, int Degree, int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    float RotationMatrix[MAXMATSIZE][MAXPARAMSIZE];
    RotationMatrixBuild(Size,Axis, Degree, RotationMatrix);
    MatrixMultiplicationFloat(Size, ParamSize, RotationMatrix, MatrixA, Result);
}

void Translation(int Size, int ParamSize, int TranslationVector[MAXMATSIZE], int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int TranslationMatrix[MAXMATSIZE][MAXPARAMSIZE];
    TranslationMatrixBuild(Size,TranslationVector, TranslationMatrix,0);
    printf("\nBuilt Translation Matrix: \n");
    MatrixDisplay(Size, Size, TranslationMatrix);
    MatrixMultiplication(Size, ParamSize, TranslationMatrix, MatrixA, Result);
}

void Shearing(int Size, int ParamSize, int Axis, int ShearVector[MAXMATSIZE], int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int ShearMatrix[MAXMATSIZE][MAXPARAMSIZE];
    ShearMatrixBuild(Size, Axis,ShearVector, ShearMatrix);
    printf("\nBuilt Reflection Matrix: \n");
    MatrixDisplay(Size, Size, ShearMatrix);

    MatrixMultiplication(Size, ParamSize, ShearMatrix, MatrixA, Result);
}

void Reflection(int Size, int ParamSize, int Axis, int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int ReflectionMatrix[MAXMATSIZE][MAXPARAMSIZE];
    ReflectionMatrixBuild(Size, Axis, ReflectionMatrix);
    printf("\nBuilt Reflection Matrix: \n");
    MatrixDisplay(Size, Size, ReflectionMatrix);
    MatrixMultiplication(Size, ParamSize, ReflectionMatrix, MatrixA, Result);
}

void Scaling(int Size, int ParamSize, int ScalingVector[MAXMATSIZE], int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int ScalingMatrix[MAXMATSIZE][MAXPARAMSIZE];
    ScalingMatrixBuild(Size, ScalingVector, ScalingMatrix);
    MatrixMultiplication(Size, ParamSize, ScalingMatrix, MatrixA, Result);
}

void FixedPointScaling(int Size, int ParamSize,int FixedPoint[MAXMATSIZE], int ScalingVector[MAXMATSIZE], int MatrixA[MAXMATSIZE][MAXPARAMSIZE], int Result[MAXMATSIZE][MAXPARAMSIZE]) {
    int ScalingMatrix[MAXMATSIZE][MAXPARAMSIZE];
    FixedPointScalingMatrixBuild(Size,ParamSize, FixedPoint, ScalingVector, ScalingMatrix);
    MatrixMultiplication(Size, ParamSize, ScalingMatrix, MatrixA, Result);
}