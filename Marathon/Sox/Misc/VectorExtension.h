#ifndef VectorExtension_H
#define VectorExtension_H

#include <Xboxmath.h>

//821E8778 
// Name :CreateRotationQuaternionFromXMVectors , not correct
XMVECTOR CreateRotationQuaternionFromXMVectors(XMVECTOR quat2, XMVECTOR quat3, XMVECTOR quat4){

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


XMVECTOR CreateRotationQuaternionFromVectorsAlternative(XMVECTOR quat2, XMVECTOR quat3, XMVECTOR quat4) {
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
