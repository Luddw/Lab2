#pragma once
#include <cmath>
#define A _matrix_values

/** A 4-dimensional homogenous vector*/
class Vector4D
{
public:
	Vector4D(); //default construct

	/**
	* costum construct for a 4D-vector
	* @param x : x-value
	* @param y : y-value
	* @param z : z-value
	* @param w : w-value
	* @return : 4D-vector
	*/
	Vector4D(float x, float y, float z, float w); //custom construct

	Vector4D(Vector4D& o);	// copy construct
	

	
	/**
	* Performs a dotproduction of two vectors
	* @param vect4 : the 2nd vector used in the dotproduct
	* @return Returns a Scalar 
	*/
	float DotProduct(const Vector4D& vect4);

	/**
	* Performs crossproduct with another vector
	* @param vect4 : the 2nd vector used in the crossproduct
	* @return Returns a new vector 
	*/
	Vector4D CrossProduct(const Vector4D& vect4);

	/**
	* Calculates the lenght of a vector
	* @return Returns the lenght of the vector
	*/
	float LenghtOf();
	 
	/**
	* Normalizes the vector
	* @return Returns a new normalized vector
	*/
	Vector4D Normalize();


	//-----overloading operators-----

	/**
	* Allows Addition between two vectors
	*/
	Vector4D operator+(const Vector4D& other);

	/**
	* Allows Subtraction between two vectors
	*/
	Vector4D operator-(const Vector4D& other);

	/**
	* Allows multiplication with a vector and a number, Scalar
	*/
	Vector4D operator*(const float& other);

	/**
	* Allows assigning a vector with another vector
	*/
	Vector4D& operator=(const Vector4D& other);

	/**
	* Compares a vector with another vector. Checks if the two vectors are the same.
	* @return True or False 
	*/
	bool operator==(const Vector4D& other);

	/**
	* Compares a vector with another vector. Checks if the two vectors are not the same.
	* @return True or False
	*/
	bool operator!=(const Vector4D& other);

	/**
	* Allows access to the vectors private data. Reading the data
	*/
	const float& operator[] (int index) const;

	/**
	* Allows access to the vectors private data. Writing data to the array of data
	*/
	float& operator[] (int index);



private:
	float _vect_values[4];
};

// default construct
Vector4D::Vector4D()
{
	_vect_values[0] = 0;
	_vect_values[1] = 0;
	_vect_values[2] = 0;
	_vect_values[3] = 1;
}
//customconstruct
Vector4D::Vector4D(float x, float y, float z, float w)
{
	this->_vect_values[0] = x;
	this->_vect_values[1] = y;
	this->_vect_values[2] = z;
	this->_vect_values[3] = w;
}
// copy construct
Vector4D::Vector4D(Vector4D& o)
{
	this->_vect_values[0] = o._vect_values[0];
	this->_vect_values[1] = o._vect_values[1];
	this->_vect_values[2] = o._vect_values[2];
	this->_vect_values[3] = o._vect_values[3];
}

Vector4D Vector4D::operator+(const Vector4D& other)
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] + other._vect_values[0];
	new_vect._vect_values[1] = this->_vect_values[1] + other._vect_values[1];
	new_vect._vect_values[2] = this->_vect_values[2] + other._vect_values[2];

	return new_vect;
}

Vector4D Vector4D::operator-(const Vector4D& other)
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] - other._vect_values[0];
	new_vect._vect_values[1] = this->_vect_values[1] - other._vect_values[1];
	new_vect._vect_values[2] = this->_vect_values[2] - other._vect_values[2];

	return new_vect;
}

Vector4D Vector4D::operator*(const float& other)
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] * (other);
	new_vect._vect_values[1] = this->_vect_values[1] * (other);
	new_vect._vect_values[2] = this->_vect_values[2] * (other);

	return new_vect;
}

Vector4D& Vector4D::operator=(const Vector4D& other)
{
	_vect_values[0] = other._vect_values[0];
	_vect_values[1] = other._vect_values[1];
	_vect_values[2] = other._vect_values[2];

	return *this;
}

