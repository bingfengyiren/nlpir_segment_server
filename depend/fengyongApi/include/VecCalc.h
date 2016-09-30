#ifndef _LINEAR_OPTS_VEC_CALC_H 
#define _LINEAR_OPTS_VEC_CALC_H 

#include <stdint.h>


namespace fengyoung
{

// ������VecCalc
// ˵��������������
class VecCalc
{
private: 
	// ���캯�� & ��������
	VecCalc(); 
	virtual ~VecCalc(); 

public:
	// ��������Print_F / Print_S
	// ˵������ӡһ���������� / ��ӡһ��ϡ������	
	// ������
	//	[IN] v - ��������
	//	[IN] size - ��������
	//	[IN] sv - ϡ������
	//	[IN] scnt - ϡ�������з���Ԫ�ظ���
	static void Print_F(double* v, const int64_t size); 
	static void Print_S(double* sv, const int64_t scnt); 

	// ��������Copy_F / Copy_S
	// ˵����copy v to v_out / copy sparse sv to sv_out
	//	[OUT] v_out - �������������
	//	[IN] v - ��������
	//	[IN] size - ��������
	//	[OUT] sv_out - �����ϡ������
	//	[IN] sv - ϡ������
	//	[IN] scnt - ϡ�������з���Ԫ�ظ���
	static void Copy_F(double* v_out, double* v, const int64_t size); 
	static void Copy_S(double* sv_out, double* sv, const int64_t scnt); 

	// ��������Dot_FF / Dot_FS
	// ˵��������dot(v1, v2) / dot(v1, sv2)
	// ������	
	//	[IN] v1, v2 - ��������
	//	[IN] size - ��������
	//	[IN] sv1, sv2 - ϡ������
	//	[IN] scnt1, scnt2 - ϡ��sv1��sv2�з���Ԫ�ظ���
	// ����ֵ����˽��
	static double Dot_FF(double* v1, double* v2, const int64_t size); 
	static double Dot_FS(double* v1, const int64_t size, double* sv2, const int64_t scnt2); 

	// ��������ScalWith_F / ScalWith_S
	// ˵����v := alpha * v / sv := alpha * sv
	// ������
	//	[IN|OUT] v - ��������
	//	[IN] alpha - ����
	//	[IN] size - ��������
	//	[IN|OUT] sv - ϡ������
	//	[IN] scnt - ϡ�������з���Ԫ�ظ���
	static void ScalWith_F(double* v, const double alpha, const int64_t size); 
	static void ScalWith_S(double* sv, const double alpha, const int64_t scnt); 
	
	// ��������Scal_F / Scal_S
	// ˵����v_out := alpha * v / sv_out := alpha * sv
	// ������
	//	[OUT] v_out - �������������
	//	[IN] alpha - ����
	//	[IN] v - ��������
	//	[IN] size - ��������
	//	[OUT] sv_out - �����ϡ������
	//	[IN] sv - ϡ������
	//	[IN] scnt - ϡ�������з���Ԫ�ظ���
	static void Scal_F(double* v_out, const double alpha, double* v, 
			const int64_t size); 
	static void Scal_S(double* sv_out, const double alpha, double* sv, 
			const int64_t scnt); 

	// ��������AddWith_FF
	// ˵����v_out := alpha * v + v_out
	// ������
	//	[OUT] v_out - �������������
	//	[IN] alpha - ����
	//	[IN] v - ��������
	//	[IN] size - ��������
	static void AddWith_FF(double* v_out, const double alpha, double* v, 
			const int64_t size); 

	// ��������Add_FF
	// ˵����v_out := alpha * v1 + beta * v2
	// ������
	//	[OUT] v_out - �������������
	//	[IN] alpha, beta - ����
	//	[IN] v1, v2 - ��������
	//	[IN] size - ��������
	static void Add_FF(double* v_out, const double alpha, double* v1, 
			const double beta, double* v2, const int64_t size); 

	// ��������ModL1_F / ModL1_S
	// ˵������������������L1ģ / ����ϡ��������L1ģ
	// ������
	//	[IN] v - ��������
	//	[IN] size - ��������
	//	[IN] sv - ϡ������
	//	[IN] scnt - ϡ�������з���Ԫ�ظ���
	static double ModL1_F(double* v, const int64_t size); 
	static double ModL1_S(double* sv, const int64_t scnt); 
	
	// ��������ModL2_F / ModL2_S
	// ˵������������������L2ģ / ����ϡ��������L2ģ
	// ������
	//	[IN] v - ��������
	//	[IN] size - ��������
	//	[IN] sv - ϡ������
	//	[IN] scnt - ϡ�������з���Ԫ�ظ���
	static double ModL2_F(double* v, const int64_t size); 
	static double ModL2_S(double* sv, const int64_t scnt); 
};

}

#endif /* _LINEAR_OPTS_VEC_CALC_H */

