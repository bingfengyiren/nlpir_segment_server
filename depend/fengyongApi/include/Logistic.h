#ifndef _LINEAR_OPTS_LOGISTIC_H 
#define _LINEAR_OPTS_LOGISTIC_H 

#include <stdint.h>


namespace fengyoung
{

// ��������Logistic
// ˵����Logistic�任��ؼ�����
class Logistic
{
private:
	// ���캯�� & ��������
	Logistic(); 
	virtual ~Logistic(); 

public:
	// ��������Sigma
	// ˵����Logistic�任��y = 1/(1+exp(-x))
	// ������
	//	[IN] x - �Ա���
	// ����ֵ��Logistic�任���(�����y)	
	static double Sigma(const double x);

	// ��������Sigma_FF
	// ˵����Logistic�ع麯��
	//		 ������������Ȩ�������Լ���������������������
	// ������
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] xi - ��������
	//	[IN] vec_size - ������������
	// ����ֵ��Logistic�ع�ֵ
	static double Sigma_FF(double* w, const double yi, double* xi, 
			const int64_t vec_size); 

	// ��������Sigma_FS
	// ˵����Logistic�ع麯��
	//		 ������������Ȩ����������������������������ϡ������
	// ������
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] sxi - ��������(ϡ������)
	//	[IN] vec_size - ������������
	//	[IN] scnt - ϡ������������з���Ԫ�ظ���
	// ����ֵ��Logistic�ع�ֵ
	static double Sigma_FS(double* w, const double yi, double* sxi, 
			const int64_t vec_size, const int64_t scnt); 
	
	// ��������CostFunc_FF
	// ˵����Logistic�ع��е���ʧ����
	//		 ������������Ȩ�������Լ���������������������
	// ������
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] xi - ��������
	//	[IN] vec_size - ������������
	// ����ֵ��Logistic�ع���ʧ����ֵ
	static double CostFunc_FF(double* w, const double yi, double* xi, 
			const int64_t vec_size); 
	
	// ��������CostFunc_FS
	// ˵����Logistic�ع��е���ʧ����
	//		 ������������Ȩ����������������������������ϡ������
	// ������
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] sxi - ��������(ϡ������)
	//	[IN] vec_size - ������������
	//	[IN] scnt - ϡ������������з���Ԫ�ظ���
	// ����ֵ��Logistic�ع���ʧ����ֵ
	static double CostFunc_FS(double* w, const double yi, double* sxi, 
			const int64_t vec_size, const int64_t scnt); 
	
	// ��������CostFuncGrad_FF
	// ˵��������Logistic�ع�����ʧ�������ݶ�
	//		 ������������Ȩ�������Լ���������������������
	//	[OUT] g - ��ʧ�������ݶ�����
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] xi - ��������
	//	[IN] vec_size - ������������
	static void CostFuncGrad_FF(double* g, const double yi, double* w, 
			double* xi, const int64_t vec_size);
	
	// ��������CostFuncGrad_FS
	// ˵��������Logistic�ع�����ʧ�������ݶ�
	//		 ������������Ȩ����������������������������ϡ������
	//	[OUT] g - ��ʧ�������ݶ�����(��������)
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] sxi - ��������(ϡ������)
	//	[IN] vec_size - ������������
	//	[IN] scnt - ϡ������������з���Ԫ�ظ���
	static void CostFuncGrad_FS(double* g, const double yi, double* w, 
			double* sxi, const int64_t vec_size, const int64_t scnt);

	// ��������CostFuncWithGrad_FF
	// ˵��������Logistic�ع�����ʧ�����Լ���ʧ�������ݶ�
	//		 ������������Ȩ�������Լ���������������������
	//	[OUT] cost - ��ʧ����ֵ
	//	[OUT] g - ��ʧ�������ݶ�����
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] xi - ��������
	//	[IN] vec_size - ������������
	static void CostFuncWithGrad_FF(double& cost, double* g, const double yi, 
			double* w, double* xi, const int64_t vec_size);
	
	// ��������CostFuncWithGrad_FS
	// ˵��������Logistic�ع�����ʧ�����Լ���ʧ�������ݶ�
	//		 ������������Ȩ����������������������������ϡ������
	//	[OUT] cost - ��ʧ����ֵ
	//	[OUT] g - ��ʧ�������ݶ�����(��������)
	//	[IN] w - ����Ȩ������
	//	[IN] yi - ���������ǩ(+1 or -1)
	//	[IN] sxi - ��������(ϡ������)
	//	[IN] vec_size - ������������
	//	[IN] scnt - ϡ������������з���Ԫ�ظ���
	static void CostFuncWithGrad_FS(double& cost, double* g, const double yi, 
			double* w, double* sxi, const int64_t vec_size, const int64_t scnt);
};

}

#endif /* _LINEAR_OPTS_LOGISTIC_H */