bool Vector4D::operator==(const Vector4D& v)
{
	return (this->_vect_values[0] == v._vect_values[0] &&
		this->_vect_values[1] == v._vect_values[1]) &&
		this->_vect_values[2] == v._vect_values[2];
}

bool Vector4D::operator!=(const Vector4D& v)
{
	return (this->_vect_values[0] != v._vect_values[0] &&
		this->_vect_values[1] != v._vect_values[1] &&
		this->_vect_values[2] != v._vect_values[2]);
}

const float& Vector4D::operator[] (int index) const
{
	if (index <= 3 && index >= 0)
	{
		return this->_vect_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}

float& Vector4D::operator[] (int index)
{
	if (index <= 3 && index >= 0)
	{
		return this->_vect_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}

float Vector4D::DotProduct(const Vector4D& vect2)
{
	float result =
		this->_vect_values[0] * vect2._vect_values[0] +
		this->_vect_values[1] * vect2._vect_values[1] +
		this->_vect_values[2] * vect2._vect_values[2];

	return result;
}

Vector4D Vector4D::CrossProduct(const Vector4D& vect2)
{
	Vector4D result;
	result._vect_values[0] = (this->_vect_values[1] * vect2._vect_values[2]) - (this->_vect_values[2] * vect2._vect_values[1]);
	result._vect_values[1] = -((this->_vect_values[0] * vect2._vect_values[2]) - (this->_vect_values[2] * vect2._vect_values[0]));
	result._vect_values[2] = (this->_vect_values[0] * vect2._vect_values[1]) - (this->_vect_values[1] * vect2._vect_values[0]);


	return result;
}

float Vector4D::LenghtOf()
{
	float lenght = sqrt(pow(this->_vect_values[0], 2) + pow(this->_vect_values[1], 2) + pow(this->_vect_values[2], 2)); // square root of (x^2 + y^2)
	return lenght;
}

Vector4D Vector4D::Normalize()
{
	Vector4D new_vect;
	new_vect._vect_values[0] = this->_vect_values[0] / this->LenghtOf();
	new_vect._vect_values[1] = this->_vect_values[1] / this->LenghtOf();
	new_vect._vect_values[2] = this->_vect_values[2] / this->LenghtOf();

	return new_vect;
}




/** A 4-dimensional homogenous matrix*/
class Matrix4D
{
public:
	/** Default construct, creates a 4x4 identity matrix*/
	Matrix4D();
	
	/**
	* Custom constructor for a 4x4 matrix
	*/
	Matrix4D(float x1, float x2, float x3, float x4,
			float y1, float y2, float y3, float y4,
			float z1, float z2, float z3, float z4,
			float w1, float w2, float w3, float w4);


	
	/** static member function that creates a Rotation Matrix for the X-axis
	* @param angle : the angle in radians
	* @return rotation matrix around the x axis
	*/
	static Matrix4D RotX_axis(float angle); 
	/** static member function that creates a Rotation Matrix for the X-axis
	* @param angle : the angle in radians
	* @return rotation matrix around the x axis
	*/
	static Matrix4D RotY_axis(float angle);
	/** static member function that creates a Rotation Matrix for the Z-axis
	* @param angle : the angle in radians
	* @return rotation matrix around the Z-axis
	*/
	static Matrix4D RotZ_axis(float angle);
	/** static member function that creates a Rotation Matrix for a vectors axis
	* @param angle : the angle in radians
	* @param vect : vector which axis is rotated around
	* @return rotation matrix around the given vector
	*/
	static Matrix4D RotVect_axis(Vector4D vect, float angle);

	/** static member function that calculates the transpose of a given matrix
	* @param mat : matrix to transpose
	* @return Transposed matrix
	*/
	static Matrix4D Transpose(Matrix4D mat);

	/**
	* Static member function That calculates the inverse of the given matrix
	* @param matrix
	* @return inverse of the matrix
	*/
	static Matrix4D Inverse(Matrix4D mat);


	/**
	* Calculates the determinant of a 4x4 matrix
	* @return Determinant as a float
	*/
	float Det();
	/**
	* Calculates the inverse of a 4x4 matrix
	* @return A New matrix which is the inverse of matrix calling the method.
	*/
	Matrix4D Inverse();

	/** Changes the matrix into it's transpose*/
	void Transpose();

	/** 4x4 matrix multiplication with a 4x4 matrix
	* @return a new matrix
	*/
	Matrix4D operator*(const Matrix4D& other);

	/**
	* Operator overloading, allowing scalar with a float and 4x4 matrix
	* @return A new matrix with the cells multiplied with the given float.
	*/
	Matrix4D operator*(const float& other);


	/** 4x4 matrix multiplication with a 4D vector 
	* @return a new vector
	*/
	Vector4D operator*(const Vector4D& other);

	/** allows access to the matrixs private data, reading */
	float& operator[] (int index);

	/** allows access to the matrixs private data, writing */
	const float& operator[] (int index) const;



private:
	/**
	* private member function used for the calculation of a 3x3 matrix Determinant used in the calculation of 4x4 Matrix inverse.
	* @param submat[9] : a submatrix of a 4x4 matrix
	* @return determinant of a 3x3 matrix
	*/
	static float det3x3(float submat[9]);
	float _matrix_values[16]; /*[ x1[0]  y1[1]  z1[2]  w1[3]  ]
								[ x2[4]  y2[5]  z2[6]  w2[7]  ]
								[ x3[8]  y3[9]  z3[10] w3[11] ]
								[ x4[12] y4[13] z4[14  w4[15] ] */
																
};

Matrix4D::Matrix4D()
{
	this->_matrix_values[0] = 1;
	this->_matrix_values[1] = 0;
	this->_matrix_values[2] = 0;
	this->_matrix_values[3] = 0;

	this->_matrix_values[4] = 0;
	this->_matrix_values[5] = 1;
	this->_matrix_values[6] = 0;
	this->_matrix_values[7] = 0;

	this->_matrix_values[8] = 0;
	this->_matrix_values[9] = 0;
	this->_matrix_values[10] = 1;
	this->_matrix_values[11] = 0;

	this->_matrix_values[12] = 0;
	this->_matrix_values[13] = 0;
	this->_matrix_values[14] = 0;
	this->_matrix_values[15] = 1;
}



Matrix4D::Matrix4D(float x1, float x2, float x3, float x4,
					float y1, float y2, float y3, float y4,
					float z1, float z2, float z3, float z4,
					float w1, float w2, float w3, float w4)
{
	_matrix_values[0] = x1;
	_matrix_values[4] = x2;
	_matrix_values[8] = x3;
	_matrix_values[12] = x4;

	_matrix_values[1] = y1;
	_matrix_values[5] = y2;
	_matrix_values[9] = y3;
	_matrix_values[13] = y4;

	_matrix_values[2] = z1;
	_matrix_values[6] = z2;
	_matrix_values[10] = z3;
	_matrix_values[14] = z4;

	_matrix_values[3] = w1;
	_matrix_values[7] = w2;
	_matrix_values[11] = w3;
	_matrix_values[15] = w4;


}

Matrix4D Matrix4D::RotX_axis(float rad)
{
	
	return Matrix4D(1,			0,			0,			0,
					0,		 cos(rad), -sin(rad),		0,
					0,		 sin(rad), cos(rad),		0,
					0,		 0,			 0,				1);
}
Matrix4D Matrix4D::RotY_axis(float rad)
{
	return Matrix4D(cos(rad),	0,		sin(rad),	 0,
					0,			1,			0,		 0,
					-sin(rad), 0,	 cos(rad),		 0,
					0,			0,			0,		 1);
}
Matrix4D Matrix4D::RotZ_axis(float rad)
{
	return Matrix4D(cos(rad), -sin(rad),	0,		 0,
					sin(rad), cos(rad),   0,		 0,
					0,			0,			1,		 0,
					0,			0,			0,		 1);
}
Matrix4D Matrix4D::RotVect_axis(Vector4D vect,float rad)
{
	float co = cos(rad);
	float tcos = 1 - cos(rad);
	float si = sin(rad);
	float x = vect[0];
	float y = vect[1];
	float z = vect[2];

	return Matrix4D(co+x*x*tcos,	x*y*tcos-z*si,	x*z*tcos+y*si,	0,
					y*x*tcos+z*si,	co+y*y*tcos,	y*z*tcos-x*si,	0,
					z*x*tcos-y*si,	x*y*tcos+x*si,	co+z*z*tcos,	0,
					0,				0,				0,				0);
}
Matrix4D Matrix4D::Transpose(Matrix4D mat)
{
	mat[1] = mat[4];
	mat[2] = mat[8];
	mat[3] = mat[12];

	mat[4] = mat[1];
	mat[5] = mat[5];
	mat[6] = mat[6];
	mat[7] = mat[7];

	mat[8] = mat[2];
	mat[9] = mat[6];
	mat[10] = mat[10];
	mat[11] = mat[14];

	mat[12] = mat[3];
	mat[13] = mat[7];
	mat[14] = mat[11];
	mat[15] = mat[15];
	return mat;
}
void Matrix4D::Transpose()
{
	this->A[1] = this->A[4];
	this->A[2] = this->A[8];
	this->A[3] = this->A[12];

	this->A[4] = this->A[1];
	this->A[5] = this->A[5];
	this->A[6] = this->A[6];
	this->A[7] = this->A[7];

	this->A[8] = this->A[2];
	this->A[9] = this->A[6];
	this->A[10] = this->A[10];
	this->A[11] = this->A[14];

	this->A[12] = this->A[3];
	this->A[13] = this->A[7];
	this->A[14] = this->A[11];
	this->A[15] = this->A[15];
}

float Matrix4D::Det()
{
	return
		A[3] * A[6] * A[9] * A[12] - A[2] * A[7] * A[9] * A[12] -
		A[3] * A[5] * A[10] * A[12] + A[1] * A[7] * A[10] * A[12] +
		A[2] * A[5] * A[11] * A[12] - A[1] * A[6] * A[11] * A[12] -
		A[3] * A[6] * A[8] * A[13] + A[2] * A[7] * A[8] * A[13] +
		A[3] * A[4] * A[10] * A[13] - A[0] * A[7] * A[10] * A[13] -
		A[2] * A[4] * A[11] * A[13] + A[0] * A[6] * A[11] * A[13] +
		A[3] * A[5] * A[8] * A[14] - A[1] * A[7] * A[8] * A[14] -
		A[3] * A[4] * A[9] * A[14] + A[0] * A[7] * A[9] * A[14] +
		A[1] * A[4] * A[11] * A[14] - A[0] * A[5] * A[11] * A[14] -
		A[2] * A[5] * A[8] * A[15] + A[1] * A[6] * A[8] * A[15] +
		A[2] * A[4] * A[9] * A[15] - A[0] * A[6] * A[9] * A[15] -
		A[1] * A[4] * A[10] * A[15] + A[0] * A[5] * A[10] * A[15];
}

Matrix4D Matrix4D::Inverse()
{

	float det = this->Det();
	if (det == 0)
		this;

	float submat1[9] = { this->A[5], this->A[6], this->A[7],
						this->A[9], this->A[10], this->A[11],
						this->A[13], this->A[14], this->A[15] };
	float submat2[9] = { this->A[4], this->A[6], this->A[7],
					this->A[8], this->A[10], this->A[11],
					this->A[12], this->A[14], this->A[15] };
	float submat3[9] = { this->A[4], this->A[5], this->A[7],
					this->A[8], this->A[9], this->A[11],
					this->A[12], this->A[13], this->A[15] };
	float submat4[9] = { this->A[4], this->A[5], this->A[6],
					this->A[8], this->A[9], this->A[10],
					this->A[12], this->A[13], this->A[14] };

	float submat5[9] = { this->A[1], this->A[2], this->A[3],
					this->A[9], this->A[10], this->A[11],
					this->A[13], this->A[14], this->A[15] };
	float submat6[9] = { this->A[0], this->A[2], this->A[3],
					this->A[8], this->A[10], this->A[11],
					this->A[12], this->A[14], this->A[15] };
	float submat7[9] = { this->A[0], this->A[1], this->A[3],
					this->A[8], this->A[9], this->A[11],
					this->A[12], this->A[13], this->A[15] };
	float submat8[9] = { this->A[0], this->A[1], this->A[2],
					this->A[8], this->A[9], this->A[10],
					this->A[12], this->A[13], this->A[14] };

	float submat9[9] = { this->A[1], this->A[2], this->A[3],
					this->A[5], this->A[6], this->A[7],
					this->A[13], this->A[14], this->A[15] };
	float submat10[9] = { this->A[0], this->A[2], this->A[3],
					this->A[4], this->A[6], this->A[7],
					this->A[12], this->A[14], this->A[15] };
	float submat11[9] = { this->A[0], this->A[1], this->A[3],
					this->A[4], this->A[5], this->A[7],
					this->A[12], this->A[13], this->A[14] };
	float submat12[9] = { this->A[0], this->A[1], this->A[2],
					this->A[4], this->A[5], this->A[6],
					this->A[12], this->A[13], this->A[14] };

	float submat13[9] = { this->A[1], this->A[2], this->A[3],
					this->A[5], this->A[6], this->A[7],
					this->A[9], this->A[10], this->A[11] };
	float submat14[9] = { this->A[0], this->A[2], this->A[3],
					this->A[4], this->A[6], this->A[7],
					this->A[8], this->A[10], this->A[11] };
	float submat15[9] = { this->A[0], this->A[1], this->A[3],
					this->A[4], this->A[5], this->A[7],
					this->A[8], this->A[9], this->A[11] };
	float submat16[9] = { this->A[0], this->A[1], this->A[2],
					this->A[4], this->A[5], this->A[6],
					this->A[8], this->A[9], this->A[10] };

	float x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4;
	float detdiv = (1 / det);

	x1 = Matrix4D::det3x3(submat1);
	x2 = Matrix4D::det3x3(submat2);
	x3 = Matrix4D::det3x3(submat3);
	x4 = Matrix4D::det3x3(submat4);

	y1 = Matrix4D::det3x3(submat5);
	y2 = Matrix4D::det3x3(submat6);
	y3 = Matrix4D::det3x3(submat7);
	y4 = Matrix4D::det3x3(submat8);

	z1 = Matrix4D::det3x3(submat9);
	z2 = Matrix4D::det3x3(submat10);
	z3 = Matrix4D::det3x3(submat11);
	z4 = Matrix4D::det3x3(submat12);

	w1 = Matrix4D::det3x3(submat13);
	w2 = Matrix4D::det3x3(submat14);
	w3 = Matrix4D::det3x3(submat15);
	w4 = Matrix4D::det3x3(submat16);

	Matrix4D adj(x1, -x2, x3, -x4, -y1, y2, -y3, y4, z1, -z2, z3, -z4, -w1, w2, -w3, w4);
	adj.Transpose();
	adj = adj * detdiv;

	return adj;
}

Vector4D Matrix4D::operator*(const Vector4D& other)
{
	Vector4D new_vect;
	new_vect[0] = this->A[0] * other[0] + this->A[1] * other[1] + this->A[2] * other[2] + this->A[3] * other[3]; 
	new_vect[1] = this->A[4] * other[0] + this->A[5] * other[1] + this->A[6] * other[2] + this->A[7] * other[3];
	new_vect[2] = this->A[8] * other[0] + this->A[9] * other[1] + this->A[10] * other[2] + this->A[11] * other[3];
	new_vect[3] = this->A[12] * other[0] + this->A[13] * other[1] + this->A[14] * other[2] + this->A[15] * other[3];

	return new_vect;
}

Matrix4D Matrix4D::Inverse(Matrix4D mat)
{
	// if the determinant is 0, there's no possible inverse
	float det = mat.Det();
	if (det == 0)
		mat;


	// create 16 3x3-submatrices from the 4x4 matrix
	float submat1[9] = { mat.A[5], mat.A[6], mat.A[7],
						mat.A[9], mat.A[10], mat.A[11],
						mat.A[13], mat.A[14], mat.A[15] };
	float submat2[9] = { mat.A[4], mat.A[6], mat.A[7],
					mat.A[8], mat.A[10], mat.A[11],
					mat.A[12], mat.A[14], mat.A[15] };
	float submat3[9] = { mat.A[4], mat.A[5], mat.A[7],
					mat.A[8], mat.A[9], mat.A[11],
					mat.A[12], mat.A[13], mat.A[15] };
	float submat4[9] = { mat.A[4], mat.A[5], mat.A[6],
					mat.A[8], mat.A[9], mat.A[10],
					mat.A[12], mat.A[13], mat.A[14] };

	float submat5[9] = { mat.A[1], mat.A[2], mat.A[3],
					mat.A[9], mat.A[10], mat.A[11],
					mat.A[13], mat.A[14], mat.A[15] };
	float submat6[9] = { mat.A[0], mat.A[2], mat.A[3],
					mat.A[8], mat.A[10], mat.A[11],
					mat.A[12], mat.A[14], mat.A[15] };
	float submat7[9] = { mat.A[0], mat.A[1], mat.A[3],
					mat.A[8], mat.A[9], mat.A[11],
					mat.A[12], mat.A[13], mat.A[15] };
	float submat8[9] = { mat.A[0], mat.A[1], mat.A[2],
					mat.A[8], mat.A[9], mat.A[10],
					mat.A[12], mat.A[13], mat.A[14] };

	float submat9[9] = { mat.A[1], mat.A[2], mat.A[3],
					mat.A[5], mat.A[6], mat.A[7],
					mat.A[13], mat.A[14], mat.A[15] };
	float submat10[9] = { mat.A[0], mat.A[2], mat.A[3],
					mat.A[4], mat.A[6], mat.A[7],
					mat.A[12], mat.A[14], mat.A[15] };
	float submat11[9] = { mat.A[0], mat.A[1], mat.A[3],
					mat.A[4], mat.A[5], mat.A[7],
					mat.A[12], mat.A[13], mat.A[14] };
	float submat12[9] = { mat.A[0], mat.A[1], mat.A[2],
					mat.A[4], mat.A[5], mat.A[6],
					mat.A[12], mat.A[13], mat.A[14] };

	float submat13[9] = { mat.A[1], mat.A[2], mat.A[3],
					mat.A[5], mat.A[6], mat.A[7],
					mat.A[9], mat.A[10], mat.A[11] };
	float submat14[9] = { mat.A[0], mat.A[2], mat.A[3],
					mat.A[4], mat.A[6], mat.A[7],
					mat.A[8], mat.A[10], mat.A[11] };
	float submat15[9] = { mat.A[0], mat.A[1], mat.A[3],
					mat.A[4], mat.A[5], mat.A[7],
					mat.A[8], mat.A[9], mat.A[11] };
	float submat16[9] = { mat.A[0], mat.A[1], mat.A[2],
					mat.A[4], mat.A[5], mat.A[6],
					mat.A[8], mat.A[9], mat.A[10] };

	//define the new cells for the adjugate  4x4-matrix
	float x1, x2, x3, x4, y1, y2, y3, y4, z1, z2, z3, z4, w1, w2, w3, w4;
	// define the fraction used in calculating the inverse
	float detdiv = (1 / det);

	//calculating each cell. each cell's value is the determinant of it's 3x3-submatrix
	x1 = Matrix4D::det3x3(submat1);
	x2 = Matrix4D::det3x3(submat2);
	x3 = Matrix4D::det3x3(submat3);
	x4 = Matrix4D::det3x3(submat4);

	y1 = Matrix4D::det3x3(submat5);
	y2 = Matrix4D::det3x3(submat6);
	y3 = Matrix4D::det3x3(submat7);
	y4 = Matrix4D::det3x3(submat8);

	z1 = Matrix4D::det3x3(submat9);
	z2 = Matrix4D::det3x3(submat10);
	z3 = Matrix4D::det3x3(submat11);
	z4 = Matrix4D::det3x3(submat12);

	w1 = Matrix4D::det3x3(submat13);
	w2 = Matrix4D::det3x3(submat14);
	w3 = Matrix4D::det3x3(submat15);
	w4 = Matrix4D::det3x3(submat16);

	//construct the 4x4 matrix
	Matrix4D adj(x1, -x2, x3, -x4, -y1, y2, -y3, y4, z1, -z2, z3, -z4, -w1, w2, -w3, w4);
	// transpose the new 4x4-matrix
	adj.Transpose();
	//multiply the determinant fraction into each cell to complete the inversion. 
	adj = adj * detdiv;
	//adj will be the inverse of the origina 4x4 matrix
	return adj;
}

Matrix4D Matrix4D::operator*(const Matrix4D& other)
{
	// performs multiplication between 2 4x4-matrices
	Matrix4D new_mat;
	new_mat.A[0] = this->A[0] * other.A[0] + this->A[1] * other.A[4] + this->A[2] * other.A[8] + this->A[3] * other.A[12];
	new_mat.A[1] = this->A[0] * other.A[1] + this->A[1] * other.A[5] + this->A[2] * other.A[9] + this->A[3] * other.A[13];
	new_mat.A[2] = this->A[0] * other.A[2] + this->A[1] * other.A[6] + this->A[2] * other.A[10] + this->A[3] * other.A[14];
	new_mat.A[3] = this->A[0] * other.A[3] + this->A[1] * other.A[7] + this->A[2] * other.A[11] + this->A[3] * other.A[15];

	new_mat.A[4] = this->A[4] * other.A[0] + this->A[5] * other.A[4] + this->A[6] * other.A[8] + this->A[7] * other.A[12];
	new_mat.A[5] = this->A[4] * other.A[1] + this->A[5] * other.A[5] + this->A[6] * other.A[9] + this->A[7] * other.A[13];
	new_mat.A[6] = this->A[4] * other.A[2] + this->A[5] * other.A[6] + this->A[6] * other.A[10] + this->A[7] * other.A[14];
	new_mat.A[7] = this->A[4] * other.A[3] + this->A[5] * other.A[7] + this->A[6] * other.A[11] + this->A[7] * other.A[15];

	new_mat.A[8] = this->A[8] * other.A[0] + this->A[9] * other.A[4] + this->A[10] * other.A[8] + this->A[11] * other.A[12];
	new_mat.A[9] = this->A[8] * other.A[1] + this->A[9] * other.A[5] + this->A[10] * other.A[9] + this->A[11] * other.A[13];
	new_mat.A[10] = this->A[8] * other.A[2] + this->A[9] * other.A[6] + this->A[10] * other.A[10] + this->A[11] * other.A[14];
	new_mat.A[11] = this->A[8] * other.A[3] + this->A[9] * other.A[7] + this->A[10] * other.A[11] + this->A[11] * other.A[15];

	new_mat.A[12] = this->A[12] * other.A[0] + this->A[13] * other.A[4] + this->A[14] * other.A[8] + this->A[15] * other.A[12];
	new_mat.A[13] = this->A[12] * other.A[1] + this->A[13] * other.A[5] + this->A[14] * other.A[9] + this->A[15] * other.A[13];
	new_mat.A[14] = this->A[12] * other.A[2] + this->A[13] * other.A[6] + this->A[14] * other.A[10] + this->A[15] * other.A[14];
	new_mat.A[15] = this->A[12] * other.A[3] + this->A[13] * other.A[7] + this->A[14] * other.A[11] + this->A[15] * other.A[15];

	return new_mat;
}

Matrix4D Matrix4D::operator*(const float& other)
{
	// multiplies a matrix's cells with a float
	Matrix4D new_mat;

	for (int i = 0; i < 16; i++)
	{
		new_mat._matrix_values[i] = this->_matrix_values[i] * other;
	}
	return new_mat;
}

float& Matrix4D::operator[] (int index)
{
	if (index <= 15 && index >= 0)
	{
		return this->_matrix_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}

const float& Matrix4D::operator[] (int index) const
{
	if (index <= 15 && index >= 0)
	{
		return this->_matrix_values[index];
	}
	else
	{
		throw "INDEX OUT OF BOUNDS";
	}
}


float Matrix4D::det3x3(float submat[9])
{

	return submat[0] * (submat[4] * submat[8] - submat[5] * submat[7]) -
			submat[1] * (submat[3] * submat[8] - submat[5] * submat[6]) + 
			submat[2] * (submat[3] * submat[7] - submat[4] * submat[6]);
}
#undef A