#include "Mesh.h"

Mesh::Mesh(float* vertex, int vsize) {
	m_vertex = new float[vsize];
	m_vsize =vsize;

	for (int i = 0; i < m_vsize; i++) {
		m_vertex[i] = vertex[i];
	}	

	m_indices = nullptr;
	m_isize = 0;

}
Mesh::Mesh(float* vertex,unsigned int* indices, int vsize,int isize) {
	m_vertex = new float[vsize];
	m_vsize = vsize;

	for (int i = 0; i < m_vsize; i++) {
		m_vertex[i] = vertex[i];
	}


	m_indices = new unsigned int[isize];
	m_isize = isize;

	for (int i = 0; i < m_isize; i++) {
		m_indices[i] = indices[i];
	}

}
float* Mesh::getVertex()
{
	return m_vertex;
}
unsigned int* Mesh::getIndices() {
	return m_indices;
}
int Mesh::getVSize()
{
	return m_vsize;
}
int Mesh::getISize()
{
	return m_isize;
}


Mesh::~Mesh() {
	delete[] m_vertex;
	delete[] m_indices;
}