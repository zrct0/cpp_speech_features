#include "pch.h"
#include "DiscreteTransform.h"
#include "math.h"
namespace cpp_speech_features {

	Vectorp DiscreteTransform::dctWithOrtho(Vectorp data, accuracy scale) {
		Vectorp y = create_verctorp(dct(data));		
		int N = data->getSize();
		accuracy f;
		for (int k = 0; k < N; k++)
		{
			if (k == 0)
			{
				f = sqrt(1.0 / (4 * N));
			}
			else
			{
				f = sqrt(1.0 / (2 * N));
			}
			y->set(k, y->get(k) * f);			
		}
		return y->multiply(scale);
	}

	Matrixp DiscreteTransform::dct(Matrixp data)
	{
		Matrixp output = create_matrixp(data->getColumn(), data->getRow());		
		int u, v, i, j;
		int N = data->getRow();
		int M = data->getColumn();		

		for (u = 0; u < N; ++u) {
			for (v = 0; v < M; ++v) {
				output->set(u, v, 0);				
				for (i = 0; i < N; i++) {
					for (j = 0; j < M; j++) {
						output->set(u, v, output->get(u, v) + data->get(i, j) * cos(M_PI / ((float)N)*(i + 1. / 2.)*u)*cos(M_PI / ((float)M)*(j + 1. / 2.)*v));
					}
				}
			}
		}
		return output;
	}

	void DiscreteTransform::rfft(accuracy * x, int n)
	{
		int i, j, k, m;
		int i1, i2, i3, i4;
		int n1, n2, n4;
		accuracy a, e, cc, ss, xt, t1, t2;
		for (j = 1, i = 1; i < 16; i++)
		{
			m = i;
			j = j * 2;
			if (j == n)
				break;
		}
		n1 = n - 1;
		for (j = 0, i = 0; i < n1; i++)
		{
			if (i < j)
			{
				xt = x[j];
				x[j] = x[i];
				x[i] = xt;
			}
			k = n / 2;
			while (k < (j + 1))
			{
				j = j - k;
				k = k / 2;
			}
			j = j + k;
		}

		for (i = 0; i < n; i += 2)
		{
			xt = x[i];
			x[i] = xt + x[i + 1];
			x[i + 1] = xt - x[i + 1];
		}

		n2 = 1;
		for (k = 2; k <= m; k++)
		{
			n4 = n2;
			n2 = 2 * n4;
			n1 = 2 * n2;
			e = 6.28318530718 / n1;
			for (i = 0; i < n; i += n1)
			{
				xt = x[i];
				x[i] = xt + x[i + n2];
				x[i + n2] = xt - x[i + n2];
				x[i + n2 + n4] = -x[i + n2 + n4];
				a = e;
				for (j = 1; j <= (n4 - 1); j++)
				{
					i1 = i + j;
					i2 = i - j + n2;
					i3 = i + j + n2;
					i4 = i - j + n1;
					cc = cos(a);
					ss = sin(a);
					a = a + e;
					t1 = cc * x[i3] + ss * x[i4];
					t2 = ss * x[i3] - cc * x[i4];
					x[i4] = x[i2] - t2;
					x[i3] = -x[i2] - t2;
					x[i2] = x[i1] - t1;
					x[i1] = x[i1] + t1;
				}
			}
		}
	}
}