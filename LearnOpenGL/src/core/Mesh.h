#pragma once
#include <vector>
class Mesh {
private:
	float* m_vertex;
	unsigned int* m_indices;
	int m_vsize;
	int m_isize;
public:
	Mesh(float* vertex,int vsize);
	Mesh(float* vertex, unsigned int* indices, int vsize, int isize);
	~Mesh();

	float*getVertex();
	unsigned int*getIndices();
	int getVSize();
	int getISize();

};