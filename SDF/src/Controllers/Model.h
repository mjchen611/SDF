// Model.h : subor pre kontrolu modelov
#pragma once
#include "Octree.h"
#include "SDFController.h"
#include "Assimp.h"
#include "VCG_lib.h"
#include "MathHelper.h"

namespace ModelController
{
	using namespace std;
	using namespace AssimpFileHandler;
	using namespace VCGFileHandler;
	using namespace SDFController;

	const int color_step = 4;

	public class CModel
	{
	public:
		CModel();
		~CModel();

		void logInfo(string logString);
		void logDebug(string logString);

		void LoadFile(string Filename);
		void LoadFileVCG(string Filename);
		void SaveModel(string Filename);
		void LoadAssimp(aiScene* scene);
		//float GetSDF(const struct aiFace* face, bool smoothed);
		float* GetSDF(int& size, bool smoothed);
		void CopySDF_Vertices_to_Faces();
		void CopySDF_Faces_to_Vertices();
		void ResetSettings();
		void AssignNumber();
		void ComputeBoundary();
		void CreateOctree();
		void SetColors();
		void ComputeSusedov();
		void GetBoundary(float &siz, float &x, float &y, float &z);
		void DrawModel();
		void ColorToRGB(int color, GLubyte &R, GLubyte &G, GLubyte &B);
		void HLSToRGB(float SDF_value, GLubyte &R, GLubyte &G, GLubyte &B);
		void ProcessPick(int x, int y);
		void ComputeSDF();
		void TriangulatePoints();
		void ReloadOctreeData();
		void DeleteIdenticalVertices();
		void EraseIdenticalVertices();
		void BuildArrays();
		void ComputeSoftNormals();
		void MergeResults(LinkedList<Face>* triangles_backup, LinkedList<Vertex>* points_backup);
		void RecomputeSmoothing();
		void NormalizeTextureCoords();
		unsigned char*** GetTexture();
		void SmoothTexture();

		bool loaded;
		bool show_octree;
		bool show_normals;
		Face* selected;
		GLfloat Look_X, Look_Y, Look_Z;
	private:
		CAssimp* Assimp;
		CVCG* VCGlib;
		CSDFController* SDF_control;
		LinkedList<Face>* triangles;
		LinkedList<Vertex>* points;
		Octree* m_root;

		// rozmery modelu
		Vector4				b_stred;		// center of minN - maxN
		float				b_size;			// size for octree
		float				b_sf;			// scale factor
		float				b_max;			// diagonala v octree
		Vector4				o_min;
		Vector4				o_max;
		unsigned int		nodeCount;
		unsigned int		leafCount;
		unsigned int		triangleCount;
	};
}