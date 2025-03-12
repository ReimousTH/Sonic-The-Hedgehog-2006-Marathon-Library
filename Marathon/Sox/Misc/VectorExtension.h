#ifndef VectorExtension_H
#define VectorExtension_H

#include <Xboxmath.h>
#include <limits>

struct XMVECTOR4X3{
	XMVECTOR Vector1;
	XMVECTOR Vector2;
	XMVECTOR Vector3;
};



// Retrieve the gravity direction from the stored rotation quaternion
static XMVECTOR GetOriginalGravityDirection(const XMVECTOR& normalizedSurfaceQuaternion) {

	return normalizedSurfaceQuaternion;
}


//  Calculates a normalized surface vector based on gravity direction. (821E8578)
static XMVECTOR CreateRotationFromUpToDirection(const XMFLOAT3& inputDirection)
{
	const XMVECTOR upVector = XMVectorSet(0.0f, 1.0f, 0.0f, 0.0f);
	const float epsilon = (XMVectorSplatEpsilon()).x;

	// 1. Load and normalize input vector
	XMVECTOR direction = XMLoadFloat3(&inputDirection);
	XMVECTOR normDirection = XMVector3Normalize(direction);

	// 2. Check for zero-length input
	if(XMVector3NearEqual(normDirection, XMVectorZero(), XMVectorReplicate(epsilon)))
	{
		return XMQuaternionIdentity();
	}

	// 3. Calculate orthogonal basis
	XMVECTOR cross = XMVector3Cross(upVector, normDirection);
	XMVECTOR normCross = XMVector3Normalize(cross);

	// 4. Check for colinear vectors
	if(XMVector3NearEqual(normCross, XMVectorZero(), XMVectorReplicate(epsilon)))
	{
		return XMQuaternionIdentity();
	}

	// 5. Calculate angle components
	XMVECTOR dot = XMVector3Dot(normDirection, upVector);
	float cosAngle = (XMVectorClamp(dot, 
		XMVectorReplicate(-1.0f), 
		XMVectorReplicate(1.0f))).x;

	// 6. Create rotation quaternion
	return XMQuaternionRotationAxis(normCross, XMScalarACos(cosAngle));
}



//821E8778 
// Name :CreateRotationQuaternionFromXMVectors , not correct
static XMVECTOR CreateRotationQuaternionFromXMVectors(XMVECTOR quat2, XMVECTOR quat3, XMVECTOR quat4){

	XMVECTOR cross_vector_1 =  XMVector3Cross(quat4,quat2);
	XMVECTOR cross_vector_1_length = XMVector3Length(cross_vector_1);

	XMVECTOR cross_vector_2 =  XMVector3Cross(quat4,quat3);
	XMVECTOR cross_vector_2_length = XMVector3Length(cross_vector_2);



	XMVECTOR cross_vector_3 =  XMVector3Cross(cross_vector_1_length,cross_vector_2_length);
	XMVECTOR cross_vector_3_length = XMVector3Length(cross_vector_3);
	float cross_vector_3_length_X = cross_vector_3_length.x;
	float v15 = -1.0;
	if (cross_vector_3_length_X > 1.0){
		v15 = 1.0;
	}
	float v16 = (float)sqrt(0.5 - (v15 * 0.5) );
	float v17 = (float)sqrt(0.5 + (v15 * 0.5) );
	if (v16 != 0 && cross_vector_3_length_X == 0){

		cross_vector_3_length = XMVector3Length(quat4);
	}
	return XMVectorSet(cross_vector_3_length.x * v16,cross_vector_3_length.y * v16,cross_vector_3_length.z * v16,v17);



}


static XMVECTOR CreateRotationQuaternionFromVectorsAlternative(XMVECTOR quat2, XMVECTOR quat3, XMVECTOR quat4) {
	// 1. Normalize the vectors (important for angle calculations)
	quat2 = XMVector3Normalize(quat2);
	quat3 = XMVector3Normalize(quat3);
	quat4 = XMVector3Normalize(quat4); // Normalize rotation axis

	// 2. Calculate the angle between the vectors
	XMVECTOR angle_between = XMVector3AngleBetweenVectors(quat2, quat3);
	float angle = angle_between.x; // Extract the angle in radians

	// 3. Create a quaternion from axis-angle representation
	return XMQuaternionRotationAxis(quat4, angle);
}




#endif
